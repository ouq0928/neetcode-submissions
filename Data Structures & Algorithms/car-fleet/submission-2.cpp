class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_vel;
        int len = position.size();
        for(int i = 0; i < len; i++){
            pos_vel.push_back({position[i], speed[i]});
        }
        sort(pos_vel.rbegin(), pos_vel.rend());
        /*for(int i = 0; i < len; i++){
            cout << pos_vel[i].first << " " << pos_vel[i].second << "\n";
        }*/
        stack<double> time;
        for(auto &p : pos_vel){
            double cur_time = (double)(target - p.first) / (double)p.second;
            if(!time.empty() && cur_time <= time.top()){
                continue;
            }
            time.push(cur_time);
            //cout << time.size() << "\n";
        }
        return time.size();
    }
};
