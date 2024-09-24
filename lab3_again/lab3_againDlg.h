
// lab3_againDlg.h : header file
//

#pragma once


// Clab3againDlg dialog
class Clab3againDlg : public CDialogEx
{
// Construction
public:
	Clab3againDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB3_AGAIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int method;
	int rangeA;
	int rangeB;
	CString resultCalc;
	afx_msg void OnBnClickedButton1();
};
