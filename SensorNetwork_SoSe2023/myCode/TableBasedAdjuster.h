#ifndef TABLEBASEDADJUSTER_H_
#define TABLEBASEDADJUSTER_H_

#include <map>

#include "Adjuster.h"
#include <iterator>
#include <algorithm>

/**
 * Adjusts using values from a table. The table defines a
 * piecewise function with linear sub-functions. The breakpoints
 * (German: Nahtstellen) and values at these breakpoints are
 * stored in a map using the breakpoint values as keys and the
 * function's values at the breakpoints as values. See the
 * adjust method for details.
 */
class TableBasedAdjuster: public Adjuster {
private:
    std::map<float, float> breakpoints;

public:
    /**
     * Adds a breakpoint and the associated value of the
     * function to the table. (3 points)
     */
    TableBasedAdjuster& addBreakpoint(float x, float y);

    /**
     * If map breakpoints is empty, returns the value
     * unmodified. Else calculates an adjusted value (a)
     * from the given un-adjusted value (u) passed as
     * argument and the breakpoints with their associated
     * values in the map (bp) as follows (remember that
     * keys in a map are sorted):
     *
     * * Let k_min be the key in bp with the smallest value
     *   and k_max be the key with the largest value. Let the
     *   value associated with any key k_n be v_n.
     *
     * * If u <= k_min then a = v_min - (k_min - u)
     *
     * * If u >= k_max then a = v_max + (u - k_max)
     *
     * * For any two adjacent keys k_n and k_(n+1):
     *   If k_n < u <= k_(n+1) then
     *     a = (u - k_n) / (k_(n+1) - k_n) * (v_(n+1) - v_n) + v_n
     *
     * An example for a function with points (-1, -0,5)
     * and (2, 1) is shown in the exam paper.
     *
     * (15 points)
     */
    virtual float adjust(float value) const;
};

#endif /* TABLEBASEDADJUSTER_H_ */
