#include "pch.h"
#include "CFace.h"
CFace::CFace()
{
	vI = NULL;
}
CFace::~CFace()
{
	if (vI != NULL)
	{
		delete[]vI;
		vI = NULL;
	}
}
void CFace::SetNum(int en)
{
	vN = en;
	vI = new int[vN];
}