#ifndef ADJUSTER_H_
#define ADJUSTER_H_

#include <iostream>
#include <string>

/**
 * An Adjuster provides only the method "adjust" which performs
 * the adjustment of the measured value.
 */
class Adjuster {
public:
    virtual ~Adjuster();

    /**
     * Given the raw sensor reading, calculate the adjusted value.
     */
    virtual float adjust(float value) const = 0;
};

#endif /* ADJUSTER_H_ */
