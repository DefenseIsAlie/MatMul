#include <iostream>
#include <sstream>
#include <chrono>
#include "../inc/input.hpp"
#include "../inc/row_blocked_mul.hpp"
#include "test.hpp"

#ifdef PAPI
#include "papi.h"

//for handling error messages
inline void handle_error(int retval)
{
	printf("PAPI error %d: %s\n",retval, PAPI_strerror(retval));
	exit(1);
}
#endif

int main(int argc, char* argv[]){
    int dim;

	int blk_size;

    if (argc!=3){
        dim = diminput::_commandline_input(0);
        if (dim != INPUT_ERROR && dim){
            std::cout << dim << std::endl;
        }else{
            std::cout << "Input error wrong base or incorrect input" << std::endl;
        }
    } else {
        dim = diminput::_argv_input(argv, 1);
        if (dim != INPUT_ERROR && dim){
            std::cout << dim << std::endl;
        }else{
            std::cout << "Input error wrong base or incorrect input" << std::endl;
        }
    }

    #ifdef PAPI
        int retval, EventSet=PAPI_NULL;
        long long values[4] = {(long long)0, (long long)0, (long long)0, (long long)0};

        retval = PAPI_library_init(PAPI_VER_CURRENT);
        if(retval != PAPI_VER_CURRENT)
            handle_error(retval);
        
        retval = PAPI_create_eventset(&EventSet);
        if (retval != PAPI_OK) 
            handle_error(retval);
    
        // Add event L1 Total Cache Misses 
        retval = PAPI_add_event(EventSet, PAPI_L1_TCM);
        if (retval != PAPI_OK) 
            handle_error(retval);
        
        // Add event L2 Total cache misses
        retval = PAPI_add_event(EventSet, PAPI_L2_TCM);
        if (retval != PAPI_OK) 
            handle_error(retval);

        

        // TOTAL cycles 
        retval = PAPI_add_event(EventSet, PAPI_TOT_CYC);
        if (retval != PAPI_OK) 
            handle_error(retval);
        
        // TOTAL instructions 
        retval = PAPI_add_event(EventSet, PAPI_TOT_INS);
        if (retval != PAPI_OK) 
            handle_error(retval);
    #endif

	if (argc!=3){
        blk_size = diminput::_commandline_input(1);
        if (blk_size != INPUT_ERROR && blk_size){
            std::cout << blk_size << std::endl;
        }else{
            std::cout << "Input error wrong base or incorrect input" << std::endl;
        }
    } else {
        blk_size = diminput::_argv_input(argv, 2);
        if (blk_size != INPUT_ERROR && blk_size){
            std::cout << blk_size << std::endl;
        }else{
            std::cout << "Input error wrong base or incorrect input" << std::endl;
        }
    }

	if (dim%blk_size !=0 || dim<blk_size || dim < 0 || blk_size < 0){

		std::cout<< "dim%blk_size == 0 and dim<blk_size and dim > 0 and blk_size > 0" << std::endl;

	}

    double** A = row_block::_create_matrix(dim);
    double** B = row_block::_create_matrix(dim);
    double** C = row_block::_create_matrix(dim);
    
    row_block::_initialize_matrix(dim, A);
    row_block::_initialize_matrix(dim, B);
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    #ifdef PAPI
	    retval = PAPI_start(EventSet);
	    if (retval != PAPI_OK) handle_error(retval);
    #endif
	row_block::_matmul(dim, blk_size, A, B, C);
    #ifdef PAPI
        retval = PAPI_stop(EventSet, values);
        if (retval != PAPI_OK) handle_error(retval);
    #endif
	

    #ifdef PAPI
        float ratio = (float)values[0]/(float)values[1];
        std::cout << "L1 Total Cache Misses: " << values[0] << "\n";
        std::cout << "L2 Total Cache Misses: " << values[1] << "\n";
        std::cout << "Total Cycles: " << values[2] << "\n";
        std::cout << "Total Instructions: " << values[3] << "\n";
        std::cout << "L1-L2 miss ratio: " << ratio << "\n";
    #endif

    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

    double mul_time = std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "Time take for matmul3 is "<< mul_time << " ms" << std::endl;

    check(dim, C);

    return 0;
}