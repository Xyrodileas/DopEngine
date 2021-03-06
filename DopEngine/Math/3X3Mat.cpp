#include "3X3Mat.h"
#include <math.h>
#include <cstdlib>
#include <cstring>

M3X3Mat::M3X3Mat()
{
	for (int x = 0; x < 3; x++)
	{
		Rows[x] = _3X3RowMat();
	}
}

M3X3Mat::M3X3Mat(double x1, double x2, double x3, double y1, double y2, double y3, double z1, double z2, double z3)
{
	for (int x = 0; x < 3; x++)
	{
		Rows[x] = _3X3RowMat();
	}
	Rows[0][0] = x1;
	Rows[0][1] = x2;
	Rows[0][2] = x3;
	Rows[1][0] = y1;
	Rows[1][1] = y2;
	Rows[1][2] = y3;
	Rows[2][0] = z1;
	Rows[2][1] = z2;
	Rows[2][2] = z3;
}

M3X3Mat::M3X3Mat(const M3X3Mat& b)
{
	memcpy(this->Rows, b.Rows, sizeof(b.Rows));
}

void M3X3Mat::ReduceForm()
{


}


void M3X3Mat::AddRowToAnother(int i, int r, double coef)
{
	for (int j = 0; j < 3; j++)
	{
		Rows[i][j] = Rows[i][j] + Rows[r][j] * coef;
	}
}

void M3X3Mat::ExchangeRows(int i, int n)
{
	_3X3RowMat tmp = Rows[i];
	Rows[i] = Rows[n];
	Rows[n] = tmp;
}

void M3X3Mat::RowByScalar(int i, double x)
{
	for (int j = 0; j < 3; j++)
	{
		Rows[i][j] = Rows[i][j] * x;
	}
}

M3X3Mat::~M3X3Mat()
{
}
