#include "Math\3DVec.h"
#include "Math\Mat.h"
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


int main()
{
	return 0;
}
