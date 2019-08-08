// ToChinese.cpp : implementation file
//

#include "stdafx.h"
#include "RMB1.h"
#include "ToChinese.h"
#include<cmath>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToChinese dialog


CToChinese::CToChinese(CWnd* pParent /*=NULL*/)
	: CDialog(CToChinese::IDD, pParent)
{
	//{{AFX_DATA_INIT(CToChinese)
	m_strc = _T("");
	m_str = _T("");
	//}}AFX_DATA_INIT
}


void CToChinese::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToChinese)
	DDX_Text(pDX, IDC_EDIT1, m_strc);
	DDX_Text(pDX, IDC_EDIT2, m_str);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CToChinese, CDialog)
	//{{AFX_MSG_MAP(CToChinese)
	ON_BN_CLICKED(IDC_BUTTON01, OnButton01)
	ON_BN_CLICKED(IDC_BUTTON02, OnButton02)
	ON_BN_CLICKED(IDC_BUTTON03, OnButton03)
	ON_BN_CLICKED(IDC_BUTTON04, OnButton04)
	ON_BN_CLICKED(IDC_BUTTON05, OnButton05)
	ON_BN_CLICKED(IDC_BUTTON06, OnButton06)
	ON_BN_CLICKED(IDC_BUTTON07, OnButton07)
	ON_BN_CLICKED(IDC_BUTTON08, OnButton08)
	ON_BN_CLICKED(IDC_BUTTON09, OnButton09)
	ON_BN_CLICKED(IDC_BUTTON00, OnButton00)
	ON_BN_CLICKED(IDC_POINT_BUTTON, OnPointButton)
	ON_BN_CLICKED(IDC_DELETE_BUTTON2, OnDeleteButton2)
	ON_BN_CLICKED(IDC_TRANSFORM_BUTTON, OnTransformButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToChinese message handlers
CString Bignumber[19]= {"壹","贰","叁","肆","伍","陆","柒","捌","玖","零"};
CString Bigdanwei[13]={"仟","佰","拾"};
CString Bigfloat[6]={"角","分"};
CString BigDivide[10]={"元","万","亿"};

CString CToChinese::convertWan(int rem, int &quo, int i)
{
	CString strnumber="";
	if(rem==0)//余数为0，则不加万，不加亿
	{
		i=-1;
	}
    int divisor=0;       //除数
	int quotient=rem/1000;//千位的数字

	//传入的四位数千位是否加零
	if((rem/1000==0)&&(quo!=0)&&rem!=0)//千位为零，万位不为零，加零，整个数都为零时不加零
	{
		strnumber=strnumber+Bignumber[9];
	}

    int before_quotient=0;//高一位的数字是不是0
    for(int j=3;j>=0;j--)
    {
        divisor=(int)pow(10,j);
        quotient=rem/divisor;

		//传入的四位数都判断
        if(quotient==0)
        {
			if(before_quotient!=0&&j!=3&&rem%divisor!=0)//不能是千位
				//取余，百位这一位之后有不为零的位才加零
            {
			   strnumber=strnumber+Bignumber[9];//加零
			}
			before_quotient=0;
        }


		if(quotient!=0)
        {
			before_quotient=quotient;//上一位更新为商
			//加汉字
            strnumber=strnumber+Bignumber[quotient-1];
			strnumber=strnumber+Bigdanwei[3-j];
        }
        rem=rem%divisor;//更新余数
    }
switch(i)
        {
        case 1:
			strnumber=strnumber+BigDivide[1];//加万
            break;
        case 2:
			strnumber=strnumber+BigDivide[2];  //加亿
            break;
		default:
			break;
        }
    return strnumber;
}

CString CToChinese::convertFloat(int number)
{
	CString strfloat="";
	int reminder=0;//余数
	int quotient=0;//商
	for(int i=1;i>=0;i--)
	{
		int divisor=(int)pow(10,i);
		quotient=number/divisor;
		if(quotient!=0)
		{
		    //加汉字
			strfloat=strfloat+Bignumber[quotient-1];
			strfloat=strfloat+Bigfloat[1-i];
			//更新
			reminder = number%divisor;
			number=reminder;
		}
	}
	return strfloat;
}
CString CToChinese::convertAllNumber(double moneySum)
{
	CString result=""; //结果字符串
	int tempi = int(moneySum+0.001);  //整数部分
    double tempf = moneySum - tempi+0.001; // 小数部分
	int tempfi=int(tempf*100);//将小数转化为整数

	
    int reminder=tempi%10000;//余数
    int quotient=tempi/10000;//商

    int i=0;    //四位一次处理的处理次数
    while(tempi>0)
    {
        //操作万位以下
		CString temp=convertWan(reminder,quotient,i);
        //根据i的值， 如果i为1，加万，如果i为2加亿，i为0加圆
        if(i==0)
        {
			temp=temp+BigDivide[0];//加圆
        }
		result=temp+result;

        if(quotient==0)
            break;//如果商为0跳出循环
        //数据更新
        tempi=quotient;
        reminder=tempi%10000;
        quotient=tempi/10000;
        i++;
    }

    //小数部分
    if(tempfi>0)
    {
        result=result+convertFloat(tempfi);
    }
    else
    {
        result=result+"整";
    }
	return result;
}

CString CToChinese::erorhandle(CString a,int &flag) //错误处理函数
{
		//首先判断字符串正确性，1.字符串太长，2.字符串错误，输入点太多
	CString temp="";
	if(a.GetLength()>13)
	{
		temp="超出长度，不能转换";
		flag++;
	}
	 else if(1)
	{
		int flag2=-1;//赋值-1，加两次代表小数点有两个以上
		for(int i=0;i<a.GetLength();i++)
		{
			switch(a[i])//判断有没有小数点
			{
			case '.':
				{
				flag2++;
				}
			default:
				break;
			}
			if(flag2>0)
			{
				temp="输入不规范";
				flag=1;
			}
		}
	}
	
	return temp;
}

void CToChinese::OnButton01() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_strc=m_strc+"1";
	UpdateData(0);
}

void CToChinese::OnButton02() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_strc=m_strc+"2";
	UpdateData(0);
}

void CToChinese::OnButton03() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_strc=m_strc+"3";
	UpdateData(0);
}

void CToChinese::OnButton04() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_strc=m_strc+"4";
	UpdateData(0);
}

void CToChinese::OnButton05() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_strc=m_strc+"5";
	UpdateData(0);
}

void CToChinese::OnButton06() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_strc=m_strc+"6";
	UpdateData(0);
}

void CToChinese::OnButton07() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_strc=m_strc+"7";
	UpdateData(0);
}

void CToChinese::OnButton08() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_strc=m_strc+"8";
	UpdateData(0);
}

void CToChinese::OnButton09() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_strc=m_strc+"9";
	UpdateData(0);
}

void CToChinese::OnButton00() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_strc=m_strc+"0";
	UpdateData(0);
}

void CToChinese::OnPointButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_strc=m_strc+".";
	UpdateData(0);
}

void CToChinese::OnDeleteButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	m_strc="";
	m_str="";
	UpdateData(0);
}

void CToChinese::OnTransformButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);

	int flag=0;
	m_str=erorhandle(m_strc,flag);
	if(flag==0)
	{
	if(atof(m_strc))
	{
	double temp1 = atof(m_strc);              //CString转为double
	CString temp2=convertAllNumber(temp1);
	m_str=temp2;
	}
	else
		MessageBox("输入有误，不能转换","提示");
	}
	else
		MessageBox("输入有误，不能转换","提示");
		
	
	UpdateData(0);
}


BOOL CToChinese::PreTranslateMessage(MSG* pMsg) 
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
