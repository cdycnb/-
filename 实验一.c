#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; // 定义元素类型

/* 链表结点定义 */
typedef struct ListNode {
    ElementType data;
    struct ListNode *next;
} Node, *List;

/* 1. 创建空表 */
List CreateList() {
    List L = (List)malloc(sizeof(Node));
    L->next = NULL;
    return L;
}

/* 2. 判断表空 */
int IsEmpty(List L) {
    return L->next == NULL;
}

/* 3. 获取第i个元素 */
ElementType GetElem(List L, int i) {
    Node *p = L->next;
    int cnt = 1;
    
    while(p && cnt < i) {
        p = p->next;
        cnt++;
    }
    if(!p || cnt > i) {
        printf("位置无效\n");
        exit(1);
    }
    return p->data;
}

/* 4. 删除第i个元素 */
void Delete(List L, int i) {
    Node *p = L;
    int cnt = 0;
    
    while(p->next && cnt < i-1) {
        p = p->next;
        cnt++;
    }
    if(!(p->next) || cnt > i-1) {
        printf("删除位置错误\n");
        return;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
}

/* 5. 插入新元素到第i位 */
void Insert(List L, ElementType x, int i) {
    Node *p = L;
    int cnt = 0;
    
    while(p && cnt < i-1) {
        p = p->next;
        cnt++;
    }
    if(!p || cnt > i-1) {
        printf("插入位置错误\n");
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}

/* 打印链表 */
void PrintList(List L) {
    Node *p = L->next;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    List L = CreateList();
    
    // 插入测试
    Insert(L, 10, 1);
    Insert(L, 20, 2);
    Insert(L, 30, 3);
    printf("插入结果：");
    PrintList(L); // 应输出10 20 30
    
    // 删除测试
    Delete(L, 2);
    printf("删除后：");
    PrintList(L); // 应输出10 30
    
    // 获取元素测试
    printf("第2个元素：%d\n", GetElem(L, 2)); // 应输出30
    
    // 判空测试
    printf("表空？%s\n", IsEmpty(L) ? "是" : "否");
    
    return 0;
}