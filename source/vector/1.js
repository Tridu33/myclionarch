/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
    // [l,r)
/*
var search = function(nums, target) {
        let l =0,r = nums.length;
        while(l < r){
            // let mid = l + (r-l)>>1;
            let mid = (l+r)/2;
            if(nums[mid] === target)
                return mid;
            if(nums[mid] < target){
                l = mid+1;//[mid+1,r)
                r = r;
            }
            if(nums[mid] > target){
                r = mid;// [l,mid)
                l = l;
            }
        }
        return -1;
    };
* */

var search = function(nums, target) {
    let l = 0, r = nums.length;
    // 区间 [l, r）
    while(l < r) {
        // let mid = (l + r) /2;不可以，这样出现的是4.5小数下标太灵活也不好
        // let mid = l + (r-l)>>1;错误的优先级，相当于(4 + (6-4))>>1
        let mid = l + ((r-l)>>1);
        if(nums[mid] === target)  return mid;
        if(nums[mid] < target){
            l = mid+1;//[mid+1,r)
            r = r;
        }
        if(nums[mid] > target){
            r = mid;// [l,mid)
            l = l;
        }
    }
    return -1;
};
let nums = [-1,0,3,5,9,12];
console.log(search(nums,9));