//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    unordered_map<string, bool>m;

    bool isScramble(string s1, string s2){
        if(s1==s2) return true;
        int n=s1.length();
        if(n==1) return false;
        string t, s, key=s1+s2;
        if(m.find(key)!=m.end()) return m[key];
        vector<int>f1(26), f2(26);
        for(int i=0; i<n; i++){
            f1[s1[i]-'a']++;
            f2[s2[i]-'a']++;
        }
        if(f1!=f2) return m[key]=false;
        for(int i=0; i<n-1; i++){
            t.push_back(s1[i]);
            s.push_back(s2[i]);
            if((isScramble(t, s)==true and isScramble(s1.substr(i+1), s2.substr(i+1))==true) or (isScramble(t, s2.substr(n-i-1))==true and isScramble(s1.substr(i+1), s2.substr(0, n-i-1))==true)) return m[key]=true;
        }
        return m[key]=false;
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends