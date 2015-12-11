#pragma once

#include "_3X3RowMat.h"

static const int cols = 3;


class M3X3Mat
{
public:
	M3X3Mat();
	M3X3Mat(double x1, double x2, double x3, 
			double y1, double y2, double y3, 
			double z1, double z2, double z3);
	M3X3Mat(const M3X3Mat& b);
	~M3X3Mat();


	inline _3X3RowMat& operator[](int x)
	{
		return Rows[x];
	}


	inline M3X3Mat operator+(const M3X3Mat& b)
	{
		M3X3Mat second = b;
		M3X3Mat result;

		result = M3X3Mat(Rows[0][0] + second[0][0], Rows[0][1] + second[0][1], Rows[0][2] + second[0][2],
						 Rows[1][0] + second[1][0], Rows[1][1] + second[1][1], Rows[1][2] + second[1][2],
						 Rows[2][0] + second[2][0], Rows[2][1] + second[2][1], Rows[2][2] + second[2][2]);
		return result;
	}

	inline M3X3Mat operator+(double b)
	{
		M3X3Mat result;

		result = M3X3Mat(Rows[0][0] + b, Rows[0][1] + b, Rows[0][2] + b,
						 Rows[1][0] + b, Rows[1][1] + b, Rows[1][2] + b,
						 Rows[2][0] + b, Rows[2][1] + b, Rows[2][2] + b);
		return result;
	}

	inline M3X3Mat operator-(const M3X3Mat& b)
	{
		M3X3Mat result;
		M3X3Mat second = b;

		result = M3X3Mat(Rows[0][0] - second[0][0], Rows[0][1] - second[0][1], Rows[0][2] - second[0][2],
						 Rows[1][0] - second[1][0], Rows[1][1] - second[1][1], Rows[1][2] - second[1][2],
						 Rows[2][0] - second[2][0], Rows[2][1] - second[2][1], Rows[2][2] - second[2][2]);
		return result;
	}

	inline M3X3Mat operator-(double b)
	{
		M3X3Mat result;

		result = M3X3Mat(Rows[0][0] - b, Rows[0][1] - b, Rows[0][2] - b,
						 Rows[1][0] - b, Rows[1][1] - b, Rows[1][2] - b,
						 Rows[2][0] - b, Rows[2][1] - b, Rows[2][2] - b);
		return result;
	}

	inline bool operator==(const M3X3Mat& b)
	{
		M3X3Mat second = b;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if ((double)Rows[i][j] != (double)second[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}

	inline M3X3Mat operator*(double b)
	{
		M3X3Mat result = M3X3Mat();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result[i][j] = Rows[i][j] * b;
			}
		}
		return result;
	}
	inline M3X3Mat operator*(const M3X3Mat& b)
	{
		M3X3Mat second = b;
		M3X3Mat result;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
					result[i][j] = result[i][j] + Rows[i][k] * second[k][j];
			}
		}
		return result;
	}

	inline M3X3Mat operator/(double b)
	{
		M3X3Mat result = *this;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result[i][j] = result[i][j] / b;
			}
		}
		return result;
	}

	_3X3RowMat Rows[cols];

};