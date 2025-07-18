#pragma once
class CScene;

class CSceneMgr
{
	SINGLE(CSceneMgr);

private:
	shared_ptr<CScene>		m_arrScene[(UINT)SCENE_TYPE::END];
	shared_ptr<CScene>		m_pCurScene;

public:
	void init();
	void update();
	void render(HDC _dc);

public:
	shared_ptr<CScene> GetCurScene() { return m_pCurScene; }
private:
	void ChangeScene(SCENE_TYPE _eNext);
	friend class CEventMgr;
};

