; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMenusDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "menus.h"

ClassCount=3
Class1=CMenusApp
Class2=CMenusDlg
Class3=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MENUS_DIALOG
Resource4=IDR_MENU1
Resource5=IDD_MENUS_DIALOG (English (U.S.))
Resource6=IDD_ABOUTBOX (English (U.S.))
Resource7=IDR_MENU1 (English (U.S.))

[CLS:CMenusApp]
Type=0
HeaderFile=menus.h
ImplementationFile=menus.cpp
Filter=N

[CLS:CMenusDlg]
Type=0
HeaderFile=menusDlg.h
ImplementationFile=menusDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMenusDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=menusDlg.h
ImplementationFile=menusDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MENUS_DIALOG]
Type=1
Class=CMenusDlg
ControlCount=1
Control1=IDC_EXIT,button,1342242817

[MNU:IDR_MENU1]
Type=1
Class=CMenusDlg
Command1=IDM_FILE_HELLO
Command2=IDM_FILE_EXIT
Command3=ID_HELP_ABOUT
CommandCount=3

[MNU:IDR_MENU1 (English (U.S.))]
Type=1
Class=?
Command1=IDM_FILE_HELLO
Command2=IDM_FILE_EXIT
Command3=ID_HELP_ABOUT
CommandCount=3

[DLG:IDD_MENUS_DIALOG (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_EXIT,button,1342242817

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

