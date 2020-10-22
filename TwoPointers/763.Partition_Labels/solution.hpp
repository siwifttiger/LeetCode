class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ret;
        int tabNum[26] = {0};
        auto len = S.length();
        /* 先打表，记录每个字母出现的最远的位置 */
        for(int i = 0; i < len; ++ i)
        {
            tabNum[S[i] - 'a'] = i;
        }
        
        /* 双指针，end指向一个字母出现的最远的位置
           start用来遍历中间字符，如果遍历到start == end了，说明这是一个符合要求的分割
         */
        int start = 0, end = 0;
        for(int i = 0; i < len; ++i)
        {
            end = max(end, tabNum[S[i] - 'a']);
            if (i == end)
            {
                ret.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ret;
    }
};