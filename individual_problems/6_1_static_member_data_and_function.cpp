// Problem Statement:
// Problem 1: Implement a program to show static data member access and static member function access.

#include <iostream>

using namespace std;

class DeviceTracker {
private:
    int deviceId;
    // Static data member declaration
    static int activeDevicesCount;

public:
    DeviceTracker() {
        activeDevicesCount++;
        deviceId = activeDevicesCount;
        cout << "Device #" << deviceId << " registered and powered ON." << endl;
    }

    ~DeviceTracker() {
        cout << "Device #" << deviceId << " powered OFF and removed." << endl;
        activeDevicesCount--;
    }

    void showDeviceInfo() const {
        cout << "Device ID: " << deviceId << endl;
    }

    // Static member function (can be called using ClassName::functionName without an object)
    static int getActiveCount() {
        return activeDevicesCount;
    }
};

// Definition and initialization of static data member outside the class
int DeviceTracker::activeDevicesCount = 0;

int main() {
    cout << "=== Static Data Member & Static Member Function ===" << endl;

    // Accessing static function without creating any object
    cout << "Initial Active Devices Count: " << DeviceTracker::getActiveCount() << endl;

    cout << "\nCreating dev1 and dev2 on stack:" << endl;
    DeviceTracker dev1;
    DeviceTracker dev2;
    cout << "Active Count now: " << DeviceTracker::getActiveCount() << endl;

    cout << "\nEntering inner block scope:" << endl;
    {
        DeviceTracker dev3;
        cout << "Active Count inside block: " << DeviceTracker::getActiveCount() << endl;
        cout << "Exiting inner block..." << endl;
    }

    cout << "Active Count after block exit: " << DeviceTracker::getActiveCount() << endl;

    return 0;
}
