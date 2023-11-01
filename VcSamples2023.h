
// VcSamples2023.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CVcSamples2023App:
// See VcSamples2023.cpp for the implementation of this class
//

class CVcSamples2023App : public CWinApp
{
public:
	CVcSamples2023App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CVcSamples2023App theApp;
