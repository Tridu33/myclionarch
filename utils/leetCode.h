#include<bits/stdc++.h>
using namespace std;

namespace leetCode{
    //可以自己定义Exception
    static class myException: public exception
    {
        virtual const char* what() const throw()
        {
            return "My exception happened:vec.size() != cnt";
        }
    }myEx;

    template <typename T>
    static vector<T> nvec(){
        /*
         5
         4 3 2 1 0
         * Usage： vector<int> input = nivec();
         * */
        vector<T> vec;
        try {
            T cur;
            int cnt;
            cin >> cnt;
            while(cin >> cur){
                vec.push_back(cur);
            };
            if(vec.size() != cnt) {
                throw myEx;
            }   //如果，则抛出异常；
        }catch(exception& e){
            cout << e.what() << endl;
        }
        return vec;
    }


    template <typename T>
    static vector<vector<T>> mnmat(){
        /*
        2 3
        1 2 3
        4 5 6
         * Usage： vector<vector<int>> mat = mnmat<int> ();
         * */
        vector<vector<T>> matrix;
        try {
            T cur;
            int m,n;
            cin >> m >> n;// row,column
            for(int i =0;i<m;i++){
                vector<T> line;
                for(int j =0;j<n;j++){
                    cin >> cur;
                    line.push_back(cur);
                }
                matrix.push_back(line);
            };
            if(matrix.size() != m || matrix[0].size() != n) {
                throw myEx;
            }   //如果，则抛出异常；
        }catch(exception& e){
            cout << e.what() << endl;
        }
        return matrix;
    }
}
