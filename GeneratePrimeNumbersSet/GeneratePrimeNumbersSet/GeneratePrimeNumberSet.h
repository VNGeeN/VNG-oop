#pragma once

#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>

std::set<int> FindPrimeNumbers(std::vector<bool> const& primeNumber, int theLimitOfplurality);
std::set<int> GeneratePrimeNumbersSet(int theLimitOfplurality);
void WritePrimeNumbersInOutput(std::set<int> const& primeNumbers);