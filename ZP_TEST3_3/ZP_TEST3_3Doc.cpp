
// ZP_TEST3_3Doc.cpp : CZP_TEST3_3Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ZP_TEST3_3.h"
#endif

#include "ZP_TEST3_3Doc.h"

#include <propkey.h>
//#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CZP_TEST3_3Doc

IMPLEMENT_DYNCREATE(CZP_TEST3_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CZP_TEST3_3Doc, CDocument)
	ON_COMMAND(ID_INITDATA, &CZP_TEST3_3Doc::OnInitdata)
END_MESSAGE_MAP()


// CZP_TEST3_3Doc 构造/析构

CZP_TEST3_3Doc::CZP_TEST3_3Doc()
{
	// TODO: 在此添加一次性构造代码
	InitData();
}

CZP_TEST3_3Doc::~CZP_TEST3_3Doc()
{
}
void CZP_TEST3_3Doc::InitData()
{
	num=20;
	srand((unsigned)time(NULL));
	for (int i=0;i<num;i++)
	{
		InsertA[i]=int((rand()%90+11));
		SelectA[i]=InsertA[i];
		BubbA[i]=InsertA[i];
	}
	SpaceX=10;
	width=20;
	LevelY=1;
	LeftBottom.x=10;
	LeftBottom.y=200;
	gBrush=new CBrush(RGB(0,255,0));
	gBrush->CreateObject();
	rBrush=new CBrush(RGB(255,0,0));
	rBrush->CreateObject();
	wBrush=new CBrush(RGB(255,255,255));
	wBrush->CreateObject();
	CompA=0;
	CompB=0;
	CompB_Count=0;
	CompC=0;
}
BOOL CZP_TEST3_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CZP_TEST3_3Doc 序列化

void CZP_TEST3_3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CZP_TEST3_3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CZP_TEST3_3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CZP_TEST3_3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CZP_TEST3_3Doc 诊断

#ifdef _DEBUG
void CZP_TEST3_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CZP_TEST3_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CZP_TEST3_3Doc 命令


void CZP_TEST3_3Doc::OnInitdata()
{
	// TODO: 在此添加命令处理程序代码
	InitData();
	UpdateAllViews(NULL);
}
