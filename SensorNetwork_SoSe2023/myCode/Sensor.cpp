#include "Sensor.h"
#include "Adjuster.h"

Sensor::~Sensor() {
}

std::string Sensor::getName() const
{
    return this->name;
}

float Sensor::reading() const
{
	return this->rawReading();
}

Sensor::Sensor(const std::string &name, std::shared_ptr<Adjuster> adjuster)
: name(name)
{
}
