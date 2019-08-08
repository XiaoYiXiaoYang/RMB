#if !defined(AFX_TOCHINESE_H__CD74344B_E3C8_4031_BD34_0D43FA40FF35__INCLUDED_)
#define AFX_TOCHINESE_H__CD74344B_E3C8_4031_BD34_0D43FA40FF35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ToChinese.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CToChinese dialog

class CToChinese : public CDialog
{
// Construction
public:	
	CString erorhandle(CString a,int &flag);
	CString convertWan(int rem,int &quo,int i);
	CString convertFloat(int number);
	CString convertAllNumber(double moneySum);
	CToChinese(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CToChinese)
	enum { IDD = IDD_TOCHINESE_DIALOG };
	CString	m_strc;
	CString	m_str;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToChinese)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CToChinese)
	afx_msg void OnButton01();
	afx_msg void OnButton02();
	afx_msg void OnButton03();
	afx_msg void OnButton04();
	afx_msg void OnButton05();
	afx_msg void OnButton06();
	afx_msg void OnButton07();
	afx_msg void OnButton08();
	afx_msg void OnButton09();
	afx_msg void OnButton00();
	afx_msg void OnPointButton();
	afx_msg void OnDeleteButton2();
	afx_msg void OnTransformButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOCHINESE_H__CD74344B_E3C8_4031_BD34_0D43FA40FF35__INCLUDED_)
