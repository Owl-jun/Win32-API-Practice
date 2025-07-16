#include "pch.h"
#include "CCollider.h"
#include "CObject.h"

void CCollider::finalupdate()
{
	Vec2 vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;
}

CCollider::CCollider()
	: m_pOwner(nullptr)
	, m_vOffsetPos({0.f,0.f})
	, m_vFinalPos{}
{
}

CCollider::~CCollider()
{
}
