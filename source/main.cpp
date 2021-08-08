#include "renderd7.hpp"

#include "Board.hpp"

int size = 1;

int main()
{
    RenderD7::Init::Main();
    Paint::Board board(48, 48);
    std::vector<int> v;
    
    while(RenderD7::MainLoop())
    {
        touchPosition t;
        if (d7_hDown & KEY_UP) size ++;
        if ((size > 1 && d7_hDown & KEY_DOWN)) size --;
        if (d7_hDown & KEY_START) RenderD7::ExitApp();
        
        board.SetScale(size);
        hidTouchRead(&t);
        if ((t.px > 5 && t.py > 5)) board.DrawDot(t.px, t.py);
        RenderD7::OnScreen(Bottom);
        board.Draw();
        RenderD7::OnScreen(Top);
        RenderD7::DrawText(0, 0, 0.7f, C2D_Color32(255, 255, 255, 255), RenderD7::GetFramerate());
        RenderD7::DrawText(0, 30, 0.7f, C2D_Color32(255, 255, 255, 255), std::to_string(board.D_VectorSize()) + "/" + std::to_string((int)v.max_size()));
        for (int i = 0; i < 255; i++)
        {
             RenderD7::DrawRect(i, 55, i, 20, C2D_Color32((u8)i, 0, 0, 255));
             RenderD7::DrawRect(i, 85, i, 20, C2D_Color32(0, (u8)i, 0, 255));
             RenderD7::DrawRect(i, 115, i, 20, C2D_Color32(0, 0, (u8)i, 255));
        }
        C3D_FrameEnd(0);
    }
    RenderD7::Exit::Main();
}
