#include "pch.h"
#include "CAnimator.h"

void CAnimator::CreateAnimation()
{
}

void CAnimator::FindAnimation()
{
}

void CAnimator::Play()
{
}

CAnimator::CAnimator()
	: m_pOwner(nullptr)
{
}

CAnimator::~CAnimator()
{
	Safe_Delete_Map(m_mapAnim);
}
