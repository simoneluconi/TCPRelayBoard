// MySocket.cpp : ʵ���ļ�
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

// MySocket ��Ա����



void MySocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���

	CSocket::OnReceive(nErrorCode);
	p_dlgwnd->OnReceive(this);
}
