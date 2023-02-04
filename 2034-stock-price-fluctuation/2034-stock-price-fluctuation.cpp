class StockPrice {
public:

multiset<int>maxi,mini;
unordered_map<int,int>m;
int latest=0;

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        
        if(m[timestamp]!=0){
            maxi.erase(maxi.find(m[timestamp]));
            mini.erase(mini.find(m[timestamp]));
        }

        maxi.insert(price);
        mini.insert(price);
        m[timestamp]=price;
        latest=max(latest,timestamp);
    }
    
    int current() {
        
        return m[latest];
    }
    
    int maximum() {
        
        return *maxi.rbegin();
    }
    
    int minimum() {
        return *mini.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */