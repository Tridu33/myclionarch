#include<stdio.h>
#include<string.h>
//recursive
int fibonacci1(int n ){
    if(n == 1 || n == 2){
        return 1;
    }
    return (fibonacci1(n - 1) + fibonacci1(n - 2))%1000000007;
}
class Solution {
public:
    int fib(int n) {
        if(n == 0){return 0;};
        if(n == 1){return 1;}
        long res;
        long pre = 0,cur = 1;
        for(int i = 2;i<=n ;i++){
            res = (pre + cur)%  1000000007;
            pre = cur;
            cur = res;
        }
        return (int) (res);
    }
};


















