#coding: utf-8

import os
import os.path


def getFileNameList(fileNameList, rootdir):
    flag = os.path.isdir(rootdir)
    if False == flag:
        fileNameList.append(rootdir)
    else:
        #print rootdir
        for parent, dirnames, filenames in os.walk(rootdir):
            #print parent, ", ", dirnames, ", ", filenames
            for filename in filenames:
                fullFileName = os.path.join(parent, filename)
                fileNameList.append(fullFileName)
            	#print fullFileName


if __name__ == "__main__":
    rootdir = ""
    fileNameList = []
    getFileNameList(fileNameList, rootdir)
    print fileNameList
