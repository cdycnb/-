/*
 * 线性表实现 - 顺序存储结构
 * 编译指令: gcc -Wall -Wextra -std=c99 -o lab1 实验一.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];  // 数据存储数组
    int length;          // 当前线性表长度
} SeqList;

/* 初始化线性表 */
void init(SeqList *list) {
    list->length = 0;
}

/* 判断线性表是否为空 */
int is_empty(const SeqList list) {
    return list.length == 0;
}

/* 获取指定位置的元素 */
int get_element(const SeqList list, int index) {
    if(index < 0 || index >= list.length) {
        errno = EINVAL;
        return -1;
    }
    return list.data[index];
}
/* 向线性表插入元素 */
int insert(SeqList *list, int value) {
    if(list->length >= MAX_SIZE) {
        errno = ENOMEM;
        return -1;
    }
    list->data[list->length] = value;
    list->length++;
    return 0;
}

/* 从线性表删除元素 */
int delete(SeqList *list, int index) {
    if(index < 0 || index >= list->length) {
        errno = EINVAL;
        return -1;
    }
    for(int i = index; i < list->length - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->length--;
    return 0;
}
int main() {
    SeqList list;
    init(&list);
    
    // 测试插入
    for(int i = 1; i <= 5; i++) {
        if(insert(&list, i) == -1) {
            perror("插入失败");
            exit(EXIT_FAILURE);
        }
    }
    
    // 测试获取元素
    int val = get_element(list, 2);
    if(val == -1) {
        perror("获取元素失败");
    } else {
        printf("第2个元素: %d\n", val);
    }
    
    // 测试删除
    if(delete(&list, 2) == -1) {
        perror("删除失败");
    }
    
    val = get_element(list, 2);
    if(val == -1) {
        perror("获取元素失败");
    } else {
        printf("删除后第2个元素: %d\n", val);
    }
    
    return EXIT_SUCCESS;
}