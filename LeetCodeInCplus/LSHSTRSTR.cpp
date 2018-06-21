#include <string.h>
#include <stdio.h>

const char* lshstrstr(const char *str, const char *sub_str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        int tem = i; //tem保留主串中的起始判断下标位置   
        int j = 0;
        //遍历到起始点则结束; 使用i++%strlen(str) 实现循环列表遍历
        while ( !((i >= strlen(str) && i%strlen(str) == tem)) && (str[(i++)%strlen(str)] == sub_str[j++]))
        {
            if (sub_str[j] == '\0')
            {
                return &str[tem];
            }
        }
        i = tem;
    }

    return NULL;
}

int main()
{
    char str[] = "AABCD";
    char substr[] = "CDAA";
    printf("find str in %s\n", lshstrstr(str, substr));
    getchar();
    return 0;
}
