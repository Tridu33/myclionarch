#include <cstdio>
#include <cstring>
using namespace std;
char str[50];
int bin[100]; //每次模2后的余数
int num[30];  //每次除以2后的值
int main()
{
    while (scanf("%s", &str) != EOF)
    {
        int len = strlen(str);
        int index = 0; //bin下标的计数变量
        int i;
        for (i = 0; i < len; i++)
            num[i] = str[i] - '0';
        while (1) //每循环一次模拟一次模2取余法，余数存在bin中
        {
            i = 0;
            while (i < len && num[i] == 0)
                i++; //随着除法运算的不断进行，到最后一刻得到的上肯定是0
            //这个时候所得到的num数组姜维一个全0数组
            //另一方面也是过滤除法运算过程中产生的多余的0，比如120/2=060
            if (i == len)
                break;
            int left = 0; //记录余数，需要注意的是，每一步的被除数都在变化，因此left需要重置
            for (; i < len; i++)
            {
                int mod = left * 10 + num[i];
                num[i] = mod / 2;
                left = mod % 2;
            }
            bin[index++] = left; //记录每一步过程产生的余数
        }
        if (index == 0)
            printf("0"); //千万不要忘了考虑0的情况
        else
        {
            for (i = index - 1; i >= 0; i--)
                printf("%d", bin[i]);
        }
        printf("\n");
    }
    return 0;
}
