#include "pch.h"
#include "CBackGround.h"
#include "CResMgr.h"

CBackGround::CBackGround()
	: m_pTex(nullptr)
{
	m_pTex = GETTEX(L"BG_Start", L"texture\\BG_START.bmp");
}

CBackGround::~CBackGround()
{
}


void CBackGround::update()
{
}

void CBackGround::render(HDC _dc)
{
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();
	Vec2 vPos = GetPos();

	TransparentBlt(_dc
		, (int)(vPos.x - (float)(iWidth / 2))
		, (int)(vPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 0, 255)
	);
}

