#ifndef _DEMO_BASE_H
#define _DEMO_BASE_H

#include "matrix.h"

//! Demo base class.
class DemoBase
{
public:
	virtual void init() = 0;
	virtual void deinit() = 0;
	virtual void draw(const Matrix& viewMatrix) = 0;
};

#endif
