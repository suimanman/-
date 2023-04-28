
// testView.h: CtestView 类的接口
//

#pragma once
#include "CP2.h"
#include "CP3.h"
#include "CFace.h"
#include "CTransform.h"

class CtestView : public CView
{
protected: // 仅从序列化创建
	CtestView() noexcept;
	DECLARE_DYNCREATE(CtestView)

// 特性
public:
	CtestDoc* GetDocument() const;
	
// 操作
public:
	int m_PenSize;
	COLORREF Filling_Color;
	CPoint m_PointBegin, m_PointEnd;
	enum class DrawType
	{
		LineSegment,Translate,Rectangle,Ellips,Pencile,Filling,Scale
	}m_DrawType;
	struct LINE
	{
		int width, type1, type2;
		COLORREF clr;
	}Line;
	LINE L;
	CP3 P[8],ScreenP[8];
	CP2 pp[2];
	int PtCount;
	CFace F[6];
	int FF[6][4];
	double T[4][4];
	double LengChang;//正方体棱长
	double Wxl, Wxr, Wyt, Wyb;
	CTransform trans;
	double tx , ty ,tz,sx,sy,sz;
	void bresenham(int x1, int y1, int x2, int y2, LINE L);
	void RegionFilling(CPoint X, COLORREF clr);//填充函数
	void ReadPoint();
	void ReadFace();
	void ObliqueProject(CP3 *p,int n);
	void HuiHua();
	void ClipBoundary(CP2 rect0,CP2 rect1);
	void DrawObiect(CDC* pDC, BOOL bclip);
	void EnCode(CP2 &pt);
	void Cohen();
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CtestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint x1, x2;
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDrawLineSegment();
	afx_msg void OnDrawRecttangle();
	afx_msg void OnSetColor();
	afx_msg void OnSetPenSize();
	afx_msg void OnSet_Line_Type1();
	afx_msg void OnSet_Line_Type2();
	afx_msg void OnSetLine_Type1();
	afx_msg void OnSetLine_Type2();
	afx_msg void OnFilling();
	afx_msg void OnSet_FillingColor();
	afx_msg void OnSet_Translate_x();
	afx_msg void OnTranslate();
	afx_msg void OnSet_Scale();
	afx_msg void OnButtonbiliKuoda();
	afx_msg void OnSet_Scalexy();
	afx_msg void OnButtonpingyi();
	afx_msg void OnButtonrect();
	afx_msg void OnSetLengChang();
};


#ifndef _DEBUG  // testView.cpp 中的调试版本
inline CtestDoc* CtestView::GetDocument() const
   { return reinterpret_cast<CtestDoc*>(m_pDocument); }
#endif

