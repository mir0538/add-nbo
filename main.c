// add-nbo.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h> // for uint4_t
#include <stdio.h> // for fopen&fread
#include <netinet/in.h>

uint32_t add(uint32_t fp1, uint32_t fp2);


int main(int argc, char* argv[])
{
    printf("%d", argc);
    char name[] = "김예영";
    char mobile[] = "0538"; 
    printf("[bob11]add-nbo[%s%s]\n", name, mobile);
    uint32_t temp1, temp2;
    

    FILE* fp1 = fopen(argv[1], "rb");
    FILE* fp2 = fopen(argv[2], "rb");
    
    fread(&temp1, sizeof(uint32_t), 1, fp1);
    temp1 = ntohl(temp1);
    
    
    fread(&temp2, sizeof(uint32_t), 1, fp2);
    temp2 = ntohl(temp2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", temp1, temp1, temp2, temp2, add(temp1,temp2), add(temp1,temp2));
    
    
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}


uint32_t add(uint32_t fp1, uint32_t fp2)
{
    	return fp1 + fp2;
}


