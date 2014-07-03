#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

/******* code to submission*/
class LRUCache{
private:
	struct CacheNode{
		int key;
		int value;
		CacheNode(int k, int v): key(k), value(v){}
	};
	int capacity;
	list<CacheNode> CacheList;
	unordered_map<int,list<CacheNode>::iterator>CacheMap;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(CacheMap.find(key) == CacheMap.end())	return -1;

        CacheList.splice(CacheList.begin(), CacheList, CacheMap[key]);
        CacheMap[key] = CacheList.begin();
        return CacheList.begin()->value;
    }
    
    void set(int key, int value) {
		if(CacheMap.find(key) == CacheMap.end()){
			if(this->capacity == CacheList.size()){
				CacheMap.erase(CacheList.back().key);
				CacheList.pop_back();
			}
			CacheList.push_front(CacheNode(key,value));
			CacheMap[key] = CacheList.begin();
		}
		else{
			CacheMap[key]->value = value;
			CacheList.splice(CacheList.begin(), CacheList, CacheMap[key]);
			CacheMap[key] = CacheList.begin();
		}
    }
};
/*******end code */
/*******for test */
int main(){
	LRUCache lruCache(10);
	for(int i=0; i<20; i++){
		lruCache.set(i,i*5);
		cout<<lruCache.get((i+3)%10)<<endl;
	}

	return 0;
	
}
