#pragma once


// CBubbSortView 视图

class CBubbSortView : public CView
{
	DECLARE_DYNCREATE(CBubbSortView)

protected:
	CBubbSortView();           // 动态创建所使用的受保护的构造函数
	virtual ~CBubbSortView();

public:
	//冒泡排序
	void OnBubb();
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


