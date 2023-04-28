
// testView.cpp: CtestView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test.h"
#endif

#include "testDoc.h"
#include "testView.h"
#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define LEFT 1 //0001
#define RIGHT 2 //0010
#define BOTTOM 4 //0100
#define TOP 8 //1000

#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include "Set_Line_Width.h"
#include "Set_Line_Type1.h"
#include "Set_Line_Type2.h"
#include "CP2.h"
#include "CP3.h"
#include "CTransform.h"
#include "Set_Translate.h"
#include "Set_Scale.h"
#include "SetLengChang.h"
using namespace std;

// CtestView

IMPLEMENT_DYNCREATE(CtestView, CView)

BEGIN_MESSAGE_MAP(CtestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_MBUTTONDOWN()
//	ON_WM_MBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
//	ON_WM_CREATE()
	ON_COMMAND(ID_32791, &CtestView::OnDrawLineSegment)
	ON_COMMAND(ID_32792, &CtestView::OnDrawRecttangle)
	ON_COMMAND(ID_32795, &CtestView::OnSetColor)
	ON_COMMAND(ID_32794, &CtestView::OnSetPenSize)
	ON_COMMAND(ID_32797, &CtestView::OnSetLine_Type1)
	ON_COMMAND(ID_32798, &CtestView::OnSetLine_Type2)
	ON_COMMAND(ID_32799, &CtestView::OnFilling)
	ON_COMMAND(ID_32800, &CtestView::OnSet_FillingColor)
	ON_COMMAND(ID_32802, &CtestView::OnSet_Translate_x)
	ON_COMMAND(ID_32793, &CtestView::OnTranslate)
	ON_COMMAND(ID_32790, &CtestView::OnSet_Scale)
	ON_COMMAND(ID_BUTTONBiLi_KuoDa, &CtestView::OnButtonbiliKuoda)
	ON_COMMAND(ID_32821, &CtestView::OnSet_Scalexy)
	ON_COMMAND(ID_BUTTONPingYi, &CtestView::OnButtonpingyi)
	ON_COMMAND(ID_BUTTONRECT, &CtestView::OnButtonrect)
	ON_COMMAND(ID_32824, &CtestView::OnSetLengChang)
END_MESSAGE_MAP()

// CtestView 构造/析构
CtestView::CtestView() noexcept
{
	Line = { 1,0,0,RGB(0,0,0) };
	Filling_Color = RGB(255, 0, 0);
	double Tran_x = 0,Tran_y=0;
	trans.SetMat(P, 8);
	sx = 1.0, sy = 1.0, sz = 1.0;
	FF[0][0] = 4; FF[0][1] = 5; FF[0][2] = 6; FF[0][3] = 7;
	FF[1][0] = 0; FF[1][1] = 3; FF[1][2] = 2; FF[1][3] = 1;
	FF[2][0] = 0; FF[2][1] = 4; FF[2][2] = 7; FF[2][3] = 3;
	FF[3][0] = 1; FF[3][1] = 2; FF[3][2] = 6; FF[3][3] = 5;
	FF[4][0] = 2; FF[4][1] = 3; FF[4][2] = 7; FF[4][3] = 6;
	FF[5][0] = 0; FF[5][1] = 1; FF[5][2] = 5; FF[5][3] = 4;
	// TODO: 在此处添加构造代码
	//m_PenSize=1;
	//m_PenColor = RGB(0, 0, 0);
	//m_BrushColor=RGB(0,0,0);
	//m_PointBegin = CPoint(0, 0);
	//m_PointEnd=CPoint(0,0);
	//m_DrawType = DrawType::LineSegment;
}

void CtestView::ReadPoint()
{
	P[0].x = 0;			P[0].y = 0;			P[0].z = 0;
	P[1].x = LengChang; P[1].y = 0;			P[1].z = 0;
	P[2].x = LengChang; P[2].y = LengChang; P[2].z = 0;
	P[3].x = 0;			P[3].y = LengChang; P[3].z = 0;
	P[4].x = 0;			P[4].y = 0;			P[4].z = LengChang;
	P[5].x = LengChang; P[5].y = 0;			P[5].z = LengChang;
	P[6].x = LengChang; P[6].y = LengChang; P[6].z = LengChang;
	P[7].x = 0;			P[7].y = LengChang; P[7].z = LengChang;
}
void CtestView::ReadFace()
{
	F[0].SetNum(4); F[0].vI[0] = 4; F[0].vI[1] = 5; F[0].vI[2] = 6; F[0].vI[3] = 7;
	F[1].SetNum(4); F[1].vI[0] = 0; F[0].vI[1] = 3; F[0].vI[2] = 2; F[0].vI[3] = 1;
	F[2].SetNum(4); F[2].vI[0] = 0; F[0].vI[1] = 4; F[0].vI[2] = 7; F[0].vI[3] = 3;
	F[3].SetNum(4); F[3].vI[0] = 1; F[0].vI[1] = 2; F[0].vI[2] = 6; F[0].vI[3] = 5;
	F[4].SetNum(4); F[4].vI[0] = 2; F[0].vI[1] = 3; F[0].vI[2] = 7; F[0].vI[3] = 6;
	F[5].SetNum(4); F[5].vI[0] = 0; F[0].vI[1] = 1; F[0].vI[2] = 5; F[0].vI[3] = 4;
}
void CtestView::ObliqueProject(CP3 p[], int n)
{
	for (int i = 0; i < n; i++)
	{
		ScreenP[i].x = p[i].x - p[i].z / sqrt(2);
		ScreenP[i].y = p[i].y - p[i].z / sqrt(2);
	}
}

CtestView::~CtestView()
{
}

BOOL CtestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CtestView 绘图

void CtestView::bresenham(int x1, int y1, int x2, int y2,LINE line)
{
	CDC* pDC = GetDC();
	if (y1 == y2)
	{
		if (x1 > x2) swap(x1, x2);
		for (int i = x1; i <= x2; )
		{
			pDC->SetPixel(i, y1, line.clr);
			if (line.type1 && i % line.type1 == 0) i += line.type2;
			else i++;
		}
		return;
	}
	if (y2 < y1)//让第一个点纵坐标始终小于第二个点纵坐标，即在x轴上方讨论所有情况
	{
		int t = x1;
		x1 = x2;
		x2 = t;
		t = y1; y1 = y2; y2 = t;
	}
	double k = (double)(y2 - y1) / (x2 - x1);//判断斜率
	if (k > 0 && k <= 1.0)
	{
		int x = x1;
		for (int yw = y1; yw <= y1 + line.width; yw++)//控制线宽
		{
			x1 = x;
			int y0 = yw;
			double d = 0;
			while (x1 < x2)
			{
				if (d < 0.5) pDC->SetPixel(x1, y0, line.clr);
				else
				{
					y0++;
					d -= 1;
					pDC->SetPixel(x1, y0, line.clr);
				}
				if (line.type1 && x1 % line.type1 == 0) x1 += line.type2;//虚线线型
				else x1++;
				d += k;
			}
		}
	}
	else if (k > 1.0)
	{
		int y = y1;
		double k = (double)(x2 - x1) / (y2 - y1);//这种情况为增加y讨论x，因此变换k
		for (int xw = x1; xw <= x1 + line.width; xw++)
		{
			y1 = y;
			int x0 = xw;
			double d = 0;
			while (y1 < y2)
			{
				if (d < 0.5) pDC->SetPixel(x0, y1, line.clr);
				else
				{
					x0++;
					d -= 1;
					pDC->SetPixel(x0, y1, line.clr);
				}
				if (line.type1 && y1 % line.type1 == 0) y1 += line.type2;
				else y1++;
				d += k;
			}
		}
	}
	else if (k >= -1.0 && k < 0)
	{
		int x = x1;
		for (int yw = y1; yw <= y1 + line.width; yw++)
		{
			x1 = x;
			int y0 = yw;
			double d = 0;
			while (x1 > x2)
			{
				if (d < 0.5) pDC->SetPixel(x1, y0, line.clr);
				else
				{
					y0++;
					d -= 1;
					pDC->SetPixel(x1, y0, line.clr);
				}
				if (line.type1 && x1 % line.type1 == 0) x1 -= line.type2;
				else x1--;
				d += -k;
			}
		}
	}
	else if (k < -1.0)
	{
		int y = y1;
		double k = (double)(x2 - x1) / (y2 - y1);
		for (int xw = x1; xw >= x1 - line.width; xw--)
		{
			y1 = y;
			int x0 = xw;
			double d = 0;
			while (y1 < y2)
			{
				if (d < 0.5) pDC->SetPixel(x0, y1, line.clr);
				else
				{
					x0--;
					d -= 1;
					pDC->SetPixel(x0, y1, line.clr);
				}
				if (line.type1 && y1 % line.type1 == 0) y1 += line.type2;
				else y1++;
				d += -k;
			}
		}
	}
}

void CtestView::RegionFilling(CPoint X, COLORREF clr)
{
	CDC* pDC = GetDC();
	pair<int, int> q[100000];
	int hh = 0, tt = 0;
	int x0 = X.x, y0 = X.y;
	q[0] = { x0,y0 };

	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
	while (hh <= tt)
	{
		auto t = q[hh++];

		for (int i = 0; i < 4; i++)
		{
			int x = t.first + dx[i], y = t.second + dy[i];
			COLORREF color = pDC->GetPixel(x, y);
			if (color == RGB(255, 255, 255)) {
				pDC->SetPixel(x, y, clr);
				q[++tt] = { x,y };
			}
			
		}
	}
}

void CtestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	x1= point;
	CView::OnLButtonDown(nFlags, point);
	
}

void CtestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CClientDC dc(this);
	switch (m_DrawType)
	{
		case CtestView::DrawType::LineSegment:
		{
			x2 = point;
			bresenham(x1.x, x1.y, x2.x, x2.y, Line);
			CView::OnLButtonUp(nFlags, point);
			break;
		}
		case CtestView::DrawType::Translate:
			break;
		case CtestView::DrawType::Rectangle:
		{
			dc.SetROP2(R2_NOTXORPEN);
			CRect rectP1(m_PointBegin, m_PointEnd);
			dc.Rectangle(rectP1);

			CRect rectP2(m_PointBegin, point);
			dc.Rectangle(rectP2);

			m_PointEnd = point;
			break;
		}
		case CtestView::DrawType::Ellips:
			break;
		case CtestView::DrawType::Pencile:
			break;
		case CtestView::DrawType::Filling:
		{
			x1 = point;
			RegionFilling( x1, Filling_Color);
			break;
		}
		case CtestView::DrawType::Scale:
			break;
		default:
			break;
	}
}

void CtestView::OnDraw(CDC* pDC)
{
	CtestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}


// CtestView 打印

BOOL CtestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CtestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CtestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CtestView 诊断

#ifdef _DEBUG
void CtestView::AssertValid() const
{
	CView::AssertValid();
}

void CtestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtestDoc* CtestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtestDoc)));
	return (CtestDoc*)m_pDocument;
}
#endif //_DEBUG


// CtestView 消息处理程序




void CtestView::HuiHua()
{
	CDC* pDC=GetDC();
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	ObliqueProject(P, 8);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int k = (j + 1) % 4;
			pDC->MoveTo(ScreenP[FF[i][j]].x, ScreenP[FF[i][j]].y);
			pDC->LineTo(ScreenP[FF[i][k]].x, ScreenP[FF[i][k]].y);
		}
	}
}

void CtestView::OnButtonbiliKuoda()
{
	// TODO: 在此添加命令处理程序代码
	trans.Scale(sx, sy, sz);
	HuiHua();
	Invalidate(FALSE);
}

void CtestView::OnButtonpingyi()
{
	// TODO: 在此添加命令处理程序代码
	trans.Translate(tx, ty, tz);
	HuiHua();
	Invalidate(FALSE);
}

void CtestView::EnCode(CP2 &pt)
{
	pt.rc = 0;
	if (pt.x < Wxl)
		pt.rc = pt.rc | LEFT;
	else if (pt.x > Wxr)
		pt.rc = pt.rc | RIGHT;
	if (pt.y < Wyb)
		pt.rc = pt.rc | BOTTOM;
	else if (pt.y > Wyt)
		pt.rc = pt.rc | TOP;
}

void CtestView::Cohen()
{
	CP2 p;
	EnCode(pp[0]);
	EnCode(pp[1]);
	while (pp[0].rc != 0 || pp[1].rc != 0)
	{
		if ((pp[0].rc & pp[1].rc) != 0)
		{
			PtCount = 0;
			return;
		}
		if (0 == pp[0].rc)
		{
			CP2 Temp;
			Temp = pp[0];
			pp[0] = pp[1];
			pp[1] = Temp;
		}
		UINT RC = pp[0].rc;
		double k = (pp[1].y - pp[0].y) / (pp[1].x - pp[0].x);
		if (RC & LEFT)
		{
			p.x = Wxl;
			p.y = k * (p.x - pp[0].x) + pp[0].y;
		}
		else if (RC & RIGHT)
		{
			p.x = Wxr;
			p.y = k * (p.x - pp[0].x) + pp[0].y;
		}
		else if (RC & BOTTOM)
		{
			p.y = Wyb;
			p.x = (p.y - pp[0].y)/k + pp[0].x;
		}
		else if (RC & TOP)
		{
			p.y = Wyt;
			p.x = (p.y - pp[0].y)/k + pp[0].x;
		}
		EnCode(p);
		pp[0] = p;
	}
}

void CtestView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*if (nFlags & MK_LBUTTON)
	{
		CClientDC dc(this);
		switch (m_DrawType)
		{
		case CtestView::DrawType::LineSegment:
			
			dc.SetROP2(R2_NOTXORPEN);
			dc.MoveTo(m_PointBegin);
			dc.LineTo(m_PointEnd);
			dc.MoveTo(m_PointBegin);
			dc.LineTo(point);
			m_PointEnd = point;
			break;
		case CtestView::DrawType::Circle:
			break;
		case CtestView::DrawType::Rectangle:
		{
			dc.SetROP2(R2_NOTXORPEN);
			CRect rectP1(m_PointBegin, m_PointEnd);
			dc.Rectangle(rectP1);

			CRect rectP2(m_PointBegin, point);
			dc.Rectangle(rectP2);

			m_PointEnd = point;
			break;
		}
		case CtestView::DrawType::Ellips:
			break;
		case CtestView::DrawType::Pencile:
			break;
		default:
			break;
		}
	}*/
	//if (nFlags & MK_LBUTTON)
	//{
	//	x1 = point;
	//	bresenham(x1.x, x1.y, x2.x, x2.y, Line);//有问题,bug但是曲线
	//	x2 = point;
	//}
	CView::OnMouseMove(nFlags, point);
}

void CtestView::OnDrawLineSegment()
{
	m_DrawType = DrawType::LineSegment;
	// TODO: 在此添加命令处理程序代码
}

void CtestView::OnTranslate()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DrawType::Translate;
}

void CtestView::OnDrawRecttangle()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DrawType::Rectangle;
}

void CtestView::OnSet_Scale()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = DrawType::Scale;
}

void CtestView::OnSetColor()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog dlg;
	if (IDOK == dlg.DoModal())
	{
		this->Line.clr = dlg.GetColor();
	}
}

void CtestView::OnSetPenSize()
{
	// TODO: 在此添加命令处理程序代码
	Set_Line_Width dlg;
	if (IDOK == dlg.DoModal())
	{
		Line.width = dlg.m_PenSize;
	}
}

void CtestView::OnSetLine_Type1()
{
	// TODO: 在此添加命令处理程序代码
	Set_Line_Type1 dlg;
	if (IDOK == dlg.DoModal())
	{
		Line.type1 = dlg.m_PenType1;
	}
}

void CtestView::OnSetLine_Type2()
{
	// TODO: 在此添加命令处理程序代码
	Set_Line_Type2 dlg;
	if (IDOK == dlg.DoModal())
	{
		Line.type2 = dlg.m_PenType2;
	}
}

void CtestView::OnFilling()
{
	m_DrawType = DrawType::Filling;
	// TODO: 在此添加命令处理程序代码
}

void CtestView::OnSet_FillingColor()
{
	CColorDialog dlg;
	if (IDOK == dlg.DoModal())
	{
		this->Filling_Color = dlg.GetColor();
	}
	// TODO: 在此添加命令处理程序代码
}

void CtestView::OnSet_Translate_x()
{
	// TODO: 在此添加命令处理程序代码
	Set_Translate_x dlg;
	if (IDOK == dlg.DoModal())
	{
		tx = dlg.m_x;
		ty = dlg.m_y;
		tz = dlg.m_z;
	}
}

void CtestView::OnSet_Scalexy()
{
	// TODO: 在此添加命令处理程序代码
	Set_Scale dlg;
	if (IDOK == dlg.DoModal())
	{
		sx = dlg.m_x;
		sy = dlg.m_y;
		sz = dlg.m_z;
	}
}

void CtestView::OnButtonrect()
{
	// TODO: 在此添加命令处理程序代码
	ReadPoint();
	HuiHua();
}

void CtestView::OnSetLengChang()
{
	// TODO: 在此添加命令处理程序代码
	SetLengChang dlg;
	if (IDOK == dlg.DoModal())
	{
		LengChang = dlg.Edit;
	}
}
