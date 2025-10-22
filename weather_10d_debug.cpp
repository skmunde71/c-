#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct WeatherDataPoint {
    string time;           // e.g., "14:00"
    string date;           // e.g., "2024-05-01"
    double latitude;       // e.g., 40.7128
    double longitude;      // e.g., -74.0060
    double altitude;       // e.g., 10.0 (meters)
    string city;           // e.g., "New York"
    string country;        // e.g., "USA"
    string variable;       // e.g., "temperature"
    string device_id;      // e.g., "sensor_01"
    string model_version;  // e.g., "v1.2"
    double value;          // e.g., 18.5 (the actual measurement)
};

void debug_print(const WeatherDataPoint& point, int index) {
    cout << "[DEBUG] Data Point " << index << ":\n"
         << "  Time: " << point.time << "\n"
         << "  Date: " << point.date << "\n"
         << "  Latitude: " << point.latitude << "\n"
         << "  Longitude: " << point.longitude << "\n"
         << "  Altitude: " << point.altitude << "\n"
         << "  City: " << point.city << "\n"
         << "  Country: " << point.country << "\n"
         << "  Variable: " << point.variable << "\n"
         << "  Device ID: " << point.device_id << "\n"
         << "  Model Version: " << point.model_version << "\n"
         << "  Value: " << point.value << "\n";
}

int main() {
    cout << "[INFO] Interactive 10-dimensional weather data entry (city only, others default).\n";
    int n;
    cout << "Enter number of weather data points: ";
    cin >> n;
    cin.ignore(); // Clear newline

    // Default values
    string default_time = "14:00";
    string default_date = "2024-05-01";
    double default_latitude = 0.0;
    double default_longitude = 0.0;
    double default_altitude = 0.0;
    string default_country = "USA";
    string default_variable = "temperature";
    string default_device_id = "sensor_01";
    string default_model_version = "v1.2";
    double default_value = 20.0;

    vector<WeatherDataPoint> weather_data;
    for (int i = 0; i < n; ++i) {
        WeatherDataPoint point;
        cout << "\n[INPUT] Data Point " << i << ":\n";
        cout << "  City: "; getline(cin, point.city);
        point.time = default_time;
        point.date = default_date;
        point.latitude = default_latitude;
        point.longitude = default_longitude;
        point.altitude = default_altitude;
        point.country = default_country;
        point.variable = default_variable;
        point.device_id = default_device_id;
        point.model_version = default_model_version;
        point.value = default_value;
        weather_data.push_back(point);
    }

    cout << "\n[INFO] Weather data entry complete. Total points: " << weather_data.size() << "\n\n";

    // Debug print each data point
    for (size_t i = 0; i < weather_data.size(); ++i) {
        debug_print(weather_data[i], i);
        cout << endl;
    }

    cout << "[INFO] Example: Filtering for all temperature readings in New York...\n";
    for (const auto& point : weather_data) {
        if (point.city == "New York" && point.variable == "temperature") {
            cout << "[DEBUG] Found: " << point.time << ", " << point.date << ", " << point.value << " C\n";
        }
    }

    cout << "\n[INFO] Example: Calculating average temperature for Miami...\n";
    double sum = 0.0;
    int count = 0;
    for (const auto& point : weather_data) {
        if (point.city == "Miami" && point.variable == "temperature") {
            sum += point.value;
            ++count;
            cout << "[DEBUG] Adding " << point.value << " C from " << point.time << ", " << point.date << "\n";
        }
    }
    if (count > 0) {
        cout << "[RESULT] Average temperature in Miami: " << (sum / count) << " C\n";
    } else {
        cout << "[RESULT] No temperature data for Miami.\n";
    }

    return 0;
}