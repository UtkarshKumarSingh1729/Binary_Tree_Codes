#include <iostream>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the LCA of two nodes in a binary tree
TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    // Base case: if the root is null or matches one of the nodes
    if (root == NULL || root->val == n1 || root->val == n2) {
        return root;
    }

    // Recursively search in the left and right subtrees
    TreeNode* leftLCA = findLCA(root->left, n1, n2);
    TreeNode* rightLCA = findLCA(root->right, n1, n2);

    // If both sides return non-null, the current root is the LCA
    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    // Otherwise, return the non-null result from either side
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Helper function to create a binary tree for testing
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    return root;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = createSampleTree();

    // Input the two nodes for which LCA is to be found
    int n1, n2;
    cout << "Enter the first node: ";
    cin >> n1;
    cout << "Enter the second node: ";
    cin >> n2;

    // Find the LCA
    TreeNode* lca = findLCA(root, n1, n2);

    if (lca != NULL) {
        cout << "The LCA of " << n1 << " and " << n2 << " is: " << lca->val << endl;
    } else {
        cout << "One or both nodes are not present in the tree." << endl;
    }

    return 0;
}
