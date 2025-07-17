#pragma once

class CCollider;

class CObject
{
private:
	wstring		m_wName;
	Vec2		m_vPos;
	Vec2		m_vScale;
	
	CCollider*	m_pCollider;

public:
	void SetPos(const Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(const Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	const wstring& GetName() { return m_wName; }

	void CreateCollider();

	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);

public:
	virtual void update() = 0;
	virtual void finalupdate() final;
	virtual void render(HDC _dc);

	void component_render(HDC _dc);
	CCollider* GetCollider() { return m_pCollider; }
public:
	CObject();
	virtual ~CObject();

};

