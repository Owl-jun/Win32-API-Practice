#pragma once

// 1. 프레임 동기화
// 동일 프레임 내에서 같은 키에 대해, 동일한 이벤트를 가져간다.

// 2. 키 입력 이벤트 처리
// tap, hold, away

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,W,E,R,T,Y,U,I,O,P,

	A,S,D,F,G,Z,X,C,V,B,

	ALT,
	CTRL,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LBTN,
	RBTN,


	LAST,
};

enum class KEY_STATE
{
	NONE,	// 눌리지 않고, 이전에도 눌리지 않은 상태
	TAP,	// 막 누른 시점
	HOLD,	// 누르고 있는
	AWAY	// 막 뗀 시점
};

struct tKeyInfo
{
	KEY_STATE	eState;
	bool		bPrevPush;
};

class CKeyMgr
{
	SINGLE(CKeyMgr);
private:
	vector<tKeyInfo> m_vecKey;
	Vec2			 m_vCurMousePos;
public:
	void init();
	void update();
public:
	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKey[(int)_eKey].eState; }
	Vec2 GetMousePos() { return m_vCurMousePos; }
};

