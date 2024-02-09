#include "TableBasedAdjuster.h"

using namespace std;

TableBasedAdjuster& TableBasedAdjuster::addBreakpoint(float x, float y)
{
	this->breakpoints[x] = y;

	return *this;
}

float TableBasedAdjuster::adjust(float value) const
{
	if(this->breakpoints.empty())
	{
		return value;
	}
	else
	{
		float k_max = this->breakpoints.begin()->first;
		float k_min = this->breakpoints.begin()->first;

		for(auto& itr: this->breakpoints)
		{
			if(itr.first > k_max)
			{
				k_max = itr.first;
			}
			if(itr.first < k_min)
			{
				k_min = itr.first;
			}
		}

//		auto minmax = std::minmax_element(begin(this->breakpoints), end(this->breakpoints));
//
//		float k_min = minmax.first->first;
//		float k_max = minmax.second->second;

		float adjustedValue = 0;

		if(value <= k_min)
		{
			auto itr = this->breakpoints.find(k_min);

			if(itr != this->breakpoints.end())
			{
				adjustedValue = itr->second - (itr->first - value);
			}
		}
		if(value >= k_max)
		{
			auto itr = this->breakpoints.find(k_max);

			if(itr != this->breakpoints.end())
			{
				adjustedValue = itr->second + (value - itr->first);
			}
		}

		for(auto itr = this->breakpoints.begin(); itr != this->breakpoints.end(); itr++)
		{
			auto next_itr = std::next(itr);

			if(next_itr != this->breakpoints.end() && value > itr->first && value <= next_itr->first)
			{
				adjustedValue = (value - itr->first) / (next_itr->first - itr->first) *
						(next_itr->second - itr->second) + itr->second;

				break;
			}
		}

		return adjustedValue;
	}
}
