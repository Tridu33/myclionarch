#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:
    int func(vector<int> & nums){
        ;
    }
};
// -----------------
/*
input:

5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

output:

5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9

 测试用例:
7 2 6 9 0 4 0 5 1
0 8 0 6 0 7 4 3 2
3 4 1 0 8 5 0 0 9
0 5 2 4 6 8 0 0 7
0 3 7 0 0 0 6 8 0
0 9 0 0 0 3 0 1 0
0 0 0 0 0 0 0 0 0
9 0 0 0 2 1 5 0 0
8 0 0 3 0 0 0 0 0

对应输出应该为:

7 2 6 9 3 4 8 5 1
5 8 9 6 1 7 4 3 2
3 4 1 2 8 5 7 6 9
1 5 2 4 6 8 3 9 7
4 3 7 1 9 2 6 8 5
6 9 8 5 7 3 2 1 4
2 1 5 8 4 6 9 7 3
9 6 3 7 2 1 5 4 8
8 7 4 3 5 9 1 2 6


 * */
//本题递归不用终止条件，解数独是要遍历整个树形结构寻找可能的叶子节点就立刻返回。
bool ifValidTryN(int cur_i,int cur_j,int tryN,vector<vector<int>> & board){
    // row
    for(int i=0;i<9;i++){
        if(board[i][cur_j] == tryN){
            return false;
        }
    }
    // col
    for(int j=0;j<9;j++){
        if(board[cur_i][j] == tryN){
            return false;
        }
    }
    // 9*9 box 判断9方格里是否重复
    int box_row = (cur_i/3)*3,box_col = (cur_j/3)*3;
    for(int i = box_row;i<box_row+3;i++){
        for(int j = box_col;j<box_col+3;j++){
            if(board[i][j] == tryN){
                return false;
            }
        }
    }
    return true;
}
bool backtrack(vector<vector<int>> &board){
    for(int i =0; i<9; i++){
        for(int j =0; j<9; j++){
            if(board[i][j] != 0){
                continue;
            }
            for(int tryN = 1; tryN<10;tryN++){
                if(ifValidTryN(i,j,tryN,board)){// (i, j) 这个位置放k是否合适
                    board[i][j] = tryN;// 放置k
                    if(backtrack(board))
                        return true;// 如果找到合适一组立刻返回
                    board[i][j] = 0; // 回溯，撤销k
                }
            }
            return false; // 9个数都试完了，都不行，那么就返回false
        }
    }
    return true;//遍历完没有返回false，说明找到了合适棋盘位置了
}
int main(){
    vector<vector<int>> board(9,vector<int>(9,-1));
    for(int line = 0;line<9;line++){
        for(int i =0;i<9;i++){
            cin >> board[line][i];
        }
    }
    if (backtrack(board) ){
        for (int i = 0; i < 9; i++) {
            cout << board[i][0];
            for (int j =1; j < 9; j++) {
                cout << " "<< board[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}