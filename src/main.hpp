#pragma once

#include <olcPixelGameEngine.h>

class Engine
{
public:
	Engine( olc::PixelGameEngine engine )
		: pge()
	{

	}

	static inline Engine& GetInstance()
	{
		static Engine instance;
		return instance;
	}

	olc::PixelGameEngine pge;

	Engine( Engine const& ) = delete;
	void operator=( Engine const& ) = delete;

protected:
	Engine() = default;
};

