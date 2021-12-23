class Solution {
public:
    bool checkOnesSegment(string s) {//regex最方便
        bool flag = false;//是否有连续1
        int len = s.length();
        for (int i = 0;i<len-1 ;i+=1){            
            if(s.at(i)== '1' && s.at(i+1) == '1'){
                flag = true;
            }else {//if(ch =='0'){
                flag = false;
            }
        };
        
        //with 1+0...
        int first0index =0;
        for(int i = 0;i<len ;i+=1){
            if(s.at(i) == '0'){
                first0index == i;
            };
        }
        //有连续1判断是否11011出现两次[1+]
        bool if1101 = false;
        for(int i = first0index+1;i<len ;i+=1){
            if(s.at(i) == '1'){
                if1101 == true;
                break;
            };
        }
        cout<<flag<<endl;
        return (flag & !if1101);
    }
};

#include"include.h"
using namespace std;
int main(){
    Solution solution;
    String s = "11001";
    cout<<solution.checkOnesSegment(s)<< endl;
    ;
    return 0;
}





