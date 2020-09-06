; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMouseDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mouse.h"

ClassCount=3
Class1=CMouseApp
Class2=CMouseDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MOUSE_DIALOG

[CLS:CMouseApp]
Type=0
HeaderFile=mouse.h
ImplementationFile=mouse.cpp
Filter=N

[CLS:CMouseDlg]
Type=0
HeaderFile=mouseDlg.h
ImplementationFile=mouseDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMouseDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=mouseDlg.h
ImplementationFile=mouseDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MOUSE_DIALOG]
Type=1
Class=CMouseDlg
ControlCount=0

