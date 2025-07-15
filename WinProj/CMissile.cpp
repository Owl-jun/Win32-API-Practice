#include "pch.h"
#include "CMissile.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"



CMissile::CMissile()
	: m_vDir(Vec2(0.f, 1.f))
	, m_fTheta(PI / 2.f)
	, m_cMode(MISSILE_MODE::NORMAL)
	, m_fET(0.f)
	, m_fFreq(10.f)
	, m_fAmp(150.f)
	, m_fSpeed(600.f)
	, m_fCenterX(0.f)
{
	m_vDir.Normalize();
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	m_fET += fDT;
	Vec2 vPos = GetPos();

	// vPos.y -= m_fSpeed * fDT * sinf(m_fTheta);
	vPos.y -= m_fSpeed * fDT * m_vDir.y;
	switch (m_cMode)
	{
	case MISSILE_MODE::NORMAL:
		// vPos.x += m_fSpeed * fDT * cosf(m_fTheta);
		vPos.x += m_fSpeed * fDT * m_vDir.x;
		break;
	case MISSILE_MODE::SUPER:
		vPos.x = m_fCenterX + m_fAmp * sinf(m_fFreq * m_fET);
		break;
	default :
		break;
	}

	SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
	auto vPos = GetPos();
	auto vScale = GetScale();

	switch (m_cMode)
	{
	case MISSILE_MODE::NORMAL:
		Ellipse(_dc, vPos.x - vScale.x / 2.f, vPos.y - vScale.y / 2.f
			, vPos.x + vScale.x / 2.f, vPos.y + vScale.y / 2.f);
		break;
	case MISSILE_MODE::SUPER:
		Rectangle(_dc, vPos.x - vScale.x / 2.f, vPos.y - vScale.y / 2.f
			, vPos.x + vScale.x / 2.f, vPos.y + vScale.y / 2.f);
		break;
	default:
		break;
	}
}
