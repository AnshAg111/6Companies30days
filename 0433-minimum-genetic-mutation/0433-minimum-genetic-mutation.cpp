class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_map<string, int> vis;
        // for(auto st: bank) mp[st]++;
        
        while(!q.empty()) {
            string curr = q.front().first;
            int changes = q.front().second;
            q.pop();
            if(curr == endGene) return changes;
            
            for(auto it: bank) {
                if(!vis[it]) {
                    int count = 0;
                    for(int i = 0; i < 8; i++) if(curr[i] != it[i]) count++;
                    if(count == 1) {
                        q.push({it, changes + 1});
                        vis[it] = 1;
                    }
                }
                
            }            
        }
        
        return -1;
    }
};