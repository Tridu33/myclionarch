function add(a,b){
    return a+b;
}
while(true){
    let lines = readline().split(" ");
    let a = parseInt(lines[0]), b = parseInt(lines[1]);
    if(a === 0 && b === 0) break;
    print(add(a,b));
}











