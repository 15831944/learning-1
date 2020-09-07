; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDialogsDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "dialogs.h"

ClassCount=4
Class1=CDialogsApp
Class2=CDialogsDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOGS_DIALOG
Class4=CMsgDlg
Resource4=IDD_MESSAGEDLG

[CLS:CDialogsApp]
Type=0
HeaderFile=dialogs.h
ImplementationFile=dialogs.cpp
Filter=N

[CLS:CDialogsDlg]
Type=0
HeaderFile=dialogsDlg.h
ImplementationFile=dialogsDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BWHICHOPTION

[CLS:CAboutDlg]
Type=0
HeaderFile=dialogsDlg.h
ImplementationFile=dialogsDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOGS_DIALOG]
Type=1
Class=CDialogsDlg
ControlCount=8
Control1=IDC_YESNOCANCEL,button,1342242817
Control2=IDC_ABORTRETRYIGNORE,button,1342242816
Control3=IDC_FILEOPEN,button,1342242816
Control4=IDC_BCUSTOMDIALOG,button,1342242816
Control5=IDC_BWHICHOPTION,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_RESULTS,edit,1350631620
Control8=IDC_EXIT,button,1342242816

[DLG:IDD_MESSAGEDLG]
Type=1
Class=CMsgDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_MESSAGE,edit,1350631620
Control5=IDC_STATIC,button,1342177287
Control6=IDC_OPTION1,button,1342308361
Control7=IDC_OPTION2,button,1342177289
Control8=IDC_OPTION3,button,1342177289
Control9=IDC_OPTION4,button,1342177289

[CLS:CMsgDlg]
Type=0
HeaderFile=MsgDlg.h
ImplementationFile=MsgDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMsgDlg

