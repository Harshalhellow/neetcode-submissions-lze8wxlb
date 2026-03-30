class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};


class LRUCache {
public:
    Node* head;
    Node* tail;
    int currcapacity = 0;
    int cap = 0;
    unordered_map<int,Node*> hashmap; 
    LRUCache(int capacity) {
            head = new Node(0, 0);  // dummy
            tail = new Node(0, 0);  // dummy
            cap = capacity;
            head->next = tail;
            tail->prev = head;
    }
    
    int get(int key) {
       if(hashmap.contains(key)){
        Node* temp = hashmap[key]->prev;
        Node* temp2 = hashmap[key]->next;
        temp->next = temp2;
        temp2->prev =  temp;
        temp = head->next;
        head->next = hashmap[key];
        hashmap[key]->next = temp;
        temp->prev = hashmap[key];
        hashmap[key]->prev = head;
        return hashmap[key]->value;
       }
       else return -1;

    }

    void put(int key, int value) {
        if(!hashmap.contains(key)){
            currcapacity++;
            if(currcapacity>cap){
                hashmap[key] = new Node(key,value);
                Node*temp =  hashmap[key];
                temp = head->next;
                head->next = hashmap[key];
                hashmap[key]->next = temp;
                temp->prev = hashmap[key];
                hashmap[key]->prev = head;
                temp = tail->prev;
                Node*deleting = temp;
                temp = temp->prev;
                temp->next = tail;
                tail->prev = temp;
                hashmap.erase(deleting->key);
                delete deleting;
                currcapacity--;

            }
            else{
                hashmap[key] = new Node(key,value);
                Node*temp =  hashmap[key];
                temp = head->next;
                head->next = hashmap[key];
                hashmap[key]->next = temp;
                temp->prev = hashmap[key];
                hashmap[key]->prev = head;
            }
        }
        else{
        hashmap[key]->value = value;
        Node* temp = hashmap[key]->prev;
        Node* temp2 = hashmap[key]->next;
        temp->next = temp2;
        temp2->prev =  temp;
        temp = head->next;
        head->next = hashmap[key];
        hashmap[key]->next = temp;
        temp->prev = hashmap[key];
        hashmap[key]->prev = head;
        } 
        
    }
};
