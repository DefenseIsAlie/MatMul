#include "../inc/kijmul.hpp"


double** kij::_create_matrix(int dim){
    double** mat = new double*[dim];

    for (int i = 0; i < dim; i++)
    {
        mat[i] = new double[dim];
    }

    return mat;
}

void kij::_initialize_matrix(int dim, double** &mat){

    for(int i = 0; i<dim; i++){
        
        for (int j =0; j<dim; j++){

            mat[i][j] = i+j+1;

        }

    }

}


void kij::_matmul(int dim, double** &A, double** &B, double** &C){

    for (int k = 0; k < dim; k++)
    {
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
               
        }
    }
}