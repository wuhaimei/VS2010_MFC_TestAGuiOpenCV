
// TestOpevCv.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestOpevCvApp:
// �йش����ʵ�֣������ TestOpevCv.cpp
//

class CTestOpevCvApp : public CWinApp
{
public:
	CTestOpevCvApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestOpevCvApp theApp;