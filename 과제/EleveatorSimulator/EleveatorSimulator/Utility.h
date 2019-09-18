#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <vector>
#include <string.h>
#include <sstream>

#include "Content.h"

class Utility {
public:
	static std::vector<std::string> Split(std::string target, char cut) {
		std::vector<std::string> ret;
		std::stringstream ss(target);
		std::string temp;

		while (std::getline(ss, temp, cut)) {
			ret.push_back(temp);
		}
		return ret;
	}
	static int GetIndex4DoublePtr(const int size, int x, int y) {
		return size * y + x;
	}
	static int GetIndex4DoublePtr(const int size, const Point* point) {
		return size * point->y + point->x;
	}
	static int RandomRange(int min, int max) {
		return (int)(rand() % (max - min + 1)) + min;
	}
};

#endif