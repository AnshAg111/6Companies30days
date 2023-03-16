//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
int postorderIndex;
unordered_map<int, int> inorderIndexUmp;
//Function to return a tree created from postorder and inoreder traversals.
Node* buildTreeHelper(int post[], int left, int right) {
        if (left > right)
            return NULL;
        int rootValue = post[postorderIndex--];
        Node* root = new Node(rootValue);
        int inorderPivotIndex = inorderIndexUmp[rootValue];
        root -> right = buildTreeHelper(post, inorderPivotIndex + 1, right);
        root -> left = buildTreeHelper(post, left, inorderPivotIndex - 1);
        return root;
}
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int n=inorder.size();
//         unordered_map<int, int>m;
//         for(int i=0; i<n; i++){
//             m[inorder[i]]=i;
//         }
//         return treebuilder(postorder, 0, n-1, m, 0, n-1);
//     }

Node *buildTree(int in[], int post[], int n) {
    postorderIndex = n - 1;
        for (int i = 0; i < n; i++) {
            inorderIndexUmp[in[i]] = i;
        }
        return buildTreeHelper(post, 0, n - 1);
}
