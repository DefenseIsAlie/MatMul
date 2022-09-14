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

inline double row_block::_saxpy(int dim, double &a, double* &X){

    double ret = 0.;

    for (int j = 0; j < dim; j++)
    {
        ret+= a * X[j];
    }

    return ret;
}

void row_block::_matmul(int dim, double** &A, double** &B, double** &C){

    for (int i = 0; i < dim; i++){
        double *Ci = C[i];
        double *Ai = A[i];
        for (int k = 0; k < dim; k++)
        {   
            Ci[k] += row_block::_saxpy(dim, Ai[k], B[k]);
        }
    }
}