
// VcSamples2023Dlg.h : header file
//

#pragma once


// CVcSamples2023Dlg dialog
class CVcSamples2023Dlg : public CDialogEx
{
// Construction
public:
	CVcSamples2023Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VCSAMPLES2023_DIALOG };
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
	CBitmap m_bitmapStart;
	CComboBox m_comboBox3;
	CButton m_secondButton;
	CButton m_thirdButton;
	CButton m_checkBox1;
	CButton m_checkBox2;
	CButton m_checkBox3;
	CButton m_checkBox4;
	CButton m_checkBox5;
	CButton m_radioButton1;
	CButton m_radioButton2;
	CButton m_radioButton3;
	CButton m_radioButton4;
	CMFCButton m_firstButton;
	CMFCMenuButton m_menuButton1;
	afx_msg void OnBnClickedMfcbutton1();
	int m_imageLocation;
	int m_iImage;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo4();
	int m_iCursor;
	CString m_toolTip;
	afx_msg void OnBnClickedButton1();
};
