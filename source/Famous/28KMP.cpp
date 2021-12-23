#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }
        // next
        vector<int> next(m,0);
        next[0] = -1;
        int j =-1;
//        for(int i =0;i<m;i++){// 注意i从1开始
        for(int i = 1 ;i<m;i++){// 注意i从1开始
            /*
            "mississippi"
            "issip"      如果从零开始会死循环，此时next是0,1,2,3,4,5然后遇到 issi回文的部分死循环
            */
            while(j >= 0 && needle[i] != needle[j+1]){
                j = next[j];
            }
            if(needle[i] == needle[j+1]){
                j++;
            }
            next[i] = j;//如果相等上两行试探出来的+1后的j就是长度位置，如果不等j还是那个数字
        }
        //
        j = -1;
        for(int i = 0;i<n;i++){
            while(j >= 0 && haystack[i] != needle[j+1]){
                j = next[j];
            }
            if(haystack[i] == needle[j+1]){
                j++;
            }
            if(j == m-1){
                return (i-m+1);
            }
        };
        return -1;
    }
};
int main(){
    string  s = "mississippi", t = "issip";
    Solution sol;
    cout << sol.strStr(s,t) << endl;
    return  0;
}



















