class Solution{
public:
    int searchInsert(vector<int> & nums,int target){
        int res;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if (nums[i] >= target) return i;
        }
        return n;
    }
};


class Solution{
public:
    int searchInsert(vector<int> & nums,int target){
        int n = nums.size();
        int left = 0,right = n - 1, mid ;
        while(left <= right){//!
            mid = left+(right - left)/2;//(left+right)/2防止溢出一般写成left+(right - left)/2
            if(nums[mid] == target){
                return mid;
            };//=
            if(nums[mid] > target){
                right = mid - 1;
            };//>
            if(nums[mid] < target){
                left  = mid + 1;
            };//<
        }
        return right + 1;//用例子说不如看不变量
    }
};

class Solution{
public:
    int searchInsert(vector<int> & nums,int target){
        int n = nums.size();
        int left = 0,right = n , mid ;//right = n 而不是n - 1因为这是[left,right)
        while(left < right){//!
            mid = left+((right - left)>> 1);//(left+right)/2防止溢出一般写成left+(right - left)/2
            if(nums[mid] == target){
                return mid;
            };//=
            if(nums[mid] > target){
                //right = mid - 1;这行要修改，此时[left,right)没找到应该
                right = mid;
            };//>
            if(nums[mid] < target){
                left  = mid + 1;
            };//<
        }
        return right;//用例子说不如看不变量
    }
};












