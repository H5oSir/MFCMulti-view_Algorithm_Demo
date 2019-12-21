#pragma once


// CInsertSortView 视图

class CInsertSortView : public CView
{
	DECLARE_DYNCREATE(CInsertSortView)

protected:
	CInsertSortView();           // 动态创建所使用的受保护的构造函数
	virtual ~CInsertSortView();

public:
	//插入排序
	void OnInsert();


	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnOnestep();
	afx_msg void OnAuto();
	afx_msg void OnStop();
};


