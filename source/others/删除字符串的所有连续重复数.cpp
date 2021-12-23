    public String removeDuplicates(String S) {
        int left = 0;
        int right = 0;
        int length = S.length();
        char[] chars = S.toCharArray();
        while (right < length) {
            //先把右边的字符赋值给左边
            chars[left] = chars[right];
            //然后判断左边挨着的两个字符是否相同，如果相同，
            //他两同时消失，也就是left往回退两步
            if (left > 0 && chars[left - 1] == chars[left])
                left -= 2;
            ++right;
            ++left;
        }
        return new String(chars, 0, left);
    }

作者：sdwwld
链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/solution/shi-yong-zhan-he-shuang-zhi-zhen-liang-c-fo3i/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。






class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else if (s[i] == ')') {
                if (stk.empty() || stk.top() != '(') return false;
                else {
                    stk.pop();
                }
            } else if (s[i] == ']') {
                if (stk.empty() || stk.top() != '[') return false;
                else {
                    stk.pop();
                }
            } else {
                if (stk.empty() || stk.top() != '{') return false;
                else {
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};

作者：wen-jian-69
链接：https://leetcode-cn.com/problems/valid-parentheses/solution/czhan-jie-fa-by-wen-jian-69-b29n/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



























