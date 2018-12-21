/**
 * Definition of Trip:
 * class Trip {
 * public:
 *     int id; // trip's id, primary key
 *     int driver_id, rider_id; // foreign key
 *     double lat, lng; // pick up location
 *     Trip(int rider, double lat, double lng);
 * }
 * Definition of Helper
 * class Helper {
 * public:
 *     static get_distance(double lat1, double lng1,
 *                         double lat2, double lng2) {
 *         // return distance between (lat1, lng1) and (lat2, lng2)
 *     }
 * };
 */
class MiniUber {
private:
    struct DriverInfo{
        double m_lat;
        double m_lon;
        DriverInfo() = default;
        DriverInfo(double lat, double lon) : m_lat(lat), m_lon(lon) {}
    };

    struct DriverDist {
        int m_id;
        double m_dist;
        DriverDist() = default;
        DriverDist(int id, double dist) : m_id(id), m_dist(dist) {}
    };

    struct DriverDistCompare{
        bool operator()(const DriverDist& d1, const DriverDist& d2) const {
            return d1.m_dist > d2.m_dist;
        }
    };

    unordered_map<int, DriverInfo> m_availableDrivers;
    unordered_map<int, Trip*> m_trips;

    int getClosestDriver(double lat, double lng) {
        priority_queue<DriverDist, vector<DriverDist>, DriverDistCompare> distance;
        for(const auto& driver : m_availableDrivers) {
            distance.push(DriverDist(driver.first, Helper::get_distance(lat, lng, driver.second.m_lat, driver.second.m_lon)));
        }
        return distance.empty() ? -1 : distance.top().m_id;
    }
public:
    MiniUber() {
        // initialize your data structure here.
    }

    // @param driver_id an integer
    // @param lat, lng driver's location
    // return matched trip information if there have matched rider or NULL
    Trip* report(int driver_id, double lat, double lng) {
        if(m_trips.count(driver_id)) {
            return m_trips[driver_id];
        } else {
            m_availableDrivers[driver_id] = DriverInfo(lat, lng);
            return nullptr;
        }
    }

    // @param rider_id an integer
    // @param lat, lng rider's location
    // return a trip
    Trip* request(int rider_id, double lat, double lng) {
        Trip* newTrip = new Trip(rider_id, lat, lng);
        int driverId = getClosestDriver(lat, lng);
        if(driverId != -1) {
            newTrip->driver_id = driverId;
            m_trips[driverId] = newTrip;
            m_availableDrivers.erase(driverId);
        }
        return newTrip;
    }
};