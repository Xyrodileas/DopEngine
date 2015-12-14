#include "Mat.h"
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <iostream>

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

Mat::Mat()
{
	m_N = 0;
	m_M = 0;
}

Mat::Mat(int n, int m)
{
	Rows.reserve(n);
	m_N = n;
	m_M = m;
	for(int x = 0; x < n; x++)
	{
		Rows[x] = _RowMat(m);
	}
}

Mat::Mat(int n, int m, std::vector<double> values)
{
	m_N = n;
	m_M = m;
	Rows.reserve(m_N);
	
	int i = 0;
	auto iterator = values.begin();
	for (int x = 0; x < m_N; x++)
	{
		std::vector<double> tmpValues;
		for (i; i < (x + 1)*m_M; i++)
		{
			tmpValues.push_back(*iterator);
			iterator++;
		}
		Rows.push_back(_RowMat(tmpValues));
	}
}

Mat::Mat(const Mat& b)
{
	m_N = b.m_N;
	m_M = b.m_M;
	Rows = std::vector<_RowMat>(b.Rows);
}

void Mat::ReduceForm()
{
	int i = 0; // A
	for (int j = 0; j < m_N; j++) // B
	{
		int kjmax = -1;
		double largest = 0;
		for (int k = i; k < m_N; k++) // C
		{
			double current = Rows[k][j];
			if (current*current > largest*largest)
			{
				kjmax = k;
				largest = current;
			}
		}
		if (kjmax == -1)
		{
			continue;
		}
		if (kjmax != i) // D
		{
			ExchangeRows(i, kjmax);
		}
		RowByScalar(i, 1 / Rows[i][j]); // E
		for (int r = 0; r < m_N; r++) // F
		{
			if (i != r)
			{
				AddRowToAnother(r, i, -Rows[r][j]); // Clear entry above and below i, in collumn j to 0
			}
		}
		
		i += 1;
	}
}

void Mat::insert_element(int i, int j, double t)
{
	Rows[i][j] = t;
}


void Mat::AddRowToAnother(int i, int r, double coef)
{
	for (int j = 0; j < m_M; j++)
	{
		Rows[i][j] = Rows[i][j] + Rows[r][j] * coef;
	}
}

void Mat::ExchangeRows(int i, int n)
{
	_RowMat tmp = Rows[i];
	Rows[i] = Rows[n];
	Rows[n] = tmp;
}

void Mat::RowByScalar(int i, double x)
{
	for (int j = 0; j < m_M; j++)
	{
		Rows[i][j] = Rows[i][j] * x;
	}
}

std::string Mat::ToString()
{
	std::string result = "";
	
	for (auto itRows : Rows)
	{
		result += "|";
		result += itRows.ToString();
		result += "\n";
	}
	return result;
}

Mat::~Mat()
{
}
