#include "EigenWrapper.h"
#include <Eigen/Dense>

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

    DLLExport void AddMatrices(void* matrix1, void* matrix2, float* result) 
    {
        MatrixXf& mat1 = *static_cast<MatrixXf*>(matrix1);
        MatrixXf& mat2 = *static_cast<MatrixXf*>(matrix2);

        MatrixXf resultMat = mat1 + mat2;
        std::memcpy(result, resultMat.data(), sizeof(float) * resultMat.rows() * resultMat.cols());
    }

    DLLExport void SubtractMatrices(void* matrix1, void* matrix2, float* result)
    {
        MatrixXf& mat1 = *static_cast<MatrixXf*>(matrix1);
        MatrixXf& mat2 = *static_cast<MatrixXf*>(matrix2);

        MatrixXf resultMat = mat1 - mat2;
        std::memcpy(result, resultMat.data(), sizeof(float) * resultMat.rows() * resultMat.cols());
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

    DLLExport void* CreateIdentityMatrix(int size)
    {
        MatrixXf* identity = new MatrixXf(MatrixXf::Identity(size, size));
        return static_cast<void*>(identity);
    }

    DLLExport bool AreMatricesEqual(void* matrix1, void* matrix2)
    {
        MatrixXf& mat1 = *static_cast<MatrixXf*>(matrix1);
        MatrixXf& mat2 = *static_cast<MatrixXf*>(matrix2);

        return mat1.isApprox(mat2);
    }

    DLLExport float GetDeterminant(void* matrixPtr)
    {
        MatrixXf& mat = *static_cast<MatrixXf*>(matrixPtr);
        return mat.determinant();
    }


    DLLExport void GetInverse(void* matrix, float* result)
    {
        MatrixXf& mat = *static_cast<MatrixXf*>(matrix);
        MatrixXf inversedMat = mat.inverse();

        std::memcpy(result, inversedMat.data(), sizeof(float) * inversedMat.rows() * inversedMat.cols());
    }

    DLLExport void MultiplyByScalar(void* matrixPtr, float scalar, float* result)
    {
        MatrixXf& mat = *static_cast<MatrixXf*>(matrixPtr);
        MatrixXf multipliedMat = mat * scalar;
        std::memcpy(result, multipliedMat.data(), sizeof(float) * multipliedMat.rows() * multipliedMat.cols());
    }

    DLLExport void* CreateDiagonalMatrix(float* diagonalEntries, int size)
    {
        // Create a vector from the diagonal entries
        VectorXf diagonalVector = Map<VectorXf>(diagonalEntries, size);

        // Use Eigen's built-in function to create a diagonal matrix
        MatrixXf* diagMatrix = new MatrixXf(diagonalVector.asDiagonal());

        return diagMatrix;
    }

}