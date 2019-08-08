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
CString Bignumber[19]= {"Ҽ","��","��","��","��","½","��","��","��","��"};
CString Bigdanwei[13]={"Ǫ","��","ʰ"};
CString Bigfloat[6]={"��","��"};
CString BigDivide[10]={"Ԫ","��","��"};

CString CToChinese::convertWan(int rem, int &quo, int i)
{
	CString strnumber="";
	if(rem==0)//����Ϊ0���򲻼��򣬲�����
	{
		i=-1;
	}
    int divisor=0;       //����
	int quotient=rem/1000;//ǧλ������

	//�������λ��ǧλ�Ƿ����
	if((rem/1000==0)&&(quo!=0)&&rem!=0)//ǧλΪ�㣬��λ��Ϊ�㣬���㣬��������Ϊ��ʱ������
	{
		strnumber=strnumber+Bignumber[9];
	}

    int before_quotient=0;//��һλ�������ǲ���0
    for(int j=3;j>=0;j--)
    {
        divisor=(int)pow(10,j);
        quotient=rem/divisor;

		//�������λ�����ж�
        if(quotient==0)
        {
			if(before_quotient!=0&&j!=3&&rem%divisor!=0)//������ǧλ
				//ȡ�࣬��λ��һλ֮���в�Ϊ���λ�ż���
            {
			   strnumber=strnumber+Bignumber[9];//����
			}
			before_quotient=0;
        }


		if(quotient!=0)
        {
			before_quotient=quotient;//��һλ����Ϊ��
			//�Ӻ���
            strnumber=strnumber+Bignumber[quotient-1];
			strnumber=strnumber+Bigdanwei[3-j];
        }
        rem=rem%divisor;//��������
    }
switch(i)
        {
        case 1:
			strnumber=strnumber+BigDivide[1];//����
            break;
        case 2:
			strnumber=strnumber+BigDivide[2];  //����
            break;
		default:
			break;
        }
    return strnumber;
}

CString CToChinese::convertFloat(int number)
{
	CString strfloat="";
	int reminder=0;//����
	int quotient=0;//��
	for(int i=1;i>=0;i--)
	{
		int divisor=(int)pow(10,i);
		quotient=number/divisor;
		if(quotient!=0)
		{
		    //�Ӻ���
			strfloat=strfloat+Bignumber[quotient-1];
			strfloat=strfloat+Bigfloat[1-i];
			//����
			reminder = number%divisor;
			number=reminder;
		}
	}
	return strfloat;
}
CString CToChinese::convertAllNumber(double moneySum)
{
	CString result=""; //����ַ���
	int tempi = int(moneySum+0.001);  //��������
    double tempf = moneySum - tempi+0.001; // С������
	int tempfi=int(tempf*100);//��С��ת��Ϊ����

	
    int reminder=tempi%10000;//����
    int quotient=tempi/10000;//��

    int i=0;    //��λһ�δ���Ĵ������
    while(tempi>0)
    {
        //������λ����
		CString temp=convertWan(reminder,quotient,i);
        //����i��ֵ�� ���iΪ1���������iΪ2���ڣ�iΪ0��Բ
        if(i==0)
        {
			temp=temp+BigDivide[0];//��Բ
        }
		result=temp+result;

        if(quotient==0)
            break;//�����Ϊ0����ѭ��
        //���ݸ���
        tempi=quotient;
        reminder=tempi%10000;
        quotient=tempi/10000;
        i++;
    }

    //С������
    if(tempfi>0)
    {
        result=result+convertFloat(tempfi);
    }
    else
    {
        result=result+"��";
    }
	return result;
}

CString CToChinese::erorhandle(CString a,int &flag) //��������
{
		//�����ж��ַ�����ȷ�ԣ�1.�ַ���̫����2.�ַ������������̫��
	CString temp="";
	if(a.GetLength()>13)
	{
		temp="�������ȣ�����ת��";
		flag++;
	}
	 else if(1)
	{
		int flag2=-1;//��ֵ-1�������δ���С��������������
		for(int i=0;i<a.GetLength();i++)
		{
			switch(a[i])//�ж���û��С����
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
				temp="���벻�淶";
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
	double temp1 = atof(m_strc);              //CStringתΪdouble
	CString temp2=convertAllNumber(temp1);
	m_str=temp2;
	}
	else
		MessageBox("�������󣬲���ת��","��ʾ");
	}
	else
		MessageBox("�������󣬲���ת��","��ʾ");
		
	
	UpdateData(0);
}


BOOL CToChinese::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN) //������Ϣ
		{    
		/*if(pMsg -> wParam == VK_ESCAPE)  //�����ϵ�Esc��
				return TRUE;*/
		     if(pMsg -> wParam == VK_RETURN)   //�����ϵĻس���
				return TRUE;
		}

	return CDialog::PreTranslateMessage(pMsg);
}
