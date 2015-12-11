#include "3DVec.h"
#include <math.h>

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

M3DVec::M3DVec()
{

}

M3DVec::M3DVec(double x, double y, double z)
{
	X = x;
	Y = y;
	Z = z;
}

double M3DVec::DotP(M3DVec b)
{
	return (b.X*X) + (b.Y*Y) + (b.Z*Z);
}

M3DVec M3DVec::CrossP(M3DVec b)
{
	DOP_DEBUG("test")
	M3DVec result = M3DVec((Y*b.Z) - (Z*b.Y), (Z*b.X) - (X*b.Z), (X*b.Y) - (Y*b.X));
	return result;
}

double M3DVec::Abs()
{
	return sqrt(X*X + Y*Y + Z*Z);
}

M3DVec M3DVec::ProjOnto(M3DVec b)
{
	double abs = b.Abs();
	return b*((this->DotP(b)) / abs*abs);
}
M3DVec M3DVec::PerpOnto(M3DVec b)
{
	M3DVec result = M3DVec(*this - ProjOnto(b));
	return result;
}

double M3DVec::AngleBetween(M3DVec b)
{
	return asin(((M3DVec)(this->CrossP(b))).Abs() / this->Abs()*b.Abs());
}


M3DVec::~M3DVec()
{
}
