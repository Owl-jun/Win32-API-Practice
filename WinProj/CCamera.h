#pragma once

class CObject;

class CCamera
{
	SINGLE(CCamera);

private:
	Vec2		m_vLookAt;	// 카메라가 보는 위치
	Vec2		m_vCurLookAt;	// 이전위치와 현재위치 보정 위치
	Vec2		m_vPrevLookAt;	// 카메라가 보는 이전프레임 위치

	CObject*	m_pTargetObj; // 카메라 타겟 오브젝트
	Vec2		m_vDiff;	// 화면 중앙 좌표와 카메라 LookAt 좌표간의 차이값
	
	float		m_fTime;	// 타겟을 따라가는 시간.
	float		m_fSpeed;
	float		m_fAccTime;

public:
	void SetLookAt(Vec2 _vLook) 
	{ 
		m_vLookAt = _vLook; 
		float fMoveDist = (m_vLookAt - m_vPrevLookAt).Length();
		m_fSpeed = fMoveDist / m_fTime;
		m_fAccTime = 0.f;
	}
	void SetTarget(CObject* _pTarget) { m_pTargetObj = _pTarget; }
	Vec2 GetLookAt() { return m_vCurLookAt; }
	Vec2 GetRenderPos(Vec2 _vObjPos) { return _vObjPos - m_vDiff; }
	Vec2 GetRealPos(Vec2 _vRenderPos) { return _vRenderPos + m_vDiff; }

public:
	void update();

	void CalDiff();

};

