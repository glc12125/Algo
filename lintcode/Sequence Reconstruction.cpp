class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        if(org.size() == 0 && seqs.size() != 0) return false;
        if(org.size() != 0 && seqs.size() == 0) return false;
        if(org.size() == 0 && seqs.size() == 0) return true;

        std::unordered_map<int, int> inDegrees;
        std::unordered_map<int, std::vector<int> > neighbours;
        for(auto seq : seqs) {
            int seqNum = seq.size();
            if(seqNum == 0) continue;
            for(int i = 0; i < seqNum - 1; ++i) neighbours[seq[i]].push_back(seq[i+1]);
            if(inDegrees.count(seq[0]) == 0) inDegrees[seq[0]] == 0;
            for(int i = 1; i < seqNum; ++i) ++inDegrees[seq[i]];
        }

        std::queue<int> q;
        for(auto item : inDegrees) {
            if(item.second == 0) q.push(item.first);
        }
        if(q.size() > 1) return false;

        std::vector<int> sequence;
        while(!q.empty()) {
            if(q.size() > 1) return false;
            auto current = q.front();
            q.pop();
            sequence.push_back(current);
            for(auto neighbour : neighbours[current]) {
                if(--inDegrees[neighbour] == 0) q.push(neighbour);
            }
        }

        if(sequence.size() == org.size()) {
            for (int i = 0; i < org.size(); ++i) {
                if(sequence[i] != org[i]) return false;
            }
            return true;
        }
        return false;
    }
};