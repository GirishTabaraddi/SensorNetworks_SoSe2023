#ifndef TESTSENSOR_H_
#define TESTSENSOR_H_

#include "Adjuster.h"
#include "Sensor.h"

/**
 * A specialization of class Sensor for testing purposes that
 * returns a settable value as raw reading.
 */
class TestSensor : public Sensor {
private:
    float value;

public:
    /**
     * Initializes a new instance with the given name and adjustor
     * and a raw reading of 0. (3 points)
     *
     * @param name the name of the sensor
     * @param adjustor the adjustor to use
     */
    TestSensor(const std::string& name, std::shared_ptr<Adjuster> adjustor);

    /**
     * Sets the value to return from rawReading(). (1 point)
     *
     * @param value the value
     */
    void setRawReading(float value);

    /**
     * Returns the value set with setRawReading() or 0 if no
     * value has been set (yet). (1 point)
     *
     * @return the value
     */
    float rawReading() const;
};

#endif /* TESTSENSOR_H_ */
