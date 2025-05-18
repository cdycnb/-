#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; // ����Ԫ������

/* �����㶨�� */
typedef struct ListNode {
    ElementType data;
    struct ListNode *next;
} Node, *List;

/* 1. �����ձ� */
List CreateList() {
    List L = (List)malloc(sizeof(Node));
    L->next = NULL;
    return L;
}

/* 2. �жϱ�� */
int IsEmpty(List L) {
    return L->next == NULL;
}

/* 3. ��ȡ��i��Ԫ�� */
ElementType GetElem(List L, int i) {
    Node *p = L->next;
    int cnt = 1;
    
    while(p && cnt < i) {
        p = p->next;
        cnt++;
    }
    if(!p || cnt > i) {
        printf("λ����Ч\n");
        exit(1);
    }
    return p->data;
}

/* 4. ɾ����i��Ԫ�� */
void Delete(List L, int i) {
    Node *p = L;
    int cnt = 0;
    
    while(p->next && cnt < i-1) {
        p = p->next;
        cnt++;
    }
    if(!(p->next) || cnt > i-1) {
        printf("ɾ��λ�ô���\n");
        return;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
}

/* 5. ������Ԫ�ص���iλ */
void Insert(List L, ElementType x, int i) {
    Node *p = L;
    int cnt = 0;
    
    while(p && cnt < i-1) {
        p = p->next;
        cnt++;
    }
    if(!p || cnt > i-1) {
        printf("����λ�ô���\n");
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}

/* ��ӡ���� */
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
    
    // �������
    Insert(L, 10, 1);
    Insert(L, 20, 2);
    Insert(L, 30, 3);
    printf("��������");
    PrintList(L); // Ӧ���10 20 30
    
    // ɾ������
    Delete(L, 2);
    printf("ɾ����");
    PrintList(L); // Ӧ���10 30
    
    // ��ȡԪ�ز���
    printf("��2��Ԫ�أ�%d\n", GetElem(L, 2)); // Ӧ���30
    
    // �пղ���
    printf("��գ�%s\n", IsEmpty(L) ? "��" : "��");
    
    return 0;
}