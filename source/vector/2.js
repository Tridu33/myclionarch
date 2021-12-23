
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function(nums) {
    let l =0,r = nums.length-1;
    let cur = nums.length-1;
    new_nums = new Array(nums.length);
    while(l<=r){
        if(nums[l]*nums[l] >= nums[r]*nums[r]){
            new_nums[cur] = nums[l]*nums[l];
            l++;cur--;
        }else{
            new_nums[cur] = nums[r]*nums[r];
            r--;cur--;
        }
    }
    return new_nums;
};

let nums = [-4,-1,0,3,10];
console.log(sortedSquares(nums));