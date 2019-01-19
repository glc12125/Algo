class Solution {
private:
    struct DenorAndValue{
        double m_value;
        string m_item;

        DenorAndValue() : m_value(-1.0), m_item("") {}
        DenorAndValue(double value, const string& item) : m_value(value), m_item(item) {}
    };

    double bfsFind(unordered_map<string, vector<DenorAndValue>>& neighbours, const string& nor, const string& denor) {
        if(neighbours.count(nor) == 0 || neighbours.count(denor) == 0) return -1.0;
        if(nor == denor) return 1.0;

        unordered_set<string> visited;
        queue<DenorAndValue> q;
        q.push(DenorAndValue(1.0, nor));
        visited.insert(nor);

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            if(curr.m_item == denor) {
                return curr.m_value;
            }

            for(const auto& next : neighbours[curr.m_item]) {
                if(visited.count(next.m_item)) continue;
                visited.insert(next.m_item);
                q.emplace(next.m_value*curr.m_value, next.m_item);
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int len = equations.size();
        if(len == 0 || len != values.size()) return {};
        int queryLen = queries.size();
        if(queryLen == 0) return {};

        unordered_map<string, vector<DenorAndValue>> neighbours;
        for(int i = 0; i < len; ++i) {
            neighbours[equations[i].first].emplace_back(DenorAndValue(values[i], equations[i].second));
            neighbours[equations[i].second].emplace_back(DenorAndValue(1.0/values[i], equations[i].first));
        }


        vector<double> result(queryLen, -1.0);
        for(int i = 0; i < queryLen; ++i) {
            result[i] = bfsFind(neighbours, queries[i].first, queries[i].second);
        }
        return result;
    }
};