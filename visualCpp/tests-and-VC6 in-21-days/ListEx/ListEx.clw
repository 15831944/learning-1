; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CListExDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ListEx.h"

ClassCount=3
Class1=CListExApp
Class2=CListExDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_LISTEX_DIALOG

[CLS:CListExApp]
Type=0
HeaderFile=ListEx.h
ImplementationFile=ListEx.cpp
Filter=N

[CLS:CListExDlg]
Type=0
HeaderFile=ListExDlg.h
ImplementationFile=ListExDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_RADIO_SMALL

[CLS:CAboutDlg]
Type=0
HeaderFile=ListExDlg.h
ImplementationFile=ListExDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LISTEX_DIALOG]
Type=1
Class=CListExDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_lista,SysListView32,1350631424
Control4=IDC_STATIC,button,1342177287
Control5=IDC_RADIO_ICON,button,1342177289
Control6=IDC_RADIO_SMALL,button,1342177289
Control7=IDC_RADIO_LIST,button,1342177289
Control8=IDC_RADIO_REPORT,button,1342177289

