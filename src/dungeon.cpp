#include "dungeon.hpp"

Dungeon::Dungeon( olc::PixelGameEngine* engine )
	: mEngine(engine)
{
	srand( time( NULL ) );
    // Generate a dungeon
    // Loosely follows the algorithm in section 3.3 "Agent Based Growing"
    // http://pcgbook.com/wp-content/uploads/chapter03.pdf

    struct Room
    {
        int x, y, w, h;
    };

    auto randomRoom = []( int x, int y )
    { return new Room{ x, y, (rand() % 7) + 3, (rand() % 7) + 3 }; };

    std::vector<olc::vi2d> tiles;

    // Starting at 0,0
    int directionChance = 5;
    int roomChance = 5;
    int dungeonMinSize = 5000;

    struct Agent
    {
        // 0 up 1 right 2 down 3 left
        int x, y, direction;
    };

    Agent* agent = new Agent();
    agent->x = 0; agent->y = 0;
    agent->direction = rand() % 4;

    auto addTile = [&]( int x, int y ) {
        for ( auto i : tiles )
            if ( i.x == x && i.y == y )
                return;
        tiles.push_back( { x, y } );
    };

    addTile( 0, 0 );

    while ( tiles.size() < dungeonMinSize )
    {
        switch ( agent->direction )
        {
        case 0: agent->y -= 1; break;
        case 1: agent->x += 1; break;
        case 2: agent->y += 1; break;
        case 3: agent->x -= 1; break;
        }
        addTile( agent->x, agent->y );

        if ( rand() % 200 < directionChance )
        {
            agent->direction = rand() % 4;
            directionChance = 0;
        }
        else
        {
            directionChance += 5;
        }

        if ( rand() % 300 < roomChance )
        {
            Room* room = randomRoom( agent->x, agent->y );
            for ( int x = room->x; x < room->w + room->x; x++ )
                for ( int y = room->y; y < room->h + room->y; y++ )
                    addTile( x, y );
            delete room;
            roomChance = 0;
        }
        else
        {
            roomChance += 5;
        }
    }

    for ( auto& tile : tiles )
    {
        auto DoesTileExist = [&]( olc::vi2d tile )
        {
            return std::find( tiles.begin(), tiles.end(), tile ) != tiles.end();
        };

        mWorld.push_back( { tile } );
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
