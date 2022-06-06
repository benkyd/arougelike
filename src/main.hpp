#pragma once

#include <olcPixelGameEngine.h>

class Engine
{
public:
	Engine( olc::PixelGameEngine engine )
		: engine( engine )
	{

	}

	static inline Engine& GetInstance()
	{
		static Engine instance;
		return instance;
	}

	olc::PixelGameEngine engine;

	Engine( Engine const& ) = delete;
	void operator=( Engine const& ) = delete;

protected:
	Singleton() = default;
};

