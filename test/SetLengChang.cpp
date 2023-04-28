// SetLengChang.cpp: 实现文件
//

#include "pch.h"
#include "test.h"
#include "afxdialogex.h"
#include "SetLengChang.h"


// SetLengChang 对话框

IMPLEMENT_DYNAMIC(SetLengChang, CDialogEx)

SetLengChang::SetLengChang(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

SetLengChang::~SetLengChang()
{
}

void SetLengChang::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	CString str;
	m_Edit.GetWindowTextW(str);
	Edit = _ttoi(str);
}


BEGIN_MESSAGE_MAP(SetLengChang, CDialogEx)
END_MESSAGE_MAP()


// SetLengChang 消息处理程序
