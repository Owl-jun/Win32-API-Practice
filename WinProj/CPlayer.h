#pragma once
#include "CObject.h"
#include "CMissile.h"

class CPlayer : public CObject
{
private:
	float m_fAttackCoolDown;
	float m_fSkillCoolDown;
public:
	CPlayer();
	~CPlayer();
public:
	void update() override;

private:
	void CreateMissile(MISSILE_MODE _mode);

};

