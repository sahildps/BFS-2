/*
TC : O (N)
SC : O (H)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int x_lvl = -1, y_lvl = -1;
    TreeNode *x_parent = new TreeNode();
    TreeNode *y_parent = new TreeNode();

    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root == nullptr)
        {
            return false;
        }

        dfs(root, x, y, -1);
        // return true if elements found at same level and parent node is different
        return x_lvl == y_lvl && x_parent != y_parent;
    }

private:
    void dfs(TreeNode *root, int x, int y, int level)
    {
        // base
        // if node is null or one of the element is found at any level
        // to avoid additional traversal
        if (root == nullptr || (x_lvl != -1 && y_lvl != -1))
        {
            return;
        }

        // update the level if the element is found
        if (root->val == x)
        {
            x_lvl = level;
        }
        if (root->val == y)
        {
            y_lvl = level;
        }

        // update parent if the element is found
        if (root->left)
        {
            if (root->left->val == x)
            {
                x_parent = root;
            }
            if (root->left->val == y)
            {
                y_parent = root;
            }
        }

        if (root->right)
        {
            if (root->right->val == x)
            {
                x_parent = root;
            }
            if (root->right->val == y)
            {
                y_parent = root;
            }
        }

        // check for left and right child
        dfs(root->left, x, y, level + 1);
        dfs(root->right, x, y, level + 1);
    }
};