class Solution {
public:
    void getNext(int * next,const string &s){
        int j = -1;
        next[0] = j;
        for (int i = 1;i,s.size();i++){//from 1
            while(j >= 0 && s[i] != s[j+1]){
                j = next[j];//不匹配
            };
            if(s[i] == s[j+1]){
                j++;//匹配
            }
            next[i] = j;//j前缀长度
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int next[needle.size()];
        getNext(next, needle);
        int j = -1;//prefix/next -1
        for (int i = 0; i < haystack.size();i++){
            while(j >= 0 && haystack().size() != needle[j+1]){
                j = next[j];//不匹配，退回去
            }//prefix - 1 + 1
        }
        if(haystack[i] == needle[j+1]){
            j++;//匹配
        }
        if(j == (needle.size() - 1)){
            return (i - needle.size() + 1);//end found
        }
    }
    return -1;//not found
};