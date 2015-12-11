#pragma once
class M3DVec
{
public:
	M3DVec();
	M3DVec(double x, double y, double z);
	~M3DVec();

	double DotP(M3DVec b);

	M3DVec CrossP(M3DVec b);

	double Abs();

	M3DVec ProjOnto(M3DVec b);

	M3DVec PerpOnto(M3DVec b);

	double AngleBetween(M3DVec b);

	inline bool operator==(const M3DVec& b)
	{
		return ((b.X == X) && (b.Y == Y) && (b.Z == Z));
	}

	inline bool operator!=(const M3DVec& b)
	{
		return !(*this == b);
	}
	inline M3DVec operator+(const M3DVec& b)
	{
		M3DVec result;
		result = M3DVec(X + b.X, Y + b.Y, Z + b.Z);
		return result;
	}
	inline M3DVec operator-(const M3DVec& b)
	{
		M3DVec result;
		result = M3DVec(X - b.X, Y - b.Y, Z - b.Z);
		return result;
	}
	inline M3DVec operator*(double b)
	{
		M3DVec result;
		result = M3DVec(X * b, Y * b, Z * b);
		return result;
	}
	inline M3DVec operator/(double b)
	{
		M3DVec result;
		result = M3DVec(X / b, Y / b, Z / b);
		return result;
	}
	double X;
	double Y;
	double Z;
};

