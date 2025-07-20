#pragma once
#include "CObject.h"
class CMonster : public CObject
{
private:
	Vec2					m_vCenterPos;
	float					m_fSpeed;
	float					m_fMaxDistance;
	int						m_iDir;	// 1 : right , -1 : left
	int						m_iHP;
private:
	CTexture*	m_pTex;
public:
	float GetSpeed() { return m_fSpeed; }
	void SetSpeed(float _spd) { m_fSpeed = _spd; }
	void SetMoveDistance(float _f) { m_fMaxDistance = _f; }
	void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }

	void OnCollisionEnter(CCollider* _pOther) override;

public:
	void update() override;
	void render(HDC _dc) override;
	CLONE(CMonster);

public:
	CMonster();
	~CMonster();
};

