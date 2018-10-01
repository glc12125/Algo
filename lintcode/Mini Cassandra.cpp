/**
 * Definition of Column:
 * class Column {
 * public:
 *     int key;
 *     String value;
 *     Column(int key, string value) {
 *         this->key = key;
 *         this->value = value;
 *    }
 * }
 */

struct ColumnComp {
  bool operator() (const Column& lhs, const Column& rhs) const
  {return lhs.key<rhs.key;}
};

class MiniCassandra {
private:
    typedef std::set<Column, ColumnComp> Columns;
    std::unordered_map<std::string, Columns> m_db;
public:
    MiniCassandra() {
        // do intialization if necessary
    }

    /*
     * @param raw_key: a string
     * @param column_key: An integer
     * @param column_value: a string
     * @return: nothing
     */
    void insert(string &raw_key, int column_key, string &column_value) {
        auto itr = m_db[raw_key].find(Column(column_key, ""));
        if(itr != m_db[raw_key].end()) m_db[raw_key].erase(itr);
        m_db[raw_key].insert(Column(column_key, column_value));
    }

    /*
     * @param raw_key: a string
     * @param column_start: An integer
     * @param column_end: An integer
     * @return: a list of Columns
     */
    vector<Column> query(string &raw_key, int column_start, int column_end) {
        std::vector<Column> result;
        auto itr = m_db.find(raw_key);
        if(itr == m_db.end()) return result;
        const auto& columns = m_db[raw_key];
        auto start = columns.lower_bound(Column(column_start, ""));
        auto end = columns.upper_bound(Column(column_end, ""));
        while(start != end) {
            result.push_back(*start);
            ++start;
        }
        return result;
    }
};