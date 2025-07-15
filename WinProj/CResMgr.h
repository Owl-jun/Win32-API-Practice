#pragma once

#include "CTexture.h"

class CResMgr
{
	SINGLE(CResMgr);
private:
	unordered_map<wstring, shared_ptr<CTexture>> m_mapTex;

public:
	shared_ptr<CTexture> LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	shared_ptr<CTexture> FindTexture(const wstring& _strKey);
};

