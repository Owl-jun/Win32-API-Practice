#pragma once

// �̱��� ����
// ��ü�� ������ 1���� ����
// ��𼭵� ���� ���� ����
class CCore
{
public:
	SINGLE(CCore);
private:
	HWND	m_hWnd;			// ������ �ڵ�
	POINT	m_ptResolution;   // �ػ�
	HDC		m_hDC;

public:
	int init(HWND _hwnd , POINT _ptResol);
	void progress();
private:
	void update();
	void render();
private:
	CCore();
	~CCore();
};

