 #include <iostream>
  #include <algorithm>

        using namespace std;

        // The tree node
        struct TreeNode {
            int key;
            TreeNode *left;
            TreeNode *right;
            int height;

            // Constructor
            TreeNode(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
        };

        // Gets the height of a node
        int Get_Height(TreeNode *node) {
            // If the node is null, return 0
            if (node == nullptr) {
                return 0;
            }
            return node->height;
        }

        // Update the height of a node
        void Update_Height(TreeNode *node) {
            // If the node is null, return
            if (node != nullptr) {
                node->height = 1 + max(Get_Height(node->left), Get_Height(node->right));
            }
        }

        // Rotate a subtree rooted with node y to the left
        int Balance_Factor(TreeNode *node) {
            // If the node is null, return 0
            if (node == nullptr) {
                return 0;
            }
            return Get_Height(node->left) - Get_Height(node->right);
        }

        // Rotate a subtree rooted with node y to the left
        bool Is_AVL_Tree_Helper(TreeNode *node) {
            // If the node is null, return true
            if (node == nullptr) {
                return true;
            }
            int BF = Balance_Factor(node);
            // If the balance factor is greater than 1 or less than -1, return false
            if (BF > 1 || BF < -1) {
                return false;
            }
            // Recursively check the left and right subtrees
            return Is_AVL_Tree_Helper(node->left) && Is_AVL_Tree_Helper(node->right);
        }

        // Check if a tree is an AVL tree
        bool Is_AVL_Tree(TreeNode *root) {
            // If the root is null, return true
            if (root == nullptr) {
                return true;
            }
            // Update the height for the root node
            Update_Height(root);

            return Is_AVL_Tree_Helper(root) && 
                    Is_AVL_Tree(root->left) && 
                    Is_AVL_Tree(root->right);
        }
