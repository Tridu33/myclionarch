function sum (...nums) {
    let num = 0
    nums.forEach((item) => {
        num += item
    })
    return num
}
arr = [1,2,3]
b = sum(arr)
console.log(b);//01,2,3相当于 0 + [1,2,3]自动把对象转型为字符串进行拼接，所以这样传参是错误的做法

c = sum(6,7);
a = sum();

console.log(a);