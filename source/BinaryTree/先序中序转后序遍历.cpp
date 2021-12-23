#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
input:树的先序与中序
output:树的后序
*/
void BuildPostOrder(char *str1, char *str2, char *ans, int length)
{
    if(length <= 0)
        return;
    int index = strchr(str2, str1[0]) - str2;  //先序的首节点在中序中的下标
    ans[length - 1] = str1[0];
    //利用下标，拆分左右子树，进行递归
    BuildPostOrder(str1 + 1, str2, ans, index);
    BuildPostOrder(str1 + index + 1, str2 + index + 1, ans + index, length - index - 1);
}

int main()
{
    char *str1 = (char *)malloc(10 * sizeof(char));
    char *str2 = (char *)malloc(10 * sizeof(char));
    char *result = (char *)malloc(11 * sizeof(char));
    int length = 0;
    while(scanf("%s %s", str1, str2) == 2)
    {
        length = strlen(str1);
        BuildPostOrder(str1, str2, result, length);
        result[length] = '\0';
        printf("%s\n", result);
    }
    return 0;
}

















