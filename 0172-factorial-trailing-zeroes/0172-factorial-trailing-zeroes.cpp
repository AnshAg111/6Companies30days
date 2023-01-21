class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0) return 0;
        int c2=0, c5=0;
        for(int i=1; i<=n; i++){
            if(i%2==0){
                int j=i;
                while(j%2==0){
                    j/=2;
                    c2++;
                }
            }
            if(i%5==0){
                int j=i;
                while(j%5==0){
                    j/=5;
                    c5++;
                }
            }
        }
        return min(c2, c5);
    }
};