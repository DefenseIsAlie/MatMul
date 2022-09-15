#include "../inc/row_blocked_mul.hpp"


double** row_block::_create_matrix(int dim){
    double** mat = new double*[dim];

    for (int i = 0; i < dim; i++)
    {
        mat[i] = new double[dim];
    }

    return mat;
}

void row_block::_initialize_matrix(int dim, double** &mat){

    for(int i = 0; i<dim; i++){
        
        for (int j =0; j<dim; j++){

            mat[i][j] = 1;

        }

    }

}


void row_block::_matmul(int dim,int block_size, double** &A, double** &B, double** &C){     

    for (int block = 0; block < dim; block+=block_size){

        // Read Ci and Ai into fast memory

        for (int  element = 0; element < dim; element++){

            for (int block_row = 0; block_row < block_size; block_row++){

                for (int dot = 0; dot < dim; dot++){

                    C[block+block_row][element] += A[block+block_row][element] * B[dot][element];
                }

                
            }
            
        }
    
    }

}