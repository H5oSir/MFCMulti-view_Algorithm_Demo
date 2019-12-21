
// ZP_TEST3_3Doc.h : CZP_TEST3_3Doc 类的接口
//


#pragma once


class CZP_TEST3_3Doc : public CDocument
{
protected: // 仅从序列化创建
	CZP_TEST3_3Doc();
	DECLARE_DYNCREATE(CZP_TEST3_3Doc)

// 特性
public:
	void InitData();
// 操作
public:
	//插入排序数列
	int InsertA[100];
	//插入排序当前选择的数的位置
	int CompA;
	//冒泡排序当前选择的数的位置
	int CompB;
	//冒泡排序已经排好的数的个数
	int CompB_Count;
	//选择排序当前选择的数的位置
	int CompC;
	//插入排序数列
	int SelectA[100];
	//插入排序数列
	int BubbA[100];
	//数的个数
	int num;
	//矩形之间的X间隔
	int SpaceX;
	//像素与高度的比
	int LevelY;
	//矩形宽度
	int width;
	//红色画刷
	CBrush *rBrush;
	//绿色画刷
	CBrush *gBrush;
	//白色画刷
	CBrush *wBrush;
	//右下角坐标点
	POINT LeftBottom;
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CZP_TEST3_3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnInitdata();
};
