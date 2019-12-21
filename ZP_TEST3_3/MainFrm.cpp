
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "ZP_TEST3_3.h"

#include "MainFrm.h"
#include "InsertSortWnd.h"
#include "InsertSortView.h"
#include "BubbSortView.h"
#include "SelectSortView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_SELECT, &CMainFrame::OnSelect)
	ON_COMMAND(ID_INSERT, &CMainFrame::OnInsert)
	ON_COMMAND(ID_BUBB, &CMainFrame::OnBubb)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



void CMainFrame::OnSelect()
{
	// TODO: 在此添加命令处理程序代码
	//获取APP指针
	CZP_TEST3_3App* myApp=(CZP_TEST3_3App*)AfxGetApp();	
	//获取文档指针
	CDocument* myDoc= myApp->pSelectDocTemplate->CreateNewDocument();
	//获取框架指针
	CFrameWnd* myFrame=	myApp->pSelectDocTemplate->CreateNewFrame(myDoc,NULL);
	
	if (myFrame == NULL)
		return ;
	//初始化框架
	myApp->pSelectDocTemplate->InitialUpdateFrame(myFrame,NULL,TRUE);
	//获取对应的视图
	CSelectSortView* pview=(CSelectSortView*)(myFrame->GetActiveView());
}


void CMainFrame::OnInsert()
{
	// TODO: 在此添加命令处理程序代码
	//获取APP指针
	CZP_TEST3_3App* myApp=(CZP_TEST3_3App*)AfxGetApp();	
	//获取文档指针
	CDocument* myDoc= myApp->pInsertDocTemplate->CreateNewDocument();
	//获取框架指针
	CFrameWnd* myFrame=	myApp->pInsertDocTemplate->CreateNewFrame(myDoc,NULL);
	
	if (myFrame == NULL)
		return ;
	//初始化框架
	myApp->pInsertDocTemplate->InitialUpdateFrame(myFrame,NULL,TRUE);
	//获取对应的视图
	CInsertSortView* pview=(CInsertSortView*)(myFrame->GetActiveView());

}
void CMainFrame::OnBubb()
{
	// TODO: 在此添加命令处理程序代码
	//获取APP指针
	CZP_TEST3_3App* myApp=(CZP_TEST3_3App*)AfxGetApp();	
	//获取文档指针
	CDocument* myDoc= myApp->pBubbDocTemplate->CreateNewDocument();
	//获取框架指针
	CFrameWnd* myFrame=	myApp->pBubbDocTemplate->CreateNewFrame(myDoc,NULL);
	
	if (myFrame == NULL)
		return ;
	//初始化框架
	myApp->pBubbDocTemplate->InitialUpdateFrame(myFrame,NULL,TRUE);
	//获取对应的视图
	CBubbSortView* pview=(CBubbSortView*)(myFrame->GetActiveView());
}
