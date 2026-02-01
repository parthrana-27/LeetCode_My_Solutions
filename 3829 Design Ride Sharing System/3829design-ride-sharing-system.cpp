class RideSharingSystem {
    private:
    queue<int>rider;
    queue<int>driver;
    unordered_set<int>active;
public:
    RideSharingSystem() {
    }
    
    void addRider(int riderId) {
        if(active.count(riderId)) return ;
        rider.push(riderId);
        active.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!rider.empty() && !active.count(rider.front())){
            rider.pop();
        }
        if(!rider.empty() && !driver.empty()){
            int rId=rider.front();
            rider.pop();
            int dId=driver.front();
            driver.pop();
            return {dId,rId};
        }
        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        active.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */