class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        // for(int i=bottom; i<=top; i++){
        //     if(j<n and i==special[j]){
        //         c=0;
        //         j++;
        //     }
        //     else{
        //         c++;
        //         ans=max(ans, c);
        //     }
        // }
        int m=special[0]-bottom, n=special.size();
        for(int i=0; i<n; i++){
            if(i==n-1){
                m=max(m, top-special[i]);
            }
            else m=max(m, special[i+1]-special[i]-1);
        }
        return m;
    }
};