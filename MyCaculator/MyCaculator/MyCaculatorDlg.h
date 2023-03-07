
// MyCaculatorDlg.h: 头文件
//

#pragma once
#include <string>
#include<iomanip>
#include "CMyButton1.h"
using namespace std;

// CMyCaculatorDlg 对话框
class CMyCaculatorDlg : public CDialogEx
{
// 构造
public:
	CMyCaculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYCACULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	CString editv;
	CEdit editc;
	CString resultv;
	CEdit resultc;

	//编辑框
	CBrush m_brMine;
	COLORREF m_BackColor;
	COLORREF m_TextColor;
	
	//第二个编辑框
	CBrush m_brMine1;
	COLORREF m_BackColor1;
	COLORREF m_TextColor1;

	CFont m_oFont;
	CToolTipCtrl m_stat;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
	CMyButton1 m_Button1;	//1
	CMyButton1 m_Button2;	//2
	CMyButton1 m_Button3;	//3
	CMyButton1 m_Button4;	//4
	CMyButton1 m_Button5;	//5
	CMyButton1 m_Button6;	//6
	CMyButton1 m_Button7;	//7
	CMyButton1 m_Button8;	//8
	CMyButton1 m_Button9;	//9
	CMyButton1 m_Button10;	//0
	CMyButton1 m_Button11;	//+
	CMyButton1 m_Button12;	//-
	CMyButton1 m_Button15;	//=
	CMyButton1 m_Button16;	//del
	CMyButton1 m_Button17;	//c
	CMyButton1 m_Button13;	//*
	CMyButton1 m_Button14;	// /
	
};
