#pragma once

class CAnimator;
class CTexture;

struct tAnimFrm
{
	Vec2	vLT;
	Vec2	vSlice;
	float	fDuration;
};

class CAnimation
{
private:
	wstring					m_strName;
	CAnimator*				m_pAnimator;
	shared_ptr<CTexture>	m_pTex;			// Animation이 사용하는 텍스쳐
	vector<tAnimFrm>		m_vecFrm;		// 모든 프레임 정보
	int						m_iCurFrm;
	float					m_fAccTime;

	bool					m_bFinish;

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }
	bool IsFinish() { return m_bFinish; }
	void SetFrame(int _iFrameIdx)
	{
		m_bFinish = false;
		m_iCurFrm = _iFrameIdx;
		m_fAccTime = 0.f;
	}

public:
	void update();
	void render(HDC _dc);
	void Create(shared_ptr<CTexture> _pTex, Vec2 _vLT, Vec2 _SliceSize, Vec2 _vStep, float _fDuration, UINT _iFrameCount);

public:
	CAnimation();
	~CAnimation();

	friend class CAnimator;
};

