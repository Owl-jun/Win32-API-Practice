#pragma once
#include "CScene.h"
class CScene_Tool : public CScene
{
private:

public:
	void update() override;
	void Enter() override;
	void Exit() override;

public:
	CScene_Tool(wstring _name);
	~CScene_Tool();
};

