class Solution {
public:
    string getHint(string secret, string guess) {
        string ans;
        int b=0, c=0;
        vector<int>s(10, 0);
        vector<int>g(10, 0);
        for(int i=0; i<secret.length(); i++){
            s[secret[i]-'0']++;
            g[guess[i]-'0']++;
        }
        for(int i=0; i<secret.length(); i++){
            if(secret[i]==guess[i]) {
                b++;
                s[secret[i]-'0']--;
                g[guess[i]-'0']--;
            }
        }
        string x, y;
        if(b==0) ans.push_back('0');
        else{
        while(b!=0){
            int rem=b%10;
            x.push_back(rem+'0');
            b/=10;
        }
        for(int i=x.length()-1; i>=0; i--) ans.push_back(x[i]);
        }
        ans.push_back('A');
        for(int i=0; i<10; i++){
            c+=min(s[i], g[i]);
        }
        if(c==0) ans.push_back('0');
        else{
        while(c!=0){
            int rem=c%10;
            y.push_back(rem+'0');
            c/=10;
        }
        for(int i=y.length()-1; i>=0; i--) ans.push_back(y[i]);
        }
        ans.push_back('B');
        return ans;
    }
};