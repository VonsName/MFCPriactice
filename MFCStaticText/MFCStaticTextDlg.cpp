
// MFCStaticTextDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCStaticText.h"
#include "MFCStaticTextDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCStaticTextDlg 对话框



CMFCStaticTextDlg::CMFCStaticTextDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSTATICTEXT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCStaticTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, change);
	DDX_Control(pDX, IDC_TEXT, my_text);
	DDX_Control(pDX, IDC_IMAGE, image);
	DDX_Control(pDX, IDC_BUTTON3, m_btn);
}

BEGIN_MESSAGE_MAP(CMFCStaticTextDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCStaticTextDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCStaticTextDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCStaticTextDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCStaticTextDlg 消息处理程序

BOOL CMFCStaticTextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//使用static text显示图片
	image.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);
#define HBMP(filepath,width,height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)
	CRect rect;
	image.GetWindowRect(rect);
	
	image.SetBitmap(HBMP(TEXT("./2.png"), rect.Width(), rect.Height()));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCStaticTextDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCStaticTextDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCStaticTextDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//点击改变内容
void CMFCStaticTextDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//设置文本内容
	my_text.SetWindowTextW(TEXT("哈哈 我被改变了"));
}


//获取内容
void CMFCStaticTextDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取内容
	CString str;
	my_text.GetWindowTextW(str);
	MessageBox(str);
}


void CMFCStaticTextDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//点击按钮修改显示内容
	m_btn.SetWindowTextW(TEXT("aaaa"));
	CString str1;
	m_btn.GetWindowTextW(str1);
	MessageBox(str1);
	//设置i点击状态
	m_btn.EnableWindow(FALSE);//禁用
}
