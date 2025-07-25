#include "pch.h"
#include "CMonster.h"
#include "CTimeMgr.h"
#include "CResMgr.h"
#include "CCollider.h"
#include "CCamera.h"

CMonster::CMonster()
	: m_vCenterPos(Vec2(0.f,0.f))
	, m_fSpeed(100.f)
	, m_fMaxDistance(50.f)
	, m_iDir(1)
	, m_pTex(nullptr)
	, m_iHP(5)
{
	m_pTex = GETTEX(L"MonsterTex", L"texture\\Monster.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vec2{ 48.f,24.f });
	GetCollider()->SetOffsetPos(Vec2{ 0.f, 10.f });
}

CMonster::~CMonster()
{
}

void CMonster::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Missile_Player")
	{
		if (0 >= --m_iHP)
			DeleteObject(this);
	}
}

void CMonster::update()
{
	Vec2 vCurPos = GetPos();

	// 진행 방향으로 시간당 m_fSpeed 만큼 이동
	vCurPos.x += fDT * m_fSpeed * m_iDir;

	// 패트롤 거리 초과했는지 확인
	float fLeft = m_vCenterPos.x - m_fMaxDistance;
	float fRight = m_vCenterPos.x + m_fMaxDistance;
	if (vCurPos.x < fLeft)
	{
		m_iDir = 1;
		vCurPos.x = fLeft;
	}
	else if (vCurPos.x > fRight)
	{
		m_iDir = -1;
		vCurPos.x = fRight;
	}
	SetPos(vCurPos);
}

void CMonster::render(HDC _dc)
{
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();
	Vec2 vPos = GetPos();

	vPos = CCamera::GetInst()->GetRenderPos(vPos);

	// 255 , 0 , 255 (마젠타) 색 크로마키 화 해서 Blt
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(iWidth / 2))
		, (int)(vPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 0, 255)
	);

	component_render(_dc);
}

