#include "EigenWrapper.h"
#include <Eigen/Core>

using namespace Eigen;

extern "C" {
    DLLExport void* CreateMatrix(int rows, int cols, float* data, bool rowMajor = false)
    {
        if (rowMajor)
        {
            auto tempMat = Map<Matrix<float, Dynamic, Dynamic, RowMajor>>(data, rows, cols);
            MatrixXf* mat = new MatrixXf(tempMat);
            return mat;
        }
        else
        {
            MatrixXf* mat = new MatrixXf(rows, cols);
            std::memcpy(mat->data(), data, sizeof(float) * rows * cols);
            return mat;
        }
    }


    DLLExport void DeleteMatrix(void* matrixPtr)
    {
        delete static_cast<MatrixXf*>(matrixPtr);
    }

    DLLExport void MultiplyMatrices(void* matrix1, void* matrix2, float* result)
    {
        MatrixXf& mat1 = *static_cast<MatrixXf*>(matrix1);
        MatrixXf& mat2 = *static_cast<MatrixXf*>(matrix2);

        MatrixXf resultMat = mat1 * mat2;
        std::memcpy(result, resultMat.data(), sizeof(float) * resultMat.rows() * resultMat.cols());
    }

    DLLExport int GetRowCount(void* matrixPtr) {
        MatrixXf* mat = static_cast<MatrixXf*>(matrixPtr);
        return mat->rows();
    }

    DLLExport int GetColumnCount(void* matrixPtr) {
        MatrixXf* mat = static_cast<MatrixXf*>(matrixPtr);
        return mat->cols();
    }

    DLLExport float GetElement(void* matrixPtr, int row, int col) {
        MatrixXf* mat = static_cast<MatrixXf*>(matrixPtr);
        return (*mat)(row, col);
    }

    DLLExport void SetElement(void* matrixPtr, int row, int col, float newEntry) {
        MatrixXf* mat = static_cast<MatrixXf*>(matrixPtr);
        (*mat)(row, col) = newEntry;
    }

    DLLExport void Transpose(void* matrixPtr, float* result) {
        MatrixXf* mat = static_cast<MatrixXf*>(matrixPtr);
        MatrixXf transposedMat = mat->transpose();
        std::memcpy(result, transposedMat.data(), sizeof(float) * transposedMat.rows() * transposedMat.cols());
    }

    DLLExport void TransposeInPlace(void* matrixPtr) {
        MatrixXf* mat = static_cast<MatrixXf*>(matrixPtr);
        mat->transposeInPlace();
    }
}