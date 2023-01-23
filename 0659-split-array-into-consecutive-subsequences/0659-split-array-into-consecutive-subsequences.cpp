class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int>m, v;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        for(int i=0; i<n; i++){
            if(m[nums[i]]<=0) continue;
            else if(v[nums[i]]>0){
                m[nums[i]]--;
                v[nums[i]]--;
                v[nums[i]+1]++;
            }
            else if(m[nums[i]]>0 and m[nums[i]+1]>0 and m[nums[i]+2]>0){
                m[nums[i]]--;
                m[nums[i]+1]--;
                m[nums[i]+2]--;
                v[nums[i]+3]++;
            }
            else return false;
        }
        return true;
    }
};   