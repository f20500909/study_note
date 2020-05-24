//给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。 
//
// 示例 1: 
//
// 输入:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//输出: [1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2: 
//
// 输入:
//[
//  [1, 2, 3, 4],
//  [5, 6, 7, 8],
//  [9,10,11,12]
//]
//输出: [1,2,3,4,8,12,11,10,9,5,6,7]
// 
// Related Topics 数组


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector <vector<int>> &matrix) {
        //     col
        // row

        int row = matrix.size();
        int col = matrix[0].size();
        int round = (min(row, col) + 1) >> 1;
        int top = 0;
        int bot = row - 1;
        int left = 0;
        int right = col - 1;
        int i=0;
        int j=0;

        while(round--){
            for()

        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
