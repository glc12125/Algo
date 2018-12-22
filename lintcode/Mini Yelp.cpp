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