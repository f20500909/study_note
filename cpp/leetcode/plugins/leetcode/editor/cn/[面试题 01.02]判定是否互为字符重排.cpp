//给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。 
//
// 示例 1： 
//
// 输入: s1 = "abc", s2 = "bca"
//输出: true 
// 
//
// 示例 2： 
//
// 输入: s1 = "abc", s2 = "bad"
//输出: false
// 
//
// 说明： 
//
// 
// 0 <= len(s1) <= 100 
// 0 <= len(s2) <= 100 
// 
// Related Topics 数组 字符串


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        char data[256] = {};
        for (int i = 0; i < s1.size(); i++) {
            int index = s1[i];
            data[index]++;
        }
        for (int i = 0; i < s2.size(); i++) {
            int index = s2[i];
            data[index]--;
        }

        for (int i = 0; i < 256; i++) {
            if (data[i] != 0) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
