class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int len = S.size();
        //# of 0s in right, including self
        vector<int> right(len + 1, 0);
        int cnt = 0;
        for(int i = len - 1; i >= 0; --i)
        {
            if(S[i] == '0')++cnt;
            right[i] = cnt;
        }
        //cnt # of 1s in left
        cnt = 0;
        int res = INT_MAX;
        for(int i = 0; i < len + 1; ++i)
        {
            int curr = cnt + right[i];
            res = min(res, curr);
            if(S[i] == '1')++cnt;
        }
        return res;
    }
};