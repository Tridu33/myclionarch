class Solution {
public:
    /**
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */
    vector<vector<string> > topKstrings(vector<string>& strings, int k) {
        struct pqcmp{
            bool operator()(pair<string,int> a,pair<string,int> b){
                if(a.second != b.second){
                    return a.second > b.second;
                }
                return a.first<b.first;
            };
        };
        // 建立小根堆，按照出现次数频率由高到低降序排序，次数相同按照字典序(字母升序)
//         auto pqcmp = [](const pair<string, int>& p1, const pair<string, int> p2) {
//             if (p1.second != p2.second)
//                 return p1.second > p2.second;//小根堆,大于号.根最小频率排数组后面
//             return p1.first < p2.first;//相同频率根字典序大，因而排数组后面
//         };        // 将全部元素入堆
//         priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> max_heap(cmp);
        vector<vector<string>> res;
        int n = strings.size();
        if(n == 0) return res;
        priority_queue<pair<string,int>,vector<pair<string,int>>,pqcmp> pq;
        unordered_map<string, int> map;
        for(auto str:strings){
            map[str]++;
        }
        for(unordered_map<string,int>::iterator it = map.begin();it!= map.end();it++){
            pq.emplace(*it);
            if(pq.size() > k){
                pq.pop();
            }
        };
        while(!pq.empty()){
            pair<string,int> cur = pq.top();
            pq.pop();
            res.insert(res.begin(),vector<string>{cur.first,to_string(cur.second)});
        };
        return res;
    }
};