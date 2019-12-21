// BubbSortView.cpp : 实现文件
//

#include "stdafx.h"
#include "ZP_TEST3_3.h"
#include "BubbSortView.h"
#include "ZP_TEST3_3Doc.h"

// CBubbSortView

IMPLEMENT_DYNCREATE(CBubbSortView, CView)

CBubbSortView::CBubbSortView()
{

}

CBubbSortView::~CBubbSortView()
{
}

BEGIN_MESSAGE_MAP(CBubbSortView, CView)
	ON_WM_TIMER()
	ON_COMMAND(ID_ONESTEP, &CBubbSortView::OnOnestep)
	ON_COMMAND(ID_AUTO, &CBubbSortView::OnAuto)
	ON_COMMAND(ID_STOP, &CBubbSortView::OnStop)
END_MESSAGE_MAP()

void CBubbSortView::OnBubb()
{
	CZP_TEST3_3Doc *pDoc=(CZP_TEST3_3Doc*)GetDocument();
	if (pDoc->CompB!=0)
	{
		if (pDoc->BubbA[pDoc->CompB]<pDoc->BubbA[pDoc->CompB-1])
		{
			int t=pDoc->BubbA[pDoc->CompB];
			pDoc->BubbA[pDoc->CompB]=pDoc->BubbA[pDoc->CompB-1];
			pDoc->BubbA[pDoc->CompB-1]=t;
		}
	}
	pDoc->CompB++;
	if(pDoc->CompB==pDoc->num-pDoc->CompB_Count)
	{
		pDoc->CompB_Count++;
		pDoc->CompB=0;
	}
}

// CBubbSortView 绘图

void CBubbSortView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	//获取文档指针
	CZP_TEST3_3Doc *pDoc=(CZP_TEST3_3Doc*)GetDocument();
	// TODO: 在此添加绘制代码
	//画文字标题
	pDC->TextOut(pDoc->LeftBottom.x+pDoc->num*(pDoc->width+pDoc->SpaceX)/2,pDoc->LeftBottom.y-(100*pDoc->LevelY+30),_T("冒泡排序"));
	for (int i = 0; i < pDoc->num; i++)
	{
		//计算当前矩形
		CRect Rect=CRect(pDoc->LeftBottom.x+i*(pDoc->width+pDoc->SpaceX),pDoc->LeftBottom.y,pDoc->LeftBottom.x+i*(pDoc->width+pDoc->SpaceX)+pDoc->width,pDoc->LeftBottom.y-pDoc->LevelY*pDoc->BubbA[i]);
		//当前矩形不被选中
		if (i!=pDoc->CompB)
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
	if (pDoc->CompB_Count<pDoc->num)
	{
		OnBubb();
	}
}


// CBubbSortView 诊断

#ifdef _DEBUG
void CBubbSortView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CBubbSortView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBubbSortView 消息处理程序


void CBubbSortView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Invalidate(TRUE);
	CView::OnTimer(nIDEvent);
}


void CBubbSortView::OnOnestep()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
	Invalidate(TRUE);
}


void CBubbSortView::OnAuto()
{
	// TODO: 在此添加命令处理程序代码
	SetTimer(1,1000,0);
}


void CBubbSortView::OnStop()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
}
