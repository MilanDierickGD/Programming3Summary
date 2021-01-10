#pragma once
#include <string>

struct Float3f
{
	float X, Y, Z;
};

struct TeleportLocation
{
	bool IsActive;
	float X, Y, Z;
};

struct NPC
{
	std::string Name;
	float X, Y, Z;
};