










#include <unordered_map>
class Solution {
public:
    /**
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */
    vector<vector<string> > topKstrings(vector<string>& strings, int k) {
        // write code here
        vector<vector<string> > ans;
        if (strings.size() == 0 || strings.size() < k)
            return ans;
        // 记录每个元素出现的次数
        unordered_map<string, int> hash;
        for (const auto& string : strings) {
            hash[string]++;
        }
        // 建立小根堆，按照出现次数排序，次数相同按照字典序
        auto cmp = [](const pair<string, int>& p1, const pair<string, int> p2) {
            if (p1.second != p2.second)
                return p1.second > p2.second;
            return p1.first < p2.first;
        };
        // 将全部元素入堆
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> max_heap(cmp);

        auto p_iter = hash.begin();

        for ( ; p_iter != hash.end(); p_iter++) {
            max_heap.emplace(*p_iter);
            if (max_heap.size() > k)
                max_heap.pop();
        }

        while (!max_heap.empty()) {
            pair<string, int> p = min_heap.top();
            max_heap.pop();
            ans.insert(ans.begin(), vector<string>{p.first, to_string(p.second)} );
        }

        return ans;

    }
};












class Solution {
public:
    //greater
    // 小顶堆
    struct cmp{
        public:
            bool operator()(const pair<int,int> & lhs,const pair<int,int>&rhs){
                return lhs.second > rhs.second;
            }//重载operator（）变成自定义operator
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> map;
        for(int i =0;i<nums.size();i++){
            map[nums[i]]++;
        }
        //
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pri_que;
        //
        for (unordered_map<int, int>::iterator it = map.begin();it!= map.end();it++){
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }//
        }
        //inverse
        vector<int> res(k);
        for(int i = k-1;i>=0;i--){
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};




// 建立小根堆，按照出现次数排序，次数相同按照字典序
auto cmp = [](const pair<string, int>& p1, const pair<string, int> p2) {
    if (p1.second != p2.second)
        return p1.second > p2.second;
    return p1.first < p2.first;
};

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a,string b){
	return a < b; //按字典序从小到大排列 
} 

int main(){
	string s[3];
	s[0] = "wu";s[1]="jia";s[2]="jun";
	sort(s,s+3,cmp);
	for(int i = 0;i < 3;i++){
		cout << s[i]<<" ";
	}
}


//-----------------------------------------------------------------








    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
// priority_queue自定义函数的比较与sort正好是相反的
// 也就是说，如果你是把大于号作为第一关键字的比较方式，那么堆顶的元素就是第一关键字最小的
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq; 
// 此时pq就按照节点的值将最小的放在堆顶



    struct Status{
        int val;
        ListNode* node;
        bool operator < (const Status &tmp) const{ 
        // 函数必须是静态的 使得该函数可以被 const 对象也就是常量所调用
        // 形参可以加上const关键字和&，保证安全性，提高效率
            return val > tmp.val;
        }
    };
    priority_queue<Status> pq;  



    struct Status{
        int val;
        ListNode* node; 
        friend bool operator<(Status a, Status b)  // 形参可以加上const关键字和&，保证安全性，提高效率
        {
            return a.val > b.val;
        }
    };
    priority_queue<Status> pq;  



优先队列自定义排序的三种方式 - 克莱登大学本硕博的文章 - 知乎
https://zhuanlan.zhihu.com/p/344121142




重载()和重载<是两种不同的思路，前者是修改优先队列设置优先级的方式，后者是改变优先队列存放的数据类型，可以根据需要选择合适的自定义排序方法。












