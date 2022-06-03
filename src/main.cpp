#include <iostream>

#define OLC_PGE_APPLICATION
#include <olcPixelGameEngine.h>

class Game : public olc::PixelGameEngine
{
public:
    Game()
    {

    }

    ~Game()
    {

    }

    bool OnUserCreate() override
    {
        return true;
    }

    bool OnUserUpdate( float fElapsedFrameTime ) override
    {
        Clear(olc::BLACK);

        DrawRect( { 100, 100 }, { 10, 10 }, olc::RED );

        return true;
    }

    bool OnUserDestroy() override
    {
        return true;
    }

};


int main(int* argc, char** argv) 
{
    Game aRogueLike;

    aRogueLike.Construct( 980, 720, 1, 1, false, false );
    aRogueLike.Start();

    return 0;
}
