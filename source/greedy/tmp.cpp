#include<bits/stdc++.h>
using namespace std;
bool myCmp(vector<int> a,vector<int> b){
    if(a[0] != b[0]) return a[0] > b[0];
    return a[2] < b[2];
}
int main(){
    int n;
    while(cin >> n) {
        vector<int> v(n,0),t(n,0),d(n,0);
        for(int i =0;i<n;i++){
            cin >> v[i];
        }
        for(int i =0;i<n;i++){
            cin >> t[i];
        }
        for(int i =0;i<n;i++){
            cin >> d[i];
        }
        vector<vector<int>> vec(n,vector<int> (3,0));
        for(int i =0;i<n;i++){
            vec[i][0] = v[i];
            vec[i][1] = t[i];
            vec[i][2] = d[i];
        }
        sort(vec.begin(),vec.end(),myCmp);
        int res =0, curddl = 0;
        for(int i =0;i<n;i++){
            if(curddl + vec[i][1] <= vec[i][2]){
                res += vec[i][0];// can do
                curddl += vec[i][1];
            }
        }
        cout << res << endl;
    }
    return 0;
}