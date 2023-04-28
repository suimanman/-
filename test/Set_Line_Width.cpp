// Set_Line_Width.cpp: 实现文件
//

#include "pch.h"
#include "test.h"
#include "afxdialogex.h"
#include "Set_Line_Width.h"

// Set_Line_Width 对话框

IMPLEMENT_DYNAMIC(Set_Line_Width, CDialogEx)

Set_Line_Width::Set_Line_Width(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Set_Line_Width::~Set_Line_Width()
{
}

void Set_Line_Width::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	
	CString str;
	m_Edit.GetWindowTextW(str);
	m_PenSize = _ttoi(str);

}


BEGIN_MESSAGE_MAP(Set_Line_Width, CDialogEx)
END_MESSAGE_MAP()


// Set_Line_Width 消息处理程序
