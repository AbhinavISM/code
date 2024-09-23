// This function returns distance of x from
// root. This function assumes that x exists
// in BST and BST is not NULL.
int distanceFromRoot(struct BinaryTreeNode* root, int x)
{
    if (root->data == x)
        return 0;
    else if (root->data > x)
        return 1 + distanceFromRoot(root->left, x);
    return 1 + distanceFromRoot(root->right, x);
}
 
// Returns minimum distance between a and b.
// This function assumes that a and b exist
// in BST.
int distanceBetween2(struct BinaryTreeNode* root, int a, int b)
{
    if (!root)
        return 0;
 
    // Both datas lie in left
    if (root->data > a && root->data > b)
        return distanceBetween2(root->left, a, b);
 
    // Both datas lie in right
    if (root->data < a && root->data < b) // same path
        return distanceBetween2(root->right, a, b);
 
    // Lie in opposite directions (Root is
    // LCA of two BinaryTreeNodes)
    if (root->data >= a && root->data <= b)
        return distanceFromRoot(root, a) + 
               distanceFromRoot(root, b);
}
 
// This function make sure that a is smaller
// than b before making a call to findDistWrapper()
int findDistWrapper(BinaryTreeNode *root, int a, int b)
{
   if (a > b)
     swap(a, b);
   return distanceBetween2(root, a, b);   
}