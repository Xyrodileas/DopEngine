#include "_3X3RowMat.h"

_3X3RowMat::_3X3RowMat()
{
	for (int x = 0; x < rows; x++)
	{
		Col[x] = double();
	}
}

_3X3RowMat::~_3X3RowMat()
{

}