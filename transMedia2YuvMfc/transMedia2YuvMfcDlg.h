
// transMedia2YuvMfcDlg.h : ͷ�ļ�
//

#pragma once


// CtransMedia2YuvMfcDlg �Ի���
class CtransMedia2YuvMfcDlg : public CDialogEx
{
// ����
public:
	CtransMedia2YuvMfcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRANSMEDIA2YUVMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1_trans2YUV();
	afx_msg void OnBnClickedButton2_test_binary_io_align_problm();
};
