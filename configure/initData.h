/*
  @brief: single instance of CInitFile
*/


#ifndef INIT_DATA_H
#define INIT_DATA_H

#include "initFile.h"

using namespace std;


class InitData
{
  public:
	static bool init(const char* iniFileName);

	static CInitFile& getIniFile();

  private:
	static CInitFile* m_iniFile;
};

#endif
