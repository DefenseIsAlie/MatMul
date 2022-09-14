#include <iostream>
#include <sstream>
#include <chrono>
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
        dim = diminput::_argv_input(argv,1);
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

    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    kij::_matmul(dim, A, B, C);
    std::cout << C[5][5] << "\n";
    std::cout << C[6][6] << "\n";
    std::cout << C[10][10] << "\n";
    std::cout << C[17][17] << "\n";
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

    double mul_time = std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << "Time take for matmul2 is "<< mul_time << " ms" << std::endl;

    return 0;
}