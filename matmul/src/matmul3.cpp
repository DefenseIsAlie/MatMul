#include <iostream>
#include <sstream>
#include <ctime>
#include "../inc/input.hpp"
#include "../inc/row_blocked_mul.hpp"

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

    double** A = row_block::_create_matrix(dim);
    double** B = row_block::_create_matrix(dim);
    double** C = row_block::_create_matrix(dim);
    
    row_block::_initialize_matrix(dim, A);
    row_block::_initialize_matrix(dim, B);


    time_t start = time(NULL);
    row_block::_matmul(dim, A, B, C);
    time_t end   = time(NULL);

    std::cout << "Time taken is: " << end - start << " seconds" << std::endl;  

    return 0;
}