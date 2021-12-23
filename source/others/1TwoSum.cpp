// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int> hash;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             unordered_map<int,int>::iterator iter = hash.find(target - nums[i]);
//             if(iter == hash.end()){
//                 hash[nums[i]] = i;
//             }else{
//                 return {iter->second,i};
//             }
//         }
//         return {};
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //vector<int> res{};
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j =i+1;j<n;j++){
            if(nums[i]+nums[j] == target){
                return {i,j};
                }
            }
        }
        return {};
    }
};






