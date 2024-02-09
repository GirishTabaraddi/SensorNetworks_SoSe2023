#ifndef SENSORNETWORK_H_
#define SENSORNETWORK_H_

#include <list>
#include <memory>
#include "Sensor.h"

/**
 * Models a network of sensors.
 */
class SensorNetwork {
private:
    std::list<std::unique_ptr<Sensor>> sensors;

public:
    /**
     * Adds the given sensor to the network. If a sensor with
     * the name of the sensor passed as parameter already
     * exists in the network, throws a DuplicateSensorName
     * exception. (11 points)
     *
     * @param sensor the sensor to add
     * @throws DuplicateSensorName
     */
    SensorNetwork& add(std::unique_ptr<Sensor>&& sensor);

	const std::list<std::unique_ptr<Sensor> >& getSensors() const
	{
		return sensors;
	}
};

#endif /* SENSORNETWORK_H_ */
