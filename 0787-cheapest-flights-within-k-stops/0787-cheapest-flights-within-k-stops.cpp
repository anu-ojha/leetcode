class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        int MAX = 1e6+1;
        vector<int> dist(n, MAX);
        
        //base case
        dist[src] = 0;
        for(vector<int>& flight : flights){
            
            if(flight[0] == src)
                dist[flight[1]] = flight[2];
        }
        
        
        while(K-- > 0){
            
            vector<int> tmp(dist);
            for(vector<int>& flight : flights){
                
                tmp[flight[1]] = min(tmp[flight[1]], dist[flight[0]] + flight[2]);
                
            }
            swap(tmp, dist);
        }
        
        
        return dist[dst] == MAX ? -1 : dist[dst];
    }
};