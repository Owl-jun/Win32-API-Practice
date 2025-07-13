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
	, m_hBit(0)
	, m_memDC(0)
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);

	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}

int CCore::init(HWND _hwnd, POINT _ptResol)
{
	m_hWnd = _hwnd;
	m_ptResolution = _ptResol;
	// �ػ󵵿� �°� ������ ũ�� ����
	RECT rt = { 0, 0, m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
	
	m_hDC = GetDC(m_hWnd);

	// ���� ���۸� �뵵�� ��Ʈ�ʰ� DC�� �����.
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	// Manager �ʱ�ȭ
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	g_obj.SetPos(Vec2(m_ptResolution.x / 2, m_ptResolution.y / 2));
	g_obj.SetScale(Vec2{ 100.f, 100.f });

	return S_OK;
}

void CCore::progress()
{
	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();
	update();

	render();
}

void CCore::update()
{
	Vec2 vPos = g_obj.GetPos();
	if (GETKEY(KEY::LEFT) == KEY_STATE::HOLD)
	{
		vPos.x -= 300.f * fDT;
	}
	if (GETKEY(KEY::RIGHT) == KEY_STATE::HOLD)
	{
		vPos.x += 300.f * fDT;
	}
	if (GETKEY(KEY::UP) == KEY_STATE::HOLD)
	{
		vPos.y -= 300.f * fDT;
	}
	if (GETKEY(KEY::DOWN) == KEY_STATE::HOLD)
	{
		vPos.y += 300.f * fDT;
	}
	g_obj.SetPos(vPos);
}

void CCore::render()
{
	// ȭ�� Clear
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	// �׸���
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();
	Rectangle(m_memDC
			, vPos.x - vScale.x / 2
			, vPos.y - vScale.y / 2
			, vPos.x + vScale.x / 2
			, vPos.y + vScale.y / 2);
	
	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y
		, m_memDC, 0, 0, SRCCOPY);

}
