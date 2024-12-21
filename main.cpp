#include <vector>
#include <functional>
#include <iostream>

#include "candle.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

//Check valid candle
bool CandleExist(Candle& candle)
{
  return (candle.open < candle.high &&
   candle.low < candle.close &&
   candle.low < candle.high);
}

bool BodyContains_ByDefaultPrice_ReturnsTrue()
{
  Candle candle(10, 25, 5, 20); //GreenCandle
  
  return ((candle.body_contains(20) && CandleExist(candle)) == true);
}
bool BodyContains_PriceOverParameters_ReturnsFalse()
{
  Candle candle(20, 25, 5, 10); //RedCandle

  return ((candle.body_contains(30) && CandleExist(candle)) == false);
}
bool BodyContains_CandleDoesNotExist_ReturnsFalse()
{
  Candle candle(20, 10, 10, 30); //Does not exist candle _open > _high, _low < _close

  return ((candle.body_contains(0) && CandleExist(candle)) == false);
}


bool Contains_ByDefaultPrice_ReturnsTrue()
{
  Candle candle(10, 25, 5, 20);
  
  return ((candle.contains(20) && CandleExist(candle)) == true);
}
bool Contains_PriceOverParameters_ReturnsFalse()
{
  Candle candle(20, 25, 5, 10);
  
  return ((candle.contains(30) && CandleExist(candle)) == false);
}
bool Contains_ZeroCandle_ReturnsFalse()
{
  Candle candle(0, 0, 0, 0);

  return ((candle.contains(0) && CandleExist(candle)) == false);
}


bool full_size_ByGreenCandle_ReturnsTrue()
{
  Candle candle(10, 25, 5, 20); //GreenCandle

  return ((candle.full_size() > 0 && CandleExist(candle)) == true);
}
bool full_size_ByRedCandle_ReturnsTrue()
{
  Candle candle(20, 25, 5, 10); //RedCandle

  return ((candle.full_size() > 0 && CandleExist(candle)) == true);
}
bool full_size_ZeroCandle_ReturnsFalse()
{
  Candle candle(0, 0, 0, 0); //Does not exist candle

  return ((candle.full_size() > 0 && CandleExist(candle)) == false);
}


bool body_size_ByGreenCandle_ReturnsFalse()
{
  Candle candle(10, 25, 5, 20); //GreenCandle

  return ((candle.body_size() > 0 && CandleExist(candle)) == true);
}
bool body_size_ByRedCandle_ReturnsFalse()
{
  Candle candle(20, 25, 5, 10); //RedCandle

  return ((candle.body_size() > 0 && CandleExist(candle)) == true);
}
bool body_size_ZeroCandle_ReturnsFalse()
{
  Candle candle(0, 0, 0, 0); //Does not exist candle

  return ((candle.body_size() > 0 && CandleExist(candle)) == false);
}


void initTests()
{
  tests.push_back(BodyContains_ByDefaultPrice_ReturnsTrue);
  tests.push_back(BodyContains_PriceOverParameters_ReturnsFalse);
  tests.push_back(BodyContains_CandleDoesNotExist_ReturnsFalse);

  tests.push_back(Contains_ByDefaultPrice_ReturnsTrue);
  tests.push_back(Contains_PriceOverParameters_ReturnsFalse);
  tests.push_back(Contains_ZeroCandle_ReturnsFalse);

  tests.push_back(full_size_ByGreenCandle_ReturnsTrue);
  tests.push_back(full_size_ByRedCandle_ReturnsTrue);
  tests.push_back(full_size_ZeroCandle_ReturnsFalse);
  
  tests.push_back(body_size_ByGreenCandle_ReturnsFalse);
  tests.push_back(body_size_ByRedCandle_ReturnsFalse);
  tests.push_back(body_size_ZeroCandle_ReturnsFalse);

}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}
