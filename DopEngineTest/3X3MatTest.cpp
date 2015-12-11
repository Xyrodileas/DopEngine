#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DopEngine/Math/3X3Mat.h"
#include "../DopEngine/Math/_3X3RowMat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DopEngineTest
{
	TEST_CLASS(M3X3MatTest)
	{
	public:

		TEST_METHOD(M3X3MatTestConstructor)
		{
			M3X3Mat mat1 = M3X3Mat(1, 2, 3, 4, 5, 6, 7, 8, 9);
			M3X3Mat mat2 = mat1;
			double expectedValue = 1.0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					// TEST Constructor
					Assert::AreEqual(expectedValue, mat1[i][j]);
					// TEST Copy Constructor
					Assert::AreEqual(expectedValue, mat2[i][j]);
					expectedValue += 1.0;
				}
			}
			
		}

		TEST_METHOD(M3X3MatTestAdd)
		{
			M3X3Mat mat1 = M3X3Mat(1, 2, 3, 4, 5, 6, 7, 8, 9);
			M3X3Mat mat2 = mat1 + mat1;
			mat1 = mat1 + 2.0;

			
			double expectedValue = 1.0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					// TEST Add Scalar to Matrix
					Assert::AreEqual(expectedValue + 2, mat1[i][j]);
					// TEST Add Matrix to Matrix
					Assert::AreEqual(expectedValue + expectedValue, mat2[i][j]);
					expectedValue += 1.0;
				}
			}
		}

		TEST_METHOD(M3X3MatTestSubb)
		{
			M3X3Mat mat1 = M3X3Mat(1, 2, 3, 4, 5, 6, 7, 8, 9);
			M3X3Mat mat2 = mat1 - mat1;
			mat1 = mat1 - 2.0;

			
			double expectedValue = 1.0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					// TEST Add Scalar to Matrix
					Assert::AreEqual(expectedValue - 2, mat1[i][j]);
					// TEST Add Matrix to Matrix
					Assert::AreEqual(0.0, mat2[i][j]);
					expectedValue += 1.0;
				}
			}
		}

		TEST_METHOD(M3X3MatTestMultiplyByScalar)
		{
			M3X3Mat mat1 = M3X3Mat(1, 2, 3, 4, 5, 6, 7, 8, 9);
			mat1 = mat1 * 2;
			double expectedValue = 1.0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Assert::AreEqual(expectedValue * 2, mat1[i][j]);
					expectedValue += 1.0;
				}
			}

		}

		TEST_METHOD(M3X3MatTestMultiplyBy3X3Matrix)
		{
			M3X3Mat mat1 = M3X3Mat(1, 2, 3, 4, 5, 6, 7, 8, 9);
			double expectedResults[9] = { 30, 36, 42, 66, 81, 96, 102, 126, 150 };
			mat1 = mat1 * mat1;
			int comptr = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Assert::AreEqual(expectedResults[comptr], mat1[i][j]);
					comptr++;
				}
			}
		}
		TEST_METHOD(M3X3MatTestMultiplyBy3X3Matrix)
		{
			M3X3Mat mat1 = M3X3Mat(1, 2, 3, 4, 5, 6, 7, 8, 9);
			double expectedResults[9] = { 30, 36, 42, 66, 81, 96, 102, 126, 150 };
			mat1 = mat1 * mat1;
			int comptr = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Assert::AreEqual(expectedResults[comptr], mat1[i][j]);
					comptr++;
				}
			}
		}

		TEST_METHOD(M3X3MatTestDivideByScalar)
		{
			M3X3Mat mat1 = M3X3Mat(1, 2, 3, 4, 5, 6, 7, 8, 9);
			mat1 = mat1 / 2;
			double expectedValue = 1.0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Assert::AreEqual(expectedValue / 2, mat1[i][j]);
					expectedValue += 1.0;
				}
			}
		}
	};
}