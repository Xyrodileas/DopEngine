#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DopEngine/Math/Mat.h"
#include "../DopEngine/Math/_RowMat.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DopEngineTest
{
	TEST_CLASS(MatTest)
	{
	public:

		TEST_METHOD(MatTestConstructor)
		{
			int nSize = 3;
			int mSize = 3;
			Mat mat1 = Mat(nSize, mSize, std::vector<double>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
			Mat mat2 = mat1;
			double expectedValue = 1.0;
			for (int i = 0; i < nSize; i++)
			{
				for (int j = 0; j < mSize; j++)
				{
					// TEST Constructor
					Assert::AreEqual(expectedValue, mat1[i][j]);
					// TEST Copy Constructor
					Assert::AreEqual(expectedValue, mat2[i][j]);
					expectedValue += 1.0;
				}
			}

		}

		TEST_METHOD(MatTestAdd)
		{
			int nSize = 3;
			int mSize = 3;
			Mat mat1 = Mat(nSize, mSize, std::vector<double>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
			Mat mat2 = mat1 + mat1;
			mat1 = mat1 + 2.0;


			double expectedValue = 1.0;
			for (int i = 0; i < nSize; i++)
			{
				for (int j = 0; j < mSize; j++)
				{
					// TEST Add Scalar to Matrix
					Assert::AreEqual(expectedValue + 2, mat1[i][j]);
					// TEST Add Matrix to Matrix
					Assert::AreEqual(expectedValue + expectedValue, mat2[i][j]);
					expectedValue += 1.0;
				}
			}
		}

		TEST_METHOD(MatTestSubb)
		{
			int nSize = 3;
			int mSize = 3;
			Mat mat1 = Mat(nSize, mSize, std::vector<double>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
			Mat mat2 = mat1 - mat1;
			mat1 = mat1 - 2.0;


			double expectedValue = 1.0;
			for (int i = 0; i < nSize; i++)
			{
				for (int j = 0; j < mSize; j++)
				{
					// TEST Add Scalar to Matrix
					Assert::AreEqual(expectedValue - 2, mat1[i][j]);
					// TEST Add Matrix to Matrix
					Assert::AreEqual(0.0, mat2[i][j]);
					expectedValue += 1.0;
				}
			}
		}

		TEST_METHOD(MatTestMultiplyByScalar)
		{
			int nSize = 3;
			int mSize = 3;
			Mat mat1 = Mat(nSize, mSize, std::vector<double>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
			mat1 = mat1 * 2;
			double expectedValue = 1.0;
			for (int i = 0; i < nSize; i++)
			{
				for (int j = 0; j < mSize; j++)
				{
					Assert::AreEqual(expectedValue * 2, mat1[i][j]);
					expectedValue += 1.0;
				}
			}

		}

		TEST_METHOD(MatTestMultiplyByMatrix)
		{
			int nSize = 3;
			int mSize = 3;
			Mat mat1 = Mat(nSize, mSize, std::vector<double>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
			double expectedResults[9] = { 30, 36, 42, 66, 81, 96, 102, 126, 150 };
			mat1 = mat1 * mat1;
			int comptr = 0;
			for (int i = 0; i < nSize; i++)
			{
				for (int j = 0; j < mSize; j++)
				{
					Assert::AreEqual(expectedResults[comptr], mat1[i][j]);
					comptr++;
				}
			}
		}

		TEST_METHOD(MatTestDivideByScalar)
		{
			int nSize = 3;
			int mSize = 3;
			Mat mat1 = Mat(nSize, mSize, std::vector<double>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
			mat1 = mat1 / 2;
			double expectedValue = 1.0;
			for (int i = 0; i < nSize; i++)
			{
				for (int j = 0; j < mSize; j++)
				{
					Assert::AreEqual(expectedValue / 2, mat1[i][j]);
					expectedValue += 1.0;
				}
			}
		}

		TEST_METHOD(MatTestExchangeRows)
		{
			int nSize = 3;
			int mSize = 3;
			Mat mat1 = Mat(nSize, mSize, std::vector<double>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
			mat1.ExchangeRows(0, 2);
			mat1.ExchangeRows(1, 0);

			double expectedResults[9] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
			int comptr = 0;
			for (int i = 0; i < nSize; i++)
			{
				for (int j = 0; j < mSize; j++)
				{
					Assert::AreEqual(expectedResults[comptr], mat1[i][j]);
					comptr++;
				}
			}
		}

		TEST_METHOD(MatTestAddRowToAnother)
		{
			int nSize = 3;
			int mSize = 3;
			Mat mat1 = Mat(nSize, mSize, std::vector<double>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
			mat1.AddRowToAnother(0, 2, 3);
			mat1.AddRowToAnother(2, 2, -1);

			double expectedResults[9] = { 22, 26, 30, 4, 5, 6, 0, 0, 0 };
			int comptr = 0;
			for (int i = 0; i < nSize; i++)
			{
				for (int j = 0; j < mSize; j++)
				{
					Assert::AreEqual(expectedResults[comptr], mat1[i][j]);
					comptr++;
				}
			}
		}

		TEST_METHOD(MatTestReducedForm)
		{
			int nSize = 3;
			int mSize = 4;
			Mat mat1 = Mat(nSize, mSize, std::vector<double>{ 3, 2, -3, -13, 4, -3, 6, 7, 1, 0, -1, -5});
			mat1.ReduceForm();

			double expectedResults[12] = { 1,0,0,-2,0,1,0,1,0,0,1,3 };
			int comptr = 0;
			for (int i = 0; i < nSize; i++)
			{
				for (int j = 0; j < mSize; j++)
				{
					Assert::AreEqual(expectedResults[comptr], mat1[i][j]);
					comptr++;
				}
			}
		}
	};
}