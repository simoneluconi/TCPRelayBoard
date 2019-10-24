
// relay_demoDlg.h : 头文件
//

#pragma once
#include "MySocket.h"
#include "afxcmn.h"

// Crelay_demoDlg 对话框
class Crelay_demoDlg : public CDialogEx
{
// 构造
public:
	Crelay_demoDlg(CWnd* pParent = NULL);	// 标准构造函数
	void OnReceive(MySocket *sock);
// 对话框数据
	enum { IDD = IDD_RELAY_DEMO_DIALOG };
	MySocket* m_MySocket;
	char relay1,relay2,relay3,relay4;
	char relay_status;
	char net_check;
	char start_net;
	char sent_con;
	unsigned int far_port;
	CString far_IP;
	CString	m_DomainName;
	WSADATA     wsaData;
	struct hostent *host;
	unsigned char status_dns;

	CFile file_dns,file_port,file_ip;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedControl1();
	afx_msg void OnBnClickedControl2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButtonStart();
	CIPAddressCtrl m_ADDRESS_FAT;
	afx_msg void OnBnClickedCheck1();
};
