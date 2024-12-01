
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "hinhchunhatdichuyen.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	active = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	/*CRect rect(0, 0, 30, 30);
	dc.Rectangle(rect);*/

	hcn1.setHcn(50, 50, 200, 200);
	hcn1.draw(&dc);
	// Do not call CWnd::OnPaint() for painting messages
}






void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

char key;
key = nChar;
int d = 10;
//down 40, left 37, right 39, up 38
//CPaintDC dc(this);
CClientDC pdc(this);
pdc.Rectangle(0, 0, 1000, 1000);
if (key == 37)
{
	hcn1.left(d);
}
if (key == 39)
{
	hcn1.right(d);
}
if (key == 38)
{
	hcn1.up(d);
}
if (key == 40)
{
	hcn1.down(d);
}
//hcn1.draw(&dc);
hcn1.draw(&pdc);

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (hcn1.Kttronghinh(point) == 1)
	{
		active = 1;
		CClientDC pdc(this);
		//pdc.Rectangle(0, 0, 1000, 1000);
	}
	p1.x = point.x;
	p1.y = point.y;
	pmove.x = point.x;
	pmove.y = point.y;

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (active == 1)
	{
		int dx = point.x - pmove.x;
		int dy = point.y - pmove.y;
		hcn1.right(dx);
		hcn1.down(dy);
		CClientDC pdc(this);
		hcn1.draw(&pdc);
	}
	active = 0;

	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (active == 1)
	{
		int dx = point.x - pmove.x;
		int dy = point.y - pmove.y;

		//if (dx > 2 || dy > 2)
		{
			CClientDC pdc(this);
			pdc.Rectangle(0, 0, 1000, 1000);
			hcn1.right(dx);
			hcn1.down(dy);
			hcn1.draw(&pdc);
		}
	}
	pmove.x = point.x;
	pmove.y = point.y;

	CWnd::OnMouseMove(nFlags, point);
}
