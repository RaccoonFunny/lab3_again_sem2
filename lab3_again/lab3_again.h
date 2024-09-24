
// lab3_again.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clab3againApp:
// See lab3_again.cpp for the implementation of this class
//

class Clab3againApp : public CWinApp
{
public:
	Clab3againApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Clab3againApp theApp;
