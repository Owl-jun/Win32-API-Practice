#pragma once
class CPathMgr
{
	SINGLE(CPathMgr);
private:
	wchar_t		m_szContentPath[255];	// Window 경로 글자 제한 255자

public:
	void init();
	const wchar_t* GetContentPath() { return m_szContentPath; }
};

