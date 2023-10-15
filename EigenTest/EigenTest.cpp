#include "pch.h"
#include "CppUnitTest.h"
#include "../EigenWrapper/EigenWrapper.h"
#include <Eigen/Core>

using namespace Eigen;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EigenTest
{
	TEST_CLASS(EigenTestWrapper)
	{
	public:
        TEST_METHOD(TestCreateMatrixRowMajor)
        {
            // Arrange
            int rows = 2;
            int cols = 2;
            float data[] = { 1, 2, 3, 4 };

            // Act
            MatrixXf* matrix = (MatrixXf*)CreateMatrix(rows, cols, data, true);

            // Assert
            Assert::AreEqual(1.0f, (*matrix)(0, 0));
            Assert::AreEqual(2.0f, (*matrix)(0, 1));
            Assert::AreEqual(3.0f, (*matrix)(1, 0));
            Assert::AreEqual(4.0f, (*matrix)(1, 1));

            // Cleanup
            delete matrix;
        }

        TEST_METHOD(TestCreateMatrixColMajor)
        {
            // Arrange
            int rows = 2;
            int cols = 2;
            float data[] = { 1, 2, 3, 4};

            // Act
            MatrixXf* matrix = (MatrixXf*)CreateMatrix(rows, cols, data, false);

            // Assert
            Assert::AreEqual(1.0f, (*matrix)(0, 0));
            Assert::AreEqual(2.0f, (*matrix)(1, 0));
            Assert::AreEqual(3.0f, (*matrix)(0, 1));
            Assert::AreEqual(4.0f, (*matrix)(1, 1));

            // Cleanup
            delete matrix;
        }

        TEST_METHOD(TestCreateIdentityMatrix)
        {
            // Arrange
            int size = 3;

            // Act
            MatrixXf* identityMatrix = (MatrixXf*)CreateIdentityMatrix(size);

            // Assert
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i == j)
                        Assert::AreEqual(1.0f, (*identityMatrix)(i, j));
                    else
                        Assert::AreEqual(0.0f, (*identityMatrix)(i, j));
                }
            }

            // Cleanup
            delete identityMatrix;
        }

        TEST_METHOD(TestAreMatricesEqual)
        {
            // Arrange
            float data1[] = { 1, 2, 3, 4 };
            float data2[] = { 1, 2, 3, 4 };
            float data3[] = { 1, 2, 3, 5 };

            MatrixXf* matrix1 = (MatrixXf*)CreateMatrix(2, 2, data1, false);
            MatrixXf* matrix2 = (MatrixXf*)CreateMatrix(2, 2, data2, false);
            MatrixXf* matrix3 = (MatrixXf*)CreateMatrix(2, 2, data3, false);

            // Act & Assert
            // should be true
            Assert::IsTrue(AreMatricesEqual(matrix1, matrix2));
            // should be false
            Assert::IsFalse(AreMatricesEqual(matrix1, matrix3));

            // Cleanup
            delete matrix1;
            delete matrix2;
            delete matrix3;
        }

        TEST_METHOD(TestGetInverse)
        {
            // Arrange
            int rows = 2;
            int cols = 2;
            float data[] = { 1, 2, 3, 4 };
            MatrixXf* matrix = (MatrixXf*)CreateMatrix(rows, cols, data, true);
            float result[4];

            // Act
            GetInverse(matrix, result);

            // Assert
            float tol = 1e-5f;
            Assert::AreEqual(-2.0f, result[0], tol);
            Assert::AreEqual(1.5f, result[1], tol);
            Assert::AreEqual(1.0f, result[2], tol);
            Assert::AreEqual(-0.5f, result[3], tol);

            // Cleanup
            delete matrix;
        }
	};
}
