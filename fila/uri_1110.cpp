#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> count;
        int cnt = 0;
        int n = nums.size();
        int ans = 0;
        for (int x : nums) {
            if (x == 0) {
                cnt--;
            }
            else {
                cnt++;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (count[i] == count[j] && j - i > ans) {
                    ans = j - i;
                }
            }
        }
        return ans;
    }
};
//int main() {
//
//    vector<int> input{ 0, 1, 0, 0,1,1,0 };
//    int target = 9;
//    Solution solve;
//    cout << solve.findMaxLength(input) << endl;
//
//    return 0;
//}