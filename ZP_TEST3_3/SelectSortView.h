#pragma once


// CSelectSortView 视图

class CSelectSortView : public CView
{
	DECLARE_DYNCREATE(CSelectSortView)

protected:
	CSelectSortView();           // 动态创建所使用的受保护的构造函数
	virtual ~CSelectSortView();

public:
	//选择排序
	void OnSelect();
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


