#include<bits/stdc++.h>

using namespace std;

Status initList(LinkList &CL){
    CL->next = CL;
    CL->data = -1;
    return OK;
}

Status insert(LinkList &CL,LinkList &tail,ElemType val){
     LinkList newNode = new LNode();
    newNode->data = val;
    if(tail == nullptr){
        CL->next = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    return OK;
}

Status ListCreate_CL(LinkList &CL) {
    initList(CL);    //初始化链表,初始化一个头节点
    LinkList tail = nullptr;
    
    int count; cin >> count;
    for(int i = 1;i <= count;i ++){
        int val; cin >> val;
        insert(CL,tail,val); //使用尾插。   
    }
    if(tail != nullptr) tail->next = CL;
    
    return OK;
}

void ListDelete_CL(LinkList &CL, ElemType min, ElemType max) {
    if (CL == nullptr || CL->next == nullptr) return; // 如果链表为空或只有头节点，返回

    LinkList current = CL->next; // 从第一个节点开始
    LinkList prev = CL; // 维护前一个节点

    do {
        if (current->data > min && current->data < max) {
            // 如果当前节点的值在范围内，删除该节点
            prev->next = current->next; // 前一个节点指向下一个节点
            LinkList temp = current; // 保存当前节点以便释放内存
            current = current->next; // 移动到下一个节点
            delete temp; // 释放内存
        } else {
            // 如果当前节点的值不在范围内，继续遍历
            prev = current; // 更新前一个节点
            current = current->next; // 移动到下一个节点
        }
    } while (current != CL->next); // 直到回到头节点
}
/* 请在这里填写答案 */
