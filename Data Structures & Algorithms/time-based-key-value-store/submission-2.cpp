class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string bs(vector<pair<string, int>> &p, int timestamp, int n){
        int l = 0; int r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(p[mid].second > timestamp) r = mid;
            else l = mid + 1;
        }
        return p[r - 1].first;
    }

    string get(string key, int timestamp) {
        vector<pair<string, int>> v = m[key];
        int n = v.size();
        if(v.empty()) return "";
        if(v[0].second > timestamp) return "";
        return bs(v, timestamp, n);
    }
};
