// RMB1Dlg.h : header file
//

#if !defined(AFX_RMB1DLG_H__A1DC58ED_A5A2_435C_B273_CC9B941700F5__INCLUDED_)
#define AFX_RMB1DLG_H__A1DC58ED_A5A2_435C_B273_CC9B941700F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRMB1Dlg dialog

class CRMB1Dlg : public CDialog
{

// Construction
public:
	CRMB1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRMB1Dlg)
	enum { IDD = IDD_RMB1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRMB1Dlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRMB1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTomathButton();
	afx_msg void OnTochineseButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMB1DLG_H__A1DC58ED_A5A2_435C_B273_CC9B941700F5__INCLUDED_)
