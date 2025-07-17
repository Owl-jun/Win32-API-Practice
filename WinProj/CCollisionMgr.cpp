#include "pch.h"
#include "CCollisionMgr.h"

#include "CSceneMgr.h"
#include "CScene.h"
#include "CObject.h"
#include "CCollider.h"

CCollisionMgr::CCollisionMgr()
{ 
}

CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::update()
{
	for (UINT iRow = 0; iRow < (UINT)GROUP_TYPE::END; ++iRow)
	{
		for (UINT iCol = iRow; iCol < (UINT)GROUP_TYPE::END; ++iCol)
		{
			if (m_arrCheck[iRow] & (1 << iCol))
			{
				CollisionGroupUpdate((GROUP_TYPE)iRow, (GROUP_TYPE)iCol);
			}
		}
	}
}

void CCollisionMgr::CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	UINT iRow = min((UINT)_eLeft, (UINT)_eRight);
	UINT iCol = max((UINT)_eLeft, (UINT)_eRight);

	if (m_arrCheck[iRow] & (1 << iCol))
	{
		m_arrCheck[iRow] &= ~(1 << iCol);
	}
	else
	{
		m_arrCheck[iRow] |= (1 << iCol);
	}
}

void CCollisionMgr::Reset()
{
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);
}

void CCollisionMgr::CollisionGroupUpdate(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	shared_ptr<CScene> pCurScene = CSceneMgr::GetInst()->GetCurScene();

	auto& vecLeft = pCurScene->GetGroupObject(_eLeft);
	auto& vecRight = pCurScene->GetGroupObject(_eRight);

	unordered_map<ULONGLONG, bool>::iterator iter;

	for (size_t i = 0; i < vecLeft.size(); ++i)
	{
		// �浹ü�� �������� �ʴ� ���
		if (nullptr == vecLeft[i]->GetCollider())
			continue;

		for (size_t j = 0; j < vecRight.size(); ++j)
		{
			// �浹ü�� ���ų�, �ڱ� �ڽŰ��� �浹�� ���
			if (nullptr == vecRight[i]->GetCollider()
				|| vecLeft[i] == vecRight[i])
				continue;

			CCollider* pLeftCol = vecLeft[i]->GetCollider();
			CCollider* pRightCol = vecRight[j]->GetCollider();;

			// �� �浹ü ���� ���̵� ����
			COLLIDER_ID ID;
			ID.Left_id = pLeftCol->GetId();
			ID.Right_id = pRightCol->GetId();

			iter = m_mapColInfo.find(ID.id);

			// �浹 ������ �� ��� ������ ��� ���
			if (m_mapColInfo.end() == iter)
			{
				m_mapColInfo.insert(make_pair(ID.id, false));
				iter = m_mapColInfo.find(ID.id);
			}

			if (IsCollision(pLeftCol, pRightCol))
			{
				// ���� �浹 ���̴�.

				if (iter->second)
				{
					// �������� �浹 �ϰ� �־���.
					pLeftCol->OnCollision(pRightCol);
					pRightCol->OnCollision(pLeftCol);
				}
				else
				{
					// �������� �浹���� �ʾҴ�.
					pLeftCol->OnCollisionEnter(pRightCol);
					pRightCol->OnCollisionEnter(pLeftCol);
					iter->second = true;
				}
			}
			else
			{
				if (iter->second)
				{
					// �������� �浹�ϰ� �־���.
					pLeftCol->OnCollisionExit(pRightCol);
					pRightCol->OnCollisionExit(pLeftCol);
					iter->second = false;
				}
			}
		}
	}

}

bool CCollisionMgr::IsCollision(CCollider* _pLeftCol, CCollider* _pRightCol)
{
	Vec2 vLeftPos = _pLeftCol->GetFinalPos();
	Vec2 vLeftScale = _pLeftCol->GetScale();
	Vec2 vRightPos = _pRightCol->GetFinalPos();
	Vec2 vRightScale = _pRightCol->GetScale();

	if (abs(vRightPos.x - vLeftPos.x) < ((vLeftScale.x + vRightScale.x) / 2.f)
		&& abs(vRightPos.y - vLeftPos.y) < ((vLeftScale.y + vRightScale.y) / 2.f))
	{
		// �浹
		return true;
	}

	return false;
}
