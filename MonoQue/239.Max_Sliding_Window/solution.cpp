//
// Created by lfxyl on 2021/1/18.
//
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<pair<int, int>> monoQue;

        monoQue.push_back({nums[0], 0});
        for (int i = 1; i < k; ++i) {
            while(!monoQue.empty() && monoQue.back().first<nums[i]){
                monoQue.pop_back();
            }
            monoQue.push_back({nums[i], i});
        }
        res.push_back(monoQue.front().first);

        for (int i = k; i < nums.size(); ++i) {
            while(!monoQue.empty() && monoQue.back().first<nums[i]){
                monoQue.pop_back();
            }
            monoQue.push_back({nums[i], i});
            if (monoQue.back().second - monoQue.front().second == k){   // 栈头已经移除窗口了
                monoQue.pop_front();
            }
            res.push_back(monoQue.front().first);
        }

        return res;
    }
};