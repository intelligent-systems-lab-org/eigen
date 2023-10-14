#include "EigenWrapper.h"
#include <Eigen/Dense>

extern "C" {
    DLLExport void* CreateMatrix(int rows, int cols, float* data)
    {
        Eigen::MatrixXf* mat = new Eigen::MatrixXf(rows, cols);
        std::memcpy(mat->data(), data, sizeof(float) * rows * cols);
        return mat;
    }

    DLLExport void DeleteMatrix(void* matrixPtr)
    {
        delete static_cast<Eigen::MatrixXf*>(matrixPtr);
    }

    DLLExport void MultiplyMatrices(void* matrix1, void* matrix2, float* result)
    {
        Eigen::MatrixXf& mat1 = *static_cast<Eigen::MatrixXf*>(matrix1);
        Eigen::MatrixXf& mat2 = *static_cast<Eigen::MatrixXf*>(matrix2);

        Eigen::MatrixXf resultMat = mat1 * mat2;
        std::memcpy(result, resultMat.data(), sizeof(float) * resultMat.rows() * resultMat.cols());
    }

    DLLExport int GetRowCount(void* matrixPtr) {
        Eigen::MatrixXf* mat = static_cast<Eigen::MatrixXf*>(matrixPtr);
        return mat->rows();
    }

    DLLExport int GetColumnCount(void* matrixPtr) {
        Eigen::MatrixXf* mat = static_cast<Eigen::MatrixXf*>(matrixPtr);
        return mat->cols();
    }

    DLLExport float GetElement(void* matrixPtr, int row, int col) {
        Eigen::MatrixXf* mat = static_cast<Eigen::MatrixXf*>(matrixPtr);
        return (*mat)(row, col);
    }
}