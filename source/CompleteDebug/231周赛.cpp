class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long  sum = 0;//int会越界
        for(int i= 0;i<nums.size();i+=1){
            sum += nums[i];
        };
        long  rest = abs(goal  -  sum);//diff
        // while(rest - limit <= limit){
        //     rest = rest - limit;
        //     res += 1;
        // }
        return (int)((rest+limit - 1)/limit);
        
    }
};

class Solution {
    public int minElements(int[] nums, int limit, int goal) {
        int n = nums.length;
        long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        long diff = Math.abs(goal - sum);
        return (int)((diff + limit - 1) / limit);
    }
}




class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=0;
        for(auto x:nums)sum+=x;
        sum=abs(goal-sum);
        return (sum+limit-1)/limit;
    }
};

