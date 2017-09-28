//
//  bjut_oj_新生赛.cpp
//  ACM
//
//  Created by 王子豪 on 2017/9/28.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE *Node;
struct NODE {
    Node next;
    int value;
};

void remove_duplicates(Node head) {
    if(head == NULL || head->next == NULL) return;
    Node current = head;
    bool *arr;
    arr = (bool *)malloc(2147483647*sizeof(bool));
    Node ago = head;
    current = current->next;
    arr[ago->value] = true;
    while(current->next != NULL){
        if(arr[current->value] == true){
            ago->next = current->next;
            
        }
        else{
            arr[current->value] = true;
        }
        current = current->next;
        ago = ago->next;
    }
    // 在此处补充你的代码
}

int main() {
    Node head = NULL;
    Node *ptail = &head;
    
    int n;
    scanf("%d", &n);
    
    while (n--) {
        int d;
        scanf("%d", &d);
        
        Node node = (Node) malloc(sizeof(struct NODE));
        node->next = NULL;
        node->value = d;
        
        *ptail = node;
        ptail = &node->next;
    }
    
    remove_duplicates(head);
    
    while (head != NULL) {
        printf("%d\n", head->value);
        Node next = head->next;
        free(head);
        head = next;
    }
}

