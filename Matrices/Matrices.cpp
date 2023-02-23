#include "Matrices.h"

namespace Matrices {
    Matrix::Matrix(int _rows, int _cols) {
        this->rows = _rows;
        this->cols = _cols;
        this->a.resize(this->getRows(), vector<double>(this->getCols(), 0));
    }

    Matrix operator*(const Matrix &a, const Matrix &b);

    Matrix operator*(const Matrix &a, const Matrix &b) {
        int ar = a.getRows();
        int ac = a.getCols();
        int br = b.getRows();
        int bc = b.getCols();

        if (ac != br) {
            throw runtime_error("Error: dimensions must agree");
        }

        for (int i = 0; i < ac; i++) {

        }
    }

}
