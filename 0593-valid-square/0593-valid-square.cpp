class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int a, b, c, d, e, f;
        a=(p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
        b=(p1[0]-p3[0])*(p1[0]-p3[0])+(p1[1]-p3[1])*(p1[1]-p3[1]);
        c=(p1[0]-p4[0])*(p1[0]-p4[0])+(p1[1]-p4[1])*(p1[1]-p4[1]);
        d=(p3[0]-p2[0])*(p3[0]-p2[0])+(p3[1]-p2[1])*(p3[1]-p2[1]);
        e=(p4[0]-p2[0])*(p4[0]-p2[0])+(p4[1]-p2[1])*(p4[1]-p2[1]);
        f=(p3[0]-p4[0])*(p3[0]-p4[0])+(p3[1]-p4[1])*(p3[1]-p4[1]);
        int m=max({a, b, c, d, e,f});
        int s=min({a,b,c,d,e,f});
        map<int, int>mp;
        mp[a]++;
        mp[b]++;
        mp[c]++;
        mp[d]++;
        mp[e]++;
        mp[f]++;
        if(mp[m]!=2 or mp[s]!=4) return false;
        return true;
    }
};