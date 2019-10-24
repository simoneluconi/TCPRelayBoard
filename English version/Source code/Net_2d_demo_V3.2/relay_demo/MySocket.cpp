// MySocket.cpp : 实现文件
//

#include "stdafx.h"
#include "relay_demo.h"
#include "MySocket.h"
#include "relay_demo.h"
#include "relay_demoDlg.h"

// MySocket

MySocket::MySocket()
{
}

MySocket::~MySocket()
{
}
MySocket::MySocket(Crelay_demoDlg* p_hwnd)
{
	p_dlgwnd=p_hwnd;
}

// MySocket 成员函数



void MySocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	CSocket::OnReceive(nErrorCode);
	p_dlgwnd->OnReceive(this);
}
