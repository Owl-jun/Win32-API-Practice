#include "pch.h"
#include "CTimeMgr.h"
#include "CCore.h"

CTimeMgr::CTimeMgr()
	: m_llCurCount{}
	, m_llPrevCount{}
	, m_llFrequency{}
	, m_dDT(0.)
	, m_dAcc(0.)
	, m_iCallCount()
	, m_iFPS()
{
}

CTimeMgr::~CTimeMgr()
{
}

void CTimeMgr::init()
{
	// 현재 카운트
	QueryPerformanceCounter(&m_llPrevCount);
	// 초당 카운트 횟수
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);
	
	m_dDT = ((double)m_llCurCount.QuadPart - (double)m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;
	
	m_llPrevCount = m_llCurCount;

}

void CTimeMgr::render()
{
	++m_iCallCount;
	m_dAcc += m_dDT; // DT 누적

	if (1. <= m_dAcc)
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0.;
		m_iCallCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d DT : %f", m_iFPS, m_dDT);
		SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);
	}
}
