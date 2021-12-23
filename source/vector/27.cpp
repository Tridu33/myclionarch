
/*
 * lc 27
4
3,2,2,3
3
 */
#include<bits/stdc++.h>
using namespace  std;
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 因为下表i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
        }
        return size;

    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};
int main(){
    int n;
    while(cin >> n){
        vector<int> nums(n,-1);
        char ch = ',';
        for(int i =0;i<n;i++){
            cin >> ch;
            if(ch == ','){
                cin >> ch;// next
            }
            nums[i] = ch - '0';
        }
//        cout << endl;
//        for(int i =0;i<n;i++){
//            cout << nums[i] << ' ';
//        }
        int target ;
        cin >> target ;
        Solution sol;
        cout << sol.removeElement(nums,target) << endl;
    }
    return 0;
}













