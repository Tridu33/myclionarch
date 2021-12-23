class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int resindex = -1;
        int mindis = INT_MAX;
        for(int i = 0;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            if(x == x1 | y == y1){
                int temp = abs(x1 - x) + abs(y1 - y);
                if(temp < mindis) {
                    mindis = temp;
                    resindex = i;
                }
            };
        }
        if(resindex == -1)return -1;
//        if(x == points[resindex][0] && y == points[resindex][1] ) return 0;//返回resindex
        return resindex;
    }
};


/*
28
51
[[25,45],[60,19],[11,38],[32,22],[1,24],[26,25],[52,36],[45,54],[45,30],[45,39],[39,38],[25,38],[39,57],[47,51],[47,49],[37,21],[16,43],[53,33],[10,50],[30,29],[3,31],[45,26],[22,40],[2,31],[57,42],[25,42],[37,13],[13,54],[17,5],[50,32]]
*/


int cnt[26];
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i += 1){
            for(int& x : cnt) x = 0;
            for(int j = i; j < s.size(); j += 1){
                cnt[s[j] - 'a'] += 1;
                int ma = 0, mi = s.size();
                for(int x : cnt) if(x){
                    ma = max(ma, x);
                    mi = min(mi, x);
                }
                ans += ma - mi;
            }
        }
        return ans;
    }
};