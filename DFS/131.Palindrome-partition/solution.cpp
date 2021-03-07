//
// Created by lfxyl on 2021/3/7.
//



class Solution {
private:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> slides;
    int n;
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        dp(s);
        dfs(s, 0);
        return ret;
    }

    void dp(string s){
        f.assign(n, vector<int>(n, true));
        for(int i=n-1; i>=0; --i){
            for (int j = i+1; j < n; ++j) {
                if (!(s[i] == s[j] && f[i+1][j-1])){
                    f[i][j] = false;
                }
            }
        }
        return;
    }

    void dfs(string s, int i){
        if(i==n){
            ret.push_back(slides);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (f[i][j]){
                slides.push_back(s.substr(i, j-i+1));
                dfs(s, j+1);
                slides.pop_back();
            }
        }
        return ;
    }

};