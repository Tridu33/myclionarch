class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i =0 ; i*2<=n;i+=1){
            bool match = true;
            if(n%i == 0){
                for(int j =i ;j<n;j+=1){
                    if(s[j] != s[j-i]){
                        match = false;
                        break;
                    };
                };
            //};不应该这行，要i试探过程中包括下面的if(match)，循环完这次枚举的i这次有没有改变
            //match = true;
            //break;
            // :wrong
            if(match == true){return true;};
            }
        }
        return false;//不return match因为走到这步说明枚举完都没有适合的i，结果为false;
    }
};


/*
string中find()返回值是字母在母串中的位置（下标记录），如果没有找到，那么会返回一个特别的标记npos。（返回值可以看成是一个int型的数）
    find函数返回类型 size_type
    string s("1a2b3c4d5e6f7jkg8h9i1a2b3c4d5e6f7g8ha9i");

    string::size_type position;
    //find 函数 返回jk 在s 中的下标位置
    position = s.find("jk");
    if (position != s.npos)  //如果没找到，返回一个特别的标志c++中用npos表示，我这里npos取值是4294967295，
    {
        printf("position is : %d\n" ,position);
    }

返回子串出现在母串中的首次出现的位置，和最后一次出现的位置。

flag = "c";
position = s.find_first_of(flag);
printf("s.find_first_of(flag) is :%d\n",position);//5
position = s.find_last_of(flag);
printf("s.find_last_of(flag) is :%d\n",position);//25

查找某一给定位置后的子串的位置

//从字符串s 下标5开始，查找字符串b ,返回b 在s 中的下标
position=s.find("b",5);
cout<<"s.find(b,5) is : "<<position<<endl;//23

4.查找所有子串在母串中出现的位置

//查找s 中flag 出现的所有位置。
    flag="a";
    position=0;
    int i=1;
    while((position=s.find(flag,position))!=string::npos)
    {
        cout<<"position  "<<i<<" : "<<position<<endl;
        //1
        /21
        //36
        position++;
        i++;
    }

5.反向查找子串在母串中出现的位置，通常我们可以这样来使用，当正向查找与反向查找得到的位置不相同说明子串不唯一。

//反向查找，flag 在s 中最后出现的位置
flag="3";
position=s.rfind (flag);
printf("s.rfind (flag) :%d\n",position);

*/

//invariant
return (s+s).find(s,1) != s.size();


//KMP算法





















