#pragma once
class CFace
{
public:
	CFace();
	virtual ~CFace();
	void SetNum(int);
public:
	int vN;//面的顶点数
	int* vI;//面的顶点索引
};

