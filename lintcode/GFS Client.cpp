/* Definition of BaseGFSClient
 * class BaseGFSClient {
 * private: map<string, string> chunk_list;
 * public:
 *     string readChunk(string& filename, int chunkIndex) {
 *         // Read a chunk from GFS
 *     }
 *     void writeChunk(string& filename, int chunkIndex,
 *                     string& content) {
 *         // Write a chunk to GFS
 *     }
 *  };
 */


class GFSClient : public BaseGFSClient {
private:
    int m_chunkSize;
    unordered_map<string, vector<int>> m_fileManager;
public:
    /*
    * @param chunkSize: An integer
    */GFSClient(int chunkSize) : m_chunkSize(chunkSize) {
        // do intialization if necessary
    }

    /*
     * @param filename: a file name
     * @return: conetent of the file given from GFS
     */
    string read(string &filename) {
        if(m_fileManager.count(filename) == 0) return "";
        const auto& chunkIndexes =  m_fileManager[filename];
        string content;
        for(auto index : chunkIndexes) {
            content += readChunk(filename, index);
        }
        return content;
    }

    /*
     * @param filename: a file name
     * @param content: a string
     * @return: nothing
     */
    void write(string &filename, string &content) {
        if(m_fileManager.count(filename)) {
            m_fileManager.erase(filename);
        }
        int len = content.size();
        int currentIndex = 0;
        int chunkIndex = 0;
        while(currentIndex < len) {
            string chunkContent = content.substr(currentIndex, std::min(m_chunkSize, len - currentIndex));
            writeChunk(filename, chunkIndex, chunkContent);
            m_fileManager[filename].push_back(chunkIndex);
            currentIndex += m_chunkSize;
            ++chunkIndex;
        }
    }
};