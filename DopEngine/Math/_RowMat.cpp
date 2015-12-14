#include "_RowMat.h"

#include <string>

_RowMat::_RowMat()
{

}

_RowMat::_RowMat(int m)
{
	Col.reserve(m);
	for (int x = 0; x < rows; x++)
	{
		Col[x] = double();
	}
}
_RowMat::_RowMat(std::vector<double>& col)
{
	Col = col;
}

_RowMat::_RowMat(const _RowMat& b)
{
	Col = std::vector<double>(b.Col);
}

std::string _RowMat::ToString()
{
	std::string line;

	for (auto itCol : Col)
	{
		line += std::to_string(itCol);
		line += "|";
	}
	return line;
}

_RowMat::~_RowMat()
{

}