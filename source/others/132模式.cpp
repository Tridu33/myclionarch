class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> candidate_k_maxVals;
        candidate_k_maxVals.push(nums[n- 1]);
        int max_k_mid = INT_MIN;
        for (int i = n - 2; i >= 0;i--){
            if(nums[i] < max_k_mid){
                return true;
            };//find
            while(!candidate_k_maxVals.empty() && nums[i] > candidate_k_maxVals.top()){
                max_k_mid = candidate_k_maxVals.top();
                candidate_k_maxVals.pop();
            }
            if(nums[i] > max_k_mid){
                candidate_k_maxVals.push(nums[i]);
            }
        }
        return false;
    }
};