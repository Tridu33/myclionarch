#include <bits/stdc++.h>
using namespace std;

int main() {
//    ios::sync_with_stdio(false);
    priority_queue<long long> pq;
    long long l,p,n;
    vector<long long> get(l+1,0);
    long long x,y;
    int ans = 0;
    for(long long i =0;i<n;i++){
        cin >> x >> y;
        get[x] = y;
    }
    for(long long i =0;i<=l;i++){
        p--;
        if(get[i] != 0) pq.push(get[i]);
        if(p == 0){
            if(pq.empty()){
                ans = -1;
                break;
            }else{
                p += pq.top();
                pq.pop();
                ans++;
            }
        }

    }
    cout << ans << endl;
    return 0;
}