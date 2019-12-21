// SelectSortView.cpp : 实现文件
//

#include "stdafx.h"
#include "ZP_TEST3_3.h"
#include "SelectSortView.h"
#include "ZP_TEST3_3Doc.h"


// CSelectSortView

IMPLEMENT_DYNCREATE(CSelectSortView, CView)

CSelectSortView::CSelectSortView()
{

}

CSelectSortView::~CSelectSortView()
{
}

BEGIN_MESSAGE_MAP(CSelectSortView, CView)
	ON_WM_TIMER()
	ON_COMMAND(ID_ONESTEP, &CSelectSortView::OnOnestep)
	ON_COMMAND(ID_AUTO, &CSelectSortView::OnAuto)
	ON_COMMAND(ID_STOP, &CSelectSortView::OnStop)
END_MESSAGE_MAP()
void CSelectSortView::OnSelect()
{
	CZP_TEST3_3Doc *pDoc=(CZP_TEST3_3Doc*)GetDocument();
	int minIndex=pDoc->CompC;
	for (int j = pDoc->CompC; j < pDoc->num; j++)
	{
		if (pDoc->SelectA[minIndex]>pDoc->SelectA[j])
		{
			minIndex=j;
		}
	}
	int t=pDoc->SelectA[minIndex];
	pDoc->SelectA[minIndex]=pDoc->SelectA[pDoc->CompC];
	pDoc->SelectA[pDoc->CompC]=t;
	pDoc->CompC++;

}

// CSelectSortView 绘图

void CSelectSortView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	//获取文档指针
	CZP_TEST3_3Doc *pDoc=(CZP_TEST3_3Doc*)GetDocument();
	// TODO: 在此添加绘制代码
	//画文字标题
	pDC->TextOut(pDoc->LeftBottom.x+pDoc->num*(pDoc->width+pDoc->SpaceX)/2,pDoc->LeftBottom.y-(100*pDoc->LevelY+30),_T("选择排序"));
	//画所有矩形
	for (int i = 0; i < pDoc->num; i++)
	{
		//计算当前矩形
		CRect Rect=CRect(pDoc->LeftBottom.x+i*(pDoc->width+pDoc->SpaceX),pDoc->LeftBottom.y,pDoc->LeftBottom.x+i*(pDoc->width+pDoc->SpaceX)+pDoc->width,pDoc->LeftBottom.y-pDoc->LevelY*pDoc->SelectA[i]);
		//当前矩形不被选中
		if (i!=pDoc->CompC)
		{
			//用绿色色画刷填充
			pDC->FillRect(Rect,pDoc->gBrush);
		}
		else
		{
			//用红色画刷
			pDC->FillRect(Rect,pDoc->rBrush);
		}
	}
	//若没有排好就继续排序
	if (pDoc->CompC<pDoc->num-1)
	{
		OnSelect();
	}
}


// CSelectSortView 诊断

#ifdef _DEBUG
void CSelectSortView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectSortView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectSortView 消息处理程序


void CSelectSortView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Invalidate(TRUE);
	CView::OnTimer(nIDEvent);
}


void CSelectSortView::OnOnestep()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
	Invalidate(TRUE);
}


void CSelectSortView::OnAuto()
{
	// TODO: 在此添加命令处理程序代码
	SetTimer(1,1000,0);
}


void CSelectSortView::OnStop()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
}
