class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int max=*max_element(cards.begin(), cards.end()), n=cards.size();
        int ans=n;
        vector<vector<int>>v(max+1);
        for(int i=0; i<n; i++){
            v[cards[i]].push_back(i);
        }
        for(int i=0; i<v.size(); i++){
            int m=v[i].size();
            if(m>1){
                for(int j=0; j<m-1; j++){
                    if(ans>v[i][j+1]-v[i][j]) ans=v[i][j+1]-v[i][j];
                }
            }
        }
        if(ans==n) return -1;
        return ans+1;
    }
};