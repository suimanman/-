#pragma once
#include "afxdialogex.h"


// Set_Line_Type2 对话框

class Set_Line_Type2 : public CDialogEx
{
	DECLARE_DYNAMIC(Set_Line_Type2)

public:
	Set_Line_Type2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Set_Line_Type2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit;
	int m_PenType2 = 1;
};
