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
		/// this logic works for both ordered and unordered maps
//		float k_max = this->breakpoints.begin()->first;
//		float k_min = this->breakpoints.begin()->first;
//
//		float v_max = this->breakpoints.begin()->second;
//		float v_min = this->breakpoints.begin()->second;
//
//		for(auto& itr: this->breakpoints)
//		{
//			if(itr.first > k_max)
//			{
//				k_max = itr.first;
//				v_max = itr.second;
//			}
//			if(itr.first < k_min)
//			{
//				k_min = itr.first;
//				v_min = itr.second;
//			}
//		}

		/// this logic works for both ordered and unordered maps
//		auto minmax = std::minmax_element(begin(this->breakpoints), end(this->breakpoints));
//
//		float k_min = minmax.first->first;
//		float k_max = minmax.second->first;
//		float v_min = minmax.first->second;
//		float v_max = minmax.second->second;

//		cout << k_min << " " << v_min << " " << k_max << " " << v_max << endl;

		/// Logic using begin and rbegin only for ordered map
		float k_min = this->breakpoints.begin()->first;
		float k_max = this->breakpoints.rbegin()->first;

		float v_min = this->breakpoints.begin()->second;
		float v_max = this->breakpoints.rbegin()->second;

		float adjustedValue = 0;

		if(value <= k_min)
		{
			adjustedValue = v_min - (k_min - value);
		}
		if(value >= k_max)
		{
			adjustedValue = v_max + (value - k_max);
		}

		for(auto k_n = this->breakpoints.begin(); k_n != this->breakpoints.end(); k_n++)
		{
			auto k_n_1 = next(k_n);

			if(k_n_1 != this->breakpoints.end() && value > k_n->first && value <= k_n_1->first)
			{
				adjustedValue = (value - k_n->first) / (k_n_1->first - k_n->first) *
						(k_n_1->second - k_n->second) + k_n->second;

				break;
			}
		}

		return adjustedValue;
	}
}
