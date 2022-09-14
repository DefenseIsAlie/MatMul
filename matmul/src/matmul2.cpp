#include <iostream>
#include <sstream>
#include <chrono>
#include "../inc/input.hpp"
#include "../inc/kijmul.hpp"

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

        

        // TOTAL cycles 
        retval = PAPI_add_event(EventSet, PAPI_TOT_CYC);
        if (retval != PAPI_OK) 
            handle_error(retval);
        
        // TOTAL instructions 
        retval = PAPI_add_event(EventSet, PAPI_TOT_INS);
        if (retval != PAPI_OK) 
            handle_error(retval);
    #endif

    double** A = kij::_create_matrix(dim);
    double** B = kij::_create_matrix(dim);
    double** C = kij::_create_matrix(dim);
    
    kij::_initialize_matrix(dim, A);
    kij::_initialize_matrix(dim, B);

    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    #ifdef PAPI
	    retval = PAPI_start(EventSet);
	    if (retval != PAPI_OK) handle_error(retval);
    #endif
    kij::_matmul(dim, A, B, C);
    #ifdef PAPI
        retval = PAPI_stop(EventSet, values);
        if (retval != PAPI_OK) handle_error(retval);
    #endif
    std::cout << C[5][5] << "\n";
    std::cout << C[6][6] << "\n";
    std::cout << C[10][10] << "\n";
    std::cout << C[17][17] << "\n";
    
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    #ifdef PAPI
	    float ratio = values[0]/(float)(values[1]);
	    printf("total L1 misses:%lld total L2 misses:%lld total instructions:%lld total cycles:%lld\n", values[0],values[1], values[3], values[2]);
        std::cout << "ratio" << ratio << std::endl;

    #endif
    double mul_time = std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << "Time take for matmul2 is "<< mul_time << " ms" << std::endl;

    return 0;
}