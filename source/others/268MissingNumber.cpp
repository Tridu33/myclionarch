//3-1
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i =0;i<nums.size();i++){
//             if (i != nums[i]){return i;}
//         }
//         return nums.size();
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();int res = n;
        for(int i =0;i<nums.size();i++){
            res = res^i^nums[i];
        }
        return res;
    }
};
