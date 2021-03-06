// (C) Copyright 2002-2003 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- RxTrace.cpp : 
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "RxTrace.h"

//-----------------------------------------------------------------------------
#ifdef _DEBUG

#ifndef _WINBASE_
extern "C" void _stdcall OutputDebugStringA (const char *lpOutputString) ;
extern "C" void _stdcall OutputDebugStringW (const unsigned short *lpOutputString) ;
#ifdef UNICODE
#define OutputDebugString  OutputDebugStringW
#else
#define OutputDebugString  OutputDebugStringA
#endif // !UNICODE
#endif // _WINBASE

//-----------------------------------------------------------------------------
#define _countof(array) (sizeof(array)/sizeof(array[0]))

void RxTrace (const TCHAR *lpszFormat, ...) {
	va_list args ;
	va_start (args, lpszFormat) ;
	int nBuf ;
	TCHAR szBuffer [512] ;
	nBuf =_vsntprintf (szBuffer, _countof (szBuffer), lpszFormat, args) ;
	//- was there an error?
	RXASSERT(nBuf >= 0) ;
	::OutputDebugString (szBuffer) ;
	va_end (args) ;
}

#endif
