; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTimersDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "timers.h"

ClassCount=3
Class1=CTimersApp
Class2=CTimersDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TIMERS_DIALOG

[CLS:CTimersApp]
Type=0
HeaderFile=timers.h
ImplementationFile=timers.cpp
Filter=N

[CLS:CTimersDlg]
Type=0
HeaderFile=timersDlg.h
ImplementationFile=timersDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_STOPTIME

[CLS:CAboutDlg]
Type=0
HeaderFile=timersDlg.h
ImplementationFile=timersDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TIMERS_DIALOG]
Type=1
Class=CTimersDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_INTERVAL,edit,1350631552
Control3=IDC_STARTTIME,button,1342242816
Control4=IDC_STOPTIME,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATICTIME,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATICCOUNT,static,1342308352
Control9=IDC_EXIT,button,1342242816

