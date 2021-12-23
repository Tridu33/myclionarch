//224




class Solution {
public:
    int calculate(string s) {
        stack<int> ss;
        // 当前的结果
        int res = 0;
        // 当前符号，默认+为1， -为-1
        int sign = 1;

        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            // 这里只考虑 0 且范围有效
            if (s[i] >= '0')
            {
                long curr = 0;
                while (i < n && s[i] >= '0')
                {
                    //curr = curr * 10 + s[i] - '0';
                    curr += curr * 10 + s[i] - '0';
                    ++i;
                }
                // 因为每次都会++i，这里需要减去一个
                --i;
                res += sign * curr;
            }
            else if (s[i] == '+')
            {
                sign = 1;
            }
            else if (s[i] == '-')
            {
                sign = -1;
            }
            else if (s[i] == '(')
            {
                // 把 当前值 和 符号插入到栈里
                ss.push(res);
                ss.push(sign);
                res = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                // 先取出符号，改变数值
                res *= ss.top();
                ss.pop();
                // 类加上之前的结果
                res += ss.top();
                ss.pop();
            }
            // 忽略其他情况
        }

        return res;
    }
}; 

/*
2147483647
cur:
2& i is:0
23& i is:1
257& i is:2
2834& i is:3
31178& i is:4
342966& i is:5
3772629& i is:6
41498925& i is:7
456488179& i is:8
5021369976& i is:9

2& s[i] is:2
23& s[i] is:1
257& s[i] is:4
2834& s[i] is:7
31178& s[i] is:4
342966& s[i] is:8
3772629& s[i] is:3
41498925& s[i] is:6
456488179& s[i] is:4
5021369976& s[i] is:7


2& s[i] - '0' is:2
23& s[i] - '0' is:1
257& s[i] - '0' is:4
2834& s[i] - '0' is:7
31178& s[i] - '0' is:4
342966& s[i] - '0' is:8
3772629& s[i] - '0' is:3
41498925& s[i] - '0' is:6
456488179& s[i] - '0' is:4
5021369976& s[i] - '0' is:7



*/
#define pass (void)0 //pass function like python
class Solution {
public:
    int calculate(string s) {
        stack <int > stk;int len = s.size();
        int sign = 1 ;//+: 1 -:0 -1 
        int res = 0;
        for(int i = 0; i < len; i++){
            long cur =0;//scanner founded curent number
            if(s[i] >= '0' && s[i] <= '9'){
                while(i<len && (s[i] >= '0' && s[i] <= '9') ){
                    //cur += cur*10 + (s[i] - '0');
                    cur = cur*10 + (s[i] - '0');
                    i++;
                }
                --i;//the last i++;
                res += sign*cur;
            }else if(s[i] == '+'){
                sign = 1;
            }else if(s[i] == '-'){
                sign = -1;
            }else if(s[i] == '('){
                stk.push(res);
                stk.push(sign);
                res = 0;sign = 1;//next bracket reset initial res' & sign'
            }else if (s[i] == ')'){
                res *= stk.top();stk.pop();//sign
                res += stk.top();stk.pop();//res_before+ res in current bracket
            }
            pass;
            //default rest situation ,do nothing
        }
        return res;
    }
};


//227

class Solution {
public:
    int calculate(string s) {

    }
};




// 772






class Solution {
public:
    int calculate(string s) {

    }
};




















