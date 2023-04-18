//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends



string merge (string word1, string word2)
{
    int i=0, j=0, n1=word1.length(), n2=word2.length();
        string s;
        while(i<n1 and j<n2){
            s.push_back(word1[i]);
            i++;
            s.push_back(word2[j]);
            j++;
        }
        while(i<n1) {
            s.push_back(word1[i]);
            i++;
        }
        while(j<n2){
            s.push_back(word2[j]);
            j++;
        }
        return  s;
}