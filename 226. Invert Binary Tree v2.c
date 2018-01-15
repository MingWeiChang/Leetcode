/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct Queue{
    struct TreeNode *top;
    struct TreeNode *end;
}queue;
bool empty(struct queue q){
    if(q.end==NULL)   return true;
    return false;
}
void enqueue(struct queue q, struct TreeNode *node){
    if(q.top == NULL && q.end == NULL){
        q.top = q.end = node;
        return;
    }
    
}
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root==NULL)  return NULL;
    struct queue q;
    struct TreeNode *reverse_root, *temp;
    enqueue(q,root);
    while(!empty(q)){
        reverse_root = dequeue(q);
        temp = reverse_root->left;
        reverse_root->left = reverse_root->right;
        reverse_root->right = temp;
        if(reverse_root->left!=NULL)    enqueue(q, reverse_root->left);
        if(reverse_root->right!=NULL)   enqueue(q, reverse_root->right);
    }
    
    return root;
}
