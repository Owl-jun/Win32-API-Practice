#pragma once
#include "CScene.h"

class CScene_Start : public CScene
{
private:
public:
	void update() override;
	void Enter() override;
	void Exit() override;
public:
	CScene_Start(wstring _name);
	~CScene_Start();
};

