#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H



using namespace std;


class CFileManager
{
  public:
		static uint64_t calFileSize(const string& fileName);
		
		static int calFileNum(const vector<string>& fileNameVec);
		
		static string getFileName(const string& dir, const int iFileName);

		static string getFileName(const stationId_t id, const int fileNum);
};

#endif
