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
    initList(CL);    //��ʼ������,��ʼ��һ��ͷ�ڵ�
    LinkList tail = nullptr;
    
    int count; cin >> count;
    for(int i = 1;i <= count;i ++){
        int val; cin >> val;
        insert(CL,tail,val); //ʹ��β�塣   
    }
    if(tail != nullptr) tail->next = CL;
    
    return OK;
}

void ListDelete_CL(LinkList &CL, ElemType min, ElemType max) {
    if (CL == nullptr || CL->next == nullptr) return; // �������Ϊ�ջ�ֻ��ͷ�ڵ㣬����

    LinkList current = CL->next; // �ӵ�һ���ڵ㿪ʼ
    LinkList prev = CL; // ά��ǰһ���ڵ�

    do {
        if (current->data > min && current->data < max) {
            // �����ǰ�ڵ��ֵ�ڷ�Χ�ڣ�ɾ���ýڵ�
            prev->next = current->next; // ǰһ���ڵ�ָ����һ���ڵ�
            LinkList temp = current; // ���浱ǰ�ڵ��Ա��ͷ��ڴ�
            current = current->next; // �ƶ�����һ���ڵ�
            delete temp; // �ͷ��ڴ�
        } else {
            // �����ǰ�ڵ��ֵ���ڷ�Χ�ڣ���������
            prev = current; // ����ǰһ���ڵ�
            current = current->next; // �ƶ�����һ���ڵ�
        }
    } while (current != CL->next); // ֱ���ص�ͷ�ڵ�
}
/* ����������д�� */
