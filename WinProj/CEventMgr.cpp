#include "pch.h"

#include "CObject.h"
#include "CEventMgr.h"
#include "CSceneMgr.h"
#include "CScene.h"

CEventMgr::CEventMgr()
{ }
CEventMgr::~CEventMgr()
{ }

void CEventMgr::update()
{
	// ===================================================
	// 이전 프레임에서 등록해둔 Dead Object 들을 삭제한다.
	// ===================================================
	for (size_t i = 0; i < m_vecDead.size(); ++i)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();

	// ==========
	// EVENT 처리
	// ==========
	for (size_t i = 0; i < m_vecEvent.size(); ++i)
	{
		Execute(m_vecEvent[i]);
	}
	m_vecEvent.clear();
}

void CEventMgr::Execute(const tEvent& _eve)
{
	switch (_eve.eEven)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// lParam : Object Address
		// wParam : Group Type
		CObject* cObj = (CObject*)_eve.lParam;
		GROUP_TYPE eType = (GROUP_TYPE)_eve.wParam;

		CSceneMgr::GetInst()->GetCurScene()->AddObject(cObj, eType);
	}
		break;
	case EVENT_TYPE::DELETE_OBJECT:
	{
		// lParam : Object Address
		// wParam : Null
		// Object를 Dead 상태로 변경
		// 삭제예정 오브젝트를 모아둔다.

		CObject* pDeadObj = (CObject*)_eve.lParam;
		pDeadObj->SetDead();
		m_vecDead.push_back(pDeadObj);
	}
		break;
	case EVENT_TYPE::SCENE_CHANGE:
		// lParam : Next Scene Type
		CSceneMgr::GetInst()->ChangeScene((SCENE_TYPE)_eve.lParam);
		break;
	}
}
