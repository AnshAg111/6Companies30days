class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length(), c=0;
        if(n-k+1<pow(2, k)) return false;
        unordered_map<string, int>m;
        for(int i=0; i<n-k+1; i++){
            string st=s.substr(i, k);
            if(m[st]==0){
                m[st]++;
                c++;
            }
        }
        if(c==pow(2, k)) return true;
        return false;
    }
};