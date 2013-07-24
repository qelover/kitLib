/*
  @brief: maintain a list of fstream*
          reduce cost caused by frequently file opening and closing
*/


#ifndef FSTREAM_MANAGER_H
#define FSTREAM_MANAGER_H

#include <fstream>
#include "hash_map.h"


using namespace std;


class FStreamMgr
{
public:
	static FStreamMgr* getInstance();
	
	static void Destroy();

	fstream* getFStream(const string& fileName);

	void addFStream(const string& fileName, fstream* pFStream);
	
	hash_map<string, fstream*>& getAllFStream() {return m_fsHashMap; }

private:
	FStreamMgr();
	
	~FStreamMgr();
	
private:
	static hash_map<string, fstream*> m_fsHashMap;

	static FStreamMgr* m_cpFStreamMgr;

	class DestroyFStreamMgr
	{
		public:
			~DestroyFStreamMgr()
			{
				FStreamMgr::Destroy();
			}
	};
	static DestroyFStreamMgr cDesFStreamMgr;
};

#endif
