
#include "initData.h"


CIniFile* InitData::m_iniFile = NULL;
  	

bool InitData::init(const char* iniFileName) 
{ 
	if( NULL == iniFileName )
	{
		std::cerr<<"InitData::init: input file pointer is NULL "<<std::endl;
		return false;
	}

	if ( NULL == m_iniFile )
	{	
		m_iniFile = new CIniFile();

		if( !m_iniFile->open(iniFileName) )
		{
			std::cerr<<"InitData::init: can not open :"<<iniFileName<<std::endl;
			return false;
		}
	}
	return true;
}
		
CIniFile& InitData::getIniFile()
{ 
	return (*m_iniFile); 
}
