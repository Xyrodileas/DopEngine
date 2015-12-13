#include "_3X3RowMat.h"

#include <cstdlib>
#include <cstring>

_3X3RowMat::_3X3RowMat()
{
	for (int x = 0; x < rows; x++)
	{
		Col[x] = double();
	}
}

_3X3RowMat::_3X3RowMat(const _3X3RowMat& b)
{
	memcpy(Col, b.Col, sizeof(b.Col));
}

_3X3RowMat::~_3X3RowMat()
{

}