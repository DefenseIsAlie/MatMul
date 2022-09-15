#include "../inc/ijkmul.hpp"


double** ijk::_create_matrix(int dim){
    double** mat = new double*[dim];

    for (int i = 0; i < dim; i++)
    {
        mat[i] = new double[dim];
    }

    return mat;
}

void ijk::_initialize_matrix(int dim, double** &mat){

    for(int i = 0; i<dim; i++){
        
        for (int j =0; j<dim; j++){

            mat[i][j] = 1;

        }

    }

}


void ijk::_matmul(int dim, double* &A, double* &B, double* &C){

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            for (int k = 0; k < dim; k++)
            {
                C[i*dim + j] += A[i*dim + k] * B[j*dim + k];
            }
               
        }
    }
}