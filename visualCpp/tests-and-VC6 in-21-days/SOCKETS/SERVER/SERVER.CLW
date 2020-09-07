; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CServerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "server.h"

ClassCount=3
Class1=CServerApp
Class2=CServerDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SERVER_DIALOG

[CLS:CServerApp]
Type=0
HeaderFile=server.h
ImplementationFile=server.cpp
Filter=N

[CLS:CServerDlg]
Type=0
HeaderFile=serverDlg.h
ImplementationFile=serverDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CServerDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=serverDlg.h
ImplementationFile=serverDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SERVER_DIALOG]
Type=1
Class=CServerDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_connect,button,1342242816
Control4=IDC_port,edit,1350631552
Control5=IDC_prel,button,1342242816
Control6=IDC_send,edit,1350633600
Control7=IDC_recv,edit,1350633600
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_end,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_error,edit,1350633600

