/* 
Using queue to traverse all node (BFS)
*/
/*
Runtime: 3 ms
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_QUEUE_SIZE	1000
struct Queue{
	struct TreeNode *array[MAX_QUEUE_SIZE];
	int front;
	int rear;
};

void queue_init(struct Queue *q){
	q->front = 0;
	q->rear = 0;
}

int queue_empty(struct Queue *q){
	if(q->front == q->rear)	return 1;
	return 0;
}

int queue_full(struct Queue *q){
	if(q->front == ((q->rear+1)%MAX_QUEUE_SIZE) )	return 1;
	return 0;
}

int enqueue(struct Queue *q, struct TreeNode *data){
	if(queue_full(q))	return -1;
	q->array[q->rear] = data;
	q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
	return 0;
}

int dequeue(struct Queue *q, struct TreeNode **output){
	if(queue_empty(q))	return -1;
	*output = q->array[q->front];
	q->front = (q->front+1)%MAX_QUEUE_SIZE;
	return 0;
}

struct TreeNode* invertTree(struct TreeNode* root) {
    if(root==NULL)  return NULL;
    struct TreeNode *reverse_root, *temp;
    struct Queue q;
    queue_init(&q);
    enqueue(&q,root);
    while(!queue_empty(&q)){
        dequeue(&q, &reverse_root);
        temp = reverse_root->left;
        reverse_root->left = reverse_root->right;
        reverse_root->right = temp;
        if(reverse_root->left!=NULL)    enqueue(&q, reverse_root->left);
        if(reverse_root->right!=NULL)   enqueue(&q, reverse_root->right);
    }
    
    return root;
}
