
// relay_demo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Crelay_demoApp:
// �йش����ʵ�֣������ relay_demo.cpp
//

class Crelay_demoApp : public CWinApp
{
public:
	Crelay_demoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Crelay_demoApp theApp;