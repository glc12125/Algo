class Solution {
private:
    int m_magic;
    int m_mod;
    int m_shardNum;
    std::map<int, int> m_hashTable;

    int getHashCode(const std::string& name) {
        int code = 0;
        int size = name.size();
        for(int i = 0; i < size; ++i) {
            code = (code + m_magic * (int)name[i]) % m_mod;
            while(m_hashTable.count(code) > 0) {
                code = (1 + code) % m_mod;
            }
        }
        return code;
    }
public:
    /*
     * @param n: a positive integer
     * @param k: a positive integer
     * @return: a Solution object
     */
    static Solution create(int n, int k) {
        return Solution(n, k);
    }

    Solution(int n, int k) : m_mod(n), m_shardNum(k), m_magic(31){

    }

    /*
     * @param machine_id: An integer
     * @return: a list of shard ids
     */
    vector<int> addMachine(int machine_id) {
        std::string baseName = std::to_string(machine_id);
        std::vector<int> newHashCodes;
        for(int i = 0; i < Solution::m_shardNum; ++i) {
            auto hashCode = getHashCode(baseName + "_" + std::to_string(i));
            newHashCodes.push_back(hashCode);
            m_hashTable[hashCode] = machine_id;
        }
        return newHashCodes;
    }

    /*
     * @param hashcode: An integer
     * @return: A machine id
     */
    int getMachineIdByHashCode(int hashcode) {
        auto itr = m_hashTable.lower_bound(hashcode);
        int machineId;
        if( itr == m_hashTable.end()) machineId = m_hashTable.begin()->second;
        else machineId = itr->second;
        return machineId;
    }
};