#pragma once

#define SINGLE(type) public:\
						static type* GetInst()\
						{\
							static type mgr;\
							return &mgr;\
						}\
					 private:\
						type();\
						~type();

#define CLONE(type) type* Clone() override {return new type(*this);}

#define GETTEX(key, path) CResMgr::GetInst()->LoadTexture(key, path)
#define PATH CPathMgr::GetInst()->GetContentPath()

#define DT CTimeMgr::GetInst()->GetDT()
#define fDT CTimeMgr::GetInst()->GetfDT()

#define GETKEY(key) CKeyMgr::GetInst()->GetKeyState(key)
#define KEY_HOLD(key)	GETKEY(key) == KEY_STATE::HOLD
#define KEY_TAP(key)	GETKEY(key) == KEY_STATE::TAP
#define KEY_AWAY(key)	GETKEY(key) == KEY_STATE::AWAY
#define KEY_NONE(key)	GETKEY(key) == KEY_STATE::NONE

#define PI 3.141592f

enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MONSTER,
	PROJ_PLAYER,
	PROJ_MONSTER,



	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,


	END,
};

enum class BRUSH_TYPE
{
	HOLLOW,
	END,
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END
};

enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,



	END,
};