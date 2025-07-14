#include "pch.h"
#include "CMissile.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
CMissile::CMissile()
	: m_fDir(1.f)
{
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	Vec2 vPos = GetPos();

	vPos.y += 600.f * fDT * (float)m_fDir;

	SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
	auto vPos = GetPos();
	auto vScale = GetScale();
	Ellipse(_dc, vPos.x - vScale.x / 2.f, vPos.y - vScale.y / 2.f
		, vPos.x + vScale.x / 2.f, vPos.y + vScale.y / 2.f);
}
