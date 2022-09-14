#include <iostream>
#include <sstream>
#include <chrono>
#include "../inc/input.hpp"
#include "../inc/row_blocked_mul.hpp"

int main(int argc, char* argv[]){
    int dim;

	int blk_size;

    if (argc!=3){
        dim = diminput::_commandline_input();
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

	if (argc!=3){
        blk_size = diminput::_commandline_input();
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

	row_block::_matmul(dim, blk_size, A, B, C);
	std::cout << C[5][5] << "\n";
    std::cout << C[6][6] << "\n";
    std::cout << C[10][10] << "\n";
    std::cout << C[17][17] << "\n";

    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

    double mul_time = std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "Time take for matmul3 is "<< mul_time << " ms" << std::endl;
    return 0;
}