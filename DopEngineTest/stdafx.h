// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

// Headers for CppUnitTest
#include "CppUnitTest.h"


#include <Windows.h>
#include <iostream>
#include <sstream>

#define DOPTEST_DEBUG( s )            \
{                             \
	std::ostringstream os_;    \
	os_ << s;                   \
	os_ << "\n";						 \
	OutputDebugString(os_.str().c_str());  \
}

// TODO: reference additional headers your program requires here
