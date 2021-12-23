class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        if(n == 1)
            return nums[0];
        for (int i = 0;i<n;i++){
            int tempsum =0;
            for (int j = i;j<n;j++){
                tempsum += nums[j];
                if(tempsum >= res)
                    res = tempsum;
            } //temp += nums[i];
        }
        return res;
    }
};

//DP


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        res = dp[0];
        for (int i = 1;i<n;i++){
            //dp[i] = max(dp[i-1] + nums[i] ,dp[i]);
            dp[i] = max(dp[i-1] + nums[i] ,nums[i]);
            //res = dp[i];
            res =max(dp[i],res);
        }
        return res;
    }
};
















