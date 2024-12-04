#include<bits/stdc++.h>

using namespace std;

//以下所有索引0都是存放元素的
void bubbleSort(vector<int> &nums){
    for(int i = nums.size() - 1;i > 0;i --){
        bool flag = false; //代表这一趟进行交换了没有
        for(int j = 0;j < i;j ++){
            if(nums[j] > nums[j + 1]){
                swap(nums[j],nums[j + 1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}

void insertSort(vector<int> nums){
    //类似于手动整理扑克牌
    for(int i = 1;i < nums.size();i ++){
        int temp = nums[i], j = i - 1;
        while(nums[j] > temp && j >= 0){
            nums[j + 1] = nums[j];
            j --;
        }
        nums[j + 1] = temp; 
    }
}

void chooseSort(vector<int> nums){
    for(int i = 0;i < nums.size() - 1;i ++){
        int k = i;
        for(int j = i + 1;j < nums.size();j ++){
            if(nums[j] < nums[k]) k = j;
        }
        swap(nums[k],nums[i]);
    }
}

int partition(vector<int> &nums,int left,int right){
    int temp = nums[left];
    while(left < right){
        while(right > left && nums[right] >= temp) right --;
        while(left < right && nums[left] <= temp) left ++;
        swap(nums[left],nums[right]);
    }
    nums[left] = temp;
    return left;
}

void quickSort(vector<int> &nums,int left,int right){
    if(left >= right) return ;
    
    int mid = partition(nums,left,right);

    // int mid = (left + right) / 2; //这里不一定在中间,这个应该是right和left相遇的位置   
    quickSort(nums,left,mid - 1);
    quickSort(nums,mid + 1,right);
}

void merge(vector<int> &nums,int left,int mid,int right){
    vector<int> temp(left - right + 1);
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right){
        if(nums[i] <= nums[right]){
            temp[k] = nums[i];
            i ++;    
        }
        else{
            temp[k] = nums[j];
            j ++;
        }
        k ++;
    }
    while(i <= mid) temp[k ++] = nums[i ++];
    while(j <= right) temp[k ++] = nums[j ++];
    for(k = 0;k < temp.size();k ++) nums[left + k] = temp[k];
}

void mergeSort(vector<int> &nums,int left,int right){
    if(left >= right) return ;
    
    int mid = (left + right) / 2;
    
    mergeSort(nums,left,mid);
    mergeSort(nums,right,mid + 1);
    merge(nums,left,mid,right);
}

int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

int parent(int i){
    return (i - 1) / 2;
}

int peek(vector<int> maxHeap){
    return maxHeap[0];
}

//入堆操作,将元素放到堆底,之后不断向上
void push(vector<int> &nums,int val){
    nums.push_back(val);
    siftUp(nums.size() - 1,nums);
}
void siftUp(int i,vector<int> &nums){
    while(true){
        int p = parent(i);
        if(p < 0 || nums[p] >= nums[i]) break;
        swap(nums[i],nums[p]);
        i = p;
    }
}

void pop(vector<int> nums){
    if(nums.size() == 0) throw out_of_range("堆为空");
    swap(nums[0],nums[nums.size() - 1]);
    siftDown(0,nums);
}

void siftDown(int i,vector<int> nums){
    while(true){
        int ma = i;
        int r = right(i);
        int l = left(i);
        
        if(l < nums.size() && nums[l] > nums[ma]) ma = l;
        if(l < nums.size() && nums[r] > nums[ma]) ma = r; 

        if(ma == i) break;
        swap(nums[i],nums[ma]);
        i = ma;
    }

}

