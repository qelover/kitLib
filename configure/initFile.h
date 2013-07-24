#ifndef INIFILE_H
#define INIFILE_H

 
#include <iostream>
#include <vector>
#include <map>


class CInitFile
{
	public:
		static const int InvalidInt;

	public:
		CIniFile(){};

		~CIniFile(){};

		bool open(const char* fileName);	

		std::string get(const std::string& key) const;

		std::string get(const std::string& key, const std::string& defaultValue) const;

		int getInt(const std::string& key, int defaultValue=(int)InvalidInt) const;

		long getLong(const std::string& key, long defaultValue=(long)InvalidInt) const;

		double getDouble(const std::string& key, double defaultValue=(double)InvalidInt) const;
                

   private:
    std::map<std::string, std::string>  m_key2Value;

		bool m_isOpen;

};

#endif
