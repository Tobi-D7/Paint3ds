#include "renderd7.hpp"

#include "Board.hpp"

int main()
{
    RenderD7::Init::Main();
    Paint::Board board(48, 48);
    std::vector<int> v;
    
    while(RenderD7::MainLoop())
    {
        touchPosition t;
        hidTouchRead(&t);
        board.DrawDot(t.px, t.py);
        RenderD7::OnScreen(Bottom);
        board.Draw();
        RenderD7::OnScreen(Top);
        RenderD7::DrawText(0, 0, 0.7f, C2D_Color32(255, 255, 255, 255), RenderD7::GetFramerate());
        RenderD7::DrawText(0, 0, 0.7f, C2D_Color32(255, 255, 255, 255), std::to_stribg((int)v.max_size());
        C3D_FrameEnd(0);
    }
    RenderD7::Exit::Main();
}
