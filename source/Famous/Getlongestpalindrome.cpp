//1
// for i for j for k , get the max;


//2
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int dp[N][N];
int main(){
    string str;
    getline(cin,str);
    int max_len = 0;
    for (int i = 0; i < str.size();i++)
    {
        int left = i - 1;
        int right = i+1;
        // odd
        while(left >= 0 && right<= str.size()-1 && str[left] == str[right]){
            left--;
            right++;
        };
        max_len = max(max_len,right - left - 1);
        // even
        int left = i;
        int right = i + 1;
        while(left >= 0 && right<= str.size()-1 && str[left] == str[right]){
            left--;
            right++;
        };
        max_len = max(max_len,right - left - 1);
    };
    cout << max_len << endl;
    return 0;
}


//3
#include<bits/stdc++.h>
using namespace std;
int main(){
    ;
    return 0;
}





















//Manacher algorithm
#include<bits/stdc++.h>
using namespace std;
int manacher(string str)
{
    if(!str.length()) return 0;
    int l=(int)(str.length()*2+1);
    char *s=new char[l];//记录回文子串
    int *p=new int[l];//记录每个位置最大回文半径
    int r,c,index,mx;
    r=c=-1;
    index=mx=0;
    for(int i=0;i<l;i++) s[i]=i&1?str[index++]:'#';
    for(int i=0;i<l;i++)
    {
        p[i]=r>i?min(r - i, p[2 * c - i]):1;
        while(i+p[i]<l&&i-p[i]>-1)
        {
            if(s[i+p[i]]==s[i-p[i]]) p[i]++;
            else break;
        }
        if(i+p[i]>r) 
        {
            r=i+p[i];
            c=i;
        }
        mx=max(mx,p[i]);
    }
    delete[] s;
	delete[] p;
    return mx-1;
    
}
int main()
{
    string str;
    cin>>str;
    cout<<manacher(str)<<endl;
    return 0;
}
