// Set_Line_Type2.cpp: 实现文件
//

#include "pch.h"
#include "test.h"
#include "afxdialogex.h"
#include "Set_Line_Type2.h"


// Set_Line_Type2 对话框

IMPLEMENT_DYNAMIC(Set_Line_Type2, CDialogEx)

Set_Line_Type2::Set_Line_Type2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

Set_Line_Type2::~Set_Line_Type2()
{
}

void Set_Line_Type2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);

	CString str;
	m_Edit.GetWindowTextW(str);
	m_PenType2 = _ttoi(str);
}


BEGIN_MESSAGE_MAP(Set_Line_Type2, CDialogEx)
END_MESSAGE_MAP()


// Set_Line_Type2 消息处理程序
