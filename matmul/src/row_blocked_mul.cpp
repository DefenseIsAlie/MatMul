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

            mat[i][j] = i+j+1;

        }

    }

}


void row_block::_matmul(int dim,int block_size, double** &A, double** &B, double** &C){     

    for (int i = 0; i < dim; i+=block_size){

        for (int block = 0; block < block_size; block++){
        // i+block gives the row we are working on

            for (int j = 0; j < dim; j++)
            {
                // Cij += RAi * CBj
                double dotprod = 0.;

                for (int o = 0; o < dim; o++)
                {
                    dotprod += A[i+block][o]*B[o][j];
                    
                }

                C[i+block][j] += dotprod;
            }

        }

    }

}