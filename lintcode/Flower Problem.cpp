class Solution {
private:
    int find(vector<int>& fathers, int son) {
        if(fathers[son] < 0) return son;
        fathers[son] = find(fathers, fathers[son]);
        return fathers[son];
    }

public:
    /**
     * @param flowers: an array
     * @param k: an integer
     * @param m: an integer
     * @return: the last day
     */
    int flowerProblem(vector<int> &flowers, int k, int m) {
        int len = flowers.size();
        if(len == 0) return -1;
        if(m > len || k > len || k * m > len) return -1;

        vector<bool> slots(len, false);
        vector<int> fathers(len + 1);

        int groupNum = 0;
        map<int, int> kToGroupNum;
        int lastIndex = -1;
        for(int i = 0; i < len; ++i) {
            int slot = flowers[i];
            slots[slot] = true;
            fathers[slot] = -1;
            ++groupNum;
            ++kToGroupNum[1];

            if(slot > 0 && slots[slot - 1]) {
                auto father1 = find(fathers, slot-1);
                auto father2 = find(fathers, slot);

                if(father1 != father2) {
                    fathers[father1] += fathers[father2];
                    int father2Count = fathers[father2];
                    fathers[father2] = father1;
                    --groupNum;
                    ++kToGroupNum[-fathers[father1]];
                    if(--kToGroupNum[-fathers[father1]+father2Count] == 0) {
                        kToGroupNum.erase(-fathers[father1]+father2Count);
                    }
                    if(--kToGroupNum[1] <= 0) {kToGroupNum.erase(1);}
                }
            }

            if(slot < len && slots[slot + 1]) {
                auto father1 = find(fathers, slot+1);
                auto father2 = find(fathers, slot);

                if(father1 != father2) {
                    fathers[father1] += fathers[father2];
                    int father2Count = fathers[father2];
                    fathers[father2] = father1;
                    --groupNum;
                    ++kToGroupNum[-fathers[father1]];
                    if(--kToGroupNum[-fathers[father1]+father2Count] == 0) {
                        kToGroupNum.erase(-fathers[father1]+father2Count);
                    }
                    if(--kToGroupNum[-father2Count] == 0) {
                        kToGroupNum.erase(-father2Count);
                    }
                }
            }

            /*for(auto father : fathers) {
                std::cout << father << ", ";
            }
            std::cout << "|";
            std::cout << "groupNum : " << groupNum << ", first: " << kToGroupNum.begin()->first;
            std::cout << "|";
            for(auto it : kToGroupNum) {
                std::cout << "[" << it.first << ":" << it.second << "] ";
            }
            std::cout << "\n";*/

            if(groupNum == m && kToGroupNum.begin()->first >= k) {
                lastIndex = i + 1;
            }
        }

        return lastIndex;
    }
};


// Time O(N), space(N)
class Solution {
private:
    int find(vector<int>& fathers, int son) {
        if(fathers[son] == son) return son;
        fathers[son] = find(fathers, fathers[son]);
        return fathers[son];
    }


    void connect(vector<int>& fathers, unordered_map<int, int>& counts, int son1, int son2, int k, int& groupNum) {
        int father1 = find(fathers, son1);
        int father2 = find(fathers, son2);
        if(father1 != father2) {
            fathers[father2] = father1;

            if(counts[father2] >= k && counts[father1] >= k) {
                --groupNum;
            } else if (counts[father2] < k && counts[father1] < k) {
                if(counts[father2] + counts[father1] >= k) {
                    ++groupNum;
                }
            }

            counts[father1] += counts[father2];
        }
    }
public:
    /**
     * @param flowers: an array
     * @param k: an integer
     * @param m: an integer
     * @return: the last day
     */
    int flowerProblem(vector<int> &flowers, int k, int m) {
        int len = flowers.size();
        if(len == 0) return -1;
        if(m > len || k > len || k * m > len) return -1;

        vector<int> fathers(len + 1, -1);

        int answer = -1;
        int groupNum = 0;
        unordered_map<int, int> counts;

        for(int i = 0; i < len; ++i) {
            int plot = flowers[i];
            fathers[plot] = plot;
            counts[plot] = 1;
            if (1 >= k) ++groupNum;
            if (plot > 1 && fathers[plot-1] != -1) connect(fathers, counts, plot - 1, plot, k, groupNum);
            if (plot < len && fathers[plot+1] != -1) connect(fathers, counts, plot, plot + 1, k, groupNum);
            if (groupNum >= m) answer = i + 1;
        }

        return answer;
    }
};