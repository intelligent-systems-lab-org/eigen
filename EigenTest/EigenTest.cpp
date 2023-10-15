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
	};
}
