#pragma once
#include "CObject.h"
class CMissile : public CObject
{
private:
	float		m_fDir; // πÊ«‚
public:
	void SetDir(bool _bUp)	{ m_fDir = _bUp ? -1.f : 1.f; }
private:
	void update() override;
	void render(HDC _dc) override;
public:
	CMissile();
	~CMissile();
};

