#include "pch.h"
#include "CScene.h"
#include "CPlayer.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CSceneMgr.h"
#include "CPathMgr.h"
#include "CResMgr.h"
#include "CCollider.h"

CPlayer::CPlayer()
	: m_fAttackCoolDown(0.1f)
	, m_fSkillCoolDown(3.f)
	, m_fSpeed(400.f)
	, m_pTex(nullptr)
{
	// Texture 로딩
	m_pTex = GETTEX(L"PlayerTex", L"texture\\Player.bmp");

	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2{ 0.f, 5.f });
	GetCollider()->SetScale(Vec2{ 20.f, 60.f });
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
		m_vPos.y -= m_fSpeed * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		m_vPos.y += m_fSpeed * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		m_vPos.x -= m_fSpeed * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		m_vPos.x += m_fSpeed * fDT;
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

void CPlayer::render(HDC _dc)
{
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();
	Vec2 vPos = GetPos();
	
	/*BitBlt(_dc, (int)(vPos.x - (float)(iWidth / 2))
			  , (int)(vPos.y - (float)(iHeight / 2))
			  ,	iWidth , iHeight, m_pTex->GetDC(), 0, 0, SRCCOPY);*/
	
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(iWidth / 2))
		, (int)(vPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 0, 255)
	);

	// 컴포넌트 충돌체 Render
	component_render(_dc);
}

void CPlayer::CreateMissile(MISSILE_MODE _mode)
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	shared_ptr<CMissile> pMissile = make_shared<CMissile>();
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetDir(Vec2(0.f,2.f));
	pMissile->SetMode(_mode);
	pMissile->SetCenterX(vMissilePos.x);

	auto curScene = CSceneMgr::GetInst()->GetCurScene(); 
	curScene->AddObject(pMissile,GROUP_TYPE::MISSILE);
}


