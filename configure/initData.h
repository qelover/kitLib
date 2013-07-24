#ifndef INIT_DATA_H
#define INIT_DATA_H

#include "iniFile.h"

using namespace std;


class InitData
{
  public:
		static bool init(const char* iniFileName);

		static CIniFile& getIniFile();
	
	private:
		static CIniFile* m_iniFile;
};

#endif
