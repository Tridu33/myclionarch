class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();int res = 0;
        //[1]有问题
        //1
        int l = 0;
        int r = n-1;
        while(l<=r){
            if(nums[l] == val && nums[r] == val ){
                r--;
                res ++;
            }
            if(nums[l] == val && nums[r] != val ){
                swap(nums[l],nums[r]);
                r--;
                l++;
                res++;
            }
            if(nums[l] != val && nums[r] == val ){
                r--;
                res++;
            }
            if(nums[l] != val && nums[r] != val ){
                l++;
                //r-- //delete this line
            }
        }
        //[0,1,2,2,3,0,4,2]
        //2
        //wrong:[0,1,2,3]
        //right:[0,1,4,0,3]
        return n-res;
    }
};




class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int res = 0;
        for(num:nums){
            if(num != val){
                nums[ans] = num;
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for(int j = 0;j<size;j++){
            // for(i = j;i>size;i++){
            //     nums[i] = num[i+1];
            for(i = j+1;i>size;i++){
                nums[i-1] = num[i];;
            }
            size--;
            i--;
        }
        return ans;
    }
};


class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (nums[i] == val) {
				for (int j = i; j < len - 1; j++) {//这里j<len-1是因为遍历到len-2时就已经将所有的元素移好了
					nums[j] = nums[j + 1];
				}
				i--;//i以后的值都往前移了一位，所以i要减一。
				//换句话说就是 移完之后i位置的值改变了 还得判断当前i位置的值是否等于val，
				//如果不减一，第一层的循环直接加一的话会跳过当前位置
				len--;//数组长度减一
			}
		}
		return len;
	}
};

作者：tian-yun-xiang
链接：https://leetcode-cn.com/problems/remove-element/solution/c-shuang-zhi-zhen-bao-li-fa-by-tian-yun-rcw7k/




class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for(int j = 0;j<size;j++){
            // for(i = j;i>size;i++){
            //     nums[i] = nums[i+1];
            for(int i = j+1;i>size;i++){
                nums[i] = nums[i+1];;
            }
            size--;
            j--;//j以后的值都往前移了一位，所以要减一。
				//换句话说就是 移完之后j位置的值改变了 还得判断当前j位置的值是否等于val，
				//如果不减一，第一层的循环直接加一的话会跳过当前位置
        }
        return size;
    }
};











