class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int maxcoins=0, n=piles.size()/3;
        sort(piles.begin(), piles.end(), greater<int>());
        for(int i=1; i<2*n; i+=2){
            maxcoins+=piles[i];
        }
        return maxcoins;
    }
};