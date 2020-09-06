; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMDI_ReditView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MDI_Redit.h"
LastPage=0

ClassCount=6
Class1=CMDI_ReditApp
Class2=CMDI_ReditDoc
Class3=CMDI_ReditView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MDI_RETYPE
Resource2=IDR_MDI_RETYPE_CNTR_IP
Resource3=IDR_MAINFRAME
Resource4=IDD_ABOUTBOX
Class5=CChildFrame
Class6=CAboutDlg

[CLS:CMDI_ReditApp]
Type=0
HeaderFile=MDI_Redit.h
ImplementationFile=MDI_Redit.cpp
Filter=N

[CLS:CMDI_ReditDoc]
Type=0
HeaderFile=MDI_ReditDoc.h
ImplementationFile=MDI_ReditDoc.cpp
Filter=N

[CLS:CMDI_ReditView]
Type=0
HeaderFile=MDI_ReditView.h
ImplementationFile=MDI_ReditView.cpp
Filter=C
BaseClass=CRichEditView
VirtualFilter=VWC
LastObject=ID_SELECT_FONT


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=MDI_Redit.cpp
ImplementationFile=MDI_Redit.cpp
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

[MNU:IDR_MDI_RETYPE]
Type=1
Class=CMDI_ReditView
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
Command16=ID_EDIT_PASTE_SPECIAL
Command17=ID_EDIT_SELECT_ALL
Command18=ID_EDIT_FIND
Command19=ID_EDIT_REPEAT
Command20=ID_EDIT_REPLACE
Command21=ID_OLE_INSERT_NEW
Command22=ID_OLE_EDIT_LINKS
Command23=ID_OLE_EDIT_PROPERTIES
Command24=ID_OLE_VERB_FIRST
Command25=ID_SELECT_FONT
Command26=ID_VIEW_TOOLBAR
Command27=ID_VIEW_STATUS_BAR
Command28=ID_WINDOW_NEW
Command29=ID_WINDOW_CASCADE
Command30=ID_WINDOW_TILE_HORZ
Command31=ID_WINDOW_ARRANGE
Command32=ID_APP_ABOUT
CommandCount=32

[MNU:IDR_MDI_RETYPE_CNTR_IP]
Type=1
Class=CMDI_ReditView
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
Command12=ID_WINDOW_NEW
Command13=ID_WINDOW_CASCADE
Command14=ID_WINDOW_TILE_HORZ
Command15=ID_WINDOW_ARRANGE
CommandCount=15

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
Command9=ID_EDIT_SELECT_ALL
Command10=ID_EDIT_FIND
Command11=ID_EDIT_REPEAT
Command12=ID_EDIT_REPLACE
Command13=ID_OLE_EDIT_PROPERTIES
Command14=ID_EDIT_UNDO
Command15=ID_EDIT_CUT
Command16=ID_EDIT_COPY
Command17=ID_EDIT_PASTE
Command18=ID_NEXT_PANE
Command19=ID_PREV_PANE
Command20=ID_CANCEL_EDIT_CNTR
CommandCount=20

[ACL:IDR_MDI_RETYPE_CNTR_IP]
Type=1
Class=CMDI_ReditView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
Command7=ID_CANCEL_EDIT_CNTR
CommandCount=7

