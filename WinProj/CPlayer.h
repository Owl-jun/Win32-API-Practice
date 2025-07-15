#pragma once
#include "CObject.h"
#include "CMissile.h"
#include "CTexture.h"


class CPlayer : public CObject
{
private:
	float					m_fAttackCoolDown;
	float					m_fSkillCoolDown;
	float					m_fSpeed;
private:
	shared_ptr<CTexture>	m_pTex;

public:
	CPlayer();
	~CPlayer();
public:
	void update() override;
	void render(HDC _dc) override;
private:
	void CreateMissile(MISSILE_MODE _mode);

};

