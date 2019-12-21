// InsertSortView.cpp : 实现文件
//

#include "stdafx.h"
#include "ZP_TEST3_3.h"
#include "InsertSortView.h"
#include "MainFrm.h"
#include "ZP_TEST3_3Doc.h"


// CInsertSortView

IMPLEMENT_DYNCREATE(CInsertSortView, CView)

CInsertSortView::CInsertSortView()
{
}

CInsertSortView::~CInsertSortView()
{
}

BEGIN_MESSAGE_MAP(CInsertSortView, CView)
	ON_WM_TIMER()
	ON_COMMAND(ID_ONESTEP, &CInsertSortView::OnOnestep)
	ON_COMMAND(ID_AUTO, &CInsertSortView::OnAuto)
	ON_COMMAND(ID_STOP, &CInsertSortView::OnStop)
END_MESSAGE_MAP()


// CInsertSortView 绘图

void CInsertSortView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	//获取文档指针
	CZP_TEST3_3Doc *pDoc=(CZP_TEST3_3Doc*)GetDocument();
	// TODO: 在此添加绘制代码
	//画文字标题
	pDC->TextOut(pDoc->LeftBottom.x+pDoc->num*(pDoc->width+pDoc->SpaceX)/2,pDoc->LeftBottom.y-(100*pDoc->LevelY+30),_T("插入排序"));
	//画所有矩形
	for (int i = 0; i < pDoc->num; i++)
	{
		//计算当前矩形
		CRect Rect=CRect(pDoc->LeftBottom.x+i*(pDoc->width+pDoc->SpaceX),pDoc->LeftBottom.y,pDoc->LeftBottom.x+i*(pDoc->width+pDoc->SpaceX)+pDoc->width,pDoc->LeftBottom.y-pDoc->LevelY*pDoc->InsertA[i]);
		//当前矩形不被选中
		if (i!=pDoc->CompA)
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
	if (pDoc->CompA<pDoc->num)
	{
		OnInsert();
	}
}


// CInsertSortView 诊断

#ifdef _DEBUG
void CInsertSortView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CInsertSortView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CInsertSortView 消息处理程序


void CInsertSortView::OnInsert()
{
	CZP_TEST3_3Doc *pDoc=(CZP_TEST3_3Doc*)GetDocument();
	int minIndex=0;
	for (int j = 0; j < pDoc->CompA; j++)
	{
		if (pDoc->InsertA[pDoc->CompA]<pDoc->InsertA[j])
		{
			minIndex=j;
			int t=pDoc->InsertA[pDoc->CompA];
			pDoc->InsertA[pDoc->CompA]=pDoc->InsertA[j];
			pDoc->InsertA[j]=t;
		}
	}
	if (pDoc->CompA<pDoc->num-1)
	{
		pDoc->CompA++;
	}
}

void CInsertSortView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Invalidate(TRUE);
	CView::OnTimer(nIDEvent);
}


void CInsertSortView::OnOnestep()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
	Invalidate(TRUE);
}


void CInsertSortView::OnAuto()
{
	// TODO: 在此添加命令处理程序代码
	SetTimer(1,1000,0);
	//Invalidate(TRUE);
}


void CInsertSortView::OnStop()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
}
