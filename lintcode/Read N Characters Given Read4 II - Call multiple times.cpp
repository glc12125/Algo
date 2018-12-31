// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    string m_buffer;
public:
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    int read(char *buf, int n) {
        n -= m_buffer.size();
        int iterNum = n / 4;
        int modnum = n % 4;
        int offset = 0;
        if(!m_buffer.empty()) {
            offset = m_buffer.size();
            memcpy(buf, m_buffer.c_str(), offset);
            m_buffer.clear();
        }
        for(int i = 0; i < iterNum; ++i) {
            int bytesRead = read4(buf + offset);
            if(bytesRead != 4) {
                offset += bytesRead;
                break;
            }
            offset += 4;
        }
        if(modnum > 0) {
            char temp[4] = {' '};
            int bytesRead = read4(temp);
            if(bytesRead > 0) {
                if(bytesRead >= modnum) {
                    memcpy(buf + offset, temp, modnum);
                    m_buffer.assign(temp + modnum, bytesRead - modnum);
                    offset += modnum;
                } else {
                    memcpy(buf + offset, temp, bytesRead);
                    offset += bytesRead;
                }
            }
        }
        return offset;
    }
};

// Just kept reading to a local buffer.
// Only call read4 API if necessary, otherwise assign values from
// local buffer to the given buf

class Solution {
private:
    char m_buffer[4] = {'\0'};
    int m_index = 0;
    int m_readBytes = 0;
public:
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    int read(char *buf, int n) {
        for (int i = 0; i < n; i++) {
            if (m_index == m_readBytes) {
                m_readBytes = read4(m_buffer);
                m_index = 0;
            }
            if (m_index < m_readBytes) {
                buf[i] = m_buffer[m_index++];
            } else {
                return i;
            }
        }
        return n;
    }
};