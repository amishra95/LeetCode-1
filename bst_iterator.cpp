/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        
        while (root) {
            nodes.push_back(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodes.empty();
    }

    /** @return the next smallest number */
    int next() {
        
        if (!hasNext()) {
            return -1;
        }
        
        TreeNode * retNode = nodes.back();
        nodes.pop_back();
        TreeNode * n = retNode->right;
        
        while (n) {
            nodes.push_back(n);
            n = n->left;
        }
        
        return retNode->val;
    }
    
private:
    
    list<TreeNode *> nodes;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */