#include<iostream>
using namespace std;

#define m 16 
#define NULLKEY 0 //单元为空的标记

struct HashTable{
   int  key;
};

void CreateHash(HashTable HT[],int n);
int SearchHash(HashTable HT[],int key);

int main()
{    int value,key;
    int result;
    int i,j,n;
    HashTable HT[m];
    for(i=0;i<m;i++)
     HT[i].key=0;
    cin >> n;
    if(n>m) return 0;
    CreateHash(HT,n);
    cin >> key;
    result=SearchHash(HT,key);
    if(result!=-1)
        cout << "search success，The key is located in "<< result+1;
    else
        cout << "search failed";
    return 0;
}

int hashFunc(int key){
    return key % 13;
}

void CreateHash(HashTable HT[],int n){
    for(int i = 1;i <= n;i ++){
        int key; cin >> key;
        int index = hashFunc(key);
        while(HT[index].key && index < n) index ++;
        HT[index].key = key;
    }
}

int SearchHash(HashTable HT[],int key){

    int index = hashFunc(key);
    while(HT[index].key && HT[index].key != key) index++;
    return HT[index].key == key ? index : -1;
}

/* 请在这里填写答案 */