#include "crow.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Utility functions for file handling
bool validateCredentials(const string& filePath, const string& username, const string& password) {
    ifstream file(filePath);
    string line;
    bool usernameMatch = false;

    while (getline(file, line)) {
        if (line.find("username: " + username) != string::npos) {
            usernameMatch = true;
        }
        if (usernameMatch && line.find("password: " + password) != string::npos) {
            return true;
        }
    }
    return false;
}

string readFile(const string& filePath) {
    ifstream file(filePath);
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void writeFile(const string& filePath, const string& content) {
    ofstream file(filePath, ios::app);
    file << content << endl;
}

string generateId(const string& prefix) {
    srand(time(nullptr)); // Seed for randomization
    return prefix + "-" + to_string(rand() % 100000);
}

// Main Crow server logic
int main() {
    crow::SimpleApp app;

    // Login route
    CROW_ROUTE(app, "/login").methods("POST"_method)([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        string username = body["username"].s();
        string password = body["password"].s();

        // Validate against admin.txt or users.txt
        if (validateCredentials("data/admin.txt", username, password)) {
            return crow::response(200, R"({"role": "admin"})");
        }
        else if (validateCredentials("data/users.txt", username, password)) {
            return crow::response(200, R"({"role": "user"})");
        }
        else {
            return crow::response(401, R"({"error": "Invalid credentials"})");
        }
        });

    // Admin routes
    CROW_ROUTE(app, "/admin/add_user").methods("POST"_method)([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        string username = body["username"].s();
        string password = body["password"].s();
        string name = body["name"].s();

        string newUser = "userId: " + generateId("U") + "\nusername: " + username +
            "\npassword: " + password + "\nname: " + name + "\n";
        writeFile("data/users.txt", newUser);

        return crow::response(200, R"({"status": "User added successfully"})");
        });

    CROW_ROUTE(app, "/admin/add_home").methods("POST"_method)([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        string homeName = body["homeName"].s();
        string ownerId = body["ownerId"].s();

        string newHome = "homeId: " + generateId("H") + "\nhomeName: " + homeName +
            "\nownerId: " + ownerId + "\n";
        writeFile("data/homes.txt", newHome);

        return crow::response(200, R"({"status": "Home added successfully"})");
        });

    CROW_ROUTE(app, "/admin/add_room").methods("POST"_method)([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        string roomName = body["roomName"].s();
        string homeId = body["homeId"].s();

        string newRoom = "roomId: " + generateId("R") + "\nroomName: " + roomName +
            "\nhomeId: " + homeId + "\n";
        writeFile("data/rooms.txt", newRoom);

        return crow::response(200, R"({"status": "Room added successfully"})");
        });

    CROW_ROUTE(app, "/admin/add_device").methods("POST"_method)([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        string deviceName = body["deviceName"].s();
        string roomId = body["roomId"].s();
        string deviceType = body["deviceType"].s();

        string newDevice = "deviceId: " + generateId("D") + "\ndeviceName: " + deviceName +
            "\nroomId: " + roomId + "\ndeviceType: " + deviceType + "\n";
        writeFile("data/devices.txt", newDevice);

        return crow::response(200, R"({"status": "Device added successfully"})");
        });

    // User routes
    CROW_ROUTE(app, "/user/homes").methods("GET"_method)([](const crow::request& req) {
        string homesData = readFile("data/homes.txt");
        return crow::response(200, homesData);
        });

    CROW_ROUTE(app, "/user/rooms/<string>").methods("GET"_method)([](const crow::request& req, const string& homeId) {
        string roomsData = readFile("data/rooms.txt");
        string filteredRooms;
        stringstream ss(roomsData);
        string line;

        while (getline(ss, line)) {
            if (line.find("homeId: " + homeId) != string::npos) {
                filteredRooms += line + "\n";
            }
        }

        return crow::response(200, filteredRooms);
        });

    CROW_ROUTE(app, "/user/devices/<string>").methods("GET"_method)([](const crow::request& req, const string& roomId) {
        string devicesData = readFile("data/devices.txt");
        string filteredDevices;
        stringstream ss(devicesData);
        string line;

        while (getline(ss, line)) {
            if (line.find("roomId: " + roomId) != string::npos) {
                filteredDevices += line + "\n";
            }
        }

        return crow::response(200, filteredDevices);
        });

    // Start Crow server
    app.port(8080).multithreaded().run();
}