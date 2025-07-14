#include "pch.h"
#include "CScene.h"
#include "CPlayer.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CMissile.h"
#include "CSceneMgr.h"

void CPlayer::update()
{
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
 	if (KEY_TAP(KEY::SPACE))
	{
		CreateMissile();
	}

	SetPos(m_vPos);

}

void CPlayer::CreateMissile()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	shared_ptr<CMissile> pMissile = make_shared<CMissile>();
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetDir(true);

	auto curScene = CSceneMgr::GetInst()->GetCurScene();
	curScene->AddObject(pMissile,GROUP_TYPE::MISSILE);
	
}
