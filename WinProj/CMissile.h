#pragma once
#include "CObject.h"

enum class MISSILE_MODE
{
	NORMAL,
	SUPER,
	END
};

class CMissile : public CObject
{
private:
	Vec2			m_vDir;

	MISSILE_MODE	m_cMode;
	float			m_fTheta; // πÊ«‚
	float			m_fET;
	float			m_fFreq;
	float			m_fAmp;
	float			m_fCenterX;
	float			m_fSpeed;

private:
	shared_ptr<CTexture>	m_pNormalTex;
	shared_ptr<CTexture>	m_pSuperTex;

public:
	void SetDir(Vec2 _vDir)	{ 
		m_vDir = _vDir; 
		m_vDir.Normalize();
	}
	void SetMode(MISSILE_MODE _mode) { m_cMode = _mode; }
	void SetCenterX(float _x) { m_fCenterX = _x; }

private:
	void update() override;
	void render(HDC _dc) override;

public:
	CMissile();
	~CMissile();
};

