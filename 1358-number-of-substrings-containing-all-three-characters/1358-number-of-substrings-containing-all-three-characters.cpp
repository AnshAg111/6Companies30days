class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0, j=0, c=0, n=s.length();
        unordered_map<char, int>m;
        while(j<n){
            m[s[j]]++;
            while(m['a']>=1 and m['b']>=1 and m['c']>=1){
                c+=(n-j);
                m[s[i]]--;
                i++;
            }
            j++;
        }
        return c;
    }
};