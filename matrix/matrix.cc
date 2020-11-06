#include "matrix.h"

Matrix &Matrix::operator=(const Matrix &rhs)
{
    if (this != &rhs)
    {
        col_ = rhs.col();
        row_ = rhs.row();

        int elem_cnt = col_ * row_;
        delete[] pmat_;
        pmat_ = new double[elem_cnt];
        for (int i = 0; i < elem_cnt; i++)
        {
            pmat_[i] = rhs.pmat_[i];
        }
    }
    return *this;
}