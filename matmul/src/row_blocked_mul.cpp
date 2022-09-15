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


void row_block::_matmul(int dim,int block_size, double* &a, double* &b, double* &c){ 

for(int blk = 0; blk < block_size; blk++){

    for (int element = 0; element < dim; element++){

      for(int blk_row = 0; blk_row < dim/block_size; blk_row++){
        
        for(int col = 0; col < dim; col++){

          int blocked_index_row = blk*(dim/block_size)*dim + blk_row*dim + col;
          int blocked_index_col = blk_row + element*dim + blk*(dim/block_size);
          c[blocked_index_row] = c[blocked_index_row] + a[blocked_index_col] * b[(element*dim) + col];
        }
      }
    }
  }
}