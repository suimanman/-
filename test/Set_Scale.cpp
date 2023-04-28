// Set_Scale.cpp: 实现文件
//

#include "pch.h"
#include "test.h"
#include "afxdialogex.h"
#include "Set_Scale.h"


// Set_Scale 对话框

IMPLEMENT_DYNAMIC(Set_Scale, CDialogEx)

Set_Scale::Set_Scale(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

Set_Scale::~Set_Scale()
{
}

void Set_Scale::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Editx);
	DDX_Control(pDX, IDC_EDIT2, Edity);
	DDX_Control(pDX, IDC_EDIT3, Editz);
	CString str1;
	Editx.GetWindowTextW(str1);
	m_x = _ttoi(str1);
	CString str2;
	Edity.GetWindowTextW(str2);
	m_y = _ttoi(str2);
	CString str3;
	Editz.GetWindowTextW(str3);
	m_z = _ttoi(str3);

}


BEGIN_MESSAGE_MAP(Set_Scale, CDialogEx)

END_MESSAGE_MAP()


// Set_Scale 消息处理程序

