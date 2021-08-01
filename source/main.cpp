#include "renderd7.hpp"

#include "Board.hpp"

int main()
{
    RenderD7::Init::Main();
    Paint::Board board(48, 48);
    
    while(RenderD7::MainLoop())
    {
        RenderD7::OnScreen(Top);
        
        C3D_FrameEnd(0);
    }
    RenderD7::Exit::Main();
}
