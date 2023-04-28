#include "pch.h"
#include "CP3.h"
#include "CTransform.h"
CTransform::CTransform()
{

}
CTransform::~CTransform()
{

}
void CTransform::SetMat(CP3* p, int n)
{
	POld = p;
	num = n;
}
void CTransform::Identity()
{
	T[0][0] = 1.0; T[0][1] = 0.0; T[0][2] = 0.0; T[0][3] = 0.0;
	T[1][0] = 0.0; T[1][1] = 1.0; T[1][2] = 0.0; T[1][3] = 0.0;
	T[2][0] = 0.0; T[2][1] = 0.0; T[2][2] = 1.0; T[2][3] = 0.0;
	T[3][0] = 0.0; T[3][1] = 0.0; T[3][2] = 0.0; T[3][3] = 1.0;
}
void CTransform::Translate(double tx, double ty,double tz)
{
	Identity();
	T[3][0] = tx;
	T[3][1] = ty;
	T[3][2] = tz;
	MultiMatrix();
}
void CTransform::Scale(double sx, double sy,double sz)
{
	Identity();
	T[0][0] = sx;
	T[1][1] = sy;
	T[2][2] = sz;
	MultiMatrix();
}
void CTransform::Scale(double sx, double sy, double sz,CP3 p)
{
	Translate(-p.x,-p.y,-p.z);
	Scale(sx,sy,sz);
	Translate(p.x, p.y, p.z);
}
void CTransform::MultiMatrix()
{
	CP3 *PNew=new CP3[num];
	for (int i = 0; i < num; i++)
	{
		PNew[i] = POld[i];
	}
	for (int j = 0; j < num; j++)
	{
		POld[j].x = PNew[j].x * T[0][0] + PNew[j].y * T[1][0] + PNew[j].z * T[2][0] + PNew[j].w * T[3][0];
		POld[j].y = PNew[j].x * T[0][1] + PNew[j].y * T[1][1] + PNew[j].z * T[2][1] + PNew[j].w * T[3][1];
		POld[j].z = PNew[j].x * T[0][2] + PNew[j].y * T[1][2] + PNew[j].z * T[2][2] + PNew[j].w * T[3][2];
		POld[j].w = PNew[j].x * T[0][3] + PNew[j].y * T[1][3] + PNew[j].z * T[2][3] + PNew[j].w * T[3][3];
	}
	delete[]PNew;
}