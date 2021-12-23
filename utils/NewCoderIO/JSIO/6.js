function sum(arr){
    let sum = 0
    for(var i=1;i<arr.length;i++){
        sum += parseInt(arr[i])
    }
    return sum;
}
let line = "";
while(line = readline()){
    let nums = line.split(" ").map(Number);
    print(sum(nums));
}










