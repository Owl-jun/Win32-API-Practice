#pragma once

// �̱��� ����
// ��ü�� ������ 1���� ����
// ��𼭵� ���� ���� ����
class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hWnd;			// ������ �ڵ�
	POINT	m_ptResolution;   // �ػ�
	HDC		m_hDC;
	HBITMAP m_hBit;
	HDC		m_memDC;
public:
	int init(HWND _hwnd , POINT _ptResol);
	void progress();

private:


public:
	HWND GetMainHwnd() { return m_hWnd; }
	POINT GetResolution() { return m_ptResolution; }
};

