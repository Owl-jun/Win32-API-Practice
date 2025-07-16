#include "pch.h"
#include "CMonster.h"
#include "CTimeMgr.h"
#include "CResMgr.h"

CMonster::CMonster()
	: m_vCenterPos(Vec2(0.f,0.f))
	, m_fSpeed(100.f)
	, m_fMaxDistance(50.f)
	, m_iDir(1)
	, m_pTex(nullptr)
{
	m_pTex = GETTEX(L"MonsterTex", L"texture\\Monster.bmp");
	CreateCollider();
}

CMonster::~CMonster()
{
}

void CMonster::update()
{
	Vec2 vCurPos = GetPos();

	// ���� �������� �ð��� m_fSpeed ��ŭ �̵�
	vCurPos.x += fDT * m_fSpeed * m_iDir;

	// ��Ʈ�� �Ÿ� �ʰ��ߴ��� Ȯ��
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

	TransparentBlt(_dc
		, (int)(vPos.x - (float)(iWidth / 2))
		, (int)(vPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 0, 255)
	);
}

