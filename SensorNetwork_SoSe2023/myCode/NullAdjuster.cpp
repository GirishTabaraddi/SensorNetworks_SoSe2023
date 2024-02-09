#include "NullAdjuster.h"

std::shared_ptr<Adjuster> NullAdjuster::sharedInstance
    = std::make_shared<NullAdjuster>();

float NullAdjuster::adjust(float value) const {
    return value;
}
