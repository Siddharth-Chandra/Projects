// Select.cpp : implementation file
//

#include "stdafx.h"
#include "Counter.h"
#include "Select.h"
#include "afxdialogex.h"


// CSelect dialog

IMPLEMENT_DYNAMIC(CSelect, CDialogEx)

CSelect::CSelect(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CSelect::~CSelect()
{
}

void CSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_ShapeList);
}


BEGIN_MESSAGE_MAP(CSelect, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSelect::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CSelect message handlers


void CSelect::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}
