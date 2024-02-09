#ifndef DUPLICATESENSORNAME_H_
#define DUPLICATESENSORNAME_H_

#include <stdexcept>
#include <iostream>

/**
 * An exception which is thrown when an attempt is made to add
 * a sensor to a network that already includes a sensor with
 * this sensor's name.
 */
class DuplicateSensorName: public std::invalid_argument {
public:
    /**
     * Initialize a new object. (2 points)
     *
     * @param name the sensor's (duplicate) name.
     */
    DuplicateSensorName(std::string sensorName);
};

#endif /* DUPLICATESENSORNAME_H_ */
