#if !defined(AFX_TOMATH_H__00355D4F_01AF_4E88_986E_92AC4833E633__INCLUDED_)
#define AFX_TOMATH_H__00355D4F_01AF_4E88_986E_92AC4833E633__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ToMath.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CToMath dialog

class CToMath : public CDialog
{

// Construction
public:

	CToMath(CWnd* pParent = NULL);   // standard constructor
// CToMath message handlers

// Dialog Data
	//{{AFX_DATA(CToMath)
	enum { IDD = IDD_TOMATH_DIALOG };
	CString	m_str;
	CString	m_strm;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToMath)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CToMath)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnLingButton();
	afx_msg void OnJiaoButton();
	afx_msg void OnFenButton();
	afx_msg void OnYuanButton();
	afx_msg void OnShiButton();
	afx_msg void OnBaiButton();
	afx_msg void OnQianButton();
	afx_msg void OnWanButton2();
	afx_msg void OnYiButton2();
	afx_msg void OnDeleteButton();
	afx_msg void OnTransformButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOMATH_H__00355D4F_01AF_4E88_986E_92AC4833E633__INCLUDED_)
