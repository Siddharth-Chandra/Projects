
// CounterView.h : interface of the CCounterView class
#include "CounterDoc.h"
#include "Values.h"
#pragma once


#define HEIGHT 40
#define WIDTH 40
#define X_OFFSET 50
#define Y_OFFSET 10

#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define CUSTOM 5


class CCounterView : public CView
{
protected: // create from serialization only
	CCounterView();
	DECLARE_DYNCREATE(CCounterView)
	CWinThread *pThread;


// Attributes


public:
	CCounterDoc* GetDocument() const;
	CArray<CPoint, CPoint>m_PointArray;
	CArray<CValues,CValues>m_Spiral;
	CArray<CValues, CValues>m_Cdamped;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCounterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg
		
	void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	long m_Counter;
	long m_MatrixSize;
	long maxPoints;
	long points;

	
	long iCondition;
	afx_msg void OnThreadStart();
	afx_msg void OnThreadPause();

	void DrawGrid(CDC *pDC);
;
	

	afx_msg void OnSelectpatternSelectpattern();
	
	afx_msg void OnThreadResume32786();

	afx_msg void OnAppAbout();
};

#ifndef _DEBUG  // debug version in CounterView.cpp
inline CCounterDoc* CCounterView::GetDocument() const
   { return reinterpret_cast<CCounterDoc*>(m_pDocument); }
#endif

