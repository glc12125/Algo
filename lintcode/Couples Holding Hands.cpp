/*
The proof proceeds by using mathematical induction:

    Base case: If we have a group of size 1, what is the minimum number of swaps needed to resolve the group? First,
        what does it imply if a group has size 1? A group of size 1 takes the form j --> j. From the definition of
        the --> notation, we know the element at index j is expected to appear at index j at the end of the swapping process.
        Since this is already the case (that is, element at index j is already placed at index j), we don't need to take any
        further actions, therefore the minimum number of swaps needed is 0, which is the group size minus 1. Hence the base case stands.

    Induction case: Assume the minimum number of swaps needed to resolve a group of size m is given
    by m - 1, where 1 <= m <= k. For a group of size k + 1, we can always use one swap to turn it into
    two mutually exclusive groups of size k1 and k2, respectively, such that k1 + k2 = k + 1 with
    1 <= k1, k2 <= k. This is done by first choosing any two different indices i and j in the group,
    then swapping the elements at index i with that at index j. Before swapping, the group is visualized
    as: ... --> i --> p --> ... --> j --> q --> .... The swapping operation is equivalent to repointing
    index i to index q meanwhile repointing index j to index p. This is because the element originally at
    index i is now at index j, therefore the expected index for the element at index j after swapping will
    be the same as the one for the element at index i before swapping, which is p, so we have j --> p after
    swapping. Similarly we have i --> q after swapping. Therefore, the original group becomes two disjoint
    groups after swapping: ... --> i --> q --> ... and ... --> j --> p --> ..., where each group contains
    at least one index. Now by the induction assumption, the minimum number of swaps needed to resolve
    the above two groups are given by k1 - 1 and k2 - 1, respectively. Therefore, the minimum number of
    swapping needed to resolve the original group of size (k + 1) is given by
    (k1 - 1) + (k2 - 1) + 1 = k1 + k2 - 1 = k. Hence the induction case also stands.

In conclusion, the minimum number of swaps needed to resolve the whole array can be obtained by summing up
the minimum number of swaps needed to resolve each of the index groups. To resolve each index group, we are
free to choose any two distinct indices in the group and swap them so as to reduce the group to two smaller
disjoint groups. In practice, we can always choose a pivot index and continuously swap it with its expected
index until the pivot index is the same as its expected index, meaning the entire group is resolved and all
placement requirements within the group are satisfied.

II -- N couples problem

The N couples problem can be solved using exactly the same idea as the N integers problem,
except now we have different placement requirements: instead of i == row[i], we require i == ptn[pos[ptn[row[i]]]],
where we have defined two additional arrays ptn and pos:

    1. ptn[i] denotes the partner of label i (i can be either a seat or a person) - - ptn[i] = i + 1 if i is even; ptn[i] = i - 1 if i is odd.

    2. pos[i] denotes the index of the person with label i in the row array - - row[pos[i]] == i.

The meaning of i == ptn[pos[ptn[row[i]]]] is as follows:

    1. The person sitting at seat i has a label row[i], and we want to place him/her next to his/her partner.

    2. So we first find the label of his/her partner, which is given by ptn[row[i]].

    3. We then find the seat of his/her partner, which is given by pos[ptn[row[i]]].

    4. Lastly we find the seat next to his/her partner's seat, which is given by ptn[pos[ptn[row[i]]]].

Therefore, for each pivot index i, its expected index j is given by ptn[pos[ptn[row[i]]]]. As long as
i != j, we swap the two elements at index i and j, and continue until the placement requirement is
satisfied. A minor complication here is that for each swapping operation, we need to swap both the row and pos arrays.
*/
class Solution {
public:
    /**
     * @param row: the couples' initial seating
     * @return: the minimum number of swaps
     */
    int minSwapsCouples(vector<int> &row) {

        int res = 0；
        int N = row.size();

        vector<int> ptn(N, 0);
        vector<int> pos(N, 0);

        for (int i = 0; i < N; i++) {
            ptn[i] = (i % 2 == 0 ? i + 1 : i - 1);
            pos[row[i]] = i;
        }

        for (int i = 0; i < N; i++) {
            for (int j = ptn[pos[ptn[row[i]]]]; i != j; j = ptn[pos[ptn[row[i]]]]) {
    			swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]);
    			res++;
    		}
        }

        return res;
    }

};

// DFS
/*
1. Move next when the pair already matches. If they don't there are two things you can do:
    swap the value in row[pos] to the pair of row[pos+1], or
    swap row[pos+1] to the pair of row[pos]
2. This back tracking will time out, but how to prune using memoisation? if we reach pos, the number of non-matched pairs is fixed
    and we can cache that. Therefore the optimal swaping strategy should be fixed, too
*/
class Solution {
private:
    const static int OFFSET = 61;
public:
    /**
     * @param row: the couples' initial seating
     * @return: the minimum number of swaps
     */
    int minSwapsCouples(vector<int> &row) {

        //This is Person To Index
        unordered_map<int, int> maps;

        int diffs = 0;

        for (int i = 0; i < row.size(); i += 2) {
            maps[row[i]] = i;
            maps[row[i + 1]] = i + 1;
            if (row[i] / 2 != row[i + 1] / 2) {
                diffs++;
            }
        }
        unordered_map<int, int> mem;
        return dfs (0, diffs, row, maps, mem);
    }

    int dfs (int index, int diffs, vector<int> &row, unordered_map<int, int> &maps, unordered_map<int, int>& mem) {

        if (index == row.size()) {
            return 0;
        }

        int memIndex = index * OFFSET + diffs;

        if (mem.find(memIndex) != mem.end()) {
            return mem[memIndex];
        }

        int swaps;

        if (row[index] / 2 == row[index + 1] / 2) {
            swaps = dfs (index + 2, swaps, row, maps, mem);
            mem[memIndex] = swaps;
            return swaps;
        }

        int pair = (row[index] % 2 == 1) ? row[index] - 1 : row[index] + 1;
        int index1 = maps[pair];

        Swap(index + 1, index1, row, maps);
        swaps = 1 + dfs (index + 2, swaps + 1, row, maps, mem);
        Swap(index + 1, index1, row, maps);

        pair = (row[index + 1] % 2 == 1) ? row[index + 1] - 1 : row[index + 1] + 1;
        index1 = maps[pair];

        Swap(index, index1, row, maps);
        swaps = min(swaps, 1 + dfs(index + 2, swaps + 1, row, maps, mem));
        Swap(index, index1, row, maps);

        mem[memIndex] = swaps;
        return swaps;
    }

    void Swap (int index1, int index2, vector<int> &row, unordered_map<int, int> &maps) {

        int tmp = row[index1];
        row[index1] = row[index2];
        row[index2] = tmp;

        maps[row[index1]] = index1;
        maps[row[index2]] = index2;
    }

};
