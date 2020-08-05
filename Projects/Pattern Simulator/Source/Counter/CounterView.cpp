
// CounterView.cpp : implementation of the CCounterView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Counter.h"
#endif

#include "CounterDoc.h"
#include "CounterView.h"
#include "TestThread.h"
#include "Values.h"
#include "SelectPattern.h"
#include "About.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCounterView

IMPLEMENT_DYNCREATE(CCounterView, CView)

BEGIN_MESSAGE_MAP(CCounterView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCounterView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_THREAD_START, &CCounterView::OnThreadStart)
	ON_COMMAND(ID_THREAD_PAUSE, &CCounterView::OnThreadPause)



	ON_COMMAND(ID_SELECTPATTERN_SELECTPATTERN, &CCounterView::OnSelectpatternSelectpattern)

	ON_COMMAND(ID_THREAD_RESUME32786, &CCounterView::OnThreadResume32786)

	ON_COMMAND(ID_APP_ABOUT, &CCounterView::OnAppAbout)
END_MESSAGE_MAP()

// CCounterView construction/destruction

CCounterView::CCounterView()

{





}

CCounterView::~CCounterView()
{
}

BOOL CCounterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCounterView drawing

void CCounterView::OnDraw(CDC* pDC)
{
	CCounterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (iCondition == 1)
	{
		for (int iCount = 0; iCount < m_PointArray.GetSize() - 2; iCount++)
		{
			pDC->MoveTo(m_PointArray[iCount].x, m_PointArray[iCount].y);
			pDC->LineTo(m_PointArray[iCount + 1].x, m_PointArray[iCount + 1].y);
		}
	}


	else if (iCondition == 2)
	{

		pDC->MoveTo(400, 300);
		for (int iCount = 0; iCount <= (m_Spiral.GetSize() - 2); iCount++)
		{

			pDC->LineTo(m_Spiral[iCount].m_dX, m_Spiral[iCount].m_dY);
		}

	}


	else if (iCondition == 3)

	{
		pDC->MoveTo(10, 30);
		pDC->LineTo(10, 800);
		pDC->MoveTo(10, 200);
		pDC->LineTo(800, 200);


		pDC->MoveTo(10, 200);

		for (int iCount = 0; iCount <= m_Cdamped.GetSize() - 1; iCount++)
		{
			pDC->LineTo(m_Cdamped[iCount].m_dX1, m_Cdamped[iCount].m_dY1);

		}
	}
}



// CCounterView printing


void CCounterView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCounterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCounterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCounterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCounterView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCounterView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCounterView diagnostics

#ifdef _DEBUG
void CCounterView::AssertValid() const
{
	CView::AssertValid();
}

void CCounterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCounterDoc* CCounterView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCounterDoc)));
	return (CCounterDoc*)m_pDocument;
}
#endif //_DEBUG


// CCounterView message handlers


void CCounterView::OnThreadStart()
{
	pThread = AfxBeginThread(CTestThread::RunThreadFunction, this);

}


void CCounterView::OnThreadPause()
{
	pThread->SuspendThread();
}
void CCounterView::OnThreadResume32786()
{
	pThread->ResumeThread();
}



void CCounterView::DrawGrid(CDC *pDC)
{
	CCounterDoc *pDoc = GetDocument();



}










void CCounterView::OnSelectpatternSelectpattern()
{
	// TODO: Add your command handler code here
	CSelectPattern select;

	if (select.DoModal() == IDOK)
	{
		if (select.m_SelectedData == ("Random Walk"))
		{
			iCondition = 1;
		}
		else if (select.m_SelectedData == ("Spiral"))
		{
			iCondition = 2;
		}
		else if (select.m_SelectedData == ("Damped Harmonic Oscillator"))
		{
			iCondition = 3;
		}


	}UpdateData();

}

void CCounterView::OnAppAbout()
{
	CAbout about;
	about.DoModal();
}
