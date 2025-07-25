#pragma once

class CObject;
class CAnimation;
class CTexture;

class CAnimator
{
private:
	unordered_map<wstring, CAnimation*> m_mapAnim;
	CAnimation*							m_pCurAnim;
	CObject*							m_pOwner;
	bool								m_bRepeat;

public:
	void CreateAnimation(const wstring& _strName, CTexture* _pTex, 
		Vec2 _vLT, Vec2 _SliceSize, Vec2 _vStep, float _fDuration, UINT _iFrameCount);
	CAnimation* FindAnimation(const wstring& _strName);
	void Play(const wstring& _strName, bool _repeat);

	void update();
	void render(HDC _dc);
public:
	CObject* GetObj() { return m_pOwner; }

public:
	CAnimator();
	~CAnimator();

	friend class CObject;
};

