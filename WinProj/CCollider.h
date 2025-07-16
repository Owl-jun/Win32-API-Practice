#pragma once

class CObject;

class CCollider
{
private:
	CObject*	m_pOwner;		// collider를 소유하고 있는 오브젝트

	Vec2		m_vOffsetPos;	// 오브젝트로 부터 상대적인 위치
	Vec2		m_vFinalPos;	// finalupdate에서 매 프레임마다 계산
public:
	void finalupdate();

public:
	CCollider();
	~CCollider();
	friend class CObject;
};

