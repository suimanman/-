#pragma once
#include "afxdialogex.h"


// Set_Translate_x 对话框

class Set_Translate_x : public CDialogEx
{
	DECLARE_DYNAMIC(Set_Translate_x)

public:
	Set_Translate_x(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Set_Translate_x();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit;
	int m_x = 1;
	CEdit Edity;
	CEdit Editz;
	int m_y = 1;
	int m_z = 1;
};
