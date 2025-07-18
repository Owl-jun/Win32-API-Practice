#include "pch.h"
#include "CMissile.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CResMgr.h"
#include "CCollider.h"


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
	m_pNormalTex = GETTEX(L"NormalMissileTex", L"texture\\Missile_Normal.bmp");
	m_pSuperTex = GETTEX(L"SuperMissileTex", L"texture\\Missile_Super.bmp");
	m_vDir.Normalize();
	CreateCollider();
	GetCollider()->SetScale(Vec2{ 15.f,15.f });
}

CMissile::~CMissile()
{
}

void CMissile::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Monster")
	{
		DeleteObject(this);
	}
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
	int iNormalWidth = (int)m_pNormalTex->Width();
	int iNormalHeight = (int)m_pNormalTex->Height();	
	int iSuperWidth = (int)m_pSuperTex->Width();
	int iSuperHeight = (int)m_pSuperTex->Height();
	auto vPos = GetPos();

	switch (m_cMode)
	{
	case MISSILE_MODE::NORMAL:
		TransparentBlt(_dc
			, (int)(vPos.x - (float)(iNormalWidth / 2))
			, (int)(vPos.y - (float)(iNormalHeight / 2))
			, iNormalWidth, iNormalHeight
			, m_pNormalTex->GetDC()
			, 0, 0, iNormalWidth, iNormalHeight
			, RGB(255, 0, 255)
		);
		break;
	case MISSILE_MODE::SUPER:
		TransparentBlt(_dc
			, (int)(vPos.x - (float)(iSuperWidth / 2))
			, (int)(vPos.y - (float)(iSuperHeight / 2))
			, iSuperWidth, iSuperHeight
			, m_pSuperTex->GetDC()
			, 0, 0, iSuperWidth, iSuperHeight
			, RGB(255, 0, 255)
		);
		break;
	default:
		break;
	}
	component_render(_dc);
}
