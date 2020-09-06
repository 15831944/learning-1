; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFormTest
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MDI.h"
LastPage=0

ClassCount=7
Class1=CMDIApp
Class2=CMDIDoc
Class3=CMDIView
Class4=CMainFrame

ResourceCount=5
Resource1=IDR_MDITYPE
Resource2=IDR_DISPLAYTYPE
Resource3=IDR_MAINFRAME
Class5=CChildFrame
Class6=CAboutDlg
Class7=CFormTest
Resource4=IDD_ABOUTBOX
Resource5=IDD_formtest

[CLS:CMDIApp]
Type=0
HeaderFile=MDI.h
ImplementationFile=MDI.cpp
Filter=N

[CLS:CMDIDoc]
Type=0
HeaderFile=MDIDoc.h
ImplementationFile=MDIDoc.cpp
Filter=N
LastObject=CMDIDoc

[CLS:CMDIView]
Type=0
HeaderFile=MDIView.h
ImplementationFile=MDIView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_WINDOW_FORM


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CMDIFrameWnd
VirtualFilter=fWC
LastObject=ID_WINDOW_DISPLAY


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=MDI.cpp
ImplementationFile=MDI.cpp
Filter=D
LastObject=CAboutDlg

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
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MDITYPE]
Type=1
Class=CMDIView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_SEND_MAIL
Command10=ID_FILE_MRU_FILE1
Command11=ID_APP_EXIT
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_CUT
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=ID_WINDOW_NEW
Command19=ID_WINDOW_CASCADE
Command20=ID_WINDOW_TILE_HORZ
Command21=ID_WINDOW_ARRANGE
Command22=ID_APP_ABOUT
Command23=ID_WINDOW_DISPLAY
Command24=ID_WINDOW_FORM
CommandCount=24

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

[DLG:IDD_formtest]
Type=1
Class=CFormTest
ControlCount=2
Control1=IDC_test,button,1342242816
Control2=IDC_rez,edit,1350633600

[CLS:CFormTest]
Type=0
HeaderFile=FormTest.h
ImplementationFile=FormTest.cpp
BaseClass=CFormView
Filter=D
LastObject=CFormTest
VirtualFilter=VWC

[MNU:IDR_DISPLAYTYPE]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_SEND_MAIL
Command10=ID_FILE_MRU_FILE1
Command11=ID_APP_EXIT
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_CUT
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=ID_WINDOW_NEW
Command19=ID_WINDOW_CASCADE
Command20=ID_WINDOW_TILE_HORZ
Command21=ID_WINDOW_ARRANGE
Command22=ID_APP_ABOUT
Command23=ID_WINDOW_DISPLAY
Command24=ID_WINDOW_FORM
CommandCount=24

