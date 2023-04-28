#pragma once
#include "afxdialogex.h"


// Set_Scale 对话框

class Set_Scale : public CDialogEx
{
	DECLARE_DYNAMIC(Set_Scale)

public:
	Set_Scale(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Set_Scale();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit Editx;
	CEdit Edity;
	CEdit Editz;
	double m_x = 1.0, m_y = 1.0,m_z=1.0;
};
