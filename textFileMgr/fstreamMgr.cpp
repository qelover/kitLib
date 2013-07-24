#include <sstream>
#include <iostream>

#include "fstreamMgr.h"




FStreamMgr* FStreamMgr::m_cpFStreamMgr = NULL;
hash_map<string, fstream*> FStreamMgr::m_fsHashMap;
FStreamMgr::DestroyFStreamMgr FStreamMgr::cDesFStreamMgr;


FStreamMgr::FStreamMgr()
{
}

FStreamMgr::~FStreamMgr()
{
}

void FStreamMgr::Destroy()
{
  hash_map<string, fstream*>::iterator iter = m_fsHashMap.begin();
	for (; iter != m_fsHashMap.end(); ++iter)
	{
		if (iter->second != NULL)
		{
			iter->second->close();
			delete (iter->second);
			iter->second = NULL;
		}
	}
	m_fsHashMap.clear();

	if (m_cpFStreamMgr != NULL)
	{
		delete m_cpFStreamMgr;
		m_cpFStreamMgr = NULL;
	}
}

FStreamMgr* FStreamMgr::getInstance()
{
	if (m_cpFStreamMgr == NULL)
	{
		//防止编译器将内部类DestroyFStreamMgr优化掉
		cDesFStreamMgr;

		m_cpFStreamMgr = new FStreamMgr();
	}

	return m_cpFStreamMgr;
}

fstream* FStreamMgr::getFStream(const string& fileName)
{
	hash_map<string, fstream*>::iterator iter = m_fsHashMap.find(fileName);
	if ( iter != m_fsHashMap.end() )
	{//found
		return iter->second;
	}

	return NULL;
}

void FStreamMgr::addFStream(const string& fileName, fstream* pFStream)
{
	m_fsHashMap.insert(pair<string, fstream*>(fileName, pFStream) );
}
