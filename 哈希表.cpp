#include<bits/stdc++.h>

using namespace std;

//ʵ��һ���򵥵Ĺ�ϣ��

struct Pair{
	public :
		int key;
		string val;
		Pair(int key,string val){
			this->key = key;
			this->val = val;
		}
};

class ArrayHashMap{
	private :
		vector<Pair *>buckets;
	public :
		ArrayHashMap(){
			buckets = vector<Pair *>(100);
		}
		~ArrayHashMap(){
			for(auto bucket : buckets){
				delete bucket;//ע�⣺�˴�ɾ������ÿһ��pairָ�룬��ָ����������ָ�뻹û��ɾ����
			}
			buckets.clear();
		}
		int hashFunc(int key){
			return key % 100;
		}
		string get(int key){
			int index = hashFunc(key);
			Pair *pair = buckets[index];
			if(pair == nullptr)	return "";
			return pair->val;
		}
		void put(Pair pair){
			int index = hashFunc(pair.key);
			string value = pair.val;
			buckets[index] = new Pair(index,value);
		}
		void remove(int key){
			int index = hashFunc(key);
			Pair *temp = buckets[index];
			buckets[index] = nullptr;
			delete temp;
		}
		vector<Pair *> pairSet(){
			vector<Pair *>pairSet;
			for(auto bucket : buckets){
				if(bucket != nullptr){
					pairSet.push_back(bucket);
				}
			}
			return pairSet;
		}
		vector<int> keySet(){
			vector<int> keySet;
			for(auto bucket : buckets){
				if(bucket != nullptr){
					keySet.push_back(bucket->key);
				}
			}
			return keySet;
		}
		
		
};

class HashMapChaining{
	private:
		int size;
		int capacity;
		double loadThres;//�������ݵ���ֵ
		int extendRatio;//���ݱ���
		vector<vector<Pair *>> buckets;//ÿһ��Ԫ�ض���һ�����Pair *������
	
	public:
		HashMapChaining() : size(0),capacity(4),loadThres(2.0/3.0),extendRatio(2){
			buckets.resize(capacity);
		}
		~HashMapChaining(){
			for(auto &bucket : buckets){
				for(auto pair : bucket){
					delete pair;
				}
			}
		}
		int hashFunc(int key){
			return key % capacity;
		}
		void put(int key,string value){
			Pair pair(key,value);
			int index = hashFunc(key);
			vector<Pair *> bucket = buckets[index];
			for(auto pair : bucket){
				if(pair->key == key){
					pair->val = value;
					return ;
				}
			}
			bucket.push_back(&pair);
			size++;
		}
		void remove(int key){
			int index = hashFunc(key);
			vector<Pair *> bucket = buckets[index];
			for(int i = 0;i < (int)bucket.size();i ++){
				if(bucket[i]->key == key){
					Pair *temp = bucket[i];
					bucket.erase(bucket.begin() + i);
					delete temp;
					size--;
					return ;
				}
			}
		}
		void extend(){
			vector<vector<Pair *>> bucketsTmp = buckets;
			capacity *= extendRatio;
			buckets.resize(capacity);
			size = 0;
			for(auto bucket : buckets){
				for(auto pair : bucket){
					//�·������ڴ��ַ����Ҫɾ��pair
					put(pair->key,pair->val);
					delete pair;
				}
			}
		}
		
};	

int main(void){
	
	
	
	return 0;
}
