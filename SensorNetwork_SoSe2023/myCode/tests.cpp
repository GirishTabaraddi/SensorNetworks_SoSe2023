#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std;

#include "TestSensor.h"
#include "LinearAdjuster.h"
#include "TableBasedAdjuster.h"
#include "SensorNetwork.h"
#include "DuplicateSensorName.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Tests for the adjustor classes. (12 points)
 */
void adjusterTests() {

    /*
     * Values for subsequent tests.
     */
    float testValues[] = { -10, -1, 0, 1, 10 };

    /*
     * (1) Using the test values given above as samples, assert that a
     * NullAdjustor's adjust method returns the argument's value
     * unchanged.
     */
    // TODO
    NullAdjuster nulladj;

	for(float& x : testValues)
	{
//		cout << nulladj.adjust(x) << endl;

		assertTrue((nulladj.adjust(x) == x), "values are not same");
	}
    /*
     * (2) Using the test values given above as samples, assert that a
     * TableBasedAdjustor with a single breakpoint (0,0) returns
     * the same values as a NullAdjustor.
     */
    // TODO
	TableBasedAdjuster tableAdj;

	auto val = tableAdj.addBreakpoint(0,0);

	for(float& x : testValues)
	{
//		cout << "Expected: " << val.adjust(x) << " nullVal: " << nulladj.adjust(x) << endl;

		assertTrue((nulladj.adjust(x) == val.adjust(x)), "values are not same");
	}
    /*
     * (3) Using the test values given above as samples, assert that a
     * TableBasedAdjustor with breakpoints (-100,-110), (0,0)
     * and (100,90) returns the given expected values.
     *
     * Remember (from your basic C/C++ courses) that floating
     * point calculations do not always yield exact results
     * (rounding errors due to using the binary system).
     * Take this into account when checking the result.
     */
    float expected[] = { -11, -1.1, 0, 0.9, 9 };
    // TODO

	tableAdj.addBreakpoint(-100, -110);
	tableAdj.addBreakpoint(0, 0);
	tableAdj.addBreakpoint(100, 90);

	for(int i = 0; i < 5;  i++)
	{
		float result = tableAdj.adjust(testValues[i]);
//		cout << result << " " << expected[i] << endl;

		assertTrue((result >= expected[i] - 0.0001 && result <= expected[i] + 0.0001),
				"values are not same");
	}
}

/**
 * Tests for the sensor classes. (12 points)
 */
void sensorTests () {

    /*
     * Values for subsequent tests.
     */
    float testValues[] = { -10, -1, 0, 1, 10 };

    /*
     * (1) Using a TestSensor and the test values given above as samples,
     * assert that a (test) sensor with a NullAdjustor returns the raw
     * readings of a sensor as readings.
     */
    // TODO
    shared_ptr<Adjuster> nullAdjuster = NullAdjuster::sharedInstance;

    TestSensor test("test", nullAdjuster);

	for(float& x : testValues)
	{
		test.setRawReading(x);

		assertTrue((test.rawReading() == nullAdjuster.get()->adjust(x)),
				"values are not same");
	}

    /*
     * (2) Using a TestSensor and the test values given above as samples,
     * assert that a (test) sensor with a LinearAdjustor returns the
     * expected readings. Test with 10 differently configured
     * LinearAdjustors for each test value for exhaustive testing
     * (50 "assertTrue" invocations in total).
     */
    // TODO
	for(float& x : testValues)
	{
		for(int i = 0; i < 10; i++)
		{
			shared_ptr<Adjuster> testLinear =
					shared_ptr<LinearAdjuster>(new LinearAdjuster(1, i));

			TestSensor testL("test", testLinear);

			testL.setRawReading(x);

			float linAdjustedValue = testLinear->adjust(x);

			float expectedValue = x * 1 + i;

			assertTrue(linAdjustedValue == expectedValue, "values are not same");
		}
	}
}

/**
 * Tests for the sensor network. (16 points)
 */
void networkTests() {
    /*
     * Create a sensor network with 10 TestSensors named
     * "Thermometer n" (with n being the number of the thermometer)
     * that have their readings set to values 20 + n * 0.05.
     */
    // TODO
	SensorNetwork sensorNW;

	shared_ptr<Adjuster> nulladj = NullAdjuster::sharedInstance;

	for(int i = 1; i < 11; i++)
	{
		string name = "Thermometer" + to_string(i);

//		cout << name << endl;

		unique_ptr<TestSensor> sensors = make_unique<TestSensor>(name, nulladj);

		sensors->setRawReading(20+i*0.05);

		sensorNW.add(move(sensors));
	}
//	for(const auto& z : sensorNW.getSensors())
//	{
//		cout << z->getName() << endl;
//	}

    /*
     * (1) Assert that adding a sensor with a name that is already
     * used by a sensor in the network throws a DuplicateSensorName
     * exception with the sensor's name as "what".
     */
    // TODO
	unique_ptr<TestSensor> sensor = make_unique<TestSensor>("Thermometer10", nulladj);
//	sensorNW.add(move(sensor));
}

void allTests() {
    adjusterTests();
    sensorTests();
    networkTests();
}
