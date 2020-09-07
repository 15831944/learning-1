; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSerializeView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "serialize.h"
LastPage=0

ClassCount=5
Class1=CSerializeApp
Class2=CSerializeDoc
Class3=CSerializeView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_SERIALIZE_FORM (English (U.S.))
Resource4=IDR_MAINFRAME (English (U.S.))
Resource5=IDD_ABOUTBOX (English (U.S.))
Resource6=IDD_SERIALIZE_FORM

[CLS:CSerializeApp]
Type=0
HeaderFile=serialize.h
ImplementationFile=serialize.cpp
Filter=N

[CLS:CSerializeDoc]
Type=0
HeaderFile=serializeDoc.h
ImplementationFile=serializeDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CSerializeDoc

[CLS:CSerializeView]
Type=0
HeaderFile=serializeView.h
ImplementationFile=serializeView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=IDC_RWIDOW


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=serialize.cpp
ImplementationFile=serialize.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_SERIALIZE_FORM]
Type=1
Class=CSerializeView
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_ENAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EAGE,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_RSINGLE,button,1342308361
Control7=IDC_RDIVORCED,button,1342177289
Control8=IDC_RMARRIED,button,1342177289
Control9=IDC_RWIDOW,button,1342177289
Control10=IDC_CBEMPLOYED,button,1342242819
Control11=IDC_BFIRST,button,1342242816
Control12=IDC_BPREV,button,1342242816
Control13=IDC_BNEXT,button,1342242816
Control14=IDC_BLAST,button,1342242816
Control15=IDC_SPOSITION,static,1342308352

[DLG:IDD_SERIALIZE_FORM (English (U.S.))]
Type=1
Class=CSerializeView
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_ENAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EAGE,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_RSINGLE,button,1342308361
Control7=IDC_RDIVORCED,button,1342177289
Control8=IDC_RMARRIED,button,1342177289
Control9=IDC_RWIDOW,button,1342177289
Control10=IDC_CBEMPLOYED,button,1342242819
Control11=IDC_BFIRST,button,1342242816
Control12=IDC_BPREV,button,1342242816
Control13=IDC_BNEXT,button,1342242816
Control14=IDC_BLAST,button,1342242816
Control15=IDC_SPOSITION,static,1342308352

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

