#include "pch.h"
#include "EigenWrapper.h"
#include <Eigen/Dense>

void* CreateMatrix(int rows, int cols, float* data)
{
    Eigen::MatrixXf* mat = new Eigen::MatrixXf(rows, cols);
    std::memcpy(mat->data(), data, sizeof(float) * rows * cols);
    return mat;
}

void DeleteMatrix(void* matrixPtr)
{
    delete static_cast<Eigen::MatrixXf*>(matrixPtr);
}

void MultiplyMatrices(void* matrix1, void* matrix2, float* result)
{
    Eigen::MatrixXf& mat1 = *static_cast<Eigen::MatrixXf*>(matrix1);
    Eigen::MatrixXf& mat2 = *static_cast<Eigen::MatrixXf*>(matrix2);

    Eigen::MatrixXf resultMat = mat1 * mat2;
    std::memcpy(result, resultMat.data(), sizeof(float) * resultMat.rows() * resultMat.cols());
}
