#pragma once

// 싱글톤 패턴
// 객체의 생성을 1개로 제한
// 어디서든 쉽게 접근 가능
class CCore
{
public:
	SINGLE(CCore);
private:
	HWND	m_hWnd;			// 윈도우 핸들
	POINT	m_ptResolution;   // 해상도
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

