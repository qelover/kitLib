#ifndef BIG_LITTLE_END_H
#define BIG_LITTLE_END_H

/*
 * @brief: big end and little end transfer mutually
 */
int bigLittleTrans(char* pOutput, const char* pInput, size_t len)
{
    char buf[len];
    for (size_t i=0,j=len-1; i<len; ++i,j--)
		    pOutput[j] = pInput[i];
}

#endif
