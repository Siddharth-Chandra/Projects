// SelectPattern.cpp : implementation file
//

#include "stdafx.h"
#include "Counter.h"
#include "SelectPattern.h"
#include "afxdialogex.h"


// CSelectPattern dialog

IMPLEMENT_DYNAMIC(CSelectPattern, CDialog)

CSelectPattern::CSelectPattern(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SelectPattern, pParent)
	, m_SelectedData(_T(""))
{

}

CSelectPattern::~CSelectPattern()
{
}

void CSelectPattern::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_OPTIONS, m_SelectedData);
}


BEGIN_MESSAGE_MAP(CSelectPattern, CDialog)
	ON_BN_CLICKED(IDOK, &CSelectPattern::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO_OPTIONS, &CSelectPattern::OnCbnSelchangeComboOptions)
END_MESSAGE_MAP()


// CSelectPattern message handlers


void CSelectPattern::OnBnClickedOk()
{
	UpdateData();
	AfxMessageBox(m_SelectedData);

	CDialog::OnOK();
}


void CSelectPattern::OnCbnSelchangeComboOptions()
{
	// TODO: Add your control notification handler code here
}
