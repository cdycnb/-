#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

/* ջ������ʵ�� */
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// 1. ����ջ
Stack* CreateStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

// 2. ��ջ
void Push(Stack* s, int item) {
    if(s->top >= MAX_SIZE-1) {
        printf("ջ��\n");
        return;
    }
    s->data[++s->top] = item;
}

// 3. ��ջ
int Pop(Stack* s) {
    if(s->top == -1) {
        printf("ջ��\n");
        return -1;
    }
    return s->data[s->top--];
}

/* ���е�����ʵ�� */
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

typedef struct {
    QNode* front;
    QNode* rear;
} Queue;

// 1. ���ɶ���
Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 2. ���
void Enqueue(Queue* q, int item) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->next = NULL;
    
    if(q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 3. �п�
int IsEmpty(Queue* q) {
    return q->front == NULL;
}

/* Ӧ��ʾ��������ƥ����֤ */
int BracketMatch(char* expr) {
    Stack* s = CreateStack();
    char ch;
    
    for(int i=0; expr[i]; i++) {
        if(expr[i]=='(' || expr[i]=='[') {
            Push(s, expr[i]);
        } else if(expr[i]==')' || expr[i]==']') {
            if(IsEmpty(s)) return 0;
            ch = Pop(s);
            if((expr[i]==')' && ch!='(') || 
               (expr[i]==']' && ch!='[')) return 0;
        }
    }
    return IsEmpty(s);
}

int main() {
    // ջ����
    Stack* s = CreateStack();
    Push(s, 10);
    Push(s, 20);
    printf("��ջԪ�أ�%d\n", Pop(s)); // 20
    
    // ���в���
    Queue* q = CreateQueue();
    Enqueue(q, 5);
    Enqueue(q, 8);
    printf("���пգ�%s\n", IsEmpty(q)?"��":"��"); // ��
    
    // Ӧ��ʾ������
    char expr1[] = "([()])";
    printf("����ƥ�䣺%s\n", BracketMatch(expr1)?"�ɹ�":"ʧ��"); // �ɹ�
    
    return 0;
}
