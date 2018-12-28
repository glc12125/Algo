class Solution {
public:
    /**
     * @param N: The number of buses
     * @param route: The route of buses
     * @param A: Start bus station
     * @param B: End bus station
     * @return: Return the minimum transfer number
     */
    int getMinTransferNumber(int N, vector<vector<int>> &route, int A, int B) {
        if(A == B) return 0;
        int len = route.size();
        // Something is obviously wrong
        if(N != len) return - 1;

        unordered_map<int, unordered_set<int>> stopToRoute;
        for(int i = 0; i < N; ++i) {
            for(auto stop : route[i]) {
                stopToRoute[stop].insert(i);
            }
        }

        int minSwitch = INT_MAX;
        const auto& startingRoutes = stopToRoute[A];
        for(auto busRoute : startingRoutes) {
            queue<int> routeQ;
            unordered_set<int> visitedRoute;
            routeQ.push(busRoute);
            visitedRoute.insert(busRoute);

            int switchCount = 1;
            bool reachedDestination = false;
            while(!routeQ.empty()) {
                int len = routeQ.size();
                while(len > 0) {
                    int currentRoute = routeQ.front();
                    routeQ.pop();
                    for(auto stop : route[currentRoute]) {
                        if(stop == B) {
                            reachedDestination = true;
                            minSwitch = std::min(minSwitch, switchCount);
                            break;
                        }
                        for(auto nextRoute : stopToRoute[stop]) {
                            if(visitedRoute.count(nextRoute)) {continue;}
                            visitedRoute.insert(nextRoute);
                            routeQ.push(nextRoute);
                        }
                    }
                    if(reachedDestination) {
                        break;
                    }
                    --len;
                }
                if(reachedDestination) {
                    break;
                }
                ++switchCount;
            }
        }

        return minSwitch == INT_MAX ? -1 : minSwitch;
    }
};

// Using stop in queue, it depends on how many bus numbers each route might have, because this solutions
// pushes many stops into queue, could be slow when average bus numbers are huge.
class Solution {
public:
    /**
     * @param N: The number of buses
     * @param route: The route of buses
     * @param A: Start bus station
     * @param B: End bus station
     * @return: Return the minimum transfer number
     */
    int getMinTransferNumber(int N, vector<vector<int>> &route, int A, int B) {
        if(A == B) return 0;
        int len = route.size();
        // Something is obviously wrong
        if(N != len) return - 1;

        unordered_map<int, unordered_set<int>> stopToRoute;
        for(int i = 0; i < N; ++i) {
            for(auto stop : route[i]) {
                stopToRoute[stop].insert(i);
            }
        }

        int minSwitch = 0;
        queue<int> stopQ;
        unordered_set<int> visitedRoute;
        unordered_set<int> visitedStop;
        stopQ.push(A);
        visitedStop.insert(A);
        const auto& BRoutes = stopToRoute[B];

        while(!stopQ.empty()) {
            ++minSwitch;
            int len = stopQ.size();
            while(len > 0) {
                int currentStop = stopQ.front();
                stopQ.pop();
                for(auto nextRoute : stopToRoute[currentStop]) {
                    if(visitedRoute.count(nextRoute)) continue;
                    visitedRoute.insert(nextRoute);
                    if(BRoutes.count(nextRoute)) {
                        return minSwitch;
                    }

                    for(auto nextStop : route[nextRoute]) {
                        if(visitedStop.count(nextStop)) {continue;}
                        visitedStop.insert(nextStop);
                        stopQ.push(nextStop);
                    }
                }
                --len;
            }
        }
        return -1;
    }
};