#include "LinearAdjuster.h"

LinearAdjuster::LinearAdjuster(float factor, float offset)
: factor(factor), offset(offset)
{
}

float LinearAdjuster::adjust(float value) const
{
	return (value * this->factor + this->offset);
}
