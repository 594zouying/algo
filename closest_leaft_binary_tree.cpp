/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root
     * @param k: an integer
     * @return: the value of the nearest leaf node to target k in the tree
     */
     // construct parents and find the val node
    TreeNode *dfs(TreeNode *rt, int k, map<TreeNode *, TreeNode *> &parents)
    {
        TreeNode *res = rt, *tmp = NULL;

        if (rt->left != NULL)
        {
            parents[rt->left] = rt;
            tmp = dfs(rt->left, k, parents);
            res = tmp->val == k ? tmp : res;
        }

        if (rt->right != NULL)
        {
            parents[rt->right] = rt;
            tmp = dfs(rt->right, k, parents);
            res = tmp->val == k ? tmp : res;
        }

        return res;
    }
    int findClosestLeaf(TreeNode *root, int k) {
        // Write your code here
        map<TreeNode *, TreeNode *> parents;
        TreeNode *pValK = dfs(root, k, parents); // find k and set parents

        queue<TreeNode *> q;
        set<TreeNode *> vis;
        q.push(pValK);
        vis.insert(pValK);
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            
            if (t->left == NULL && t->right == NULL)
            {
                return t->val;
            }
            // p1 and p2
            if (t->left != NULL && vis.find(t->left) == vis.end())
            {
                q.push(t->left);
                vis.insert(t->left);
            }

            if (t->right != NULL && vis.find(t->right) == vis.end())
            {
                q.push(t->right);
                vis.insert(t->right);
            }
            //p3
            if (parents.find(t) != parents.end() && vis.find(parents[t]) == vis.end())
            {
                q.push(parents[t]);
                vis.insert(parents[t]);
            }
        }

        return 0;
    }
};