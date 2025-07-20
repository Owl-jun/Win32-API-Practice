#include "pch.h"
#include "CSceneMgr.h"
#include "CScene_Start.h"
#include "CScene_Tool.h"
#include "CEventMgr.h"

CSceneMgr::CSceneMgr()
	: m_pCurScene(nullptr)
{

}

CSceneMgr::~CSceneMgr()
{

}

void CSceneMgr::init()
{
	// Scene ����
	m_arrScene[(UINT)SCENE_TYPE::START] = std::make_shared<CScene_Start>(L"Start Scene");
	m_arrScene[(UINT)SCENE_TYPE::TOOL] = std::make_shared<CScene_Tool>(L"Tool Scene");
	//m_arrScene[(UINT)SCENE_TYPE::STAGE_01] = std::make_shared<CScene_Stage01>();
	//m_arrScene[(UINT)SCENE_TYPE::STAGE_02] = std::make_shared<CScene_Stage02>();
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::TOOL];
	m_pCurScene->Enter();
}

void CSceneMgr::update()
{
	m_pCurScene->update();		// �� ������ �� ��ǵ� �߻�
	m_pCurScene->finalupdate();	// �� ������ �Ͼ ��ǵ� ���� (������ ����ȭ)
}

void CSceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}

void CSceneMgr::ChangeScene(SCENE_TYPE _eNext)
{
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(UINT)_eNext];
	m_pCurScene->Enter();
}

