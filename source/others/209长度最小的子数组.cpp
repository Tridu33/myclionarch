class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n =nums.size();
        int sublen = 0;
        int res =INT_MAX;
        for(int i =0;i<n;i++){
            //int sum =nums[i];
            int sum =0;
            for(int j =i;j<n;j++){
                sum += nums[j];
                if(sum >= target){
                    sublen = j  -i + 1;
                    res = res<sublen?res:sublen;
                    break;
                }
            }    
        }
        return res==INT_MAX?0:res;
    }
};





class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum >= s) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum/solution/chang-du-zui-xiao-de-zi-shu-zu-by-leetcode-solutio/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。













