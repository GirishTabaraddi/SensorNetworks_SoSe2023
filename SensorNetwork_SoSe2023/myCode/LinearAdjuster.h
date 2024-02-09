#ifndef LINEARADJUSTER_H_
#define LINEARADJUSTER_H_

#include "Adjuster.h"

/**
 * This adjuster can adjust the slope of and add an offset to the
 * sensor's raw readings.
 */
class LinearAdjuster: public Adjuster {
private:
    float factor;
    float offset;

public:
    /**
     * Initializes a new instance with the given values. (2 points)
     */
    LinearAdjuster(float factor = 1, float offset = 0);

    /**
     * Calculates the result as "value * factor + offset". (2 points)
     */
    virtual float adjust(float value) const;
};

#endif /* LINEARADJUSTER_H_ */
