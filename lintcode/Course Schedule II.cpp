class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        if(numCourses == 0) return {};
        if(prerequisites.size() == 0) {
            std::vector<int> sequence(numCourses);
            for(int i = 0; i < numCourses; ++i) sequence[i] = i;
            return sequence;
        }

        std::unordered_map<int, int> inDegrees;
        std::unordered_map<int, std::vector<int> > neighbours;
        for(auto prerequisite : prerequisites) {
            neighbours[prerequisite.second].push_back(prerequisite.first);
            if(inDegrees.count(prerequisite.second) == 0) inDegrees[prerequisite.second] == 0;
            ++inDegrees[prerequisite.first];
        }

        std::queue<int> q;
        for(auto course : inDegrees) {
            if(course.second == 0) q.push(course.first);
        }

        std::vector<int> sequence;
        while(!q.empty()) {
            auto current = q.front();
            q.pop();
            sequence.push_back(current);
            for(auto neighbour : neighbours[current]) {
                if(--inDegrees[neighbour] == 0) q.push(neighbour);
            }
        }

        if(sequence.size() == inDegrees.size()) {
            if(sequence.size() < numCourses) {
                for(int i = 0; i < numCourses; ++i) {
                    if(inDegrees.count(i) == 0) sequence.push_back(i);
                }
            }
            return sequence;
        }

        return {};
    }
};