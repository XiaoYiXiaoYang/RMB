// ToMath.cpp : implementation file
//

#include "stdafx.h"
#include "RMB1.h"
#include "ToMath.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToMath dialog


CToMath::CToMath(CWnd* pParent /*=NULL*/)
	: CDialog(CToMath::IDD, pParent)
{
	//{{AFX_DATA_INIT(CToMath)
	m_str = _T("");
	m_strm = _T("");
	//}}AFX_DATA_INIT
}


void CToMath::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToMath)
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Text(pDX, IDC_EDIT2, m_strm);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CToMath, CDialog)
	//{{AFX_MSG_MAP(CToMath)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_LING_BUTTON, OnLingButton)
	ON_BN_CLICKED(IDC_JIAO_BUTTON, OnJiaoButton)
	ON_BN_CLICKED(IDC_FEN_BUTTON, OnFenButton)
	ON_BN_CLICKED(IDC_YUAN_BUTTON, OnYuanButton)
	ON_BN_CLICKED(IDC_SHI_BUTTON, OnShiButton)
	ON_BN_CLICKED(IDC_BAI_BUTTON, OnBaiButton)
	ON_BN_CLICKED(IDC_QIAN_BUTTON, OnQianButton)
	ON_BN_CLICKED(IDC_WAN_BUTTON2, OnWanButton2)
	ON_BN_CLICKED(IDC_YI_BUTTON2, OnYiButton2)
	ON_BN_CLICKED(IDC_DELETE_BUTTON, OnDeleteButton)
	ON_BN_CLICKED(IDC_TRANSFORM_BUTTON, OnTransformButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
	double num_integer=0.0;//识别位
	double num[5]={0};//亿的和，万的和，个十百千的和，角的和，分的和

void CToMath::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"壹";//字符串显示加汉字
	num_integer=1; //数位令1
	UpdateData(0);	
}

void CToMath::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"贰";
	num_integer=2; 
	UpdateData(0);	
}

void CToMath::OnButton3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"叁";
	num_integer=3;  
	UpdateData(0);	
}

void CToMath::OnButton4() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"肆";
	num_integer=4;  
	UpdateData(0);	
}

void CToMath::OnButton5() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"伍";
	num_integer=5;  
	UpdateData(0);
}

void CToMath::OnButton6() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"陆";
	num_integer=6;  
	UpdateData(0);
}

void CToMath::OnButton7() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"柒";
	num_integer=7;   
	UpdateData(0);
}

void CToMath::OnButton8() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"捌";
	num_integer=8;  
	UpdateData(0);
}

void CToMath::OnButton9() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"玖";
	num_integer=9;  
	UpdateData(0);
}

void CToMath::OnLingButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"零";
	num_integer=0;  
	UpdateData(0);
}

void CToMath::OnJiaoButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"角";
	num[3]=num_integer*0.1;
	UpdateData(0);
}

void CToMath::OnFenButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"分";
	num[4]=num_integer*0.01;
	UpdateData(0);
}

void CToMath::OnYuanButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"圆";
	num[2]=num[2]+num_integer*1;
	num_integer=0;//加完单位清零
	UpdateData(0);	
}

void CToMath::OnShiButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"拾";
	num[2]=num[2]+num_integer*10;
	num_integer=0;//加完单位清零
	UpdateData(0);
}

void CToMath::OnBaiButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"佰";
	num[2]=num[2]+num_integer*100;
	num_integer=0;//加完单位清零
	UpdateData(0);
}

void CToMath::OnQianButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"仟";
	num[2]=num[2]+num_integer*1000;
	num_integer=0;//加完单位清零
	UpdateData(0);
}

void CToMath::OnWanButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"万";
	num[1]=(num[2]+num_integer)*10000;
	num[2]=0;//和清零
	num_integer=0;//加完单位清零
	UpdateData(0);
}

void CToMath::OnYiButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str=m_str+"亿";
	num[0]=(num[2]+num_integer)*100000000;
	num[2]=0;//和清零
	num_integer=0;//加完单位清零
	UpdateData(0);
}

void CToMath::OnDeleteButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_str="";
	m_strm="";
	num_integer=0.0;
	num[0]=0;
	num[1]=0;
	num[2]=0;
	num[3]=0;
	num[4]=0;

	UpdateData(0);
}

void CToMath::OnTransformButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);

	double temp=num[0]+num[1]+num[2]+num[3]+num[4];
	if(temp>0)
	{
	m_strm.Format(_T("%.2lf"),temp);  //double转CSTring
	}
	else
	{
		MessageBox("输入有误","提示");
	}
	
	UpdateData(0);
}

BOOL CToMath::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN) //键盘消息
		{    
		/*if(pMsg -> wParam == VK_ESCAPE)  //键盘上的Esc键
				return TRUE;*/
		     if(pMsg -> wParam == VK_RETURN)   //键盘上的回车键
				return TRUE;
		}

	return CDialog::PreTranslateMessage(pMsg);
}
