class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for (int i = 0; i < (int)position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end()); // sort by position ascending

        stack<double> st; // store times

        for (int i = (int)cars.size() - 1; i >= 0; i--) { // go from front to back
            double time = (double)(target - cars[i].first) / cars[i].second;

            // if this car catches the fleet ahead, it merges (don't create new fleet)
            if (!st.empty() && time <= st.top()) continue;

            st.push(time);
        }

        return (int)st.size();
    }
};
