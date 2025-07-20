#include "pch.h"
#include "CScene_Start.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CCore.h"
#include "CPathMgr.h"
#include "CTexture.h"
#include "CBackGround.h"
#include "CCollisionMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CCamera.h"

void CScene_Start::update()
{
	CScene::update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::TOOL);
	}

	if (KEY_TAP(KEY::LBTN))
	{
		Vec2 vLookAt = CCamera::GetInst()->GetRealPos(MOUSE_POS);
		CCamera::GetInst()->SetLookAt(vLookAt);
		
	}
}

void CScene_Start::Enter()
{
	//auto bg = new CBackGround();
	//bg->SetPos(Vec2(640.f, 384.f));
	//AddObject(bg, GROUP_TYPE::DEFAULT);

	// Object 추가
	auto pObj = new CPlayer();
	
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f,100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	//CObject* pOtherPlayer = pObj->Clone();
	//pOtherPlayer->SetPos(Vec2(700.f, 384.f));
	//AddObject(pOtherPlayer, GROUP_TYPE::PLAYER);

	//CCamera::GetInst()->SetTarget(pObj);

	// Monster Object 추가
	int iMonCount = 8;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;
	Vec2 vResolution = CCore::GetInst()->GetResolution();
	float fTerm = (vResolution.x - ((fMoveDist + fObjScale/2) * 2)) / (float)(iMonCount - 1);
	for (int i = 0; i < iMonCount; ++i)
	{
		auto mObj = new CMonster();
		mObj->SetName(L"Monster");
		mObj->SetPos(Vec2((fMoveDist + fObjScale / 2) + fTerm * i, 50.f * randint(1,3)));
		mObj->SetCenterPos(mObj->GetPos());
		mObj->SetMoveDistance(fMoveDist);
		mObj->SetScale(Vec2(fObjScale, fObjScale));
		AddObject(mObj, GROUP_TYPE::MONSTER);
	}

	// 충돌 지정
	// Player 그룹과 Monster 그룹 관의 충돌 체크
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::PROJ_PLAYER);

	// Camera Look 지정
	CCamera::GetInst()->SetLookAt(vResolution / 2.f);

}

void CScene_Start::Exit()
{
	DeleteAll();
	CCollisionMgr::GetInst()->Reset();
}

CScene_Start::CScene_Start(wstring _name)
	: CScene(_name)
{
}

CScene_Start::~CScene_Start()
{
}
