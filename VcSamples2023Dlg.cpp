
// VcSamples2023Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "VcSamples2023.h"
#include "VcSamples2023Dlg.h"
#include "afxdialogex.h"


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


// CVcSamples2023Dlg dialog



CVcSamples2023Dlg::CVcSamples2023Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VCSAMPLES2023_DIALOG, pParent)
	, m_iCursor(0)
	, m_toolTip(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVcSamples2023Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO3, m_comboBox3);
	DDX_Control(pDX, IDC_BUTTON1, m_secondButton);
	DDX_Control(pDX, IDC_BUTTON2, m_thirdButton);
	DDX_Control(pDX, IDC_CHECK2, m_checkBox1);
	DDX_Control(pDX, IDC_CHECK4, m_checkBox2);
	DDX_Control(pDX, IDC_CHECK3, m_checkBox3);
	DDX_Control(pDX, IDCANCEL, m_checkBox4);
	DDX_Control(pDX, IDC_CHECK5, m_checkBox5);
	DDX_Control(pDX, IDC_RADIO1, m_radioButton1);
	DDX_Control(pDX, IDC_RADIO2, m_radioButton2);
	DDX_Control(pDX, IDC_RADIO3, m_radioButton3);
	DDX_Control(pDX, IDC_RADIO4, m_radioButton4);
	DDX_Control(pDX, IDC_MFCBUTTON1, m_firstButton);
	DDX_Control(pDX, IDC_MFCMENUBUTTON1, m_menuButton1);
	DDX_CBIndex(pDX, IDC_COMBO1, m_imageLocation);
	DDX_CBIndex(pDX, IDC_COMBO2, m_iImage);
	DDX_CBIndex(pDX, IDC_CURSOR, m_iCursor);
	DDX_Text(pDX, IDC_EDIT1, m_toolTip);
}

BEGIN_MESSAGE_MAP(CVcSamples2023Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CVcSamples2023Dlg::OnBnClickedMfcbutton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CVcSamples2023Dlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CVcSamples2023Dlg::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_CURSOR, &CVcSamples2023Dlg::OnCbnSelchangeCombo4)
	ON_BN_CLICKED(IDC_BUTTON1, &CVcSamples2023Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CVcSamples2023Dlg message handlers

BOOL CVcSamples2023Dlg::OnInitDialog()
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

	//m_bitmapStart.LoadBitmap(IDB_BITMAP2);
	//HBITMAP hBitmap = (HBITMAP)m_bitmapStart.GetSafeHandle();
	//m_firstButton.SetBitmap(hBitmap);

	m_firstButton.SetImage(IDB_BITMAP2);
	
	m_imageLocation = 0;
	m_iImage = 2;
	m_iCursor = 0;

	m_firstButton.m_bTransparent = true;


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVcSamples2023Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CVcSamples2023Dlg::OnPaint()
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
HCURSOR CVcSamples2023Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CVcSamples2023Dlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here

	UpdateData();

	switch (m_imageLocation)
	{
	case 0:
		m_firstButton.m_bRightImage = FALSE;
		m_firstButton.m_bTopImage = FALSE;
		break;

	case 1:
		m_firstButton.m_bRightImage = TRUE;
		m_firstButton.m_bTopImage = FALSE;
		break;

	case 2:
		m_firstButton.m_bRightImage = FALSE;
		m_firstButton.m_bTopImage = TRUE;
		break;
	}

	m_firstButton.SizeToContent();
	m_firstButton.Invalidate();
}


void CVcSamples2023Dlg::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here

	MessageBox(_T("Button Clicked"));
}




void CVcSamples2023Dlg::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here

	UpdateData();

	if (m_iImage == 0) {

		m_firstButton.SetWindowTextW(_T(""));
		m_firstButton.SetImage(IDB_BITMAP2);
	}
	else if (m_iImage == 1) {

		m_firstButton.SetImage((HBITMAP) NULL);
		m_firstButton.SetWindowTextW(_T("Button"));
	}
	else {
		m_firstButton.SetWindowText(_T("Button"));
		m_firstButton.SetImage(IDB_BITMAP2);
	}

	m_firstButton.SizeToContent();
	m_firstButton.Invalidate();
}


void CVcSamples2023Dlg::OnCbnSelchangeCombo4()
{
	// TODO: Add your control notification handler code here

	UpdateData();

	if (m_iCursor == 1) {

		m_firstButton.SetMouseCursorHand();
	}
	else if (m_iCursor == 2) {

		m_firstButton.SetMouseCursor(AfxGetApp()->LoadCursor(IDC_CURSOR));
	}
	else {
		m_firstButton.SetMouseCursor(NULL);
	}
}


void CVcSamples2023Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	UpdateData();

	m_firstButton.SetTooltip(m_toolTip);
}
