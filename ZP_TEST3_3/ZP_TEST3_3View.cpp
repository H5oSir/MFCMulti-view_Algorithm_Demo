
// ZP_TEST3_3View.cpp : CZP_TEST3_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ZP_TEST3_3.h"
#endif

#include "ZP_TEST3_3Doc.h"
#include "ZP_TEST3_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZP_TEST3_3View

IMPLEMENT_DYNCREATE(CZP_TEST3_3View, CView)

BEGIN_MESSAGE_MAP(CZP_TEST3_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CZP_TEST3_3View 构造/析构

CZP_TEST3_3View::CZP_TEST3_3View()
{
	// TODO: 在此处添加构造代码

}

CZP_TEST3_3View::~CZP_TEST3_3View()
{
}

BOOL CZP_TEST3_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CZP_TEST3_3View 绘制

void CZP_TEST3_3View::OnDraw(CDC* /*pDC*/)
{
	CZP_TEST3_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CZP_TEST3_3View 打印

BOOL CZP_TEST3_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CZP_TEST3_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CZP_TEST3_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CZP_TEST3_3View 诊断

#ifdef _DEBUG
void CZP_TEST3_3View::AssertValid() const
{
	CView::AssertValid();
}

void CZP_TEST3_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZP_TEST3_3Doc* CZP_TEST3_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZP_TEST3_3Doc)));
	return (CZP_TEST3_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CZP_TEST3_3View 消息处理程序
