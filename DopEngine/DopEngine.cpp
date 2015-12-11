#include "Math\3DVec.h"
#include "Math\3X3Mat.h"
#include <Windows.h>
#include <iostream>
#include <sstream>

#define DOP_DEBUG( s )            \
{                             \
	std::ostringstream os_;    \
	os_ << s;                   \
	os_ << "\n";						 \
	OutputDebugString(os_.str().c_str());  \
}


int main()
{
	DOP_DEBUG("TEST")
	//M3X3Mat mat1 = M3X3Mat(1, 2, 3, 4, 5, 6, 7, 8, 9);
	//M3X3Mat mat2 = M3X3Mat(2, 2, 2, 2, 2, 2, 2, 2, 9);
	//double x = 1.0;
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		if (mat1[i][j] != x)
	//		{
	//			DOP_DEBUG("NOT EQUALS : got " );
	//			DOP_DEBUG(mat1[i][j]);
	//			DOP_DEBUG(" Expected : ");
	//			DOP_DEBUG(x);
	//			
	//		}
	//		x += 1;
	//	}
	//}

	M3X3Mat mat1 = M3X3Mat(1, 2, 3, 4, 5, 6, 7, 8, 9);
	M3X3Mat mat2 = mat1 * mat1;
	double expectedValue = 1.0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			DOP_DEBUG("---- \n m" << i << j);
			DOP_DEBUG(mat2[i][j]);
			//DOP_DEBUG("Expected : " << x);
			DOP_DEBUG("----");
						
			//Assert::AreEqual(mat1[i][j], expectedValue * 2);
			//expectedValue += 1.0;
		}
	}
		return 0;
}
