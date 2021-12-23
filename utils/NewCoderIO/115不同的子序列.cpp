class Solution(){
public:
    int numdistinct(String s,String t){
        int m = s.size();
        int n = t.size();
        if(m <n){return 0;}
        vector<vector<long>> dp(m+1,vector<long>(n+1));
        for(int i = 0;i<= m;i++){
            dp[i][n] = 1;
        }
        for(int i = m -1;i>= 0;i--){
            char chs = s[i];
            for(int j = n -1;j>= 0 ;j--){
                char cht = t[j];
                if(chs == cht){
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                }else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];

    };
};





































































































