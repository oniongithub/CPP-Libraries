#pragma once
#define ALLOW_CONSOLE_COLORS FALSE;

#include <string>
#include <vector>

#if ALLOW_CONSOLE_COLORS
#include <Windows.h>
#include "consoleColors.h"
#include <iostream>
#endif

namespace textParsing {
	static inline std::vector<int> parseIndexes(std::string text, std::string parseChar = "&") noexcept
	{
		std::vector<int> returnedIndexes;

		for (int i = 0; i < text.size(); i++) {
			if (text[i] == parseChar[0]) 
				returnedIndexes.push_back(i);
		}

		return returnedIndexes;
	}

#if ALLOW_CONSOLE_COLORS
	class ColorCode {
	public:
		std::string colorCode;
		std::string colorName;
		int r; int g; int b;
	};

	std::vector<ColorCode> parseColorCodes = {
		ColorCode{"0", "Black", 0, 0, 0},
		ColorCode{"1", "Dark Blue", 0, 0, 170},
		ColorCode{"2", "Dark Green", 0, 170, 0},
		ColorCode{"3", "Dark Aqua", 0, 170, 170},
		ColorCode{"4", "Dark Red", 170, 0, 0},
		ColorCode{"5", "Dark Purple", 170, 0, 170},
		ColorCode{"6", "Gold", 255, 170, 0},
		ColorCode{"7", "Gray", 170, 170, 170},
		ColorCode{"8", "Dark Gray", 85, 85, 85},
		ColorCode{"9", "Blue", 85, 85, 255},
		ColorCode{"a", "Green", 85, 255, 85},
		ColorCode{"b", "Aqua", 85, 255, 255},
		ColorCode{"c", "Red", 255, 85, 85},
		ColorCode{"d", "Light Purple", 255, 85, 255},
		ColorCode{"e", "Yellow", 255, 255, 85},
		ColorCode{"f", "White", 255, 255, 255},
	};

	static inline void consoleColorPrint(std::string text, std::string parseChar = "&") noexcept
	{
		auto parseLocations = parseIndexes(text, parseChar);

		for (int i = 0; i < parseLocations.size(); i++)
		{
			for (int f = 0; f < parseColorCodes.size(); f++)
			{
				if (text.size() >= parseLocations[i] + 1)
				{
					if (parseColorCodes[f].colorCode[0] == text[parseLocations[i] + 1])
					{
						conColors::setForeground(parseColorCodes[f].r, parseColorCodes[f].g, parseColorCodes[f].b, f);

						if (parseLocations.size() > i + 1) {
							std::cout << text.substr(parseLocations[i] + 2, parseLocations[i + 1] - (parseLocations[i] + 2));
						}
						else {
							std::cout << text.substr(parseLocations[i] + 2);
						}
					}
				}
			}
		}
	}
#endif
};
