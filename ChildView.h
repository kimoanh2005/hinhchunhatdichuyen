
// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window
#include "CHcn.h"
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
	CHcn hcn1;
	int active;
	CPoint p1;
	CPoint pmove;
// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

