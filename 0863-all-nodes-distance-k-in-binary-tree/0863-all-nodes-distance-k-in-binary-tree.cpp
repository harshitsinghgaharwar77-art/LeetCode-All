/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> parentMap;
    void buildParentMap(TreeNode* node, TreeNode* parent){
        if(!node) return;
        parentMap[node] = parent;
        buildParentMap(node -> left, node);
        buildParentMap(node -> right, node);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k <= 0) return {target -> val};
        // step-1 : craete mapping
        buildParentMap(root, nullptr);
        // step2: bfs outward from target node
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visisted;
        q.push(target);
        visisted.insert(target);
        int currDist = 0;
        while (!q.empty())
        {
            if(currDist == k){
                vector<int> res;
                while(!q.empty()){
                    res.push_back(q.front() -> val);
                    q.pop();
                }
                return res;
            }
            int size = q.size();
            // process all nodes at current level
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();

                // left child
                if(curr -> left && visisted.find(curr -> left) == visisted.end()){
                    visisted.insert(curr -> left);
                    q.push(curr -> left);
                }
                // right child
                if(curr -> right && visisted.find(curr -> right) == visisted.end()){
                    visisted.insert(curr -> right);
                    q.push(curr -> right);
                }
                // parent
                if(parentMap[curr] && visisted.find(parentMap[curr]) == visisted.end()){
                    visisted.insert(parentMap[curr]);
                    q.push(parentMap[curr]);
                }
            }
            currDist++;
        }
        return {};
    }
};