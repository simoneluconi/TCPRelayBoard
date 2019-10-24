#pragma once
// MySocket ÃüÁîÄ¿±ê
class Crelay_demoDlg;
class MySocket : public CSocket
{
public:
	MySocket();
	virtual ~MySocket();
	MySocket(Crelay_demoDlg* p_hwnd);
public:
	Crelay_demoDlg* p_dlgwnd;
	virtual void OnReceive(int nErrorCode);
};


