#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        vector<bool>a(128, 0);//ASCII
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (a[s[i]] == false)
            {
                a[s[i]] = true;
                res += s[i];
            }
        }
        cout << res << endl;
    }
    return 0;
}
/*
// 为什么不能通过牛客网却能通过自己的测例
int main(){
    string str;
    while(getline(cin,str)){
        int len = str.size();
        vector<bool> hash(26+26,false);
        // A-Z a-z
        string res = "";
        for(int i =0;i<len;i++){
            char ch = str[i];
            if('A' <= ch && ch <= 'Z'){
                if(hash[(int)(ch-'A')] != false){// 0 --- 26
                    continue;// already in
                }else{
                    res.push_back(ch);
                    hash[(int)(ch-'A')] = true;
                    continue;
                }
            }else if('a' <= ch && ch <= 'z'){// 27+0 --- 27+26
                if(hash[(int)(ch-'a') + 27] != false){
                    continue;// already in
                }else{
                    hash[(int)(ch-'a')+27] = true;
                    res.push_back(ch);
                    continue;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}

*/
