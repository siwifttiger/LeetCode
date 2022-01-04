class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>  s;
        int n = nums.size();
        vector<int> ret(n, -1);
        for(int i=0; i<2*n-1; ++i){
            while(!s.empty() && (nums[s.top()]<nums[i%n])){
                ret[s.top()] = nums[i%n];
                s.pop();
            }
            s.push(i%n);
        }
        return ret;
    }
};