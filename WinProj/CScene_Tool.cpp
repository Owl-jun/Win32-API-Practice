#include "pch.h"
#include "CScene_Tool.h"
#include "CKeyMgr.h"
#include "CTile.h"
#include "CCore.h"
#include "CResMgr.h"

CScene_Tool::CScene_Tool(wstring _name)
	: CScene(_name)
{
}

CScene_Tool::~CScene_Tool()
{
}

void CScene_Tool::Enter()
{
	CTexture* pTileTex = GETTEX(L"Tile", L"texture\\tile\\TILE.bmp");

	// 타일 생성
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			CTile* pTile = new CTile();

			pTile->SetPos(Vec2(j * TILE_SIZE, i * TILE_SIZE));
			pTile->SetTexture(pTileTex);
			AddObject(pTile, GROUP_TYPE::TILE);
		}
	}

	Vec2 vResolution = CCore::GetInst()->GetResolution();
	CCamera::GetInst()->SetLookAt(vResolution / 2.f);


}

void CScene_Tool::Exit()
{
}

void CScene_Tool::update()
{
	CScene::update();

	if (KEY_TAP(KEY::LBTN))
	{
		Vec2 vLookAt = CCamera::GetInst()->GetRealPos(MOUSE_POS);
		CCamera::GetInst()->SetLookAt(vLookAt);

	}

}


