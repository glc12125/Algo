class GeoHash {
private:
    int b2i(string bin) {
        int base = 1, val = 0;
        for (int i = bin.size() - 1; i >= 0; --i) {
            if (bin[i] == '1')
                val += base;
            base *= 2;
        }
        return val;
    }

    string getBin(double value, double left, double right) {
        string b = "";
        for (int i = 0; i < 30; ++i) {
            double mid = (left + right) / 2.0;
            if (value > mid) {
                left = mid;
                b += "1";
            } else {
                right = mid;
                b += "0";
            }
        }
        return b;
    }

public:
    /*
     * @param latitude: one of a location coordinate pair
     * @param longitude: one of a location coordinate pair
     * @param precision: an integer between 1 to 12
     * @return: a base32 string
     */
    string encode(double latitude, double longitude, int precision) {
        // Write your code here
        string _base32 = "0123456789bcdefghjkmnpqrstuvwxyz";
        string lat_bin = getBin(latitude, -90, 90);
        string lng_bin = getBin(longitude, -180, 180);

        string hash_code = "";
        string b = "";
        for (int i = 0; i < 30; ++i) {
            b += lng_bin[i];
            b += lat_bin[i];
        }
        for (int i = 0; i < 60; i += 5) {
            hash_code += _base32[b2i(b.substr(i, 5))];
        }

        return hash_code.substr(0, precision);
    }

};