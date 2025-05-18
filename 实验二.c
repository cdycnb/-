#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

/* 栈的数组实现 */
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// 1. 生成栈
Stack* CreateStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

// 2. 入栈
void Push(Stack* s, int item) {
    if(s->top >= MAX_SIZE-1) {
        printf("栈满\n");
        return;
    }
    s->data[++s->top] = item;
}

// 3. 出栈
int Pop(Stack* s) {
    if(s->top == -1) {
        printf("栈空\n");
        return -1;
    }
    return s->data[s->top--];
}

/* 队列的链表实现 */
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

typedef struct {
    QNode* front;
    QNode* rear;
} Queue;

// 1. 生成队列
Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 2. 入队
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

// 3. 判空
int IsEmpty(Queue* q) {
    return q->front == NULL;
}

/* 应用示例：括号匹配验证 */
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
    // 栈测试
    Stack* s = CreateStack();
    Push(s, 10);
    Push(s, 20);
    printf("出栈元素：%d\n", Pop(s)); // 20
    
    // 队列测试
    Queue* q = CreateQueue();
    Enqueue(q, 5);
    Enqueue(q, 8);
    printf("队列空？%s\n", IsEmpty(q)?"是":"否"); // 否
    
    // 应用示例测试
    char expr1[] = "([()])";
    printf("括号匹配：%s\n", BracketMatch(expr1)?"成功":"失败"); // 成功
    
    return 0;
}
