





//思路：
//1.字符串预处理，针对可能出现的“{，},[,],-”等特殊情况进行替换,判断‘-’是负号还是减号,负号前面+0，转变成减法运算
//2.将中缀字符串转变为后缀字符串数组
//3.对后缀字符串数组进行求解
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
bool cmpPriority(char top,char cur)//比较当前字符与栈顶字符的优先级，若栈顶高，返回true
{
    if((top=='+' || top=='-') && (cur=='+' || cur=='-'))
        return true;
    if((top=='*' || top=='/') && (cur=='+' || cur=='-'|| top=='*' || top=='/'))
        return true;
    if(cur==')')
        return true;
    return false;
}
void preProcess(string &str)//对字符串进行预处理
{
    for(int i=0;i<str.size();++i)
    {
        if(str[i]=='{')//将‘{、}、[,]’替换成'()'
            str[i]='(';
        else if(str[i]=='}')
            str[i]=')';
        else if(str[i]=='[')
            str[i]='(';
        else if(str[i]==']')
            str[i]=')';
        else if(str[i]=='-')
        {
            if(i==0)//将'-'前面添加0转变成减法运算
                str.insert(0,1,'0');
            else if(str[i-1]=='(')
                str.insert(i,1,'0');
        }
    }
}
vector<string> mid2post(string &str)
{
    vector<string>vstr;
    stack<char>cstack;
    for(int i=0;i<str.size();++i)//扫描字符串
    {
        string temp="";
        if(str[i]>='0' && str[i]<='9')//若是数字
        {
            temp+=str[i];
            while(i+1<str.size() && str[i+1]>='0' && str[i+1]<='9')
            {
                temp+=str[i+1];//若是连续数字
                ++i;
            }
            vstr.push_back(temp);
        }
        else if(cstack.empty() || str[i]=='(')//若栈空或者字符为'('
            cstack.push(str[i]);
        else if(cmpPriority(cstack.top(),str[i]))//若栈顶元素优先级较高，栈顶元素出栈
        {
            if(str[i]==')')//若当前字符是右括号，栈中元素出栈，入字符串数组中，直到遇到'('
            {
                while(!cstack.empty() && cstack.top()!='(')
                {
                    temp+=cstack.top();
                    cstack.pop();
                    vstr.push_back(temp);
                    temp="";
                }
                cstack.pop();
            }
            else//栈中优先级高的元素出栈，入字符串数组，直到优先级低于当前字符
            {
                while(!cstack.empty() && cmpPriority(cstack.top(),str[i]))
                {
                    temp+=cstack.top();
                    cstack.pop();
                    vstr.push_back(temp);
                    temp="";
                }
                cstack.push(str[i]);
            }
        }
        else//当前字符优先级高于栈顶元素，直接入栈
            cstack.push(str[i]);
    }
    while(!cstack.empty())//栈中还存在运算符时，出栈，存入字符串数组
    {
        string temp="";
        temp+=cstack.top();
        cstack.pop();
        vstr.push_back(temp);
    }
    return vstr;
}
int calcPostExp(vector<string> & vstr)//对后缀表达式进行求值，主要是根据运算符取出两个操作数进行运算
{
    int num,op1,op2;
    stack<int>opstack;
    for(int i=0;i<vstr.size();++i)
    {
        string temp=vstr[i];
        if(temp[0]>='0' && temp[0]<='9')//如果当前字符串是数字，利用字符串流转化为int型
        {
            stringstream ss;
            ss<<temp;
            ss>>num;
            opstack.push(num);
        }
        else if(vstr[i]=="+")//若是操作符，取出两个操作数，进行运算，并将结果存入
        {
            op2=opstack.top();
            opstack.pop();
            op1=opstack.top();
            opstack.pop();
            opstack.push(op1+op2);
        }
        else if(vstr[i]=="-")
        {
            op2=opstack.top();
            opstack.pop();
            op1=opstack.top();
            opstack.pop();
            opstack.push(op1-op2);
        }
        else if(vstr[i]=="*")
        {
            op2=opstack.top();
            opstack.pop();
            op1=opstack.top();
            opstack.pop();
            opstack.push(op1*op2);
        }
        else if(vstr[i]=="/")
        {
            op2=opstack.top();
            opstack.pop();
            op1=opstack.top();
            opstack.pop();
            opstack.push(op1/op2);
        }
    }
    return opstack.top();//最终的栈顶元素就是求解的结果
}
void calcExp(string str)
{
    vector<string>vstr;
    preProcess(str);//对字符串进行预处理
    vstr=mid2post(str);//将中缀表达式转为后缀，保存在字符串数组中，方便下一步求解
    int res=calcPostExp(vstr);
    cout<<res<<endl;
}
int main()
{
    string str;
    while(getline(cin,str))
    {
        calcExp(str);
    }
    return 0;
}

/*
输入：
3+2*{1+2*[-4/(8-6)+7]}
输出：
25
 * */














