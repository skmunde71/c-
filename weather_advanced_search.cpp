#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct WeatherDataPoint {
    string time;
    string date;
    double latitude;
    double longitude;
    double altitude;
    string city;
    string country;
    string variable;
    string device_id;
    string model_version;
    double value;
};

string to_lower(const string& s) {
    string out = s;
    transform(out.begin(), out.end(), out.begin(), ::tolower);
    return out;
}

bool matches(const string& field, const string& search) {
    if (search.empty()) return true;
    return to_lower(field).find(to_lower(search)) != string::npos;
}

int main() {
    vector<WeatherDataPoint> data = {
        {"14:00", "2024-05-01", 0, 0, 0, "Tokyo", "Japan", "temperature", "sensor_01", "v1.2", 22.5},
        {"14:00", "2024-05-01", 0, 0, 0, "Tokyo", "Japan", "humidity", "sensor_01", "v1.2", 60.0},
        {"14:00", "2024-05-01", 0, 0, 0, "San Jose", "USA", "temperature", "sensor_01", "v1.2", 25.0},
        {"14:00", "2024-05-01", 0, 0, 0, "Bangalore", "India", "temperature", "sensor_01", "v1.2", 30.0},
        {"15:00", "2024-05-01", 0, 0, 0, "Tokyo", "Japan", "temperature", "sensor_01", "v1.2", 23.0},
        {"15:00", "2024-05-01", 0, 0, 0, "San Jose", "USA", "humidity", "sensor_01", "v1.2", 55.0}
    };

    string search_city, search_variable, search_date, search_time;
    double min_temp = -1e9;
    cout << "Enter city to search (or leave blank for any): ";
    getline(cin, search_city);
    cout << "Enter variable to search (e.g., temperature, or leave blank for any): ";
    getline(cin, search_variable);
    cout << "Enter date to search (YYYY-MM-DD, or leave blank for any): ";
    getline(cin, search_date);
    cout << "Enter time to search (e.g., 14:00, or leave blank for any): ";
    getline(cin, search_time);
    cout << "Enter minimum temperature (or leave blank for any): ";
    string temp_input;
    getline(cin, temp_input);
    bool filter_temp = false;
    if (!temp_input.empty()) {
        try {
            min_temp = stod(temp_input);
            filter_temp = true;
        } catch (...) {
            cout << "Invalid temperature input. Using no minimum filter.\n";
            min_temp = -1e9;
        }
    }

    cout << "[DEBUG] Search criteria:" << endl;
    cout << "  search_city: '" << search_city << "'" << endl;
    cout << "  search_variable: '" << search_variable << "'" << endl;
    cout << "  search_date: '" << search_date << "'" << endl;
    cout << "  search_time: '" << search_time << "'" << endl;
    cout << "  min_temp: '" << min_temp << "' (filter_temp: " << filter_temp << ")" << endl;

    bool found = false;
    for (const auto& point : data) {
        cout << "[DEBUG] Comparing to data point: city='" << point.city << "', variable='" << point.variable << "', date='" << point.date << "', time='" << point.time << "', value=" << point.value << endl;
        bool match = matches(point.city, search_city) &&
                     matches(point.variable, search_variable) &&
                     matches(point.date, search_date) &&
                     matches(point.time, search_time);
        cout << "[DEBUG] matches() result: " << match << endl;
        if (match) {
            if (filter_temp && to_lower(point.variable).find("temp") != string::npos) {
                if (point.value <= min_temp) {
                    cout << "[DEBUG] Skipping " << point.city << " " << point.variable << " value=" << point.value << " <= min_temp=" << min_temp << endl;
                    continue;
                } else {
                    cout << "[DEBUG] Matched (temp filter): " << point.city << " " << point.variable << " value=" << point.value << " > min_temp=" << min_temp << endl;
                }
            } else {
                cout << "[DEBUG] Matched: " << point.city << " " << point.variable << " value=" << point.value << endl;
            }
            cout << "Found: " << point.city << " " << point.variable
                 << " at " << point.time << " on " << point.date
                 << " = " << point.value << endl;
            found = true;
        } else {
            cout << "[DEBUG] Not matched: " << point.city << " " << point.variable << " value=" << point.value << endl;
        }
    }
    if (!found) {
        cout << "No data found for your search criteria." << endl;
    }
    return 0;
}