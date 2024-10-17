void flatten(struct TreeNode* root) {
    if (root == NULL) {
        return; 
    }
    flatten(root->left);
    flatten(root->right);
    struct TreeNode* right_tree=root->right;
    root->right = root->left;
    root->left = NULL; 
    struct TreeNode* current=root;
    while (current->right != NULL) {
        current=current->right;
    }
    current->right = right_tree;
}