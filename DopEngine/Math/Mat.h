#pragma once

#include "_RowMat.h"

#include <vector>


class Mat
{
public:


	//Allocates an uninitialized matrix of size 0x0.
	Mat();
	//Allocates an uninitialized matrix of size nxm
	Mat(int i, int j);
	//Allocates a populated matrix with the nm values of size nxm
	// values : {11,12,13,...,1m,...,n1,...,nm}
	Mat(int n, int m, std::vector<double> values);
	// Copy Constructor
	Mat(const Mat& b);

	~Mat();

	void insert_element(int i, int j, double t);

	void ReduceForm();

	// Exchange row i with row m
	void ExchangeRows(int i, int m);
	// Multiply every cell of a row i by a scalar x
	void RowByScalar(int i, double x);
	// Add to a row i an another row r by a coeficient coef
	void AddRowToAnother(int i, int r, double coef);

	inline _RowMat& operator[](int x)
	{
		return Rows.at(x);
	}

	std::string ToString();


	inline Mat operator+(const Mat& b)
	{
		Mat second = b;
		Mat result;
		std::vector<double> values = { Rows[0][0] + second[0][0], Rows[0][1] + second[0][1], Rows[0][2] + second[0][2],
									   Rows[1][0] + second[1][0], Rows[1][1] + second[1][1], Rows[1][2] + second[1][2],
									   Rows[2][0] + second[2][0], Rows[2][1] + second[2][1], Rows[2][2] + second[2][2] };
		result = Mat(m_N, m_M, values);
		return result;
	}

	inline Mat operator+(double b)
	{
		Mat result;
		std::vector<double> values = { Rows[0][0] + b, Rows[0][1] + b, Rows[0][2] + b,
									   Rows[1][0] + b, Rows[1][1] + b, Rows[1][2] + b,
									   Rows[2][0] + b, Rows[2][1] + b, Rows[2][2] + b };
		result = Mat(m_N, m_M, values);
		return result;
	}

	inline Mat operator-(const Mat& b)
	{
		Mat result;
		Mat second = b;

		std::vector<double> values = { Rows[0][0] - second[0][0], Rows[0][1] - second[0][1], Rows[0][2] - second[0][2],
									   Rows[1][0] - second[1][0], Rows[1][1] - second[1][1], Rows[1][2] - second[1][2],
									   Rows[2][0] - second[2][0], Rows[2][1] - second[2][1], Rows[2][2] - second[2][2] };
		result = Mat(m_N, m_M, values);
		return result;
	}

	inline Mat operator-(double b)
	{
		Mat result;

		std::vector<double> values = { Rows[0][0] - b, Rows[0][1] - b, Rows[0][2] - b,
									   Rows[1][0] - b, Rows[1][1] - b, Rows[1][2] - b,
									   Rows[2][0] - b, Rows[2][1] - b, Rows[2][2] - b };
		result = Mat(m_N, m_M, values);
		return result;
	}

	inline bool operator==(const Mat& b)
	{
		auto itRowSecond = b.Rows.begin();
		for (auto itRows : Rows)
		{
			auto itColSecond = (*itRowSecond).Col.begin();
			for (auto itCol : itRows.Col)
			{
				if (itCol != *itColSecond)
				{
					return false;
				}
				itColSecond++;
			}
			itRowSecond++;
		}
		return true;
	}

	inline Mat operator*(double b)
	{
		std::vector<double> values;
		
		for (auto itRows : Rows)
		{
			for (auto itCol : itRows.Col)
			{
				values.push_back(itCol * b);
			}
		}
		Mat result = Mat(m_N, m_M, values);
		return result;
	}
	inline Mat operator*(const Mat& b)
	{
		Mat second = b;
		Mat result;
		if (m_M == second.m_N)
		{
			std::vector<double> values;
			for (int i = 0; i < m_N; i++)
			{
				for (int j = 0; j < second.m_M; j++)
				{
					double ij = 0;
					// Store the current row to avoid fetching it m times for the same cell
					auto currentRow = Rows[i].Col.begin();
					for (int k = 0; k < m_M; k++)
					{
						ij += (*currentRow) * second[k][j];
						currentRow++;
					}
					values.push_back(ij);
				}
			}
			result = Mat(m_N, second.m_M, values);
		}
		else
		{
			result = Mat();
		}
		
		return result;
	}

	inline Mat operator/(double b)
	{
		std::vector<double> values;

		for (auto itRows : Rows)
		{
			for (auto itCol : itRows.Col)
			{
				values.push_back(itCol / b);
			}
		}
		Mat result = Mat(m_N, m_M, values);
		return result;
	}

	private:
		int m_N;
		int m_M;

	std::vector<_RowMat> Rows;

};