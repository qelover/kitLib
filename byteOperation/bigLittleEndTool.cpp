#include <stdio.h>
#include <stdlib.h>


#define BigtoLittle32(A)   ((( (int)(A) & 0xff000000) >> 24) | (( (int)(A) & 0x00ff0000) >> 8) | \
                           (( (int)(A) & 0x0000ff00) << 8)  | (( (int)(A) & 0x000000ff) << 24))
#define BigtoLittle16(A)   (( ((int)(A) & 0xff00) >> 8)    | \
                           (( (int)(A) & 0x00ff) << 8))


int BigLittleEx(int a)
{
    printf("test: %x, %x, %x\n", (((int)a)&0xffffffff), (((int)a)&0x0000ff00), ((((int)a)&0x0000ff00)<<8));
    return (int)((((int)a)&0xff000000)>>24 | (((int)a)&0x00ff0000)>>8 | \
                 (((int)a)&0x0000ff00)<<8 | (((int)a)&0x000000ff)<<24);
}


bool isBigEndian()
{
    int a = 0x1234;
    printf("%d\n", sizeof(int));
    printf("%d\n", a);
    
    BigtoLittle32(a);
    //BigtoLittle16(a);
    printf("%d\n", a);
    
    //find what's stored in the low address of a;
    char b = *(char *)&a;
    if(b == 0x12)
    {
        printf("it's big endian\n");
        return true;
    }
    else
    {
        printf("it's little endian\n");
        return false;
    }
}

bool isBigEndianByUnion()
{
    /*
    union type always store from the low address
    we can use this to judge whether it's big endian
    */
    union Test
    {
        int a;
        char b;
    }test;
    test.a = 0x1234;
    if(test.b == 0x12)
    {
        printf("it's big endian\n");
        return true;
    }
    else
    {
        printf("it's little endian\n");
        return false;
    }
}


int main()
{
    //isBigEndian();
    //isBigEndianByUnion();
    int a = 0x00001234;
    int b = BigLittleEx(a);
    int c = BigLittleEx(b);
    printf("%x\n", b);
    printf("%x\n", c);

    return 0;
}
