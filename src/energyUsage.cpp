#include "EnergyUsage.h"
#include <iomanip>
#include <sstream>

EnergyUsage::EnergyUsage()
    : usageId(""), entityId(""), entityType(""), energyConsumed(0.0), cost(0.0) {
}

EnergyUsage::EnergyUsage(const Mystr& usageId, const Mystr& entityId, const Mystr& entityType)
    : usageId(usageId), entityId(entityId), entityType(entityType), energyConsumed(0.0), cost(0.0) {
}

void EnergyUsage::setOnTimestamp() {
    onTimestamp = chrono::system_clock::now();
}
void EnergyUsage::setOffTimestamp() {
    offTimestamp = chrono::system_clock::now();
}
void EnergyUsage::setOnTimestamp(const chrono::system_clock::time_point& tp) {
    onTimestamp = tp;
}
void EnergyUsage::setOffTimestamp(const chrono::system_clock::time_point& tp) {
    offTimestamp = tp;
}

void EnergyUsage::calculateEnergyConsumed(double ratePerHour) {
    using namespace chrono;
    auto realDuration = offTimestamp - onTimestamp;
    auto projectDuration = scaleProjectDuration(realDuration);
    double hours = duration_cast<minutes>(projectDuration).count() / 60.0;
    energyConsumed = hours * ratePerHour;
}

void EnergyUsage::calculateCost(double pricePerUnit) {
    cost = energyConsumed * pricePerUnit;
}

Mystr EnergyUsage::getUsageId() const { return usageId; }
Mystr EnergyUsage::getEntityId() const { return entityId; }
Mystr EnergyUsage::getEntityType() const { return entityType; }
double EnergyUsage::getEnergyConsumed() const { return energyConsumed; }
double EnergyUsage::getCost() const { return cost; }
chrono::system_clock::time_point EnergyUsage::getOnTimestamp() const { return onTimestamp; }
chrono::system_clock::time_point EnergyUsage::getOffTimestamp() const { return offTimestamp; }

chrono::system_clock::duration EnergyUsage::scaleProjectDuration(chrono::system_clock::duration realDuration) {
    return chrono::duration_cast<chrono::seconds>(realDuration) * 60;
}

Mystr EnergyUsage::formatTime(const chrono::system_clock::time_point& tp) {
    time_t tt = chrono::system_clock::to_time_t(tp);
    tm local_tm;
#ifdef _WIN32
    localtime_s(&local_tm, &tt);
#else
    localtime_r(&tt, &local_tm);
#endif
    char buffer[30];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &local_tm);
    return Mystr(buffer);
}