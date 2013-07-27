/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    TreeLinkNode *findNext(TreeLinkNode *root) {
        for (TreeLinkNode *now = root->next ; now ; now = now->next) {
            if (now->left) {
                return now->left;
            } else if (now->right) {
                return now->right;
            }
        }
        return NULL;
    }
public:
    void connect(TreeLinkNode *root) {
        if (root) {
            if (root->left) {
                if (root->right) {
                    root->left->next = root->right;
                } else {
                    root->left->next = findNext(root);
                }
            }
            if (root->right) {
                root->right->next = findNext(root);
            }
            connect(root->right);
            connect(root->left);
        }
    }
};




class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode *prev = NULL , *next = NULL;
            for ( ; root ; root = root->next) {
                if (!next) {
                    next = root->left ? root->left : root->right;
                }
                if (root->left) {
                    if (prev) {
                        prev->next = root->left;
                    }
                    prev = root->left;
                }
                if (root->right) {
                    if (prev) {
                        prev->next = root->right;
                    }
                    prev = root->right;
                }
            }
            root = next;
        }
    }
};