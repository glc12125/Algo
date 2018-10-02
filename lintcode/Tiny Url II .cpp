class TinyUrl2 {
private:
    long m_id;
    int m_base;
    std::string m_shortUrlBase;
    std::string m_chars;
    std::unordered_map<long, std::string> m_idToOriginal;
    std::unordered_map<std::string, long> m_originalToId;
    std::unordered_map<std::string, std::string> m_customL2s;
    std::unordered_map<std::string, std::string> m_customS2l;

    long toBase62(char c) {
        if ('a' <= c && c <= 'z'){
            return c - 'a' + 10;
        }
        if ('A' <= c && c <= 'Z'){
            return c - 'A' + 36;
        }
        if ('0' <= c && c <= '9'){
            return c - '0';
        }
    }

    std::string idToShort(long id) {
        std::string shortUrl;
        while(id > 0) {
            shortUrl = m_chars[id%m_base] + shortUrl;
            id /= m_base;
        }

        while(shortUrl.size() < 6) {
            shortUrl = '0' + shortUrl;
        }
        return m_shortUrlBase + shortUrl;
    }

    long shortToId(const std::string& url) {
        long id = 0;
        int size = url.size();
        for(int i = 0; i < size; ++i) {
            int base62 = toBase62(url[i]);
            id = id * m_base + base62;
        }
        return id;
    }
public:
    TinyUrl2() : m_id(111111),
                m_base(62),
                m_shortUrlBase("http://tiny.url/"),
                m_chars("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") {

    }
    /*
     * @param long_url: a long url
     * @param key: a short key
     * @return: a short url starts with http://tiny.url/
     */
    string createCustom(string &long_url, string &key) {
        // Write your code here
        std::string short_url = m_shortUrlBase + key;
        auto id = shortToId(key);
        if (m_idToOriginal.count(id) > 0 && m_idToOriginal[id] != long_url) {
            return "error";
        }

        if (m_originalToId.count(long_url) >0 && m_originalToId[long_url] != id) {
            return "error";
        }

        if (m_idToOriginal.count(id) > 0 || m_originalToId.count(long_url)) {
            return short_url;
        }

        if (m_customS2l.count(short_url) > 0 && m_customS2l[short_url] != long_url) {
            return "error";
        }

        if (m_customL2s.count(long_url) > 0 && m_customL2s[long_url] != short_url) {
            return "error";
        }

        m_customL2s[long_url] = short_url;
        m_customS2l[short_url] = long_url;
        return short_url;
    }

    /*
     * @param long_url: a long url
     * @return: a short url starts with http://tiny.url/
     */
    string longToShort(string &long_url) {
        std::string shortUrl;
        if(m_customL2s.count(long_url) > 0) {
            return m_customL2s[long_url];
        }
        long id = m_id;;
        if(m_originalToId.count(long_url) > 0) {
            id = m_originalToId[long_url];
        } else {
            ++m_id;
        }
        m_idToOriginal[id] = long_url;
        m_originalToId[long_url] = id;
        return idToShort(id);

    }

    /*
     * @param short_url: a short url starts with http://tiny.url/
     * @return: a long url
     */
    string shortToLong(string &short_url) {
        if(m_customS2l.count(short_url) > 0) {
            return m_customS2l[short_url];
        }
        short_url = short_url.substr(m_shortUrlBase.size());
        long id = shortToId(short_url);
        return m_idToOriginal[id];
    }
};