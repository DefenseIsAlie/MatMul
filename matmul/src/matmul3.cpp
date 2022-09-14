#include <iostream>
#include <sstream>
#include <chrono>
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


    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    row_block::_matmul(dim, A, B, C);
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

    double mul_time = std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "Time take for matmul3 is "<< mul_time << " ms" << std::endl;
    return 0;
}