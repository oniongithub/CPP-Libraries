#pragma once
#include <vector>
#include <string>
#include <math.h>

# define M_PI 3.14159265358979323846

namespace circVectors {
	static inline std::vector<float> getCircumferencePos(float x, float y, float radius, float angle)
	{
		float currentAngle = angle * (M_PI / 180.0f);
		return { radius * (float)(cos(currentAngle)) + x, radius * (float)(sin(currentAngle)) + y };
	}
};
