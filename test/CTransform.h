#pragma once
#include "CP2.h"
#include "CP3.h"
class CTransform
{
public:
	CTransform();
	virtual ~ CTransform();
	void SetMat(CP3 *, int);
	void Identity();
	void Translate(double, double, double);
	void Scale(double, double, double);
	void Scale(double, double, double,CP3);
	void MultiMatrix();
public:
	double T[4][4];
	CP3* POld;
	int num=8;
};


