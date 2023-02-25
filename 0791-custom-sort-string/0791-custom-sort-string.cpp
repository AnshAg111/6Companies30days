class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int>mp;
        string str, st;
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<order.length(); j++){
                if(order[j]==s[i]){
                    mp[s[i]]++;
                    break;
                }
            }
        }
        for(int i=0; i<s.length(); i++){
            if(mp[s[i]]==0) str.push_back(s[i]);
        }
        for(int i=0; i<order.length(); i++){
            for(int j=0; j<mp[order[i]]; j++) st.push_back(order[i]);
        }
        return st+str;
    }
};