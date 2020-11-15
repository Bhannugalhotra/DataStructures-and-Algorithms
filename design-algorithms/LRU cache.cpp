
class node
{
    public:
    int key;
    int data;
    
    node *next ,*prev;
    
    node(int a, int b) : key(a), data(b), next(NULL), prev(NULL) {};
};


class LRUCache 
{
    unordered_map<int,node*> map;
    node *head, *tail;
    int cap;
    int size;

public:
    LRUCache(int capacity) 
    {
        cap = capacity;
        size = 0;
        
        head = new node(0,0);
        
        tail = new node(0,0);
        
        head -> next = tail;
        
        tail -> prev = head;
    }
    
    void pop_front()
    {
        node *temp = head -> next;
        
        temp -> next -> prev = head;
        temp -> prev -> next = temp -> next;
        
        map[temp -> key] = NULL;
        delete(temp);
        
        size--;
    }
    
    void push_back(int key, int data)
    {
        node *newnode = new node(key, data);
        
        newnode -> next = tail;
        newnode -> prev = tail -> prev;
        
        newnode -> prev -> next = newnode;
        tail -> prev = newnode;
        
        map[key] = newnode;
        size++;
    }
    
    void push_back(node *newnode)
    {
        newnode -> next = tail;
        newnode -> prev = tail -> prev;
        
        newnode -> prev -> next = newnode;
        tail -> prev = newnode;

    }
    node* erase(int key)
    {
        node *temp = map[key];
        
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
        
        return temp;
    }
    
    int get(int key) 
    {
        if(!map.count(key) or !map[key])
            return -1;
        
        push_back(erase(key));
        
        return map[key] -> data;
    }
    
    void put(int key, int value)
    {
        
        if(map.count(key) and map[key])
        {
            push_back(erase(key));
            map[key] -> data = value;
        }
          
        else
        {
            if(size == cap)
            pop_front();
        
            push_back(key, value);
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */