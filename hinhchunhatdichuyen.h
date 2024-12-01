
// hinhchunhatdichuyen.h : main header file for the hinhchunhatdichuyen application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// ChinhchunhatdichuyenApp:
// See hinhchunhatdichuyen.cpp for the implementation of this class
//

class ChinhchunhatdichuyenApp : public CWinApp
{
public:
	ChinhchunhatdichuyenApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern ChinhchunhatdichuyenApp theApp;
