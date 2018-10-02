class TinyUrl {
private:
    long m_id;
    int m_base;
    std::string m_shortUrlBase;
    std::string m_chars;
    std::unordered_map<long, std::string> m_idToOriginal;

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
public:
    TinyUrl() : m_id(111111),
                m_base(62),
                m_shortUrlBase("http://tiny.url/"),
                m_chars("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") {

    }
    /*
     * @param url: a long url
     * @return: a short url starts with http://tiny.url/
     */
    string longToShort(string &url) {
        std::string shortUrl;
        long id = m_id;
        while(id > 0) {
            shortUrl = m_chars[id%m_base] + shortUrl;
            id /= m_base;
        }

        while(shortUrl.size() < 6) {
            shortUrl = '0' + shortUrl;
        }
        shortUrl = m_shortUrlBase + shortUrl;
        m_idToOriginal[m_id] = url;
        ++m_id;
        return shortUrl;
    }

    /*
     * @param url: a short url starts with http://tiny.url/
     * @return: a long url
     */
    string shortToLong(string &url) {
        url = url.substr(m_shortUrlBase.size());
        long id = 0;
        int size = url.size();
        for(int i = 0; i < size; ++i) {
            int base62 = toBase62(url[i]);
            id = id * m_base + base62;
        }
        return m_idToOriginal[id];
    }
};

// Use hash function

const string TINYURL = "http://tiny.url/";

class TinyUrl {
private:
    map<long long, string> mp;

    string getShortKey(string& url) {
        return url.substr(TINYURL.size(),
                          url.size() - TINYURL.size());
    }

    long long shortKeytoID(string& short_Key) {
        long long id = 0; // initialize result
        // A simple base conversion logic
        for (int i = 0; short_Key[i] && i < 6; ++i) {
            if ('a' <= short_Key[i] && short_Key[i] <= 'z')
                id = id * 62 + short_Key[i] - 'a';
            if ('A' <= short_Key[i] && short_Key[i] <= 'Z')
                id = id * 62 + short_Key[i] - 'A' + 26;
            if ('0' <= short_Key[i] && short_Key[i] <= '9')
                id = id * 62 + short_Key[i] - '0' + 52;
        }
        return id;
    }

    string idToShortKey(long long n) {
        string short_key;
        char c[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        // Convert given integer id to a base 62 number
        while (n) {
            // use above map to store actual character
            // in short url
            short_key.push_back(c[n % 62]);
            n = n / 62;
        }
        while (short_key.size() < 6)
            short_key.push_back('a');
        // Reverse shortURL to complete base conversion
        reverse(short_key.begin(), short_key.end());
        return short_key;
    }

public:
    /**
     * @param url a long url
     * @return a short url starts with http://tiny.url/
     */
    string longToShort(string& url) {
        // Write your code here
        long long ans = 0;
        for (int i = 0; i < url.size(); ++i)
            ans = (ans * 256L + (long long)url[i]) % 56800235584L;
        long long id = ans % 56800235584L;
        while (mp.find(id) != mp.end() && mp[id] != url)
            id ++;

        mp[id] = url;
        return TINYURL + idToShortKey(id);
    }

    /**
     * @param url a short url starts with http://tiny.url/
     * @return a long url
     */
    string shortToLong(string& url) {
        // Write your code here
        string short_key = getShortKey(url);
        long long id = shortKeytoID(short_key);
        return mp[id];
    }
};