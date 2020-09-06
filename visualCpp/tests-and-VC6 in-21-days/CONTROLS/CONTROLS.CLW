; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CControlsDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "controls.h"

ClassCount=3
Class1=CControlsApp
Class2=CControlsDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CONTROLS_DIALOG

[CLS:CControlsApp]
Type=0
HeaderFile=controls.h
ImplementationFile=controls.cpp
Filter=N

[CLS:CControlsDlg]
Type=0
HeaderFile=controlsDlg.h
ImplementationFile=controlsDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CControlsDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=controlsDlg.h
ImplementationFile=controlsDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CONTROLS_DIALOG]
Type=1
Class=CControlsDlg
ControlCount=6
Control1=IDC_edit,edit,1350631554
Control2=IDC_spindle,msctls_updown32,1342177331
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_slider,msctls_trackbar32,1350631433
Control6=IDC_progress,msctls_progress32,1350565888

