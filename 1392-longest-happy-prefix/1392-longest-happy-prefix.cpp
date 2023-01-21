class Solution {
public:
    string longestPrefix(string s) {
        // // string ans="", st, str="";
        // int n=s.length();
        // vector<string>u;
        // for(int i=0; i<n-1; i++){
        //     st.push_back(s[i]);
        //     u.push_back(st);
        // }
        // reverse(u.begin(), u.end());
        // for(int i=n-1; i>0; i--){
        //     string j;
        //     j.push_back(s[i]);
        //     strcat(j, str);
        //     str=j;
        //     if(str==u[i-1]) ans = str;
        // }
        string ans;
        int n=s.size(), j=0, i=1;
	    vector<int>v(n, 0);
	    while(i<n){
	        if(s[i]==s[j]){
	            v[i]=j+1;
	            i++;
	            j++;
	        }
	        else{
	            if(j==0) i++;
	            else j=v[j-1];
	        }
	    }
        for(int k=0; k<v.back(); k++) ans.push_back(s[k]);
        return ans;
    }
};