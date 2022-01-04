class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> greater(nums2.size(), -1);
        stack<int> s;
        for (int i = 0; i < nums2.size(); ++i) {
            while (!s.empty() && (nums2[s.top()]<nums2[i])){
                greater[s.top()] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
        // 若栈非空，那么剩余的元素，其右边是没有比自身大的元素的，不用管了。

        vector<int> ret(nums1.size(), -1);
        for(int i=0; i<nums1.size(); ++i){
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            if(it != nums2.end()){
                ret[i] = greater[it-nums2.begin()];
            }
        }
        return ret;
    }
};