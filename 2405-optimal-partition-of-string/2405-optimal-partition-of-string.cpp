class Solution {
public:
    int partitionString(string s) {
        
        int ans = 1;
        set<char>a;
        for(auto c:s){
            if(a.find(c) != a.end()){
                a.clear();
                ans++;
            }
            a.insert(c);
        }
        return ans;
        
    }
};