class EventManager {
    private:
    priority_queue<pair<int,int>>pq;
    unordered_map<int,int>mp;
public:
    EventManager(vector<vector<int>>& events) {
        for(auto &e:events){
            int id=e[0],p=e[1];
            pq.push({p,-id});
            mp[id]=p;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId]=newPriority;
        pq.push({newPriority,-eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto [p,nid]=pq.top();
            int id=-nid;
            if(mp[id]==p){
                pq.pop();
                mp.erase(id);
                return id;
            }
            pq.pop();
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */