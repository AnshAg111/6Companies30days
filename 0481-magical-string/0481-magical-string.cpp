class Solution {
public:
    int magicalString(int n) {
        string s="122";
        int i=2;
        while(s.length()<n){
            int repeat=s[i]-'0'; //no. of times to repeat the last character
            char nextch=s.back()^3;
            s+=string(repeat, nextch);
            i++;
        }
        return count(s.begin(), s.begin()+n, '1');
    }
};