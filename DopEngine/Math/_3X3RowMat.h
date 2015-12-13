#pragma once

static const int rows = 3;

class _3X3RowMat
{
	

public:
	_3X3RowMat();
	_3X3RowMat(const _3X3RowMat& b);
	~_3X3RowMat();


	double Col[rows];

	inline double& operator[](int x)
	{
		return Col[x];
	}
};

