class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
      int n = position.size();

    // Pair each car's position and speed
    vector<pair<int, double>> cars;
    for (int i = 0; i < n; ++i) {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }

    // Sort by position in ascending order → then reverse (descending)
    sort(cars.begin(), cars.end());     // ascending by position
    reverse(cars.begin(), cars.end());  // now descending

    stack<double> fleetTimes;

    for (auto& car : cars) {
        double time = car.second;

        // If no fleet ahead or car can't catch the one ahead
        if (fleetTimes.empty() || time > fleetTimes.top()) {
            fleetTimes.push(time);  // new fleet
        }
        // else, joins fleet in front (no push)
    }

    return fleetTimes.size();
    }
};


 