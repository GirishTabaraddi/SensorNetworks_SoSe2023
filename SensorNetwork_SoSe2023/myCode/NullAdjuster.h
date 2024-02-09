#ifndef NULLADJUSTER_H_
#define NULLADJUSTER_H_

#include <memory>

#include "Adjuster.h"

/**
 * This adjuster returns the value unchanged. It should be used
 * for sensors that need no adjustment by design (or are already
 * adjusted by some means during manufacturing).
 */
class NullAdjuster: public Adjuster {
public:
    static std::shared_ptr<Adjuster> sharedInstance;

    /**
     * Given the raw sensor reading, calculate the adjusted value.
     */
    float adjust(float value) const;
};

#endif /* NULLADJUSTER_H_ */
