#include "dungeon.hpp"

Dungeon::Dungeon( olc::PixelGameEngine* engine )
	: mEngine(engine)
{
	srand( time( NULL ) );

	for ( int dx = 0; dx < mDungeonSize; dx++ )
	for ( int dy = 0; dy < mDungeonSize; dy++ )
	{
		// 50% chance of tile spawning
		if ( (rand() % 2) == 1 )
		{
			mWorld.push_back( { { dx, dy } } );
		}
	}
}

Dungeon::~Dungeon()
{

}

void Dungeon::Update()
{

}

void Dungeon::Draw()
{
	for ( auto& tile : mWorld )
	{
		tile.Draw( mEngine );
	}
}
