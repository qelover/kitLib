#include <sys/stat.h>
#include <math.h>
#include <sstream>

#include "fileManager.h"
#include "initData.h"
#include "configFileMgr.h"


uint64_t CFileManager::calFileSize(const string& fileName)
{
  struct stat info;
	stat(fileName.c_str(), &info);

	uint64_t size = info.st_size;
	
	return size;
}

int CFileManager::calFileNum(const vector<string>& fileNameVec)
{
	uint64_t totalFileSize = 0;
	vector<string>::const_iterator iter = fileNameVec.begin();
	for (; iter != fileNameVec.end(); ++iter)
	{
		totalFileSize += calFileSize(*iter);
	}

	uint64_t iAvailMemSize = atol( InitData::getIniFile().get(CConfigFile::AvailMemKey).c_str() );

	if ( 0 == iAvailMemSize )
	{
		cerr<<"No available memory allowed in config file, in CFileManager::calFileNum()!"<<endl;
		return 0;
	}
	else
	{
		int fileNum = (int)ceil(totalFileSize / (double)iAvailMemSize);
		return fileNum;
	}
}


string CFileManager::getFileName(const string& dir, const int iFileName)
{
	stringstream ss;
	ss<<dir<<"/"<<iFileName<<".txt";

	return ss.str();
}

string CFileManager::getFileName(const stationId_t id, const int fileNum)
{
	int iFileName = id % fileNum;

	stringstream ss;
	ss<<iFileName
	  <<".txt";

	return ss.str();
}

