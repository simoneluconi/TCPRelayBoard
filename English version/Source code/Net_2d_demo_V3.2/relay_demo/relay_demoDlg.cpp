
// relay_demoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "relay_demo.h"
#include "relay_demoDlg.h"
#include "afxdialogex.h"

#include "winsock2.h"

#pragma comment(lib, "ws2_32.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Crelay_demoDlg �Ի���




Crelay_demoDlg::Crelay_demoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Crelay_demoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Crelay_demoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS1, m_ADDRESS_FAT);
}

BEGIN_MESSAGE_MAP(Crelay_demoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONTROL1, &Crelay_demoDlg::OnBnClickedControl1)
	ON_BN_CLICKED(IDC_CONTROL2, &Crelay_demoDlg::OnBnClickedControl2)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_START, &Crelay_demoDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_CHECK1, &Crelay_demoDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// Crelay_demoDlg ��Ϣ�������

BOOL Crelay_demoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	char szBuff[10] = "";
	char szBuff_dns[20] = "";
	char szBuff_farip[20] = "";
	char i,j_dian;
	unsigned char rip1,rip2,rip3,rip4;
	unsigned char p1lo,p2lo,p3lo,p4lo;
	int buffer_farip;
	file_port.Open("port.txt",CFile::modeRead);
    file_port.Read(szBuff,10); 
    file_port.Close();
	CString str = szBuff; 
	SetDlgItemText(IDC_EDIT_LOCAL_PORT,str);

	file_dns.Open("dns.txt",CFile::modeRead);
    file_dns.Read(szBuff_dns,20); 
    file_dns.Close();
	str=szBuff_dns;
	SetDlgItemText(IDC_EDIT_DNS,str);

	file_ip.Open("farip.txt",CFile::modeRead);
    file_ip.Read(szBuff_farip,15);
    file_ip.Close();
	//str=szBuff_farip;
	j_dian=0;
	for(i=0;i<21;i++)
	 {
     if(szBuff_farip[i]=='.')
	  {
        j_dian++;
		if(j_dian==1)
		{
		  if(i==1)
		  {
            rip1=szBuff_farip[i-1]-0x30;
		  }
		  else if(i==2)
		  {
            rip1=(szBuff_farip[i-2]-0x30)*10+(szBuff_farip[i-1]-0x30);
		  }
		  else if(i==3)
		  {
            rip1=(szBuff_farip[i-3]-0x30)*100+(szBuff_farip[i-2]-0x30)*10+(szBuff_farip[i-1]-0x30);
		  }
		  p1lo=i;
		}

		else if(j_dian==2)
		{
		  if((i-p1lo-1)==1)
		  {
            rip2=szBuff_farip[i-1]-0x30;
		  }
		  else if((i-p1lo-1)==2)
		  {
            rip2=(szBuff_farip[i-2]-0x30)*10+(szBuff_farip[i-1]-0x30);
		  }
		  else if((i-p1lo-1)==3)
		  {
            rip2=(szBuff_farip[i-3]-0x30)*100+(szBuff_farip[i-2]-0x30)*10+(szBuff_farip[i-1]-0x30);
		  }
		  p2lo=i;
		}

		else if(j_dian==3)
		{
		  if((i-p2lo-1)==1)
		  {
            rip3=szBuff_farip[i-1]-0x30;
		  }
		  else if((i-p2lo-1)==2)
		  {
            rip3=(szBuff_farip[i-2]-0x30)*10+(szBuff_farip[i-1]-0x30);
		  }
		  else if((i-p2lo-1)==3)
		  {
            rip3=(szBuff_farip[i-3]-0x30)*100+(szBuff_farip[i-2]-0x30)*10+(szBuff_farip[i-1]-0x30);
		  }
		  p3lo=i;
		}

		else if(j_dian==4)
		{
		  if((i-p3lo-1)==1)
		  {
            rip4=szBuff_farip[i-1]-0x30;
		  }
		  else if((i-p3lo-1)==2)
		  {
            rip4=(szBuff_farip[i-2]-0x30)*10+(szBuff_farip[i-1]-0x30);
		  }
		  else if((i-p3lo-1)==3)
		  {
            rip4=(szBuff_farip[i-3]-0x30)*100+(szBuff_farip[i-2]-0x30)*10+(szBuff_farip[i-1]-0x30);
		  }
		  break;
		}

	  }

	}

	m_ADDRESS_FAT.SetAddress(rip1,rip2,rip3,rip4);


	relay1=0;
	relay2=0;


	relay_status=1;
	start_net=0;
	sent_con=0;
	SetTimer(1,2000,0);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Crelay_demoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Crelay_demoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Crelay_demoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Crelay_demoDlg::OnReceive(MySocket *psock)
{
  char RcvBuffer[200];
  CString SAddress;
  unsigned int port;
  //MessageBox("���óɹ�");
  psock->ReceiveFrom(RcvBuffer,8192,SAddress,port,0);
  if((RcvBuffer[0]=='o')&&(RcvBuffer[1]=='n'))//relay1
  {
    if(RcvBuffer[2]=='1')
	{
      SetDlgItemText(IDC_RE_ST1, _T("open"));
	  GetDlgItem(IDC_CONTROL1)->SetWindowText("close");
	  relay1=1;
	}
	if(RcvBuffer[2]=='2')//relay2
	{
      SetDlgItemText(IDC_RE_ST2, _T("open"));
	  GetDlgItem(IDC_CONTROL2)->SetWindowText("close");
	  relay2=1;
	}
	net_check=0;
  }
  else if((RcvBuffer[0]=='o')&&(RcvBuffer[1]=='f')&&(RcvBuffer[2]=='f'))//
  {
    if(RcvBuffer[3]=='1')
	{
      SetDlgItemText(IDC_RE_ST1, _T("close"));
	  GetDlgItem(IDC_CONTROL1)->SetWindowText("open");
	  relay1=0;
	}
    else if(RcvBuffer[3]=='2')
	{
      SetDlgItemText(IDC_RE_ST2, _T("close"));
	  GetDlgItem(IDC_CONTROL2)->SetWindowText("open");
	  relay2=0;
	}
   net_check=0;
  }	

}

void Crelay_demoDlg::OnBnClickedControl1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(start_net)
	{
		if(relay1==0)
		{
		  GetDlgItem(IDC_CONTROL1)->SetWindowText("close");
		  m_MySocket->SendTo("on1:00",6,far_port,far_IP,0);
		  relay1=1;
		}
		else
		{
		  GetDlgItem(IDC_CONTROL1)->SetWindowText("open");
		  m_MySocket->SendTo("off1",4,far_port,far_IP,0);
		  relay1=0;
		}
	 }
}


void Crelay_demoDlg::OnBnClickedControl2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(start_net)
	{
	  if(relay2==0)
		{
		  GetDlgItem(IDC_CONTROL2)->SetWindowText("close");
		  m_MySocket->SendTo("on2:00",6,far_port,far_IP,0);
		  relay2=1;
		}
		else
		{
		  GetDlgItem(IDC_CONTROL2)->SetWindowText("open");
		  m_MySocket->SendTo("off2",4,far_port,far_IP,0);
		  relay2=0;
		}
	}
}









void Crelay_demoDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnTimer(nIDEvent);
	if(start_net)
	{
		if(net_check)
		{
		   GetDlgItem(IDC_NET_STATUS)->SetWindowText("no connect");
          
		  /*
		   if(status_dns==1)//ѡ��DNS
		   {
              m_MySocket->Close();

              GetDlgItemText(IDC_EDIT_DNS,m_DomainName);
	          /* socket DLL��ʼ�� *
	          WSAStartup(MAKEWORD(2, 0), &wsaData);
			  host = gethostbyname(m_DomainName);
			  far_IP = (char *)inet_ntoa(*(struct in_addr *)(host->h_addr));
	          WSACleanup( );

			  m_MySocket=new MySocket(this);
	          m_MySocket->Create(5000,SOCK_DGRAM);
	          m_MySocket->Bind(far_port,far_IP);
		   }*/
	   
		}
		else
		   GetDlgItem(IDC_NET_STATUS)->SetWindowText("connect");
		
		if(sent_con==0)
		{
		  m_MySocket->SendTo("read1",5,far_port,far_IP,0);
          sent_con=1;
		}
		else if(sent_con==1)
		{
          m_MySocket->SendTo("read2",5,far_port,far_IP,0);
          sent_con=0;
		}
		net_check=1;
		
		
	}
}

CSocket aSocket;

void Crelay_demoDlg::OnBnClickedButtonStart()
{
	// TODO: 
	//m_DomainName="huang2048.oicp.net";
	CString	m_IPAddress;
	CString strTemp,str1,str2,str3,str4;
	unsigned char Buffer[256];
	
	
	 //MessageBox(TEXT("HELLO!"),NULL,MB_OK);//��ȡ�豸�˿ں�
	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK_DNS))->GetCheck()) 
	{
       status_dns=1;//ѡ��DNS
	   GetDlgItemText(IDC_EDIT_DNS,m_DomainName);
	   /* socket DLL��ʼ�� */
	   WSAStartup(MAKEWORD(2, 0), &wsaData);
	   host = gethostbyname(m_DomainName);
	   far_IP = (char *)inet_ntoa(*(struct in_addr *)(host->h_addr));
	   WSACleanup( );
	}
	if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK_DNS))->GetCheck()) 
	{
       status_dns=0;//δѡ��DNS
	   GetDlgItemText(IDC_EDIT_DNS,m_DomainName);
	}
	if(start_net==0)
	{
      start_net=1;
	  GetDlgItem(IDC_BUTTON_START)->SetWindowText("disconnect");
	  GetDlgItemText(IDC_EDIT_LOCAL_PORT,strTemp);
	  m_ADDRESS_FAT.GetAddress(Buffer[0],Buffer[1],Buffer[2],Buffer[3]);
	  str1.Format("%d",Buffer[0]);
	  str2.Format("%d",Buffer[1]);
	  str3.Format("%d",Buffer[2]);
	  str4.Format("%d",Buffer[3]);
	  if(status_dns==0)
	  {
	   far_IP=str1+"."+str2+"."+str3+"."+str4;
	  }
	  far_port=atoi(strTemp);
	  m_MySocket=new MySocket(this);
	  //m_MySocket->Create(5000,SOCK_DGRAM);
	  //m_MySocket->Bind(far_port,far_IP);

	  m_MySocket->Create();
	  m_MySocket->Connect(far_IP,far_port);
	  //��ȡԶ��IP

	  if(status_dns==0)
		{
			file_ip.Remove("farip.txt");
			file_ip.Open("farip.txt",CFile::modeWrite|CFile::modeCreate);
			str1=far_IP+'.';
			file_ip.Write(str1,str1.GetLength());
			file_ip.Close();
		}
	  file_dns.Remove("dns.txt");
	  file_dns.Open("dns.txt",CFile::modeWrite|CFile::modeCreate);
      file_dns.Write(m_DomainName,m_DomainName.GetLength());
      file_dns.Close();

	  file_port.Remove("port.txt");
	  file_port.Open("port.txt",CFile::modeWrite|CFile::modeCreate);
      file_port.Write(strTemp,strTemp.GetLength());
      file_port.Close();
     
	}
	else
	{
      start_net=0;
	  GetDlgItem(IDC_BUTTON_START)->SetWindowText("connect");
	  m_MySocket->Close();
	  GetDlgItem(IDC_NET_STATUS)->SetWindowText("no connect");
	}

   

	
}



void Crelay_demoDlg::OnBnClickedCheck1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//MessageBox(TEXT("HELLO!"),NULL,MB_OK);//��ȡ�豸�˿ں�
}
