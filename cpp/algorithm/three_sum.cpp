#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int> > res;
	int n = nums.size();
	sort(nums.begin(),nums.end());
	for (int i = 0; i < n - 2; i++) {
		int j = i + 1;
		int k = n - 1;
		while (j < k) {
			if (nums[i] + nums[j] + nums[k] > 0) k--;//�ܺʹ���0��k�Լ������ܺͱ�С
			else if (nums[i] + nums[j] + nums[k] < 0) j++;//�ܺ�С��0��j���������ܺͱ��

			else {
				res.push_back({nums[i],nums[j],nums[k]});
				while (nums[j + 1] == nums[j]) j++;//�����ظ���
				j++;
			}
		}
		while (nums[i + 1] == nums[i]) i++;//�����ظ���,��֤���Ψһ
	}
	return res;
}

int main() {
	vector<int> demo = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int> > ans = threeSum(demo);

	for (auto dim1 : ans) {
		for (auto dim2 : dim1) {

			std::cout << dim2 << " ";

		}
			std::cout << endl;
	}

	cin.get();

	return 0;
}
