#include <stdio.h>
#include <stdlib.h>

/* 二叉树结点定义 */
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/* 队列结点定义 */
typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

/* 队列结构 */
typedef struct {
    QueueNode *front, *rear;
} Queue;

// 1. 创建队列
Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 2. 入队操作
void Enqueue(Queue* q, TreeNode* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    
    if(q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 3. 出队操作
TreeNode* Dequeue(Queue* q) {
    if(q->front == NULL) return NULL;
    
    QueueNode* temp = q->front;
    TreeNode* node = temp->treeNode;
    q->front = q->front->next;
    
    if(q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    return node;
}

/* 层次遍历算法 */
void LevelOrder(TreeNode* root) {
    if(root == NULL) return;
    
    Queue* q = CreateQueue();
    Enqueue(q, root);
    
    while(q->front != NULL) {
        TreeNode* current = Dequeue(q);
        printf("%d ", current->data);
        
        if(current->left != NULL)
            Enqueue(q, current->left);
        if(current->right != NULL)
            Enqueue(q, current->right);
    }
    free(q);
}

/* 创建示例二叉树 */
TreeNode* CreateSampleTree() {
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = 1;
    
    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->data = 2;
    root->left->left = root->left->right = NULL;
    
    root->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->data = 3;
    root->right->left = root->right->right = NULL;
    
    return root;
}

int main() {
    // 创建测试二叉树
    TreeNode* tree = CreateSampleTree();
    
    // 层次遍历测试
    printf("层次遍历结果：");
    LevelOrder(tree);  // 应输出1 2 3
    
    // 内存释放
    free(tree->left);
    free(tree->right);
    free(tree);
    
    return 0;
}
