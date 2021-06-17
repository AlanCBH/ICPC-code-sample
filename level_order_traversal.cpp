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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> parent_nodes;
        queue<TreeNode*> temp;
        vector<vector<int>>* res = new vector<vector<int>>;
        if (root == NULL) {
            return *res;   
        }
        int depth = 0;
        parent_nodes.push(root);
        vector<int> *temp_vec = new vector<int>;
        while (!parent_nodes.empty()) {
            temp_vec->push_back(parent_nodes.front()->val);
            if (parent_nodes.front()->left != NULL) {
                temp.push(parent_nodes.front()->left);
            }
            if (parent_nodes.front()->right != NULL) {
                temp.push(parent_nodes.front()->right);
            }
            parent_nodes.pop();
            if (parent_nodes.empty()) {
                res->push_back(*temp_vec);
                while (!temp.empty()) {
                    parent_nodes.push(temp.front());
                    temp.pop();
                }
                temp_vec = new vector<int>;
            }
        }
        return *res;
        
        
    }
};
