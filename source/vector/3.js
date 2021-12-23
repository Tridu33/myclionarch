/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    // let matrix = new Array(n).fill(new Array(n).fill(-1));//这样写每个都是同一个，复制一个等于赋值每一行
    const matrix = new Array(n).fill(0).map(() => new Array(n).fill(-1));
    let cur = 1;
    let top = left = 0;
    let down = right = n-1;
    while(cur<= n*n){
        for(let col = left;col<=right;col++){
            matrix[top][col] = cur;
            cur++;
        }
        top++;
        for(let row = top;row <= down;row++){
            matrix[row][right] = cur;
            cur++;
        }
        right--;
        for(let col = right;col>=left;col--){
            matrix[down][col] = cur;
            cur++;
        }
        down--;
        for(let row = down;row>=top;row--){
            matrix[row][left]= cur;
            cur++;
        }
        left++;
    }
    return matrix;
};
console.log(generateMatrix(3));