#include "pch.h"
#include "CScene_Start.h"
#include "CObject.h"

void CScene_Start::Enter()
{
	// Object Ãß°¡
	auto pObj = std::make_shared<CObject>();
	
	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f,100.f));

	AddObject(pObj, GROUP_TYPE::DEFAULT);
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
