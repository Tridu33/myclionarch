/*
    int a,b;
    freopen("debug\\in.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
    freopen("debug\\out.txt","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
    while(cin>>a>>b)
    cout<<a+b<<endl; // 注意使用endl
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
 * */


/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    // freopen("debug\\in.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
    // freopen("debug\\out.txt","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
    ;
    // fclose(stdin);//关闭文件
    // fclose(stdout);//关闭文件
    return 0;
}

 int     范围是-2147483648~2147483647；
float   整数部分范围是能表达式万亿级别，已经够大了，实际开发完全够用；
float   小数部分取值范围：最多只能精确到小数点后 6 位；
double  整数部分范围比 float 更大，脑补就行了….；
double  小数部分取值范围：最多只能精确到小数点后 15 位；


*/

//#include<bits/stdc++.h>
//using namespace std;
//
//void printmatrix(vector<vector<int>> matrix);
//void printmatrix(vector<vector<int>> matrix){
//    int m = matrix.size();
//    int n = matrix[0].size();
//    for(int i =0;i<m;i++){
//        for(int j =0;j<n;j++){
//            cout << matrix[i][j] << ", ";
//        }
//        cout << endl;
//    }
//}

// 暴力穷举
#include<iostream>
#include<vector>
using namespace std;
bool is24(vector<double> a, int tot, double result)
{
    if(a.empty())
    {
        return result==tot;
    }
    for(int i=0; i<a.size() ;i++)
    {
        vector<double> b(a);
        b.erase(b.begin()+i);
        if(is24(b,tot,result+a[i])
           || is24(b,tot,result-a[i])
           || is24(b,tot,result*a[i])
           || is24(b,tot,result/a[i]))
            return true;
    }
    return false;
}
int main()
{
    vector<double> a(4,0);
    while(cin >> a[0] >> a[1] >> a[2] >> a[3])
    {
        if(is24(a,24,0))
            cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
}


















//
//
//int main(){
//    string s,t;
//    while(cin >> s >> t){
//        int m = s.size(), n = t.size();
//        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
//        for(int i =0;i<=m;i++){
//            dp[i][0] = i;
//        }
//        for(int i =0;i<=n;i++){
//            dp[0][i] = i;
//        }
//        for(int i = 1; i <= m; i++){
//            for(int j =1;j <= n; j++){
//                if(s[i-1] != t[j-1]){
//                    dp[i][j] = 1 + min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
//                }
//                else{
//                    dp[i][j] = dp[i-1][j-1];
//                }
//            }
//        }
//        cout << dp[m][n] << endl;
//        printmatrix(dp);
//    }
//    return 0;
//}


/*
本题删除，替换，插入代价全是 1
//*/
//int calStringDistance(string A,string B);
//int main()
//{
//    string charA;
//    string charB;
//    while(getline(cin,charA)&&getline(cin,charB))
//    {
//        cout<<calStringDistance(charA,charB)<<endl;
//    }
//    return 0;
//}
//int calStringDistance(string A,string B)
//{
//    int row=A.size();//字符串A的长度
//    int col=B.size();//字符串B的长度
//    int **dp=new int*[row+1];//动态创建一个二维数组
//    for(int i=0;i<row+1;i++)
//    {
//        dp[i]=new int[col+1]();
//    }
//    dp[0][0]=0;//这里代价是0，也就是空字符到空字符，不需要任何编辑
//    for(int i=1;i<row+1;i++)//这里是A的i个字符到B空字符需要i个删除代价
//    {
//        dp[i][0]=i;
//    }
//    for(int j=1;j<col+1;j++)//这里是A从空字符到B的j个字符共需要j个插入代价
//    {
//        dp[0][j]=j;
//    }
//    for(int i=1;i<row+1;i++)
//    {
//        for(int j=1;j<col+1;j++)
//        {
//            if(A[i-1]==B[j-1])
//            {
//                dp[i][j]=dp[i-1][j-1];//如果i和j位置字符相同，说明i和j位置的字符不需要编辑。dp[i][j]=dp[i-1][j-1]
//            }
//            else
//            {
//                dp[i][j]=dp[i-1][j-1]+1;//这里需要一个替换代价
//            }
//            dp[i][j]=min(dp[i-1][j]+1,dp[i][j]);
//            dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
//        }
//    }
//    for(int i=1;i<row+1;i++)
//    {
//        for(int j=1;j<col+1;j++)
//        {
//            cout << dp[i][j] << ", " ;
//        }
//        cout << endl;
//    }
//    return dp[row][col];
//}





//
//#include<bits/stdc++.h>
//using namespace std;
//struct ListNode{
//    int val;
//    ListNode * next;
//    ListNode():val(-1),next(nullptr) {};
//    ListNode(int _val):val(_val),next(nullptr) {};
//};
//int main(){
//    int n;
//    while(cin >> n){
//        int first;cin>> first;
//        ListNode * dummy = new ListNode();
//        ListNode * firstnode = new ListNode(first);
//        dummy->next = firstnode;
//        int val,father;
//        for(int i =0;i<n-1;i++){
//            cin >> val >> father;
//            ListNode * node = new ListNode(val);
//            ListNode* search = dummy;
//            while(search){
//                if(search->val == father){
//                    node->next =  search->next;
//                    search->next = node;
//                    break;//插入
//                }else{
//                    search = search->next;
//                }
//            }
//        }
//        int del;
//        cout << "test" << endl;
//        //打印链表
//        {
//            ListNode* search=dummy->next;//
//            while(search)
//            {
//                cout<<search->val<<" ";
//                search=search->next;
//            }
//            cout<<endl;
//        }
//    }
//    return 0;
//}

//
//#include<bits/stdc++.h>
//using namespace std;
//void print(vector<vector<bool>> dp){
//    int n = dp.size();
//    for(int i =0;i<n;i++){
//        for(int j =0;j<n;j++){
//            cout << dp[i][j]<<"";
//        }
//        cout << endl ;
//    }
//    cout << endl;
//}
//int main(){
//    string s;
//    while(cin>>s){
//        int n = s.size();
//        vector<vector<bool>> dp(n,vector<bool> (n,false));
////        for(int i = 0;i<n;i++){
////            dp[i][i] = true;
////            if(i+1 < n){
////                dp[i][i+1] = (s[i] == s[i + 1]);
////            }
////        }
//        int maxlen = 1;
//        for (int i = s.size() - 1; i >= 0; i--) {  // 注意遍历顺序
//            for (int j = i; j < s.size(); j++) {
//                if (s[i] == s[j]) {
//                    if (j - i <= 1) { // 情况一 和 情况二
//                        dp[i][j] = true;
//                        maxlen = max(maxlen,j-i+1);
//                    } else if (dp[i + 1][j - 1]) { // 情况三
//                        dp[i][j] = true;
//                        maxlen = max(maxlen,j-i+1);
//                    }
//                }
//            }
//            print(dp);
//        }
//        cout << maxlen << endl;
//    }
//    return 0;
//}
//int main(){
//    string s;
//    while(getline(cin,s))
//    {
//        int n=s.size();
//        vector<vector<bool>> dp( n,vector<bool>(n,false) );//定义一个尺寸为n*n的二维向量并初始化为全false
//        int max=1; //最长回文子串的长度初始化为1
//        for(int i=0;i<n;i++){
//            for(int j=0;j<=i;j++)            {
//                /*确定dp[j][i]的值*/
//                if(i==j) dp[j][i]=true;
//                else if(i-j==1) dp[j][i]=(s[i]==s[j]);
//                else dp[j][i]=( s[j]==s[i] && dp[j+1][i-1] );
//                /*若s.substr(j,i-j+1)是回文子串，更新当前最长回文子串的长度*/
//                if(dp[j][i] && max<i-j+1) max=i-j+1;
//            }
//            print(dp);
//        }
//        cout<<max<<endl;
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//
//class Solution {
//public:
//    void print(vector<vector<int>> dp){
//        int n = dp.size();
//        for(int i =0;i<n;i++){
//            for(int j =0;j<n;j++){
//                cout << dp[i][j]<<"";
//            }
//            cout << endl ;
//        }
//        cout << endl;
//    }
//    string longestPalindrome(string s) {
//        int n = s.size();
//        if (n < 2) {
//            return s;
//        }
//
//        int maxLen = 1;
//        int begin = 0;
//        // dp[i][j] 表示 s[i..j] 是否是回文串
//        vector<vector<int>> dp(n, vector<int>(n));
//        // 初始化：所有长度为 1 的子串都是回文串
//        for (int i = 0; i < n; i++) {
//            dp[i][i] = true;
//        }
//        // 递推开始
//        // 先枚举子串长度
//        for (int L = 2; L <= n; L++) {
//            // 枚举左边界，左边界的上限设置可以宽松一些
//            for (int i = 0; i < n; i++) {
//                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
//                int j = L + i - 1;
//                // 如果右边界越界，就可以退出当前循环
//                if (j >= n) {
//                    break;
//                }
//
//                if (s[i] != s[j]) {
//                    dp[i][j] = false;
//                } else {
//                    if (j - i < 3) {
//                        dp[i][j] = true;
//                    } else {
//                        dp[i][j] = dp[i + 1][j - 1];
//                    }
//                }
//
//                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
//                if (dp[i][j] && j - i + 1 > maxLen) {
//                    maxLen = j - i + 1;
//                    begin = i;
//                }
//            }
//            print(dp);
//        }
//        return s.substr(begin, maxLen);
//    }
//};
//
//
//int main(){
//    Solution sol;
//    sol.longestPalindrome("ABBA");
//    return 0;
//}



//bool conmonsubstr2(string & str){
//    int n = str.size();
//    for(int i =0;i<n;i++){
//        for(int j =i+1;j<n;j++){
//            if(str[i] == str[j]){// first
//                if(i+1 < n && j + 1 < n && i+1 < j &&
//                   str[i+1] == str[j+1]){// second
//                    return false;
//                }
//            }
//        }
//    }
//    return true;
//}
//int main(){
//    for(int test = 0;test < 4 ;test++){
//        if(test == 0) {cout << "test1" << endl;continue;}
//        if(test == 1) {cout << "test2" << endl;continue;}
//        if(test == 2) {cout <<  "test3"<< endl;continue;}
//        if(test != 3) {cout << "test4" << endl;continue;}
//    }
//    string s;
//    while(cin>>s){
//        int n = s.size();
//        int flag1 = 0,flag2 = 0,flag3 = 0;// bool
//        if(s.size() > 8) flag1 = 1;
//        int isab=0,isAB= 0,isn = 0, isother = 0;
//        for(int i=0;i<n;i++){
//            char ch = s[i];
//            if('a' <= ch && ch <= 'z') {isab = 1;continue;}
//            if('A' <= ch && ch <= 'Z') {isAB = 1;continue;}
//            if('0' <= ch && ch <= '9') {isn  = 1;continue;}
//            // others
//            if(isother == 0)
//                isother = 1;
//        }
//        if(isab + isAB + isn + isother >= 3)
//            flag2 = 1;
//        // 长度大于二的重复子串
//        if(conmonsubstr2(s)) flag3 = 1;
//        if(flag1 + flag2 + flag3 == 3){
//            cout << "OK" << endl;
//        }else{
//            cout << "NG" << endl;
//        }
//    }
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    int n ;
//    while(cin >> n){
//        for(int i =0;i<n;i++){
//            string str;
//            vector<int> alpha(26,0);
//            cin >> str;
//            for(char ch: str){
//                if('a' <= ch && ch <= 'z'){
//                    alpha[ch - 'a'] ++ ;
//                }else{
//                    alpha[ch - 'A'] ++ ;
//                }
//            }
//            sort(alpha.begin(),alpha.end());
//            int res = 0,k = 26;
////            for(int i = 25; i>=0; i++){//卧槽
//                res += alpha[i] * k--;
//            }
//            cout << res << endl;
//        }
//    }
//    return 0;
//}






















//
//#include <iostream>
//
//using namespace std;
//
//struct node{
//    int val;
//    node*next = nullptr;
//};
//
//int main()
//{
//    int n = 0;
//    while(cin>>n)//n值
//    {
//        //创建头节点
//        node*head = new node;
//
//        //加入第一个节点
//        {
//            int temp = 0;
//            cin>>temp;
//            node*first = new node;
//            first->val=temp;
//            head->next=first;
//        }
//
//        //加入后续节点
//        for(int i = 0;i<n-1;i++)
//        {
//            int value;//要加入节点的值
//            int father;//父节点的值
//
//            cin>>value>>father;
//
//            //找到要插入的位置
//            node*search=head->next;
//            while(search)
//            {
//                if(search->val==father)
//                {
//                    node*son=new node;
//                    son->val=value;
//                    son->next=search->next;
//                    search->next=son;
//                    break;
//                }
//                search=search->next;
//            }
//
//        }
//
//        //删除指定值
//        {
//            int del;
//            cin>>del;
//            node*search=head->next;
//            while(search)
//            {
//                if(search->val==del)
//                {
//                    if(search->next)
//                    {
//                        search->val=search->next->val;
//                        node*temp=search->next;
//                        search->next=search->next->next;
//                        delete temp;
//                    }
//                }
//                search=search->next;
//            }
//        }
//
//
//        //打印链表
//        {
//            node* search=head->next;
//            while(search)
//            {
//                cout<<search->val<<" ";
//                search=search->next;
//            }
//            cout<<endl;
//        }
//
//        //释放所有
//        node* search=head;
//        while(search)
//        {
//            head=head->next;
//            delete search;
//            search = head;
//        }
//    }
//
//    return 0;
//}
//
//














































//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    while(cin >> n){
//         double(n);
//         cout << n << endl;
//        double res = n;
//        double hight = n;
//        for(int i =2;i<=5;i++){
//            hight /= 2;
//            res += hight * 2;
//        }
//        cout << res << endl << hight/2 << endl;
//    }
//    return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    string str,input;
//    cin >> str >> input;
//    vector<int> alpha(26,0);
//    vector<char> table;
//    for(auto ch:str){
//        if(alpha[ch - 'A'] == 0){
//            alpha[ch-'A'] = 1;
//            table.push_back(ch);
//        }
//    }
//    for(int i =0;i<26;i++){
//        if(alpha[i] == 0){
//            table.push_back(char(i + 'A'));
//        }
//    }    // table.size() == 26
//    string output;
//    for(int i =0;i<input.size();i++){
//        char ch = input[i];
//        output.push_back(table[ch - 'A']);
//    }
//    cout << output << endl;
//    return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    string str = "0123456789";
//    string retStr = str.insert(str.size(), "Hello World!");
//    cout << "str = " << str << endl;
//    cout << "retStr = " << retStr << endl;
//    return 0;
//}
/*
 * str = 0123456789Hello World!
 * retStr = 0123456789Hello World!
 */


//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    int n;cin >> n;
//    vector<vector<int>> matrix(n,vector<int> (n,0));
//    int counter = 1;
//    for(int indexsum = 0; indexsum<= n-1; indexsum++){
//        for(int i = indexsum;i>=0;i--){
//            matrix[i][indexsum - i] = counter++;
//        }
//    }
//    for(int i =0;i<n;i++){
//        for(int j =0;j<n;j++){
//            if(j != 0 && matrix[i][j] != 0){
//                cout << " " <<  matrix[i][j];
//            }
//            if(j == 0){
//                cout << matrix[i][j];
//            }
//        }
////         cout << endl;
//    }
//    return 0;
//}



//
//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    int temp,n;
//    set<int> s;
//    while(cin >> n){
//        while(n--){
//            cin >> temp;
//            s.insert(temp);
//        }
//    }
//    vector<int> nums;
//    for(auto it = s.begin();it != s.end();it++){
//        nums.push_back(*it);
//    }
//    sort(nums.begin(),nums.end());
//    for(int i =0;i<nums.size();i++){
//        cout << nums[i] << endl;
//    }
//    return 0;
//}
//


//
//
//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//
//int main() {
//    string s;
//    getline(cin,s);
//    stringstream ss(s);
//    string res="", tmp;
//    while (ss>>tmp) {
//        if (res=="")
//            res=tmp;
//        else
//            res=tmp+" "+res;
//    }
//    cout<<res;
//    return 0;
//}


//
//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//int main()
//{
//    stack<string> ss;
//    string s;
//    while(cin>>s)
//    {
//        ss.push(s);
//    }
//    while(!ss.empty())
//    {
//        cout<<ss.top();
//        ss.pop();
//        if(!ss.empty())
//            cout<<' ';
//    }
//    cout<<endl;
//}
//




//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    int n=0,k=0;
//    cin >> n >> k;
//    vector<int> nums(n,0);
//    for(int i =0;i<n;i++){
//        cin >> nums[i];
//    }
//    int sum = accumulate(nums.begin(), nums.end(), 0);
////     int average = sum / nums.size();
//    int s ;
//    int m=0, maxi, mini;
//    vector<vector<int>> vec(k,vector<int> (2,0));// m <= k不会全部打印
//    sort(nums.begin(),nums.end());
//    while(m < k){
//        maxi = max_element(nums.begin(), nums.end()) - nums.begin();
//        mini = min_element(nums.begin(), nums.end()) - nums.begin();
//        if(nums[maxi] == nums[mini] ) break;
//        vec[m][0] = maxi + 1;
//        vec[m][1] = mini + 1;
//        nums[maxi] -= 1; nums[mini] += 1;
//        m++;
//    }
//    s = *max_element(nums.begin(),nums.end()) - *min_element(nums.begin(),nums.end());//选择最简单最不容易错的，不要重复计算在循环中，尽量防止错误提出出来。
//    cout << s << " " << m << endl;
//    for(int i =0;i<m;i++){
//        cout << vec[i][0]  << " " << vec[i][1]  << endl;
//    }
//    return 0;
//}
//
//

//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    int n;
////     cin >> n;
//    scanf("%d", &n);
//    while(n--){
//        int h,m,s;
////         cin >> h >> m >> s;
//        scanf("%d:%d:%d", &h, &m, &s);//考点是格式化输入
//        if(h>= 24)
//            h %= 10;
//        if(m >= 60)
//            m %= 10;
//        if(s >= 60)
//            s %= 10;
//        printf("%02d:%02d:%02d\n", h, m, s);
//    }
//    return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//struct mytime {
//    int h;
//    int m;
//};
//bool mycmp(mytime a,mytime b){
//    return (a.h != b.h)? a.h <= b.h: a.m <= b.m;
//}
//mytime mytimesub(mytime  clock,int x){
//    mytime ddl;
//    int h = 0;
//    if(x >= 60){
//        x = x % 60;
//        h = 1;// [0,59]
//    }
//    ddl.h = ((clock.h - h) < 0)? (clock.h - h) + 12: (clock.h - h);
//    if((clock.m - x) < 0){
//        ddl.m = (clock.m - x) + 60;
//        ddl.h = (ddl.h-1 < 0)? ddl.h-1 + 12 : ddl.h - 1;
//    }else{
//        ddl.m = (clock.m - x);//17:14 - 30 = 16: 44;
//    }
//    return ddl;
//};
//int main(){
//    int n = 0;
//    cin >> n;
//    vector<mytime> clocks(n);
//    for(int i =0;i<n;i++){
//        cin >> clocks[i].h;
//        cin >> clocks[i].m;
//    }
//    int x;
//    cin >> x;
//    mytime begin;
//    cin >> begin.h >> begin.m;
//    mytime curddl = mytimesub(begin,x);
//    sort(clocks.begin(),clocks.end(),mycmp);
//    for(int i = n-1;i>=0;i--){
//        if(mycmp(clocks[i],curddl)){
//            cout << clocks[i].h << " "<< clocks[i].m << endl;
//            break;
//        }
//    }
//    return 0;
//}
//









//#include<iostream>
//#include<unordered_map>
//using namespace std;
//int main()
//{
//    int num,res=0;
//
//    unordered_map<int, int> a;
//    while (cin >> num)//回车后，在新行Ctrl+z并回车。若输入数据后Ctrl+z再回车无效。
//        //本地调试这样写会死循环，但是牛客用文本转意不会，因为文本有EOF输入cin终止符，就像手工ctrl+C ctrl+D Z
//    {
//        cout << num<<"cout " << endl;
//        if (a[num] == 0)
//        {
//            a[num] = num;
//            res += num + 1;
//        }
//        else
//            a[num]--;
//    }
//    cin.clear();
//    cout << res << endl;
//    return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//    int cur;
//    vector<int> vec; //4 4 4 4 4 4 4 4 ==> 10
//    while(cin >> cur){        // 0 0 0 ==> 3
//        vec.push_back(cur);
//    }
//    sort(vec.begin(),vec.end());
//    int res = 0;
//    for(int i =0; i<vec.size(); i++){
//        int cnt=1,temp = vec[i];//4
//        if(temp == 0){
//            cnt++;
//            res++;
//            continue;
//        }
//        while(i+1<vec.size() && vec[i+1] == temp && cnt < temp + 1){
//            i++;
//            cnt++;
//        }
//        res += (1 + temp);// one batch
//    }
//    cout << res << endl;
//    return 0;
//}
//
//


/* 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int temp ;
        cin >> temp;
        string line;
        getline(cin,line);/*while(getline(cin,line))语句
注意这里默认回车符停止读入,按Ctrl+Z或键入EOF回车即可退出循环。
在这个语句中，首先getline从标准输入设备上读入字符，然后返回给输入流cin，注意了，是cin，所以while判断语句的真实判断对象是cin，也就是判断当前是否存在有效的输入流。
在这种情况下，我想只要你的电脑不中毒不发神经你的输入流怎么会没有效？所以这种情况下不管你怎么输入都跳不出循环，因为你的输入流有效，跳不出循环。
然而有些同学误以为while判断语句的判断对象是line（也就是line是否为空），然后想通过直接回车（即输入一个空的line）跳出循环，却发现怎么也跳不出循环。
这是因为你的回车只会终止getline()函数的读入操作。getline()函数终止后又进行while（）判断（即判断输入流是否有效，你的输入流当然有效，满足条件），所以又运行getline()函数。
所以，以下的写法根本不可能让你推出while（）循环的：
while(getline(cin,line))
cout<<line<<endl;

        // cin >> line;
        int res = 0;
        cout << line << endl;
        for(int i =0;i<temp;i++){
            char ch = line[i];
            if(ch == '.'){
                i += 2;
                res ++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
 */
 
 /* 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int k ;
    cin >> k;
    while(k--){
        set<int> myset;
        int n;
        cin >> n;
        for(int i =0;i<n;i++){
            int temp;
            cin >> temp;
            myset.insert(temp);
        }
        if(myset.size() != 3 || myset.size() != 1){
            cout << 'NO' << endl;;
        }
        //
        if(myset.size() == 1){
            cout << "YES" << endl;
        }
        if(myset.size() == 3){
            vector<int> vec;
            for(auto it = myset.begin(); it != myset.end(); it++){
               vec.push_back(*it);
           }
            sort(vec.begin(),vec.end());
            if(vec[1] - vec[0] == vec[2] - vec[1]){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
 */




/*
#include<bits/stdc++.h>
using namespace std;
int problem(vector<int>& nums){
    ;
    return 0;
}
int main(){
    ;
    return 0;
}




#include<bits/stdc++.h>
using namespace std;
int main(){
    int count=2000;
    int n;
    cin >> n;
    vector<int> x(n,0),y(n,0); 
    int cur;
    for(int i=0;i<n;i++){
        cin>>x[i];   
    }
    for(int i=0;i<n;i++){
        cin>>y[i];   
    }
    int res = 0;
    for(int i = 0;i<n;i++){
        res = min(res, x[i] - 1 + y[i] - 1);
        cout << x[i]<< "," << y[i] << endl;
        cout << res << endl;
    }
    cout << res <<endl;

    return 0;
}

*/
// cout << "Test bits/stdc++.h" << endl;