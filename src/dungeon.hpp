#pragma once

#include <vector>
#include <olcPixelGameEngine.h>

class Player;

struct Tile
{
	olc::vi2d Position;
	inline void Draw(olc::PixelGameEngine* target, olc::vf2d* targetCamera) // needs screen space modifiers or camera shit
	{
		target->FillRect( olc::vf2d{ static_cast<float>(Position.x * 10) + targetCamera->x,
									 static_cast<float>(Position.y * 10) + targetCamera->y },
						  { 10, 10 } );
	}
};

class Dungeon
{
public:
	Dungeon( olc::PixelGameEngine* engine );
	~Dungeon();

	void Update();
	void Draw(olc::vf2d* cameraPosition);

protected:
	olc::PixelGameEngine* mEngine;

private:
	const int mDungeonSize = 100;

	std::vector<Tile> mWorld;

	// Player* mPlayer;
};
