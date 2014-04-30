#include <iostream>
#include <vector>

#include <stdio.h>  
#include <string.h> 
#include <stdlib.h>  
#include <dirent.h>  
#include <sys/stat.h>  
#include <unistd.h>  
#include <sys/types.h> 


void listDir(std::vector<std::string>& filePathVec, char* path)
{
    DIR              *pDir ;   
    struct dirent    *ent  ;   
    int               i=0  ;   
    char              childpath[512];  

    pDir = opendir(path);  
    memset(childpath, 0, sizeof(childpath));

    while( (ent = readdir(pDir)) != NULL )
    {
        if(ent->d_type & DT_DIR)
        {   
            if(0 == strcmp(ent->d_name,".") || 0 == strcmp(ent->d_name,"..") )
                    continue;
            
            sprintf(childpath, "%s/%s", path, ent->d_name);
            //printf("path:%s\n", childpath);  
            
            listDir(filePathVec, childpath);
        }  
        else
        {   
            //std::cout<<ent->d_name<<std::endl;
            filePathVec.push_back(ent->d_name);
        }
    }
    closedir(pDir);
}
