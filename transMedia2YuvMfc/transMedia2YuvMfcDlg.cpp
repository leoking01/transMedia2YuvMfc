
// transMedia2YuvMfcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "transMedia2YuvMfc.h"
#include "transMedia2YuvMfcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CtransMedia2YuvMfcDlg 对话框



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


// CtransMedia2YuvMfcDlg 消息处理程序

BOOL CtransMedia2YuvMfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtransMedia2YuvMfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CtransMedia2YuvMfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtransMedia2YuvMfcDlg::OnBnClickedButton1_trans2YUV()
{
	// TODO: 在此添加控件通知处理程序代码

	// TODO: 在此添加控件通知处理程序代码
	// 打开图片文件
	CString m_strPicPath;
	//IplImage* TheImage;
	CFileDialog dlg(true, _T("*.mp4"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		_T("video(*.mp4,*.avi,*.rmvb,*.rm)|*.mp4;*.avi;*.rmvb;*.rmvb;*.mpg;*.mov;*.dat;*.rm;*.bin;*.mkv|avi(*.avi)|*.avi;rmvb(*.rmvb)|*.rmvb|rm(*.rm)|*.rm|All files(*.*)|*.*"), NULL);//弹出选择图片对话框
	dlg.m_ofn.lpstrTitle = _T("open video");
	if (dlg.DoModal() != IDOK)
		return;
	m_strPicPath = dlg.GetPathName();
	//append_string_on_edit_controler(IDC_EDIT9, CString("文件名称显示(检查)：m_strPicPath = ") + m_strPicPath);
	//append_string_on_edit_controler(IDC_EDIT9, CString("打开视频：") + m_strPicPath);

	if (m_strPicPath.IsEmpty())
	{
		return;
	}

	//从这里开始进行转化，这是一个宏定义
	USES_CONVERSION;
	//进行转换
	char* keyChar = T2A(m_strPicPath.GetBuffer(0));
	m_strPicPath.ReleaseBuffer();
	//转化结束，进行对数据的操作
	//CString value(…………);
	//对数据进行显示
	//((CListBox*)GetDlgItem(IDC_LIST1))->AddString(value);
	//append_string_on_edit_controler(IDC_EDIT9, CString("文件名称显示(检查)：CString(str ) = ") + CString(keyChar));

	string  nameFile = string(keyChar ); // "d:/video/Vivo.mp4";
	string  nameFileOut = nameFile + string(".yuv");


	AllocConsole();
	freopen("CONOUT$", "a+", stdout);


	main_ttt(nameFile , nameFileOut  );
	FreeConsole();
	AfxMessageBox(_T("生成yuv数据完成。 "));

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
	



	// TODO: 在此添加控件通知处理程序代码
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




