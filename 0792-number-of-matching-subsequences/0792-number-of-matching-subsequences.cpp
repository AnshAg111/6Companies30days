class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int c=0, n=s.length(), m=words.size();
        // for(int i=0; i<m; i++){
        //     int a=0, b=0, l=words[i].length();
        //     while(a<n and b<l){
        //         if(s[a]==words[i][b]) b++;
        //         a++;
        //     }
        //     if(b==l) c++;
        // }
        map<char, vector<int>>mp;
        for(int i=0; i<n; i++){
            mp[s[i]].push_back(i);
        }
        for(int i=0; i<m; i++){
            int l=-1, w=words[i].length();
            for(int j=0; j<w; j++){
                auto it=upper_bound(mp[words[i][j]].begin(), mp[words[i][j]].end(), l);
                if(it==mp[words[i][j]].end()) break;
                l=*it;
                if(j==w-1) c++;
            }
        }
        return c;
    }
};