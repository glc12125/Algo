class GeoHash {
private:
    string m_base32 = "0123456789bcdefghjkmnpqrstuvwxyz";
    vector<int> m_mask = {16, 8, 4, 2 , 1};
    int m_width = 5;

    string getBin(char c) {
        int pos = m_base32.find(c);
        string binRep;
        int bit = 0;
        while(bit < m_width) {
            if(pos & m_mask[bit]) {
                binRep += '1';
            } else {
                binRep += '0';
            }
            ++bit;
        }
        return binRep;
    }

    double getPosition(string binRep, double left, double right) {
        double l = left;
        double r = right;

        int len = binRep.size();
        int i = 0;
        double mid = 0.0;
        while(i < len) {
            mid = (l + r) / 2.0;
            if(binRep[i] == '0') {
                r = mid;
            } else {
                l = mid;
            }
            ++i;
        }
        return (l + r) / 2.0;
    }
public:
    /*
     * @param geohash: geohash a base32 string
     * @return: latitude and longitude a location coordinate pair
     */
    vector<double> decode(string &geohash) {

        string b;
        for(auto c : geohash) {
            b += getBin(c);
        }

        string longitudeBin;
        string latitudeBin;
        for(int i = 0; i < b.size(); i+=2) {
            longitudeBin += b[i];
            if(i + 1 < b.size()) {
                latitudeBin += b[i+1];
            }
        }

        return {getPosition(latitudeBin, -90, 90), getPosition(longitudeBin, -180, 180)};
    }
};