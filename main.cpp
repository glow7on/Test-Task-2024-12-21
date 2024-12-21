#include <vector>
#include <functional>
#include <iostream>

#include "candle.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

//тест 1
bool BodyContains_ByDefaultPrice_ReturnsTrue()
{
  Candle candle(10, 25, 5, 20); //GreenCandle
  
  return (candle.body_contains(20) == true);
}

bool BodyContains_PriceOverParameters_ReturnsFalse()
{
  Candle candle(20, 25, 5, 10); //RedCandle
  
  return (candle.body_contains(30) == false);
}

bool BodyContains_CandleDoesNotExist_ReturnsFalse()
{
  Candle candle(20, 10, 10, 30); //DoesNotExist _open > _high, _low < _close
  
  return (candle.body_contains(0) == false);
}
//

void initTests()
{
  tests.push_back(BodyContains_ByDefaultPrice_ReturnsTrue);
  tests.push_back(BodyContains_PriceOverParameters_ReturnsFalse);
  tests.push_back(BodyContains_CandleDoesNotExist_ReturnsFalse);
  
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
