# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root, arr): 
        # L - N - R
        if root == None: 
            return 
        
        self.solve(root.left, arr)
        arr.append(root.val)
        self.solve(root.right, arr)

    def inorderTraversal(self, root: TreeNode | None) -> list[int]:
        arr = []
        self.solve(root, arr)
        return arr


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna