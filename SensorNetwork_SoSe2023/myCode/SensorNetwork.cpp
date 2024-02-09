#include "SensorNetwork.h"
#include "DuplicateSensorName.h"

using namespace std;

SensorNetwork& SensorNetwork::add(std::unique_ptr<Sensor> &&sensor)
{
	for(const auto& itr : this->sensors)
	{
		if(itr.get()->getName() == sensor.get()->getName())
		{
//			cout << sensor.get()->getName() << endl;

			throw DuplicateSensorName(sensor.get()->getName());
		}
	}

	this->sensors.emplace_back(move(sensor));

	return *this;
}
