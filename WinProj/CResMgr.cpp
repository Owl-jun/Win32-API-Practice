#include "pch.h"
#include "CResMgr.h"
#include "CPathMgr.h"

CResMgr::CResMgr()
{

}

CResMgr::~CResMgr()
{
	for (auto m : m_mapTex)
	{
		delete m.second;
	}
}

CTexture* CResMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	wstring strFilePath = PATH;
	strFilePath += _strRelativePath;

	CTexture* pTex = FindTexture(_strKey);
	if (nullptr != pTex)
		return pTex;
	
	pTex = new CTexture();
	pTex->Load(strFilePath);
	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath);

	m_mapTex.insert(make_pair(_strKey,pTex));

	return pTex;
}

CTexture* CResMgr::FindTexture(const wstring& _strKey)
{
	auto it = m_mapTex.find(_strKey);
	if (it != m_mapTex.end()) { return it->second; }
	else return nullptr;
}
