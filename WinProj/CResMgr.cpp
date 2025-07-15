#include "pch.h"
#include "CResMgr.h"
#include "CPathMgr.h"

CResMgr::CResMgr()
{

}

CResMgr::~CResMgr()
{
	m_mapTex.clear();
}

shared_ptr<CTexture> CResMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{

	shared_ptr<CTexture> pTex = FindTexture(_strKey);
	if (nullptr != pTex)
		return pTex;
	
	wstring strFilePath = PATH;
	strFilePath += _strRelativePath;

	CTexture* rawPtr = new CTexture();
	pTex = shared_ptr<CTexture>(rawPtr, TextureDeleter());

	pTex->Load(strFilePath);
	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath);

	m_mapTex.insert(make_pair(_strKey,pTex));

	return pTex;
}

shared_ptr<CTexture> CResMgr::FindTexture(const wstring& _strKey)
{
	auto it = m_mapTex.find(_strKey);
	if (it != m_mapTex.end()) { return it->second; }
	else return nullptr;
}
