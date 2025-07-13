#include "pch.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"

void CObject::update()
{
	if (GETKEY(KEY::W) == KEY_STATE::HOLD)
	{
		m_vPos.y -= 200.f * fDT;
	}
	if (GETKEY(KEY::S) == KEY_STATE::HOLD)
	{
		m_vPos.y += 200.f * fDT;
	}
	if (GETKEY(KEY::A) == KEY_STATE::HOLD)
	{
		m_vPos.x -= 200.f * fDT;
	}
	if (GETKEY(KEY::D) == KEY_STATE::HOLD)
	{
		m_vPos.x += 200.f * fDT;
	}
}

void CObject::render(HDC _dc)
{
	Rectangle(_dc, m_vPos.x - m_vScale.x / 2.f, m_vPos.y - m_vScale.y / 2.f
				 , m_vPos.x + m_vScale.x / 2.f, m_vPos.y + m_vScale.y / 2.f);
}

CObject::CObject()
	: m_vPos{}
	, m_vScale{}
{
}

CObject::~CObject()
{
}
