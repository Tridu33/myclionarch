function add(a,b){
    return a+b;
}
var t = parseInt(readline());
while(t--){
    let lines = readline().split(" ");
    print(add(parseInt(lines[0]), parseInt(lines[1])));
}


