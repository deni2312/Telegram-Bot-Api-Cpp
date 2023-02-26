#pragma once
#include <string>
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


//This object describes the position on faces where a mask should be placed by default.
struct MaskPosition{
	std::string point;
	float x_shift;
	float y_shift;
	float scale;
};

