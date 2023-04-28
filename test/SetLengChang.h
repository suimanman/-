#pragma once
#include "afxdialogex.h"


// SetLengChang 对话框

class SetLengChang : public CDialogEx
{
	DECLARE_DYNAMIC(SetLengChang)

public:
	SetLengChang(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetLengChang();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
		
public:
	CEdit m_Edit;
	int Edit = 1;
};
