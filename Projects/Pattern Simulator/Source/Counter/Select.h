#pragma once
#include "afxwin.h"


// CSelect dialog

class CSelect : public CDialogEx
{
	DECLARE_DYNAMIC(CSelect)

public:
	CSelect(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelect();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_ShapeList;
};
