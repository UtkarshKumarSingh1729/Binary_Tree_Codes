class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def findLCA(root, n1, n2):
    """
    Function to find the Lowest Common Ancestor (LCA) of two nodes in a binary tree.
    """
    # Base case: if the root is None or matches one of the nodes
    if root is None or root.val == n1 or root.val == n2:
        return root

    # Recursively search in the left and right subtrees
    left_lca = findLCA(root.left, n1, n2)
    right_lca = findLCA(root.right, n1, n2)

    # If both sides return non-null, the current root is the LCA
    if left_lca and right_lca:
        return root

    # Otherwise, return the non-null result from either side
    return left_lca if left_lca else right_lca

def create_sample_tree():
    """
    Helper function to create a sample binary tree for testing.
    """
    root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left.left = TreeNode(6)
    root.left.right = TreeNode(2)
    root.right.left = TreeNode(0)
    root.right.right = TreeNode(8)
    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(4)
    return root

if __name__ == "__main__":
    # Create a sample binary tree
    root = create_sample_tree()

    # Input the two nodes for which LCA is to be found
    n1 = int(input("Enter the first node: "))
    n2 = int(input("Enter the second node: "))

    # Find the LCA
    lca = findLCA(root, n1, n2)

    if lca:
        print(f"The LCA of {n1} and {n2} is: {lca.val}")
    else:
        print("One or both nodes are not present in the tree.")
