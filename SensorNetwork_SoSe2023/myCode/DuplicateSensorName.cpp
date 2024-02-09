#include "DuplicateSensorName.h"

using namespace std;

DuplicateSensorName::DuplicateSensorName(std::string sensorName)
: invalid_argument("Duplicate Sensor: " + sensorName)
{
}
