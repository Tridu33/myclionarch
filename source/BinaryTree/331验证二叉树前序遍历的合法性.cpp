class Solution{
public:
    bool isValidSerialization(string preorder){
        int n =  preorder.size();//"1,#" 运行时错误
        if(n <5) return false;///"9,#,#,1"
        vector<char>readed;
        for(int i = 0;i<n;){
            if(preorder[i] == ','){
                i++;
                continue;
            }else if(preorder[i] == '#'){
                readed.push_back(preorder[i++]);
            }else{
                while(preorder[i] != ',' && i<n){
                    i++;
                };
                readed.push_back('n');//'n' represent for Number
            };
        }
        printVec(readed);
        vector<char> stk;
        n = readed.size();//new size
        for(int i = 0;i<n;i++){
            stk.push_back(readed[i]);
            while(stk.size() >=3 && stk[stk.size() - 1] == '#' && stk[stk.size() -2] == '#' && stk[stk.size() -3] == 'n'){
                stk.pop_back();stk.pop_back();stk.pop_back();
                stk.push_back('#');
                printVec(stk);
            }
        }
        //printVec(stk);//cout<<stk[stk.size() - 3]<<endl;
        return (stk.size() == 3 && stk.back() == '#');//"9,3,4,#,#,1,#,#,2,#,6,#,#"
    }
    void printVec (vector<char> vec){
        int size = vec.size();
        for(int i = 0;i<size;i++){
            cout <<vec[i]<<' ';
        }
        cout<<' '<<endl;
    }
};