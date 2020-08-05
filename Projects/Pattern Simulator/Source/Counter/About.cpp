// About.cpp : implementation file
//

#include "stdafx.h"
#include "Counter.h"
#include "About.h"
#include "afxdialogex.h"


// CAbout dialog

IMPLEMENT_DYNAMIC(CAbout, CDialog)

CAbout::CAbout(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CAbout::~CAbout()
{
}

void CAbout::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAbout, CDialog)
END_MESSAGE_MAP()


// CAbout message handlers



