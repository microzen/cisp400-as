#include "Matrices.h"

namespace Matrices {

    Matrix::Matrix(int _rows, int _cols) {
        this->rows = _rows;
        this->cols = _cols;
        this->a.resize(this->getRows(), vector<double>(this->getCols(), 0));
    }

    ///Add each corresponding element.
    ///usage:  c = a + b;
    Matrix operator+(const Matrix &a, const Matrix &b) {

        if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
            throw runtime_error("Error: dimensions must agree");
        }
        Matrix matrix(a.getRows(), a.getCols());

        for (int i = 0; i < matrix.getRows(); ++i) {
            for (int j = 0; j < matrix.getCols(); ++j) {
                matrix(i, j) = a(i, j) + b(i, j);
            }
        }
        return matrix;
    }

    ///Matrix multiply.  See description.
    ///usage:  c = a * b;
    Matrix operator*(const Matrix &a, const Matrix &b) {
        int ar = a.getRows();
        int ac = a.getCols();
        int br = b.getRows();
        int bc = b.getCols();

        if (ac != br) {
            throw runtime_error("Error: dimensions must agree");
        }

        Matrices::Matrix c(ar, bc);
        for (int i = 0; i < ar; i++) {
            for (int k = 0; k < bc; ++k) {
                double sum = 0;
                for (int j = 0; j < ac; ++j) {
                    sum += a(i, j) * b(j, k);
                }
                c(i, k) = sum;
            }
        }
        return c;
    }
    ///Matrix comparison.  See description.
    ///usage:  a == b
    bool operator==(const Matrix& a, const Matrix& b){
        if(a.getRows() != b.getRows() || a.getCols() != b.getCols())
            return false;
        for (int i = 0; i < a.getRows(); ++i) {
            for (int j = 0; j < a.getCols(); ++j) {
                if(fabs( a(i,j) - b(i,j)) > 0.00001)return false;
            }
        }
        return true;
    }

    ///Matrix comparison.  See description.
    ///usage:  a != b
    bool operator!=(const Matrix& a, const Matrix& b){
        return !(a==b);
//        if(a.getRows() != b.getRows() || a.getCols() != b.getCols())
//            return true;
//        for (int i = 0; i < a.getRows(); ++i) {
//            for (int j = 0; j < a.getCols(); ++j) {
//                if(fabs( a(i,j) - b(i,j)) > 0.00001)return true;
//            }
//        }
//        return false;
    }

    ///Output matrix.
    ///Separate columns by ' ' and rows by '\n'
    ostream& operator<<(ostream& os, const Matrix& a){
        for (int i = 0; i < a.getRows(); ++i) {
            for (int j = 0; j < a.getCols(); ++j) {
                os << setw(10) << a(i,j) << " ";
            }
            if(i < a.getRows()-1)
                os << endl;
        }
        return os;
    }

}
