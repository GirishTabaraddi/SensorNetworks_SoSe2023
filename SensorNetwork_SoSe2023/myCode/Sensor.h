#ifndef SENSOR_H_
#define SENSOR_H_

#include <string>
#include <memory>

#include "NullAdjuster.h"

/**
 * The base class for modeling all kinds of sensors (temperature,
 * humidity, voltage etc.).
 *
 * This base class provides the support for sensor adjustment. Depending
 * on the type of sensor, adjusting can be more or less difficult.
 * For some sensors, it may be sufficient to add an offset and correct
 * the slope. Others may require more complex algorithms and parameters.
 * And some may be precise by design and therefore require no additional
 * adjustment at all.
 *
 * In order to be able to reflect these different scenarios, adjustment
 * is performed by an independent object of type Adjuster. The sensor
 * simply invokes the adjuster's adjust method, which can be very simple
 * or more complex, depending on the kind of adjustment required.
 *
 * Derived classes must implement the method "rawReading", which returns
 * the current (raw) sensor reading.
 */
class Sensor {
private:
    std::string name;

protected:
    std::shared_ptr<Adjuster> adjuster;

    /**
     * Obtains the current value of the sensor as provided
     * by the sensor's hardware.
     *
     * @return the value
     */
    virtual float rawReading() const = 0;

public:
    /**
     * Creates a new sensor. (2 points)
     *
     * @param name the name of the sensor
     * @param adjuster the adjuster to use, defaults to
     * the default NullAdjuster instance.
     */
    Sensor(const std::string& name, std::shared_ptr<Adjuster> adjuster
            = NullAdjuster::sharedInstance);

    virtual ~Sensor();

    /**
     * Returns the sensor's name.
     */
    std::string getName() const;

    /**
     * Returns the current value reported by the sensor.
     * The value is the raw reading obtained from the sensor's
     * hardware with any required adjustment applied.
     * (2 points)
     */
    virtual float reading() const;
};

#endif /* SENSOR_H_ */
