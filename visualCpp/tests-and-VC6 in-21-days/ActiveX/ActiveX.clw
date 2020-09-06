; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CActiveXDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ActiveX.h"

ClassCount=3
Class1=CActiveXApp
Class2=CActiveXDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ACTIVEX_DIALOG

[CLS:CActiveXApp]
Type=0
HeaderFile=ActiveX.h
ImplementationFile=ActiveX.cpp
Filter=N

[CLS:CActiveXDlg]
Type=0
HeaderFile=ActiveXDlg.h
ImplementationFile=ActiveXDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_MSFGRID

[CLS:CAboutDlg]
Type=0
HeaderFile=ActiveXDlg.h
ImplementationFile=ActiveXDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ACTIVEX_DIALOG]
Type=1
Class=CActiveXDlg
ControlCount=3
Control1=IDC_EXIT,button,1342242816
Control2=IDC_MSFGRID,{6262D3A0-531B-11CF-91F6-C2863C385E30},1342242816
Control3=IDC_STATIC,static,1342308352

