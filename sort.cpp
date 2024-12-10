#include<bits/stdc++.h>
#include "sort.h"


using namespace std;

//以下所有索引0都是存放元素的
void bubbleSort(SqList &nums){
    for(int i = nums.length;i > 1;i --){
        bool flag = false; //代表这一趟进行交换了没有
        for(int j = 1;j < i;j ++){
            if(nums.r[j].key > nums.r[j + 1].key){
                swap(nums.r[j],nums.r[j + 1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}
Node* insertSort(Node *head){
    Node *sortedHead = new Node(0,nullptr);
    Node *current = head -> next;
    while(current){
        Node *nextNode = current -> next;
        Node *sortedCurrent = sortedHead;

        while(sortedCurrent -> next && sortedCurrent -> next -> key < current -> key)
            sortedCurrent = sortedCurrent -> next;
            //sortCurrent -> next -> key >= key

        current -> next = sortedCurrent -> next;
        sortedCurrent -> next = current;

        current = nextNode;
    }
       
    delete head;
    head = sortedHead;

}

void chooseSort(SqList &nums){
    for(int i = 1;i < nums.length - 1;i ++){
        int k = i;
        for(int j = i + 1;j <= nums.length;j ++){
            if(nums.r[j].key < nums.r[k].key) k = j;
        }
        swap(nums.r[k],nums.r[i]);
    }
}

int parititon(SqList &nums,int left,int right){
    int temp = nums.r[left].key;
    while(left < right){
        while(right > left && nums.r[right].key >= temp) right --;
        nums.r[left] = nums.r[right];
        while(left < right && nums.r[left].key <= temp) left ++;
        nums.r[right] = nums.r[left]; 
    }
    nums.r[left].key = temp;
    return left;
}

void quickSort(SqList &nums,int left,int right){
    if(left >= right) return ;
    
    int mid = parititon(nums,left,right);

    // int mid = (left + right) / 2; //这里不一定在中间,这个应该是right和left相遇的位置   
    quickSort(nums,left,mid - 1);
    quickSort(nums,mid + 1,right);
}

void merge(SqList &nums,int left,int mid,int right){
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0    ;
    while(i <= mid && j <= right){
        if(nums.r[i].key <= nums.r[right].key){
            temp[k] = nums.r[i].key;
            i ++;    
        }
        else{
            temp[k] = nums.r[j].key;
            j ++;
        }
        k ++;
    }
    while(i <= mid){
         temp[k ++] = nums.r[i].key;
         i ++;
    }
    while(j <= right){
        temp[k ++] = nums.r[j].key;
        j ++;
    }
    for(k = 0;k < temp.size();k ++) nums.r[left + k].key = temp[k];
}

void mergeSort(SqList &nums,int left,int right){
    if(left >= right) return ;
    
    int mid = (left + right) / 2;
    
    mergeSort(nums,left,mid);
    mergeSort(nums,mid + 1,right);
    merge(nums,left,mid,right);
}

void initArray(SqList &nums,int option){
    //设置逆序的数字
    cout << "请输入数组长度";
    cin >> nums.length;
    switch (option)
    {
    case 1: {
        for(int i = 1;i <= nums.length;i ++){
            nums.r[i].key = nums.length - i + 1;
        }
    }
    break;
    
    default: {
        for(int i = 1;i <= nums.length;i ++){
            nums.r[i].key = std::rand() % 100000 + 1; //从1到100000内随机生成数字
        }
    }
    break;
    }

}

void arrayTraversal(SqList nums){
    for(int i = 1;i <= nums.length;i ++) cout << nums.r[i].key << " ";
}

void initLinkList(Node *head){
    cout << "请输入生成链表的长度";
    int len; cin >> len;

    head = new Node(0,nullptr);
    for(int i = 0;i < len;i ++) addNode(head);

}

void addNode(Node *head){
    int key; cin >> key;
    Node *newNode = new Node(key,nullptr);
    newNode -> next = head -> next;
    head -> next = newNode;
}

int main(void){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    SqList sqList; Node *head = nullptr;
    int option, choose;

    cout << "请选择排序方法(1:冒泡排序 2:选择排序 3:快速排序 4:插入排序 5:归并排序)" << endl;
    cin >> choose;

    cout << "选择数组初始化方式(1:逆序 2:随机数)" << endl;
    cin >> option;

    initArray(sqList,option);
    switch (choose)
    {
    case 1: bubbleSort(sqList);
        break;
    case 2: chooseSort(sqList);
        break;
    case 3: quickSort(sqList,1,sqList.length);
        break;
    case 4: insertSort(head);
        break;
    case 5: mergeSort(sqList,1,sqList.length);
        break;
    default:
        {
            cout << "error input";
            return 0;
        }
        break;
    }
    arrayTraversal(sqList);
    return 0;
}
