
// MyCaculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MyCaculator.h"
#include "MyCaculatorDlg.h"
#include "afxdialogex.h"
#include "Resource.h"

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
	DECLARE_MESSAGE_MAP();
};


CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CMyCaculatorDlg 对话框

CMyCaculatorDlg::CMyCaculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYCACULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}

void CMyCaculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX, IDC_EDIT_1, editv);
	DDX_Control(pDX, IDC_EDIT_1, editc);
	DDX_Text(pDX, IDC_EDIT_2, resultv);
	DDX_Control(pDX, IDC_EDIT_2, resultc);
	DDX_Control(pDX, IDC_BUTTON1, m_Button1);
	DDX_Control(pDX, IDC_BUTTON2, m_Button2);
	DDX_Control(pDX, IDC_BUTTON3, m_Button3);
	DDX_Control(pDX, IDC_BUTTON4, m_Button4);
	DDX_Control(pDX, IDC_BUTTON5, m_Button5);
	DDX_Control(pDX, IDC_BUTTON6, m_Button6);
	DDX_Control(pDX, IDC_BUTTON7, m_Button7);
	DDX_Control(pDX, IDC_BUTTON8, m_Button8);
	DDX_Control(pDX, IDC_BUTTON9, m_Button9);
	DDX_Control(pDX, IDC_BUTTON10, m_Button10);
	DDX_Control(pDX, IDC_BUTTON11, m_Button11);
	DDX_Control(pDX, IDC_BUTTON12, m_Button12);
	DDX_Control(pDX, IDC_BUTTON19, m_Button15);
	DDX_Control(pDX, IDC_BUTTON17, m_Button16);
	DDX_Control(pDX, IDC_BUTTON18, m_Button17);
	DDX_Control(pDX, IDC_BUTTON15, m_Button13);
	DDX_Control(pDX, IDC_BUTTON16, m_Button14);
}

BEGIN_MESSAGE_MAP(CMyCaculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyCaculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyCaculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyCaculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyCaculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyCaculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMyCaculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMyCaculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMyCaculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMyCaculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMyCaculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMyCaculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMyCaculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMyCaculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON15, &CMyCaculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMyCaculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CMyCaculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CMyCaculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CMyCaculatorDlg::OnBnClickedButton19)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CMyCaculatorDlg 消息处理程序

BOOL CMyCaculatorDlg::OnInitDialog()
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

	//改变按钮颜色等
	//1
	//将按钮修改为BS_OWNERDRAW风格,允许button的采用自绘模式
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button1.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button1.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button1.setWordSize(150);

	//2
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button2.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button2.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button2.setWordSize(150);

	//3
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button3.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button3.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button3.setWordSize(150);

	//4
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button4.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button4.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button4.setWordSize(150);

	//5
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button5.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button5.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button5.setWordSize(150);

	//6
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button6.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button6.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button6.setWordSize(150);

	//7
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button7.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button7.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button7.setWordSize(150);

	//8
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button8.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button8.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button8.setWordSize(150);

	//9
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button9.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button9.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button9.setWordSize(150);

	//0
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button10.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button10.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button10.setWordSize(150);

	//+
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button11.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button11.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button11.setWordSize(150);

	//-
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button12.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button12.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button12.setWordSize(150);

	//*
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button13.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button13.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button13.setWordSize(150);

	// /
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button14.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button14.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button14.setWordSize(180);

	//=
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button15.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button15.SetUpColor(RGB(0, 153, 0));
	//设置字体大小
	m_Button15.setWordSize(220);

	//del
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button16.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button16.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button16.setWordSize(180);

	//c
	GetDlgItem(IDC_BUTTON1)->ModifyStyle(0, BS_OWNERDRAW, 0);
	//设置Button Down的背景色，SetDownColor()和SetUpnColor()是CMyButton类中的析构函数
	m_Button17.SetDownColor(RGB(100, 255, 100));
	//设置Button Up的背景色
	m_Button17.SetUpColor(RGB(224, 224, 224));
	//设置字体大小
	m_Button17.setWordSize(180);


	//编辑框字体设置
	m_oFont.CreatePointFont(180, _T("宋体"));
	editc.SetFont(&m_oFont);
	resultc.SetFont(&m_oFont);

	m_BackColor = RGB(224, 224, 224);				// 黑色背景  
	m_TextColor = RGB(10, 10, 10);				 // 文本颜色设置为绿色  
	m_brMine.CreateSolidBrush(m_BackColor);		 // 黑色背景色  

	m_BackColor1 = RGB(224, 224, 224);				// 黑色背景  
	m_TextColor1 = RGB(10, 10, 10);				 // 文本颜色设置为绿色  
	m_brMine1.CreateSolidBrush(m_BackColor1);		 // 黑色背景色  


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMyCaculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyCaculatorDlg::OnPaint()
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
		//CDialogEx::OnPaint();

		//添加代码对话框背景图
		//CPaintDC   dc(this);
		//CRect   rect;
		//GetClientRect(&rect);    //获取对话框长宽      
		//CDC   dcBmp;             //定义并创建一个内存设备环境
		//dcBmp.CreateCompatibleDC(&dc);             //创建兼容性DC
		//CBitmap   bmpBackground;
		//bmpBackground.LoadBitmap(IDB_BITMAP1);    //载入资源中图片
		//BITMAP   m_bitmap;                         //图片变量               
		//bmpBackground.GetBitmap(&m_bitmap);       //将图片载入位图中
		//将位图选入临时内存设备环境
		//CBitmap  *pbmpOld = dcBmp.SelectObject(&bmpBackground);
		//调用函数显示图片StretchBlt显示形状可变
		//dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyCaculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMyCaculatorDlg::OnBnClickedButton1()	//1
{
	editv += "1";
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton2()	//2
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "2";
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton3()	//3
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "3";
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton4()	//4
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "4";
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton5()	//5
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "5";
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton6()	//6
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "6";
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton7()	//7
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "7";
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton8()	//8
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "8";
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton9()	//9
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "9";
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton10()	//0
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "0";
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton11()	//+
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "+";
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton12()	//-
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "-";
	UpdateData(false);
}

void CMyCaculatorDlg::OnBnClickedButton15()	//*
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "*";
	UpdateData(false);
}

void CMyCaculatorDlg::OnBnClickedButton16()	// /
{
	// TODO: 在此添加控件通知处理程序代码
	editv += "/";
	UpdateData(false);
}

void CMyCaculatorDlg::OnBnClickedButton17()	//del
{
	// TODO: 在此添加控件通知处理程序代码
	editv = editv.Left(editv.GetLength() - 1);
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton18()	//c
{
	// TODO: 在此添加控件通知处理程序代码
	editv = "";
	resultv = "";
	UpdateData(false);
}


void CMyCaculatorDlg::OnBnClickedButton19()	//=
{
	// TODO: 在此添加控件通知处理程序代码

	int oper_index = 0;	//运算符个数
	int index = 0;	//运算符所在的下标
	double result = 0.0;	//计算结果

	string str = CT2A(editv.GetString());	//CString->string

	//CString转换为string
	std::string str1 = CT2A(editv.GetString());	//str1为第一个编辑框的字符串

	//1.找到运算符号
	for (unsigned int i = 0; i <= str1.length(); i++) {
		if (str1[i] == '+' || str1[i] == '-' || str1[i] == '*' || str1[i] == '/') {
			oper_index++;
			index = i;
		}
	}

	//判断是否超过两个运算符
	if (oper_index >= 2) {
		editc.MessageBox(_T("只支持两元运算！"),_T("提示"),MB_OK | MB_OKCANCEL);
		OnBnClickedButton18();
	}

	//第一个操作数
	string s1 = str1.substr(0, index);
	double num1 = atof(s1.c_str());	//string转为double

	//第二个操作数
	string s2 = str1.substr(index + 1, str1.length() - 1);

	double num2 = atof(s2.c_str());

	//2.判断是什么运算符号，进行相应的操作
	if (str1[index] == '+') {
		result = num1 + num2;
	}
	else if (str1[index] == '-') {
		result = num1 - num2;
	}
	else if (str1[index] == '*') {
		result = num1 * num2;
	}
	else if (str1[index] == '/') {
		while (!num2) {
			resultv = "除数不能为0";
			break;
		}
		result = num1 / num2;
	}
	else {
		result = 0.0;
	}

	//3.将操作结果展示在result编辑框
	std::string str2 = std::to_string(result);

	//找到第一个编辑框中的小数点 保留小数点后2位
	for (int i = 0; i < str2.length(); i++) {
		if (str2[i] == '.') {	//是小数点时
			str2 = str2.substr(0, i + 3);
			break;
		}
	}
	resultv = str2.c_str();
	UpdateData(false);

	//str3为 第一个编辑框展示运算后的结果 字符串
	std::string str3 = std::to_string(result);	//double转string

	//找到第二个编辑框中的小数点 保留小数点后2位
	for (int i = 0; i < str3.length(); i++) {
		if (str3[i] == '.') {	//是小数点时
			str3 = str3.substr(0, i + 3);
			break;
		}
	}
	editv = str3.c_str();
}

//编辑框
HBRUSH CMyCaculatorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	if ((pWnd->GetDlgCtrlID() == IDC_EDIT_1) && (nCtlColor == CTLCOLOR_STATIC))
	{
		pDC->SetBkColor(m_BackColor);
		pDC->SetTextColor(m_TextColor);
		hbr = (HBRUSH)m_brMine;
		return m_brMine;
	}
	/*else
	{
		hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
		return hbr;
	}*/

	else if ((pWnd->GetDlgCtrlID() == IDC_EDIT_2) && (nCtlColor == CTLCOLOR_STATIC))
	{
		pDC->SetBkColor(m_BackColor1);
		pDC->SetTextColor(m_TextColor1);
		hbr = (HBRUSH)m_brMine1;
		return m_brMine1;
	}
	else
	{
		hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
		return hbr;
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
