#pragma once
#include "CObject.h"
#include "CTexture.h"

class CBackGround : public CObject
{
private:
	CTexture*	m_pTex;

public:
	void update() override;
	void render(HDC _dc) override;

public:
	CBackGround();
	~CBackGround();
	CLONE(CBackGround);
};

