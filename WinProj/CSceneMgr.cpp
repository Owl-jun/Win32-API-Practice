#include "pch.h"
#include "CSceneMgr.h"
#include "CScene_Start.h"


CSceneMgr::CSceneMgr()
	: m_pCurScene(nullptr)
{

}

CSceneMgr::~CSceneMgr()
{

}

void CSceneMgr::init()
{
	// Scene »ý¼º
	m_arrScene[(UINT)SCENE_TYPE::START] = std::make_shared<CScene_Start>(L"Start Scene");
	//m_arrScene[(UINT)SCENE_TYPE::TOOL] = std::make_shared<CScene_Tool>();
	//m_arrScene[(UINT)SCENE_TYPE::STAGE_01] = std::make_shared<CScene_Stage01>();
	//m_arrScene[(UINT)SCENE_TYPE::STAGE_02] = std::make_shared<CScene_Stage02>();
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_pCurScene->Enter();
}

void CSceneMgr::update()
{
	m_pCurScene->update();
	m_pCurScene->finalupdate();
}

void CSceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}
