function add(a,b){
    return a+b;
}
while(true){
    let lines = readline().split(" ");
    let n = parseInt(lines[0]);
    if(n === 0) break;
    let sum = 0, len = lines.length;
    for(let i = 1;i<len;i++){
        sum += parseInt(lines[i]);
    }
    print(sum);
}