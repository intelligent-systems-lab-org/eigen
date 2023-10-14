#pragma once
extern "C"
{
    // Functions to create, delete and manipulate matrices.
    void* CreateMatrix(int rows, int cols, double* data);
    void DeleteMatrix(void* matrixPtr);
    void MultiplyMatrices(void* matrix1, void* matrix2, double* result);
}