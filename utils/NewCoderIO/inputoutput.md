| 输入格式                                                     | 输出格式                                                     |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| 一个case输入                                                 | 一个输出结果                                                 |
| 有多个case输入，直到文件结束                                 | 一行一个结果                                                 |
| 先输入case个数，再依次输入每个case                           | 一行一个结果                                                 |
| 每行输入一组case，当case中的数据满足某种情况时退出           | 一行一个结果                                                 |
| 输入直到文件结束                                             | 一行一个结果，结果输完后还有一个blank line                   |
| 一开始输入总的case数，每组case一开始有控制该组输入个数的东西 | 一行一个结果，两个结果之间有一个回车，注意最后一个case后没有回车。 |

/*
8-9-10是实战中经常用到的方式，比如输入数组，有多组，以逗号/空格分隔，不同场景下的处理方式。主要是对 sstringstream 以及 getline 的熟练使用。

https://ac.nowcoder.com/acm/contest/5647

等待：服务器正忙，请稍后查看运行并评判您的程序

正在评测中编译中：您的程序正在被编译

正确：恭喜您！完全正确！

格式错误：结果正确，但格式不正确，比如多或少了换行或空格

答案错误：经过比对，您的程序错误运行错误程序运行后发生错误，可能包括：

指针/数组违规访问
除数为0
函数调用错误，或栈溢出
捕捉到违背处理的STL或自定义异常等
…
时间超限：程序运行时间超过了时间限制，请检查程序的算法效率

内存超限：程序使用的内存超过了内存限制，请检查程序是否栈/堆开辟空间过大 或内存泄露

输出超限：输出了与答案无关的信息，比如“please input”等提示

编译错误：程序语法错误，编译不通过。可能您在本地可以编译通过，但可能使用了非标准C的函数 ，请使用符合标准的语法。




OJ的输入输出基本都是使用标准输入输出(也称标准I/O，即直接读键盘、写屏幕)。
OJ的判题方式则是使用输入输出重定向到文件
一个问题(十分常见！！！！)，如果测试数据是多组的，但是恰巧你代码里面需要些标记数组，map，set等，在循环内一定记得清空，不然可能会产生前面的测试样例影响了后续数据的答案。
关于cin，cout和scanf，printf。做题的时候尽量使用scanf  printf。下面告诉一个小常识，不要惊讶：cin cout比scanf printf慢20倍左右
./test < data_in > data_out
在测试自己的程序时，可以在代码里加入重定向语句来方便测试，但是必须注意：自我测试完毕之后删除重定向语句，再提交代码。
代码里重定向方法：
*/

```cpp
#define LOCAL //在提交代码时注释掉

#include<stdio.h>
// 实际使用中发现freopen也包含在iostream.h中，C++代码#include <iostream.h>即可。
int main(){
#ifdef LOCAL
    freopen("data.in", "r", stdin);//将data.in改为输入文件路径
    freopen("data.out", "w", stdout);//将data.out改为输出文件路径
#endif
             
     //fclose(stdin);//最后关闭
     //fclose(stdout);
    
    return 0;
}
```



随后，正常使用C/C++的标准输入，都会定向到上述两个文件中，以便于自测代码。

```cpp
Class Solution{
    int test(int a,int b){
        return a+b;
    }
};

//要使用标准的跨平台的库函数。 各个语言一般平台都会告诉你每种语言给的编译器版本，这个环境信息也是很重要的。
#include<iostream>
using namespace std;


int main(){
    Solution sol;
    //只有一组数据
    cin>>a>>b;
    cout<<a+b<<endl;

    //预先不输入数据的组数
    while(cin>>a>>b){
        cout<<a+b<<endl;
    }

    return 0;

}

```



```cpp
//input single group of Int Number只有一组数据
    int a,b;
    scanf("%d%d",&a,&d);
    printf("%d\n", sol(a,b));//
    cout<<test(a,b);
```
/*
1、行末空格：比如我输出需要打印多个数需要使用空格分隔的时候，我们循环使用printf("%d  ",x);这种会很方便，但是这样会导致行末多一个空格，后台系统会严格比对你的输出和.out文件，这样也会被判错误

2、换行问题，对于每个样例，建议输出完全之后都换行一下。对于一些题目，可能就是不换行就导致了后面输入数据错位，那就肯定不可能过了。

*/

```cpp
//有很多组数据，然后告诉了数据个数
//预先知道数据组数
cin>>n;
for(int i=0; i<n; i++){
    int a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
}
```
//读取N行字符串

**cin.ignore**

```cpp
#include<iostream>
using namespace std;
int main(){
    int N;
    cin >> N ;  //希望读取N行，并输出
    while(N--){
        string s;
        getline(cin, s);
        cout << s << endl;
    }
}//上面的程序只能读取有效的两行，而第一行是一个空行，这不是我们想要的效果，这个看起来不起眼的错误，会导致笔试题0AC，不要问我怎么知道的。
```

*/
```cpp
//“可恶”的字符串——带空白
    int N;
    cin >> N ;  
    cin.ignore(); // 加上这一句即可解决。可去除缓冲区中残留的'\n'.
    while(N--){
        string s;
        getline(cin,s);
        cout << s << endl;;
    }
```
//output输出    //----------------------------------------------------------------

```cpp
//不需要输出case数
cin>>n;
for(int i=0; i<n; i++){
    int a, b;
    cin>>a>>b;
    cout<<a+b<<endl;
}
```

```cpp
//需要输出case数
cin>>n;
for(int i=0; i<n; i++){
    int a, b;
    cin>>a>>b;
    cout<<"Case"<<i+1<<a+b<<endl;
}
```

```cpp
//每个case之后有空行
for(int i=0; i<n; i++){
    int a, b;
    cin>>a>>b;
    cout<<"Case"<<i+1<<a+b<<endl<<endl;
}
```

```cpp
//两个Case之间有空行
cin>>n;
for(int i=0; i<n; i++){
    int a, b;
    cin>>a>>b;
    if(i>0){
        cout<<endl;
    }
    cout<<"Case"<<i+1<<a+b<<endl;
}
```


/*

处理细节和技巧
输入
不用保存所有组的输入，读一组算一组
“可恶”的字符串——带空白

scanf, cin之类都读到空白结束
gets, cin.getline。再自己parse
用scanf, gets代替cin。


输出
注意格式
字母大小写
什么时候换行
输出“case”后面有没有“#”或者“：”之类。
每行末尾有\n，但一般没有空白
用printf代替cout。


OJ常见状态

内存超限——使用内存过多
返回非零——main函数返回了非零值
浮点错误——除以零
运行错误——指针乱指
段错误——指针越界


*/
