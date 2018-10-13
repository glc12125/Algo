class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses == 0) return false;
        if(prerequisites.size() == 0) return true;

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

        if(sequence.size() == inDegrees.size()) return true;
        else return false;
    }
};