#pragma once


// CSelectPattern dialog

class CSelectPattern : public CDialog
{
	DECLARE_DYNAMIC(CSelectPattern)

public:
	CSelectPattern(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelectPattern();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SelectPattern };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_SelectedData;
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeComboOptions();
};
