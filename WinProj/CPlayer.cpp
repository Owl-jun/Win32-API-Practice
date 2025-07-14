#include "pch.h"
#include "CScene.h"
#include "CPlayer.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CSceneMgr.h"

CPlayer::CPlayer()
	: m_fAttackCoolDown(0.1f)
	, m_fSkillCoolDown(3.f)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::update()
{
	m_fAttackCoolDown -= fDT;
	m_fSkillCoolDown -= fDT;

	auto m_vPos = GetPos();
	if (KEY_HOLD(KEY::W))
	{
		m_vPos.y -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		m_vPos.y += 200.f * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		m_vPos.x -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		m_vPos.x += 200.f * fDT;
	}
 	if (KEY_HOLD(KEY::SPACE))
	{
		if (m_fSkillCoolDown < 0.f)
		{
			CreateMissile(MISSILE_MODE::SUPER);
			m_fSkillCoolDown = 3.f;
		}
		if (m_fAttackCoolDown < 0.f)
		{
			CreateMissile(MISSILE_MODE::NORMAL);
			m_fAttackCoolDown = 0.1f;
		}
	}

	SetPos(m_vPos);

}

void CPlayer::CreateMissile(MISSILE_MODE _mode)
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	shared_ptr<CMissile> pMissile = make_shared<CMissile>();
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));
	// pMissile->SetDir(true);
	pMissile->SetMode(_mode);
	pMissile->SetCenterX(vMissilePos.x);

	auto curScene = CSceneMgr::GetInst()->GetCurScene(); 
	curScene->AddObject(pMissile,GROUP_TYPE::MISSILE);
}


