#pragma once

#include <vector>
#include <olcPixelGameEngine.h>

class Player;

struct Tile
{
	olc::vi2d Position;
	inline void Draw(olc::PixelGameEngine* target) // needs screen space modifiers or camera shit
	{
		target->FillRect( Position * 10, { 10, 10 } );
	}
};

class Dungeon
{
public:
	Dungeon( olc::PixelGameEngine* engine );
	~Dungeon();

	void Update();
	void Draw();

protected:
	olc::PixelGameEngine* mEngine;

private:
	const int mDungeonSize = 100;

	std::vector<Tile> mWorld;

	// Player* mPlayer;
};
