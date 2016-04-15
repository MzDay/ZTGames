#pragma once
#include <random>
#include <string>

template<size_t Min = std::numeric_limits<size_t>::min(), size_t Max = std::numeric_limits<size_t>::max()>
class SeedBasedRandom {
public:
	 SeedBasedRandom(unsigned int seed) : rng{ seed } {}
	 SeedBasedRandom(std::string seed) : SeedBasedRandom{ stringToSeed(seed) } {}

public:
	 float getNext() {
		  return dist(rng);
	 }

private:
	 unsigned int stringToSeed(std::string seed) {
		  std::hash<std::string> hash;
		  return hash(seed);
	 }

private:
	 std::mt19937 rng;
	 std::uniform_real_distribution<float> dist{ Min, Max };
};