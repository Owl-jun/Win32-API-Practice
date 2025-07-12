#include "pch.h"
#include "CCore.h"
#include "CObject.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"

CObject g_obj;

CCore::CCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
}

int CCore::init(HWND _hwnd, POINT _ptResol)
{
	m_hWnd = _hwnd;
	m_ptResolution = _ptResol;
	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = { 0, 0, m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
	
	m_hDC = GetDC(m_hWnd);

	// Manager 초기화
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	g_obj.SetPos(Vec2(m_ptResolution.x / 2, m_ptResolution.y / 2));
	g_obj.SetScale(Vec2{ 100.f, 100.f });

	return S_OK;
}

void CCore::progress()
{
	CTimeMgr::GetInst()->update();
	update();

	render();
}

void CCore::update()
{
	Vec2 vPos = g_obj.GetPos();
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 100.f * fDT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 100.f * fDT;
	}
	g_obj.SetPos(vPos);
}

void CCore::render()
{
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();
	Rectangle(m_hDC
			, vPos.x - vScale.x / 2
			, vPos.y - vScale.y / 2
			, vPos.x + vScale.x / 2
			, vPos.y + vScale.y / 2
			);
}
