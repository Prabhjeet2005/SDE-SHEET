struct DLL{
    int storedKey;
    int storedVal;
    DLL *next;
    DLL* prev;
    DLL(int key,int val){
        this->storedKey = key;
        this->storedVal = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class LRUCache {
    unordered_map<int,DLL*>keyMap;
    int currentCapacity;
    int maxCapacity;
    DLL* head;
    DLL* tail;

    void updateTail(DLL *&tail,DLL *&currNode){
        tail->prev->next = currNode;
        currNode->prev = tail->prev;
        currNode->next = tail;
        tail->prev = currNode;
    }

    void removeNode(DLL * &tail,DLL* &nodeToDelete){
        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;
    }
public:
    LRUCache(int capacity) {
        head = new DLL(-1,-1);
        tail = new DLL(-1,-1);
        head->next = tail;
        tail->prev = head;
        this->maxCapacity = capacity;
        currentCapacity = 0;
    }
    
    int get(int key) {
        if(!keyMap.count(key)){
            return -1;
        } 
        DLL* currNode = keyMap[key];
        removeNode(tail,currNode);
        updateTail(tail,currNode);
        return currNode->storedVal;
    }
    
    void put(int key, int value) {
        if(!keyMap.count(key)){
            // Not Found
            if(currentCapacity < maxCapacity){
                // Valid cache size
                DLL* newNode = new DLL(key,value);
                currentCapacity++;
                keyMap[key] = newNode;
                updateTail(tail,newNode);
            }else{
                // Invalid cache Size
                DLL* leastRecentlyUsedNode = head->next;
                removeNode(tail,leastRecentlyUsedNode);
                keyMap.erase(leastRecentlyUsedNode->storedKey); // HERE Delete Stored key not new Key
                delete leastRecentlyUsedNode;

                DLL* newNode = new DLL(key,value);
                keyMap[key] = newNode;
                updateTail(tail,newNode);
            }
        }else{
            // Found
            DLL* currNode = keyMap[key];
            currNode->storedVal = value;
            removeNode(tail,currNode);
            updateTail(tail,currNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */