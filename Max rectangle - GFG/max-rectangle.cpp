//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxA = 0, h, w;
        stack<int> s;

        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || heights[i] <= heights[s.top()])) {
                h = heights[s.top()];   
                s.pop();
                if (s.empty())  w = i;
                else    w = i - s.top() - 1;
                maxA = max(maxA, h * w);
            }
            s.push(i);
        }
        return maxA;
    }
    int maxArea(int matrix[MAX][MAX], int r, int c) {
        int ans = INT_MIN;
        vector<int> heights(c);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 1)  heights[j]++;
                else    heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            ans = max(ans, area);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends