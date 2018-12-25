// DFS, time O(Line * Stop)
class Solution {
private:
    bool hasTargetStop(const vector<int>& stops, int target) {
        for(auto stop : stops) {
            if(stop == target) return true;
        }
        return false;
    }

    void dfsFind(int stop, int T, int busLine, unordered_map<int, unordered_set<int>>& stopToBusRoute, const vector<vector<int>>& routes, unordered_set<int>& visitedBusLine, int& minimalRouteChange, unordered_set<int>& mem) {
        //std::cout << "busLine: " << busLine << ", stop: " << stop << "\n";
        if(mem.count(busLine)) {return;}
        int totalBusLineNum = routes.size();

        if(hasTargetStop(routes[busLine], T)) {
            minimalRouteChange = std::min(minimalRouteChange, (int)visitedBusLine.size());
            return;
        }

        if(visitedBusLine.size() == totalBusLineNum) {
            return;
        }

        for(auto stop : routes[busLine]) {
            for(auto nextLine : stopToBusRoute[stop]) {
                if(busLine == nextLine) continue;
                if(visitedBusLine.count(nextLine)) continue;
                visitedBusLine.insert(nextLine);
                dfsFind(stop, T, nextLine, stopToBusRoute, routes, visitedBusLine, minimalRouteChange, mem);
                visitedBusLine.erase(nextLine);
            }
        }
        mem.insert(busLine);
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        int routesNum = routes.size();
        if(routesNum == 0) return 0;

        if(S == T) return 0;

        unordered_map<int, unordered_set<int>> stopToBusRoute;
        for(int j = 0; j < routesNum; ++j) {
            auto& stops = routes[j];
            int len = stops.size();
            for(int i = 0; i < len; ++i) {
                stopToBusRoute[stops[i]].insert(j);
            }
        }

        unordered_set<int> visitedBusLine;
        unordered_set<int> mem;
        int minimalRouteChange = INT_MAX;
        for(auto busLine : stopToBusRoute[S]) {
            visitedBusLine.insert(busLine);
            dfsFind(S, T, busLine, stopToBusRoute, routes, visitedBusLine, minimalRouteChange, mem);
            visitedBusLine.erase(busLine);
        }

        return (minimalRouteChange == INT_MAX ? -1 : minimalRouteChange);
    }
};

// BFS, time O(Line * Stop)
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        int routesNum = routes.size();
        if(routesNum == 0) return 0;

        if(S == T) return 0;

        unordered_map<int, unordered_set<int>> stopToBusRoute;
        for(int j = 0; j < routesNum; ++j) {
            const auto& stops = routes[j];
            int len = stops.size();
            for(int i = 0; i < len; ++i) {
                stopToBusRoute[stops[i]].insert(j);
            }
        }

        unordered_set<int> visitedBusLine;
        unordered_set<int> visitedBusStop;
        queue<int> routeQ;

        visitedBusStop.insert(S);
        const auto& reachableRoutes = stopToBusRoute[S];
        for(auto busLine : reachableRoutes) {
            visitedBusLine.insert(busLine);
            routeQ.push(busLine);
        }

        int minimalRouteChange = 1;

        while(!routeQ.empty()) {
            int len = routeQ.size();
            while(len > 0) {
                int busLine = routeQ.front();
                routeQ.pop();
                for(auto stop : routes[busLine]) {
                    if(visitedBusStop.count(stop)) continue;
                    if(stop == T) return minimalRouteChange;
                    for(auto nextBusLine : stopToBusRoute[stop]) {
                        if(visitedBusLine.count(nextBusLine)) continue;
                        routeQ.push(nextBusLine);
                        visitedBusLine.insert(nextBusLine);
                    }
                }
                --len;
            }
            ++minimalRouteChange;
        }

        return -1;
    }
};
