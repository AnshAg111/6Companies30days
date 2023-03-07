class Solution {
public:
int calculate(vector<vector<int>>&students, vector<vector<int>>&mentors, int sidx, int midx){
    int score=0;
    for(int i=0; i<students[sidx].size(); i++){
        if(students[sidx][i]==mentors[midx][i]) score++;
    }
    return score;
}
void solve(vector<vector<int>>&students, vector<vector<int>>&mentors, vector<bool>&taken, int idx, int score, int &ans){
    int n=students.size(), comp_sc=0;
    if(idx>=n){
        ans=max(ans, score);
        return;
    }
    for(int i=0; i<n; i++){
        if(taken[i]==false){
            taken[i]=true;
            comp_sc=calculate(students, mentors, idx, i);
            solve(students, mentors, taken, idx+1, score+comp_sc, ans);
            taken[i]=false;
        }
    }
}
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=students.size(), ans=0, idx=0, score=0;
        vector<bool>taken(n, false);
        solve(students, mentors, taken, idx, score, ans);
        return ans;
    }
};
