#pragma once

class CObject;

class CCollider
{
private:
	CObject*	m_pOwner;		// collider�� �����ϰ� �ִ� ������Ʈ

	Vec2		m_vOffsetPos;	// ������Ʈ�� ���� ������� ��ġ
	Vec2		m_vFinalPos;	// finalupdate���� �� �����Ӹ��� ���
public:
	void finalupdate();

public:
	CCollider();
	~CCollider();
	friend class CObject;
};

