/**
 * Definition of Document:
 * class Document {
 * public:
 *     int id;
 *     string content;
 * }
 */
class Solution {
public:
    /**
     * @param docs a list of documents
     * @return an inverted index
     */
    map<string, vector<int>> invertedIndex(vector<Document>& docs) {
        map<string, set<int>> uniqueMappings;
        for(const auto& document : docs) {
            stringstream ss(document.content);
            string word;
            while(ss >> word) {
                uniqueMappings[word].insert(document.id);
            }
        }

        map<string, vector<int>> result;
        for(const auto& it : uniqueMappings) {
            result[it.first] = vector<int>(it.second.begin(), it.second.end());
        }
        return result;
    }
};