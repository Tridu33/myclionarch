let t = parseInt(readline());
while(t--){
    let lines = readline().split(" ");
    let nums = lines.map(Number);// nums
    let n = nums[0];
    let sum=0,curval;
    for(let i=1; i<=n; i++){
        curval = nums[i];
        sum += curval;
    }
    print(sum);
}