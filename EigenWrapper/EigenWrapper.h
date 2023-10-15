#ifndef EIGENWRAPPER_H
#define EIGENWRAPPER_H
#define DLLExport   __declspec(dllexport)

extern "C"
{
    // Functions to create, delete and manipulate matrices.
    DLLExport void* CreateMatrix(int rows, int cols, float* data, bool rowMajor);
    DLLExport void DeleteMatrix(void* matrixPtr);
    DLLExport void AddMatrices(void* matrix1, void* matrix2, float* result);
    DLLExport void SubtractMatrices(void* matrix1, void* matrix2, float* result);
    DLLExport void MultiplyMatrices(void* matrix1, void* matrix2, float* result);
    DLLExport int GetRowCount(void* matrixPtr);
    DLLExport int GetColumnCount(void* matrixPtr);
    DLLExport float GetElement(void* matrixPtr, int row, int col);
    DLLExport void SetElement(void* matrixPtr, int row, int col, float newEntry);
    DLLExport void Transpose(void* matrixPtr, float* result);
    DLLExport void TransposeInPlace(void* matrixPtr);
    DLLExport void* CreateIdentityMatrix(int size);
    DLLExport bool AreMatricesEqual(void* matrix1, void* matrix2);
    DLLExport void GetInverse(void* matrix, float* result);
}

#endif // !EIGENWRAPPER_H