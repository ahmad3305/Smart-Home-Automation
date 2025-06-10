#ifndef ENERGYUSAGE_H
#define ENERGYUSAGE_H

#include "mystr.h"
#include <chrono>
using namespace std;

class EnergyUsage {
    Mystr usageId;
    Mystr entityId; // Could be deviceId, roomId, userId, etc.
    Mystr entityType; // "device", "room", "user", etc.

    chrono::system_clock::time_point onTimestamp;
    chrono::system_clock::time_point offTimestamp;

    double energyConsumed; // in kWh or relevant unit
    double cost; // in appropriate currency

public:
    EnergyUsage();
    EnergyUsage(const Mystr& usageId, const Mystr& entityId, const Mystr& entityType);

    void setOnTimestamp();
    void setOffTimestamp();
    void setOnTimestamp(const chrono::system_clock::time_point& tp);
    void setOffTimestamp(const chrono::system_clock::time_point& tp);

    void calculateEnergyConsumed(double ratePerHour); // Call after offTimestamp is set
    void calculateCost(double pricePerUnit); // Call after energyConsumed is set

    Mystr getUsageId() const;
    Mystr getEntityId() const;
    Mystr getEntityType() const;
    double getEnergyConsumed() const;
    double getCost() const;
    chrono::system_clock::time_point getOnTimestamp() const;
    chrono::system_clock::time_point getOffTimestamp() const;

    // Utility for converting to "project time" (1 real minute = 1 project hour)
    static chrono::system_clock::duration scaleProjectDuration(chrono::system_clock::duration realDuration);

    // Utility for formatting time as string for display/logging
    static Mystr formatTime(const chrono::system_clock::time_point& tp);
};

#endif