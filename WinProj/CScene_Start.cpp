#include "pch.h"
#include "CScene_Start.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CCore.h"

void CScene_Start::Enter()
{
	// Object 추가
	auto pObj = std::make_shared<CPlayer>();
	
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f,100.f));
	AddObject(pObj, GROUP_TYPE::DEFAULT);

	// Monster Object 추가
	int iMonCount = 16;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;
	Vec2 vResolution = CCore::GetInst()->GetResolution();
	float fTerm = (vResolution.x - ((fMoveDist + fObjScale/2) * 2)) / (float)(iMonCount - 1);
	for (int i = 0; i < iMonCount; ++i)
	{
		auto mObj = std::make_shared<CMonster>();
		mObj->SetPos(Vec2((fMoveDist + fObjScale / 2) + fTerm * i, 50.f));
		mObj->SetCenterPos(mObj->GetPos());
		mObj->SetMoveDistance(fMoveDist);
		mObj->SetScale(Vec2(fObjScale, fObjScale));
		AddObject(mObj, GROUP_TYPE::MONSTER);
	}
}

void CScene_Start::Exit()
{
}

CScene_Start::CScene_Start(wstring _name)
	: CScene(_name)
{
}

CScene_Start::~CScene_Start()
{
}
