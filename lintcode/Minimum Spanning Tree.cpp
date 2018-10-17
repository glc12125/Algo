/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */
class Solution {
private:
    struct ConnectionCmp
    {
        bool operator() (const Connection& c1, const Connection& c2)
        {
            if(c1.cost != c2.cost) return c1.cost < c2.cost;
            if(c1.city1 != c2.city1) return c1.city1 < c2.city1;
            return c1.city2 < c2.city2;
        }
    };

    int find(std::unordered_map<int, int>& fathers, int son){
        if(fathers[son] == 0) return son;
        fathers[son] = find(fathers, fathers[son]);
        return fathers[son];
    }
public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        if(connections.size() == 0) return std::vector<Connection>();
        std::sort(connections.begin(), connections.end(), ConnectionCmp());
        std::unordered_map<std::string, int> values;
        int count = -1;
        for(const auto& connection : connections) {
            if(values.count(connection.city1) == 0) values[connection.city1] = ++count;
            if(values.count(connection.city2) == 0) values[connection.city2] = ++count;
        }

        std::unordered_map<int, int> fathers;
        std::vector<Connection> result;
        for(const auto& connection : connections) {
            int value1 = values[connection.city1];
            int value2 = values[connection.city2];
            int father1 = find(fathers, value1);
            int father2 = find(fathers, value2);

            if(father1 != father2) {
                fathers[father1] = father2;
                result.push_back(connection);
            }
        }

        if(result.size() != count) return std::vector<Connection>();
        return result;
    }
};