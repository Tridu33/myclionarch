


/*
console.log("unique ")

function unique(arr){
    if (!Array.isArray(arr)) {
        console.log('type error!')
        return
    }
    return Array.from(new Set(arr));
}
var arr = [1,1,'true','true',true,true,15,15,false,false, undefined,undefined, null,null, NaN, NaN,'NaN', 0, 0, 'a', 'a',{},{}];
console.log(arr)
console.log(unique(arr))
 //[1, "true", true, 15, false, undefined, null, NaN, "NaN", 0, "a", {}, {}]
console.log("unique_for ")


function unique_for(arr){
    if (!Array.isArray(arr)) {
        console.log('type error!')
        return
    }
    for(let i =0;i<arr.length;i++){
        for(let j = i+1;j<arr.length;j++){
            if(arr[i] == arr[j]){
                arr.splice(j,1);
                j--;
            }
        }
    }
    return arr;
}
console.log(unique_for(arr))
console.log("unique_indexOf ")

function unique_indexOf(arr){
    if(!Array.isArray(arr)){
        console.log('type Error!');
        return ;
    }
    var array= [];
    for(let i = 0;i<arr.length;i++){
        if(array.indexOf(arr[i]) === -1){
            array.push(arr[i]);
        };
    }
    return  array;
}

 console.log(unique_indexOf(arr))
 console.log("unique_sort ")

 function unique_sort(arr){
    if(!Array.isArray(arr)){
        console.log('type Error!');
        return ;
    }
    arr = arr.sort();
    var array = [arr[0]];
    for(let i = 1;i<arr.length;i++){
        if(arr[i]!== arr[i-1]){
            arr.push(arr[i]);
        }
    }
    return array;
 }
console.log(unique_sort(arr))
*/


console.log("unique_includes ")
var arr = [1,1,'true','true',true,true,15,15,false,false, undefined,undefined, null,null, NaN, NaN,'NaN', 0, 0, 'a', 'a',{},{}];
//[1, "true", true, 15, false, undefined, null, NaN, "NaN", 0, "a", {…}, {…}]     //{}没有去重
function unique_includes(input_arr){
    if(!Array.isArray(input_arr)){
        console.log('Error type!');
        return ;
    }
    let array = [];
    for(let i = 0;i<input_arr.length;i++){
        if(!array.includes(input_arr[i])){
            array.push(input_arr[i]);
        }
    }
    return array;
}
console.log(unique_includes(arr))


console.log("unique_haOwnProperty ")

function unique_haOwnProperty(input_arr){
    if(!Array.isArray(input_arr)){
        console.log('type Error!');
        return ;
    }
    let array = {};
    return input_arr.filter(function(item, index, input_arr) {
        return array.hasOwnProperty(typeof item + item)?false : (array[typeof item + item] = true)
    });
}

console.log(unique_haOwnProperty(arr))
//[1, "true", true, 15, false, undefined, null, NaN, "NaN", 0, "a", {…}]   //所有的都去重了

let test = [1,2,3,4,5];
let newarray = [];
test.filter(function(item, index, input_arr) {
    let typeofitem = typeof item + item
    let res = newarray.hasOwnProperty(typeofitem)?false : (newarray[typeofitem] = true)
    return res
});




















