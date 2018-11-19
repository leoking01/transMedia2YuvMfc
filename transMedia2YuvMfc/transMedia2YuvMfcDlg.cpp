
// transMedia2YuvMfcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "transMedia2YuvMfc.h"
#include "transMedia2YuvMfcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtransMedia2YuvMfcDlg �Ի���



CtransMedia2YuvMfcDlg::CtransMedia2YuvMfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TRANSMEDIA2YUVMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtransMedia2YuvMfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtransMedia2YuvMfcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CtransMedia2YuvMfcDlg::OnBnClickedButton1_trans2YUV)
	ON_BN_CLICKED(IDC_BUTTON2, &CtransMedia2YuvMfcDlg::OnBnClickedButton2_test_binary_io_align_problm)
END_MESSAGE_MAP()


// CtransMedia2YuvMfcDlg ��Ϣ�������

BOOL CtransMedia2YuvMfcDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CtransMedia2YuvMfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtransMedia2YuvMfcDlg::OnPaint()
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
HCURSOR CtransMedia2YuvMfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtransMedia2YuvMfcDlg::OnBnClickedButton1_trans2YUV()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ��ͼƬ�ļ�
	CString m_strPicPath;
	//IplImage* TheImage;
	CFileDialog dlg(true, _T("*.mp4"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		_T("video(*.mp4,*.avi,*.rmvb,*.rm)|*.mp4;*.avi;*.rmvb;*.rmvb;*.mpg;*.mov;*.dat;*.rm;*.bin;*.mkv|avi(*.avi)|*.avi;rmvb(*.rmvb)|*.rmvb|rm(*.rm)|*.rm|All files(*.*)|*.*"), NULL);//����ѡ��ͼƬ�Ի���
	dlg.m_ofn.lpstrTitle = _T("open video");
	if (dlg.DoModal() != IDOK)
		return;
	m_strPicPath = dlg.GetPathName();
	//append_string_on_edit_controler(IDC_EDIT9, CString("�ļ�������ʾ(���)��m_strPicPath = ") + m_strPicPath);
	//append_string_on_edit_controler(IDC_EDIT9, CString("����Ƶ��") + m_strPicPath);

	if (m_strPicPath.IsEmpty())
	{
		return;
	}

	//�����￪ʼ����ת��������һ���궨��
	USES_CONVERSION;
	//����ת��
	char* keyChar = T2A(m_strPicPath.GetBuffer(0));
	m_strPicPath.ReleaseBuffer();
	//ת�����������ж����ݵĲ���
	//CString value(��������);
	//�����ݽ�����ʾ
	//((CListBox*)GetDlgItem(IDC_LIST1))->AddString(value);
	//append_string_on_edit_controler(IDC_EDIT9, CString("�ļ�������ʾ(���)��CString(str ) = ") + CString(keyChar));

	string  nameFile = string(keyChar ); // "d:/video/Vivo.mp4";
	string  nameFileOut = nameFile + string(".yuv");


	AllocConsole();
	freopen("CONOUT$", "a+", stdout);


	main_ttt(nameFile , nameFileOut  );
	FreeConsole();
	AfxMessageBox(_T("����yuv������ɡ� "));

}



#include<iostream>
#include<fstream>
using namespace std;

#include<iostream>
#include<fstream>
using namespace  std;

int main_write_binaryfile_study()
{

	int count = 0x41424344;
	//write  count(DCBAECBA)   to the file.
	fstream f("liaoZhup.txt.bin", fstream::out | fstream::binary);
	f.write((char *)&count, sizeof(int));
	count++;
	f.write((char *)&count, sizeof(int));
	f.close();

	//read byte by byte.
	f.open("liaoZhup.txt.bin", fstream::in | fstream::binary);
	char ch;
	int fileSize = f.tellg();
	cout << "file beg pos = " << fileSize << endl;
	while (f.good())
	{
		fileSize = f.tellg();
		cout << "pos before read = " << fileSize << endl;
		if (f.read(&ch, sizeof(char)))
		{
			fileSize = f.tellg();
			cout << "pos after read= " << fileSize << endl;
			cout << "read byte = " << ch << endl;
		}
	}
	fileSize = f.tellg();
	cout << "pos after end= " << fileSize << endl;
	f.clear();

	//read once a int.
	f.seekg(0, ios_base::end);
	fileSize = f.tellg();
	cout << "file size = " << fileSize << endl;
	f.seekg(0, ios_base::beg);
	fileSize = f.tellg();
	cout << "file begin = " << fileSize << endl;
	cout << "****read****" << endl;
	while (f.good())
	{
		//if (f.read((char *)&count,sizeof(int)*10))
		if (f.read((char *)&count, sizeof(int)))
		{
			int current = f.tellg();
			cout << "current pos:" << dec << current << endl;
			cout << "count = " << hex << count << endl;
		}
	}
	int current = f.tellg();
	cout << "pos end of read int:" << dec << current << endl;
	cout << "****out of read****" << endl;
	f.close();
	return 0;
}





void CtransMedia2YuvMfcDlg::OnBnClickedButton2_test_binary_io_align_problm()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	std::cout << "This is a test info" << std::endl;
	



	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fstream   of("OnBnClickedButton2_test_binary_io_align_problm.bin", ios::binary| ios::out);

	unsigned  char x1 = 2;
	int x2 = 8;

	of.write((char*)&x2, sizeof(int));
	of.write((char*)&x2, sizeof(int));
	of.write((char*)&x2, sizeof(int));
	of.write((char*)&x2, sizeof(int));


	of.write( (char*)&x1, sizeof(unsigned  char)      );
	of.write((char*)&x1, sizeof(unsigned  char));
	of.write((char*)&x1, sizeof(unsigned  char));
	of.write((char*)&x2, sizeof(  int  ));


	//of.write((char*)&x1, sizeof(unsigned  char));
	//of.write((char*)&x1, sizeof(unsigned  char));
	//of.write((char*)&x1, sizeof(unsigned  char));
	//of.write((char*)&x2, sizeof(int));



	of.close();

	main_write_binaryfile_study();
	cout << "all  finished.  " << endl;

	//system("pause" );
	FreeConsole();
}




