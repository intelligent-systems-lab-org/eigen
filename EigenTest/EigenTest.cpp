#include "pch.h"
#include "CppUnitTest.h"
#include "../EigenWrapper/EigenWrapper.h"
#include <Eigen/Core>

using namespace Eigen;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EigenTest
{
	TEST_CLASS(EigenTest)
	{
	public:
		
        TEST_METHOD(Test2DArrayConstructor)
        {
            // Setup
            int rows = 2;
            int cols = 2;
            float* arr1 = new float[2] { 1, 2 };
            float* arr2 = new float[2] { 3, 4 };
            float** data = new float* [2] { arr1, arr2 };

            // Act
            void* matrixPtr = CreateMatrix(rows, cols, data);
            MatrixXf* matrix = static_cast<MatrixXf*>(matrixPtr);

            // Assert
            Assert::AreEqual(1.0f, (*matrix)(0, 0));
            Assert::AreEqual(2.0f, (*matrix)(0, 1));
            Assert::AreEqual(3.0f, (*matrix)(1, 0));
            Assert::AreEqual(4.0f, (*matrix)(1, 1));

            // Cleanup
            delete matrix;
            delete[] arr1;
            delete[] arr2;
            delete[] data;
        }
	};
}
