// class Solution {
// public:
//     static bool comp(pair<string, int>a, pair<string, int>b){
//         string x=a.first, y=b.first;
//         return x[x.length()-1]<y[y.length()-1];
//     }
//     vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
//         vector<int>ans;
//         int n=queries.size(), m=nums[0].length();
//         for(int i=0; i<n; i++){
//             vector<pair<string, int>>temp;
//             // unordered_map<string, int>mp;
//             int le=nums.size();
//             for(int j=0; j<le; j++){
//                 string s;
//                 for(int k=m-queries[i][1]; k<m; k++) s.push_back(nums[j][k]);
//                 temp.push_back(make_pair(s, j));
//             }
//             int l=temp[0].first.length();
//             for(int j=l-1; j>=0; j--){
//                 sort(temp.begin(), temp.end(), comp);
//                 for(int k=0; k<le; k++) temp[k].first.pop_back();
//             }
//             ans.push_back(temp[queries[i][0]-1].second);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto q: queries){
            int trim= q[1];
            int k= q[0];
            priority_queue<pair<string,int>> pq;
            for (int i=0; i<nums.size(); i++){
                string  val= nums[i];
                if (trim< nums[i].size()) val= nums[i].substr(nums[i].size()-trim,trim);

                pair<string,int> val1= {val,i};
                if (pq.size()<k){
                    pq.push(val1);
                }
                else{
                    if (val1 < pq.top()){
                        pq.pop();
                        pq.push(val1);
                    }
                }
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};