
// lab3_againDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "lab3_again.h"
#include "lab3_againDlg.h"
#include "afxdialogex.h"
#include <cmath>

#define PI 3.14159265358979323846

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// Clab3againDlg dialog



Clab3againDlg::Clab3againDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB3_AGAIN_DIALOG, pParent)
	, method(0)
	, rangeA(0)
	, rangeB(0)
	, resultCalc(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clab3againDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, method);
	DDX_Text(pDX, IDC_EDIT1, rangeA);
	DDX_Text(pDX, IDC_EDIT2, rangeB);
	DDX_Text(pDX, IDC_EDIT3, resultCalc);
}

BEGIN_MESSAGE_MAP(Clab3againDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Clab3againDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Clab3againDlg message handlers

BOOL Clab3againDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Clab3againDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Clab3againDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Clab3againDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


float func(float x) {
	return tan((PI * x) / 3) + x * x - 3;
}

float dfunc(float x) {
	return (PI / 3.0f) * (1 / pow(cos((PI * x) / 3.0f), 2)) + 2.0f * x;
}

float dio(float a, float b, float accuracy) {
	if (func(a) * func(b) >= 0) {
		return -1; // Нет корня или неверный интервал
	}

	float mid = a;

	while ((b - a) >= accuracy) {
		mid = (a + b) / 2.0f;

		if (fabs(func(mid)) <= accuracy)
			break;

		else if (func(mid) * func(a) < 0)
			b = mid;
		else
			a = mid;
	}

	return mid;
}

float newton(float xStart, float accuracy, int maxI) {
	float x = xStart;
	for (int i = 0; i < maxI; ++i) {


		if (fabs(dfunc(x)) < accuracy) {
			return -1;
		}

		float xI = x - func(x) / dfunc(x);

		if (fabs(xI - x) <= accuracy) {
			return xI;
		}

		x = xI;
	}

	return -1;
}

void Clab3againDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);


	float a = rangeA + 0.0f;
	float b = rangeB + 0.0f;
	float accuracy = 0.0001f;
	int maxI = 666;

	if (method) {
		float xStart = (a + b) / 2; // Начальное приближение
		float result = newton(xStart, accuracy, maxI);

		if (result != -1) {
			if (result > 0) {
				resultCalc.Format(_T("%f"), result);
			}
			else {
				resultCalc = _T("Корень не положительный");
			}
		}
		else {
			resultCalc = _T("Корень не найден");
		}
	}
	else {
		float result = dio(a, b, accuracy);

		if (result != -1) {
			resultCalc.Format(_T("%f"), result);
		}
		else {
			resultCalc = _T("Корень не найден");
		}
	}

	UpdateData(FALSE);
}
