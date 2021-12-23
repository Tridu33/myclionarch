class Solution {
public:
    void getNext(int * next,const string &s){
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < s.size();i++){
            while(j>0 && s[i] != s[j]){
                j = next[j - 1];//not match
            };
            if(s[i] == s[j]){
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        int(s.size() == 0) { return false; };
        int next[s.size()];
        getNext(next, s);
        int n = s.size();
        if(next[len - 1] != 0 && len % (len - (next[len -1])) == 0){
            return true;
        }
        return false;
    }
};