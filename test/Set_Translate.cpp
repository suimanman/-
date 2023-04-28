// Set_Translate_x.cpp: 实现文件
//

#include "pch.h"
#include "test.h"
#include "afxdialogex.h"
#include "Set_Translate.h"


// Set_Translate_x 对话框

IMPLEMENT_DYNAMIC(Set_Translate_x, CDialogEx)

Set_Translate_x::Set_Translate_x(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

Set_Translate_x::~Set_Translate_x()
{
}

void Set_Translate_x::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	CString str1;
	m_Edit.GetWindowTextW(str1);
	m_x = _ttoi(str1);
	DDX_Control(pDX, IDC_EDIT2, Edity);
	DDX_Control(pDX, IDC_EDIT3, Editz);
	CString str2;
	Edity.GetWindowTextW(str2);
	m_y = _ttoi(str2);
	CString str3;
	Editz.GetWindowTextW(str3);
	m_z = _ttoi(str3);
}


BEGIN_MESSAGE_MAP(Set_Translate_x, CDialogEx)
END_MESSAGE_MAP()


// Set_Translate_x 消息处理程序
