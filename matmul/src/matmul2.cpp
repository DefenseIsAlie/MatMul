#include <iostream>
#include <sstream>
#include <ctime>
#include "../inc/input.hpp"
#include "../inc/kijmul.hpp"

int main(int argc, char* argv[]){
    int dim;

    if (argc!=2){
        dim = diminput::_commandline_input();
        if (dim != INPUT_ERROR && dim){
            std::cout << dim << std::endl;
        }else{
            std::cout << "Input error wrong base or incorrect input" << std::endl;
        }
    } else {
        dim = diminput::_argv_input(argv);
        if (dim != INPUT_ERROR && dim){
            std::cout << dim << std::endl;
        }else{
            std::cout << "Input error wrong base or incorrect input" << std::endl;
        }
    }
    
    double** A = kij::_create_matrix(dim);
    double** B = kij::_create_matrix(dim);
    double** C = kij::_create_matrix(dim);
    
    kij::_initialize_matrix(dim, A);
    kij::_initialize_matrix(dim, B);

    time_t start = time(NULL);
    kij::_matmul(dim, A, B, C);
    time_t end   = time(NULL);

    std::cout << "Time taken is: " << end - start << " seconds" << std::endl;
    return 0;
}