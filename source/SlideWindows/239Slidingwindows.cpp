class Solution {
private:
    class MyQueue{//monotone dequeue
    public:
        deque<int> que;
    // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
    // 同时pop之前判断队列当前是否为空。
        void pop(int val){
            if(!que.empty() && val == que.front()){
                que.pop_front();
            };
        };

    // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。 
    // 这样就保持了队列里的数值是单调从大到小的了。

        void push(int val){
            ;while(!que.empty() && val >que.back()){
                que.pop();
            };
            que.push_back(val);
        };

    // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front(){
            return que.front();
        }
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        Myqueue que;
        for (int i = 0; i < k;i++){
            que.push(nums[i]);
        };
        res.push - back(que.front());
        for (int i = k;i<nums.szie();i++){
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};











