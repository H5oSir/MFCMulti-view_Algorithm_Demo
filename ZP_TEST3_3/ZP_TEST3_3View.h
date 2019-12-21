
// ZP_TEST3_3View.h : CZP_TEST3_3View 类的接口
//

#pragma once


class CZP_TEST3_3View : public CView
{
protected: // 仅从序列化创建
	CZP_TEST3_3View();
	DECLARE_DYNCREATE(CZP_TEST3_3View)

// 特性
public:
	CZP_TEST3_3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CZP_TEST3_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ZP_TEST3_3View.cpp 中的调试版本
inline CZP_TEST3_3Doc* CZP_TEST3_3View::GetDocument() const
   { return reinterpret_cast<CZP_TEST3_3Doc*>(m_pDocument); }
#endif

