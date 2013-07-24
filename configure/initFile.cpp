#include <iostream>
#include <fstream>
#include <sstream>

#include "initFile.h"
#include "strUtil.h"


#define  EQUAL "="


const int CIniFile::InvalidInt = -1;


bool CIniFile::open(const char * fileName)
{
  std::ifstream fin(fileName);	
	if(!fin.is_open())
	{
			return false;
	}
  
	m_key2Value.clear();
  
	fin.seekg( 0, std::ios::beg );
	char buffer[255];
  
	while( fin.getline(buffer,255) )
	{
		std::string lineString(buffer);		
		std::string::size_type loc = lineString.find(EQUAL);
		if(std::string::npos != loc)
		{
			std::string keyWithSpace=lineString.substr(0,loc);	
			std::string key= CStrUtil::removeSpace(keyWithSpace);
			std::string value= lineString.substr(loc+1);
			value= CStrUtil::removeSpace(value);
      
			if(!key.empty() && !value.empty())
				m_key2Value[key]= CStrUtil::removeSpace(value);
		}
    
		memset(buffer, 0, 255);
	}
  
	fin.close();
  
	return true;
}

std::string CIniFile::get(const std::string& key) const
{
	std::map<std::string,std::string>::const_iterator iter = m_key2Value.find(key);
	return iter != m_key2Value.end() ? iter->second : "";
}

std::string CIniFile::get(const std::string& key,const std::string& defaultValue) const
{
	std::string tmp = get(key);
	return !tmp.empty() ? tmp : defaultValue;
}

int CIniFile::getInt(const std::string& key, int defaultValue) const
{
	std::string tmp = get(key);
	if( tmp.empty() )
		return defaultValue;
	return atoi(tmp.c_str());
}

long CIniFile::getLong(const std::string& key, long defaultValue) const
{
	std::string tmp = get(key);
	if( tmp.empty() )
		return defaultValue;
	return atol(tmp.c_str());
}

double CIniFile::getDouble(const std::string& key, double defaultValue) const
{
	std::string tmp = get(key);
	if( tmp.empty() )
		return defaultValue;
	return atof(tmp.c_str());
}
