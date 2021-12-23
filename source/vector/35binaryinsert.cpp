#include "../../utils/leetCode.h"
//using namespace leetCode;

class Solution {
private:

public:
    int func() {
        return 0;
    }
};

int main() {
    vector<int> arr = leetCode::nvec<int>();
//    vector<vector<int>> mat = mnmat<int> ();
//    vector<float> arr = nvec<float>();
//    if(typeid(arr[0]) == typeid(float)){
//        cout << "arr[0] 的类型是：float" << endl;
//    }
    for (auto x : arr){
        cout << x << endl;
    }
    Solution sol;
    cout << sol.func() << endl;
    return 0;
}
