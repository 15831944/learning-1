; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "sdi_edit.h"
LastPage=0

ClassCount=7
Class1=CSdi_editApp
Class2=CSdi_editDoc
Class3=CSdi_editView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CDialSearch
Class7=CRunSearch
Resource2=IDD_ABOUTBOX

[CLS:CSdi_editApp]
Type=0
HeaderFile=sdi_edit.h
ImplementationFile=sdi_edit.cpp
Filter=N

[CLS:CSdi_editDoc]
Type=0
HeaderFile=sdi_editDoc.h
ImplementationFile=sdi_editDoc.cpp
Filter=N

[CLS:CSdi_editView]
Type=0
HeaderFile=sdi_editView.h
ImplementationFile=sdi_editView.cpp
Filter=C
BaseClass=CEditView
VirtualFilter=VWC
LastObject=CSdi_editView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_SetFont
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=sdi_edit.cpp
ImplementationFile=sdi_edit.cpp
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
Command8=ID_FILE_SEND_MAIL
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_EDIT_SELECT_ALL
Command16=ID_SetFont
Command17=ID_EDIT_FIND
Command18=ID_EDIT_REPLACE
Command19=ID_VIEW_TOOLBAR
Command20=ID_VIEW_STATUS_BAR
Command21=ID_APP_ABOUT
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_SELECT_ALL
Command2=ID_EDIT_COPY
Command3=ID_FILE_NEW
Command4=ID_FILE_OPEN
Command5=ID_FILE_PRINT
Command6=ID_FILE_SAVE
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_CUT
Command15=ID_EDIT_UNDO
CommandCount=15

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

[CLS:CDialSearch]
Type=0
HeaderFile=DialSearch.h
ImplementationFile=DialSearch.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_texttofind

[CLS:CRunSearch]
Type=0
HeaderFile=RunSearch.h
ImplementationFile=RunSearch.cpp
BaseClass=CWinThread
Filter=N
LastObject=CRunSearch

