#include "pch.h"
#include "CP3.h"
CP3::CP3()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}
CP3::~CP3()
{

}
CP3::CP3(double x, double y,double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = 1;
}