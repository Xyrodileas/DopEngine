#pragma once

#include <vector>

static const int rows = 3;

class _RowMat
{


public:
	_RowMat();
	_RowMat(int m);
	_RowMat(std::vector<double>& col);
	_RowMat(const _RowMat& b);
	~_RowMat();

	std::string ToString();

	std::vector<double> Col;

	inline double& operator[](int x)
	{
		return Col.at(x);
	}
};

