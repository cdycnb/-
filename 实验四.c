#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// 创建新节点
BSTNode* new_node(int data) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// 插入操作（递归实现）
BSTNode* insert(BSTNode* root, int key) {
    if(!root) return new_node(key);
    if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);
    return root;
}

// 查找操作（迭代实现）
char* search(BSTNode* root, int key) {
    while(root) {
        if(key == root->data) return "find";
        root = (key < root->data) ? root->left : root->right;
    }
    return "not find";
}

// 中序递增遍历
void in_order(BSTNode* root) {
    if(root) {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}

// 反向中序递减遍历
void reverse_in_order(BSTNode* root) {
    if(root) {
        reverse_in_order(root->right);
        printf("%d ", root->data);
        reverse_in_order(root->left);
    }
}

// 主程序逻辑
void process_test_case() {
    int n, key;
    scanf("%d", &n);
    
    BSTNode* root = NULL;
    for(int i=0; i<n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    printf("递增序列："); 
    in_order(root); 
    printf("\n");
    
    scanf("%d", &key);
    printf("%s\n", search(root, key));
    
    scanf("%d", &key);
    if(search(root, key)[0] == 'n') 
        root = insert(root, key);
        
    printf("递减序列：");
    reverse_in_order(root);
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        process_test_case();
    }
    return 0;
}
