//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 示例 1: 
//
// 输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 说明: 
//
// 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。 
// Related Topics 堆 分治算法


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //小根堆 放大元素
    void heapify(vector<int> &data, int index, int len) {
        int left = (index >> 1) + 1;
        int right = (index >> 1) + 2;
        int maxId = index;
        if (left < len && data[left] < data[maxId]) maxId = left;
        if (right < len && data[right] < data[maxId]) maxId = right;
        if (maxId != index) {
            swap(data[maxId], data[index]);
            heapify(data, maxId, len);
        }
    }

    int findKthLargest(vector<int> &nums, int k) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return nums[0];
        vector<int> heap(k, 0);
        for (int i = 0; i < k; i++) {
            heap[i] = nums[i];
        }
        //堆有序化
        for (int i = k >> 1; i >= 0; i--) {
            heapify(heap, i, k);
        }
        //最小堆 最顶就是第k小的
        for (int i = k; i < nums.size(); i++) {
            //如果比最小堆中的最小值还大，就更新小根堆的最小数据
            if (nums[i] > heap[0]) {
                heap[0] = nums[i];
                heapify(heap, 0, k);
            }
        }
        return heap[0];

    }
};
//leetcode submit region end(Prohibit modification and deletion)
