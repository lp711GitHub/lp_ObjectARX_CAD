#pragma once
#include <afxwin.h>
class CMyButton1 :
	public CButton
{
public:
	//������ɫ�ֱ�Ϊ���֣�Button Down�ı�����ɫ��Button Up�ı�����ɫ
	COLORREF m_TextColor, m_DownColor, m_UpColor;
	//Button Down�ı�����ɫ��Button Up�ı�����ɫ��־λ
	bool bDownColor, bUpColor;
	//�������ִ�С
	int nWordSize = 100;
	UINT BKID;//��¼ͼƬID
public:
	//����Button Down�ı�����ɫ
	void SetDownColor(COLORREF color);
	//����Button Up�ı�����ɫ
	void SetUpColor(COLORREF color);
	//���ñ���ͼƬ
	void setBit(UINT ID);
	//�������ִ�С��Ĭ��Ϊ10��
	void setWordSize(int wordsize);
	//����������ɫĬ��Ϊ��ɫ
	void setWordColor(COLORREF wordColor);
public:
	// ���ִ���
	void setWord(CRect rect, CDC* pDc, int size);
	//���Ʊ���ͼƬ
	void brushBit(CRect rect, CDC *pDc, UINT ID);
	//����DrawItem
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);

};

