// TestThread.cpp : implementation file
//

#include "stdafx.h"
#include "Counter.h"
#include "TestThread.h"
#include  "CounterView.h"
#include "CounterDoc.h"
#include "Values.h"




// CTestThread

IMPLEMENT_DYNCREATE(CTestThread, CWinThread)

CTestThread::CTestThread()
{
}

CTestThread::~CTestThread()
{
}

BOOL CTestThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CTestThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CTestThread, CWinThread)
END_MESSAGE_MAP()


// CTestThread message handlers


UINT CTestThread::RunThreadFunction(LPVOID param)
{
	CCounterView *pCounterView = (CCounterView *)param;
	int iLocal = pCounterView->iCondition;

	CPoint point;
	CValues cdamp;





	if (iLocal == 1)
	{
		while (1)
		{



			point.x = rand() / 100 + 150;
			point.y = rand() / 100 + 150;
			pCounterView->m_PointArray.Add(point);
			pCounterView->Invalidate();
			Sleep(100);
		}

	}

	else if (iLocal == 2)
	{
		CValues values;

		while (values.m_dTheta <= 500)
		{
			values.m_dTheta += values.m_dDelta;
			values.m_dRadius = values.m_dTheta;
			values.m_dX = (values.m_dRadius* cos(values.m_dRadius / 10 * 3.14)) + values.m_dX;
			values.m_dY = (values.m_dRadius* sin(values.m_dRadius / 10 * 3.14)) + values.m_dY;
			pCounterView->m_Spiral.Add(values);
			pCounterView->Invalidate();
			Sleep(100);
		}

	}
	else if (iLocal == 3)
	{
		while (1)
		{
			int iT = 0;
			iT = cdamp.m_dAmp;
			for (int iPos = 1; iPos < cdamp.m_dAmp; iPos++)
			{
				cdamp.m_dX1 += cdamp.m_dPeriod / iT;
				iT--;
				cdamp.m_dY1 -= 1;
				pCounterView->m_Cdamped.Add(cdamp);
			}
			iT = 1;
			for (int iNeg = cdamp.m_dAmp; iNeg > 0; iNeg--)
			{
				cdamp.m_dX1 += cdamp.m_dPeriod / iT;
				iT++;
				cdamp.m_dY1 += 1;
				pCounterView->m_Cdamped.Add(cdamp);
			}
			iT = cdamp.m_dAmp;
			for (int iPos = 1; iPos < cdamp.m_dAmp; iPos++)
			{
				cdamp.m_dX1 += cdamp.m_dPeriod / iT;
				iT--;
				cdamp.m_dY1 += 1;
				pCounterView->m_Cdamped.Add(cdamp);
			}
			iT = 1;
			for (int iNeg = cdamp.m_dAmp; iNeg > 0; iNeg--)
			{
				cdamp.m_dX1 += cdamp.m_dPeriod / iT;
				iT++;
				cdamp.m_dY1 -= 1;
				pCounterView->m_Cdamped.Add(cdamp);
			}
			pCounterView->m_Cdamped.Add(cdamp);
			cdamp.m_dAmp -= 9;
			pCounterView->Invalidate();
			Sleep(500);
		}

	}
	return 0;
}



