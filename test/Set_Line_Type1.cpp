// Set_Line_Type1.cpp: 实现文件
//

#include "pch.h"
#include "test.h"
#include "afxdialogex.h"
#include "Set_Line_Type1.h"


// Set_Line_Type1 对话框

IMPLEMENT_DYNAMIC(Set_Line_Type1, CDialogEx)

Set_Line_Type1::Set_Line_Type1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Set_Line_Type1::~Set_Line_Type1()
{
}

void Set_Line_Type1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);

	CString str;
	m_Edit.GetWindowTextW(str);
	m_PenType1 = _ttoi(str);
}


BEGIN_MESSAGE_MAP(Set_Line_Type1, CDialogEx)
END_MESSAGE_MAP()


// Set_Line_Type1 消息处理程序
