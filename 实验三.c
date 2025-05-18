#include <stdio.h>
#include <stdlib.h>

/* ��������㶨�� */
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/* ���н�㶨�� */
typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

/* ���нṹ */
typedef struct {
    QueueNode *front, *rear;
} Queue;

// 1. ��������
Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 2. ��Ӳ���
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

// 3. ���Ӳ���
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

/* ��α����㷨 */
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

/* ����ʾ�������� */
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
    // �������Զ�����
    TreeNode* tree = CreateSampleTree();
    
    // ��α�������
    printf("��α��������");
    LevelOrder(tree);  // Ӧ���1 2 3
    
    // �ڴ��ͷ�
    free(tree->left);
    free(tree->right);
    free(tree);
    
    return 0;
}
