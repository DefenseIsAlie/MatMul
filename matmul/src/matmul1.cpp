#include <iostream>
#include <sstream>
#include <chrono>
#include "../inc/input.hpp"
#include "../inc/ijkmul.hpp"
#include "../inc/utils.hpp"
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

    if (argc!=2){
        dim = diminput::_commandline_input(0);
        if (dim != INPUT_ERROR && dim){
            std::cout << dim << std::endl;
        }else{
            std::cout << "Input error wrong base or incorrect input" << std::endl;
        }
    } else {
        dim = diminput::_argv_input(argv,1);
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

    // Add event L3 Total cache misses
    //retval = PAPI_add_event(EventSet, PAPI_L3_TCM);
    //if (retval != PAPI_OK) 
    //    handle_error(retval);

	// TOTAL cycles 
	retval = PAPI_add_event(EventSet, PAPI_TOT_CYC);
	if (retval != PAPI_OK) 
		handle_error(retval);
	
	// TOTAL instructions 
	retval = PAPI_add_event(EventSet, PAPI_TOT_INS);
	if (retval != PAPI_OK) 
		handle_error(retval);
#endif

    double** A = ijk::_create_matrix(dim);
    double** B = ijk::_create_matrix(dim);
    double** C = ijk::_create_matrix(dim);
    
    ijk::_initialize_matrix(dim, A);
    ijk::_initialize_matrix(dim, B);

    double* a = to_1d(A,dim,1);
    double* b = to_1d(B,dim,0);
    double* c = to_1d(C,dim,1);

    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    #ifdef PAPI
        retval = PAPI_start(EventSet);
        if (retval != PAPI_OK) handle_error(retval);
    #endif
    ijk::_matmul(dim, a, b, c);
    #ifdef PAPI
        retval = PAPI_stop(EventSet, values);
        if (retval != PAPI_OK) handle_error(retval);
    #endif
    
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    #ifdef PAPI
        float ratio = values[0]/(float)(values[1]);
        printf("total L1 misses:%lld total L2 misses:%lld total instructions:%lld total cycles:%lld\n", values[0],values[1], values[3], values[2]);
        std::cout << ratio << std::endl;
    #endif
    
    double mul_time = std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << "Time take for matmul1 is "<< mul_time << " ms" << std::endl;

    C = to_2d(c, dim, 1);

    check(dim, C);

    return 0;
}