; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CToChinese
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RMB1.h"

ClassCount=5
Class1=CRMB1App
Class2=CRMB1Dlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_TOMATH_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_RMB1_DIALOG
Class4=CToMath
Class5=CToChinese
Resource5=IDD_TOCHINESE_DIALOG

[CLS:CRMB1App]
Type=0
HeaderFile=RMB1.h
ImplementationFile=RMB1.cpp
Filter=N

[CLS:CRMB1Dlg]
Type=0
HeaderFile=RMB1Dlg.h
ImplementationFile=RMB1Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CRMB1Dlg

[CLS:CAboutDlg]
Type=0
HeaderFile=RMB1Dlg.h
ImplementationFile=RMB1Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RMB1_DIALOG]
Type=1
Class=CRMB1Dlg
ControlCount=3
Control1=IDC_TOCHINESE_BUTTON1,button,1342242817
Control2=IDC_TOMATH_BUTTON,button,1342242817
Control3=IDCANCEL,button,1342242817

[DLG:IDD_TOMATH_DIALOG]
Type=1
Class=CToMath
ControlCount=25
Control1=IDCANCEL,button,1342242816
Control2=IDC_EDIT1,edit,1350633600
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_BUTTON3,button,1342242816
Control6=IDC_BUTTON4,button,1342242816
Control7=IDC_BUTTON5,button,1342242816
Control8=IDC_BUTTON6,button,1342242816
Control9=IDC_BUTTON7,button,1342242816
Control10=IDC_BUTTON8,button,1342242816
Control11=IDC_BUTTON9,button,1342242816
Control12=IDC_YUAN_BUTTON,button,1342242816
Control13=IDC_SHI_BUTTON,button,1342242816
Control14=IDC_BAI_BUTTON,button,1342242816
Control15=IDC_QIAN_BUTTON,button,1342242816
Control16=IDC_WAN_BUTTON2,button,1342242816
Control17=IDC_YI_BUTTON2,button,1342242816
Control18=IDC_LING_BUTTON,button,1342242816
Control19=IDC_JIAO_BUTTON,button,1342242816
Control20=IDC_FEN_BUTTON,button,1342242816
Control21=IDC_DELETE_BUTTON,button,1342242816
Control22=IDC_TRANSFORM_BUTTON,button,1342242816
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_EDIT2,edit,1350633600

[DLG:IDD_TOCHINESE_DIALOG]
Type=1
Class=CToChinese
ControlCount=18
Control1=IDC_EDIT1,edit,1350633600
Control2=IDC_EDIT2,edit,1350633600
Control3=IDC_BUTTON01,button,1342242816
Control4=IDC_BUTTON02,button,1342242816
Control5=IDC_BUTTON03,button,1342242816
Control6=IDC_BUTTON04,button,1342242816
Control7=IDC_BUTTON05,button,1342242816
Control8=IDC_BUTTON06,button,1342242816
Control9=IDC_BUTTON07,button,1342242816
Control10=IDC_BUTTON08,button,1342242816
Control11=IDC_BUTTON09,button,1342242816
Control12=IDC_BUTTON00,button,1342242816
Control13=IDC_POINT_BUTTON,button,1342242816
Control14=IDC_DELETE_BUTTON2,button,1342242816
Control15=IDC_TRANSFORM_BUTTON,button,1342242816
Control16=IDCANCEL,button,1342242816
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352

[CLS:CToMath]
Type=0
HeaderFile=ToMath.h
ImplementationFile=ToMath.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT2
VirtualFilter=dWC

[CLS:CToChinese]
Type=0
HeaderFile=ToChinese.h
ImplementationFile=ToChinese.cpp
BaseClass=CDialog
Filter=D
LastObject=CToChinese
VirtualFilter=dWC

