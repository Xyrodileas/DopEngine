#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DopEngine/Math/3DVec.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DopEngineTest
{		
	TEST_CLASS(M3VecTest)
	{
	public:
		
		TEST_METHOD(M3DVecTestDotP)
		{
			M3DVec vec1 = M3DVec(0, 1, 0);
			M3DVec vec2 = M3DVec(0, 0, 1);
			double x = vec1.DotP(vec2);
			Assert::AreEqual(x, 0.0); 
		}
		TEST_METHOD(M3DVecTestCrossP)
		{
			M3DVec vec1 = M3DVec(0, 1, 0);
			M3DVec vec2 = M3DVec(0, 0, 1);
			
			// Result of vec1xvec2
			M3DVec result = M3DVec(1, 0, 0);

			M3DVec x = vec1.CrossP(vec2);

			Assert::IsTrue(x == result); 
		}
		TEST_METHOD(M3DVecTestProjOnto)
		{
			M3DVec vec1 = M3DVec(0, 1, 0);
			M3DVec vec2 = M3DVec(0, 0, 1);
			M3DVec result = M3DVec(0, 0, 0);
			M3DVec x = vec1.ProjOnto(vec2);
			Assert::IsTrue(result == x); 
		}

		TEST_METHOD(M3DVecTestPerpOnto)
		{
			M3DVec vec1 = M3DVec(0, 1, 0);
			M3DVec vec2 = M3DVec(0, 0, 1);
			M3DVec result = M3DVec(0, 1, 0);
			M3DVec x = vec1.PerpOnto(vec2);
			//Assert::AreEqual(1.0, x.Y);
			Assert::IsTrue(result == x); 
		}

		TEST_METHOD(M3DVecTestAddSubb)
		{
			M3DVec vec1 = M3DVec(0, 1, 0);
			M3DVec vec2 = M3DVec(0, 0, 1);
			M3DVec result = M3DVec(0, 1, 1);
			
			M3DVec x = vec1 + vec2;

			Assert::IsTrue(result == x); 

			result = M3DVec(0, 1, -1);

			x = vec1 - vec2;

			Assert::IsTrue(result == x);

		}

		TEST_METHOD(M3DVecTestMulByScalar)
		{
			M3DVec vec1 = M3DVec(1, 1, 1);

			M3DVec result = M3DVec(8, 8, 8);

			M3DVec x = vec1 * 8;

			Assert::IsTrue(result == x);

			x = x / 8;

			Assert::IsTrue(vec1 == x);

		}

	};
}