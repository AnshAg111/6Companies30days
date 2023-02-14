class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans, prime;
        if(left==right){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        vector<bool>isprime(right+1, true);
        for(int i=2; i*i<=right; i++){
            if(isprime[i]==true){
                for(int j=i*i; j<=right; j+=i){
                    isprime[j]=false;
                }
            }
        }
        for(int i=max(2, left); i<=right; i++){
            if(isprime[i]==true) prime.push_back(i);
        }
        int n=prime.size(), x, y, m=INT_MAX;
        if(n==1 or n==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else if(n==2) return prime;
        for(int i=1; i<n; i++){
            if(m>prime[i]-prime[i-1]) {
                m=prime[i]-prime[i-1];
                x=prime[i];
                y=prime[i-1];
            }
        }
        ans.push_back(y);
        ans.push_back(x);
        return ans;
    }
};