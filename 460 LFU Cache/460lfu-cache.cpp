class LFUCache {
    struct node{
        int val,freq;
        list<int>::iterator it;
    };
    int capacity,mifreq;
    unordered_map<int,node>k_mp; // key->node
    unordered_map<int,list<int>>f_mp; // freq->list of keys
public:
    LFUCache(int capacity) {
        this->capacity=capacity;
        mifreq=0;
    }
    
    int get(int key) {
        if(!capacity || k_mp.find(key)==k_mp.end()) return -1;
        auto &node=k_mp[key];
        int freq=node.freq;
        f_mp[freq].erase(node.it);
        if(f_mp[freq].empty() && mifreq==freq) mifreq++;
        f_mp[freq+1].push_front(key);
        node.freq++;
        node.it=f_mp[freq+1].begin();
        return node.val;
    }
    
    void put(int key, int value) {
        if(!capacity) return;
        if(k_mp.find(key) != k_mp.end()){
            k_mp[key].val=value;
            get(key);
            return;
        }
        if(k_mp.size()==capacity){
            int evict=f_mp[mifreq].back();
            f_mp[mifreq].pop_back();
            k_mp.erase(evict);
        }
        f_mp[1].push_front(key);
        k_mp[key]={value,1,f_mp[1].begin()};
        mifreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */