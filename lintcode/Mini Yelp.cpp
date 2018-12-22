/**
 * Definition of Location:
 * class Location {
 * public:
 *     double latitude, longitude;
 *     static Location create(double lati, double longi) {
 *         // This will create a new location object
 *     }
 * };
 * Definition of Restaurant
 * class Restaurant {
 * public:
 *     int id;
 *     string name;
 *     Location location;
 *     static Restaurant create(string &name, Location &location) {
 *         // This will create a new restaurant object,
 *         // and auto fill id
 *     }
 * };
 * Definition of Helper
 * class Helper {
 * public:
 *     static get_distance(Location &location1, Location &location2) {
 *         // return distance between location1 and location2.
 *     }
 * };
 * class GeoHash {
 * public:
 *     static string encode(Location &location) {
 *         // return convert location to a GeoHash string
 *     }
 *     static Location decode(string &hashcode) {
 *          // return convert a GeoHash string to location
 *     }
 * };
 */

class MiniYelp {
private:
    unordered_map<int, Restaurant> m_restaurants;

public:
    MiniYelp() {
        // initialize your data structure here.
    }

    // @param name a string
    // @param location a Location
    // @return an integer, restaurant's id
    int addRestaurant(string name, Location &location) {
        auto restaurant = Restaurant::create(name, location);
        m_restaurants[restaurant.id] = restaurant;
        return restaurant.id;
    }

    // @param restaurant_id an integer
    void removeRestaurant(int restaurant_id) {
        m_restaurants.erase(restaurant_id);
    }

    // @param location a Location
    // @param k an integer, distance smaller than k miles
    // @return a list of restaurant's name and sort by
    // distance from near to far.
    vector<string> neighbors(Location &location, double k) {
        vector<string> names;
        map<double, string> m;
        for(auto& restaurant : m_restaurants) {
            auto distance = Helper::get_distance(location, restaurant.second.location);
            if(distance < k) {
                m[distance] = restaurant.second.name;
            }
        }

        for(const auto& it : m) {
            names.emplace_back(it.second);
        }
        return names;
    }
};


// With GeoHash improvement
/**
 * Definition of Location:
 * class Location {
 * public:
 *     double latitude, longitude;
 *     static Location create(double lati, double longi) {
 *         // This will create a new location object
 *     }
 * };
 * Definition of Restaurant
 * class Restaurant {
 * public:
 *     int id;
 *     string name;
 *     Location location;
 *     static Restaurant create(string &name, Location &location) {
 *         // This will create a new restaurant object,
 *         // and auto fill id
 *     }
 * };
 * Definition of Helper
 * class Helper {
 * public:
 *     static get_distance(Location &location1, Location &location2) {
 *         // return distance between location1 and location2.
 *     }
 * };
 * class GeoHash {
 * public:
 *     static string encode(Location &location) {
 *         // return convert location to a GeoHash string
 *     }
 *     static Location decode(string &hashcode) {
 *          // return convert a GeoHash string to location
 *     }
 * };
 */

class Node {
public:
    double distance;
    Restaurant restaurant;
    Node(double d, Restaurant &r) {
        distance = d;
        restaurant = r;
    }
    bool operator <(const Node& obj) const {
        return distance < obj.distance;
    }
};

class MiniYelp {
private:
    map<string, Restaurant> restaurants;
    map<int, string> ids;
    stringstream ss;
public:
    MiniYelp() {
        // initialize your data structure here.
    }

    // @param name a string
    // @param location a Location
    int addRestaurant(string name, Location &location) {
        // Write your code here
        Restaurant restaurant = Restaurant::create(name, location);
        ss.str("");
        ss << restaurant.id;
        string hashcode = GeoHash::encode(location) + "." + ss.str();
        ids[restaurant.id] = hashcode;
        restaurants[hashcode] = restaurant;
        return restaurant.id;
    }

    // @param restaurant_id an integer
    void removeRestaurant(int restaurant_id) {
        // Write your code here
        string hashcode = ids[restaurant_id];
        map<string, Restaurant>::iterator it = restaurants.find(hashcode);
        if (it != restaurants.end())
            restaurants.erase(it);
    }

    // @param location a Location
    // @param k an integer, distance smaller than k miles
    // @return a list of restaurant's name and sort by
    // distance from near to far.
    vector<string> neighbors(Location &location, double k) {
        // Write your code here
        int len = get_length(k);
        string hashcode = GeoHash::encode(location);
        hashcode = hashcode.substr(0, len);
        map<string, Restaurant>::iterator it = restaurants.lower_bound(hashcode);
        vector<Node> results;
        for (; it != restaurants.end(); ++it) {
            string value = it->first;
            if (value.substr(0, len) != hashcode)
                break;
            Restaurant restaurant = it->second;
            double distance = Helper::get_distance(location, restaurant.location);
            if (distance <= k) {
                results.push_back(Node(distance, restaurant));
            }
        }

        sort(results.begin(), results.end());
        vector<string> rt;
        int n = results.size();
        for (int i = 0; i < n; ++i)
            rt.push_back(results[i].restaurant.name);
        return rt;
    }


    int get_length(double k) {
        vector<double >ERROR = {2500, 630, 78, 20, 2.4, 0.61, 0.076, 0.01911, 0.00478, 0.0005971, 0.0001492, 0.0000186};
        for (int i = 0; i < ERROR.size(); ++i)
            if (k  > ERROR[i])
                return i;
        return ERROR.size();
    }
};