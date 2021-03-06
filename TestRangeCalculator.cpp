#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "RangeCalculator.h"

//Test Driven Ranges

//passing test
TEST_CASE("Case for detecting number of continuous range in the reading array given") {
  int ChargingCurrentReadings[] = {3, 3, 5, 4, 10, 11, 12};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(NumberofContinuousRange(ChargingCurrentReadings, numOfCCReadings) == 2);
  
  //Failing test
  TEST_CASE("Case for detecting number of continuous range in the reading array given") {
  int ChargingCurrentReadings[] = {3, 3, 5, 4};
  int numOfCCReadings = sizeof(ChargingCurrentReadings) / sizeof(ChargingCurrentReadings[0]);
  REQUIRE(NumberofContinuousRange(ChargingCurrentReadings, numOfCCReadings) == 2);
