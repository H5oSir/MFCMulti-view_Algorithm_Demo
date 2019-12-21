#pragma once


// CBubbSortWnd 框架

class CBubbSortWnd : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CBubbSortWnd)
protected:
	CBubbSortWnd();           // 动态创建所使用的受保护的构造函数
	virtual ~CBubbSortWnd();

protected:
	DECLARE_MESSAGE_MAP()
};


