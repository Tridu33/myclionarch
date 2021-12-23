function add(arr){
    let sum = 0, n = arr.length;
    while(n--){
        sum += arr[n];
    }
    return sum;
}
let line = '';
while(line = readline()){
    let nums = line.split(" ").map(Number);
    print(add(nums));
}