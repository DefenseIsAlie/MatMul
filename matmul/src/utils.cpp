#include "utils.hpp"

double * to_1d(double ** mat, int dim, int row_major){
    double * mat_1d = new double[dim*dim];
    if (row_major){
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                mat_1d[i*dim + j] = mat[i][j];
            }
        }
    }
    else{
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                mat_1d[j*dim + i] = mat[i][j];
            }
        }
    }
    return mat_1d;
}

double ** to_2d(double * mat, int dim, int row_major){
    double ** mat_2d = new double*[dim];
    for (int i = 0; i < dim; i++)
    {
        mat_2d[i] = new double[dim];
    }
    if (row_major){
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                mat_2d[i][j] = mat[i*dim + j];
            }
        }
    }
    else{
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                mat_2d[i][j] = mat[j*dim + i];
            }
        }
    }
    return mat_2d;
}