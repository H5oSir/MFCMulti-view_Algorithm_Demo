#pragma once


// CSelectSortWnd 框架

class CSelectSortWnd : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CSelectSortWnd)
protected:
	CSelectSortWnd();           // 动态创建所使用的受保护的构造函数
	virtual ~CSelectSortWnd();

protected:
	DECLARE_MESSAGE_MAP()
};


