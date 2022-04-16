#include "renderd7.hpp"

#include "Board.hpp"

#include "exporter.hpp"
//hack renderd7 max obj limit;
extern int cobj___;

int size = 1;

int main()
{
    //hack renderd7 max obj limit;
    cobj___ = 15500; //3ds cant load more objects
    //Init with patched value. To patch you need to call the cobj___ before init!
    RenderD7::Init::Main("Paint-3ds");
    Paint::Board board(100, 100);
    
    std::vector<int> v;
    
    while(RenderD7::MainLoop())
    {
        touchPosition t;
        if (d7_hDown & KEY_UP) size ++;
        if ((size > 1 && d7_hDown & KEY_DOWN)) size --;
        if (d7_hDown & KEY_START) RenderD7::ExitApp();
        if (d7_hDown & KEY_SELECT) Export(board.GetBoard(), 100, 100);
        board.SetScale(size);
        hidTouchRead(&t);
        if ((t.px > 5 && t.py > 5)) board.DrawDot(t.px, t.py);
        RenderD7::OnScreen(Bottom);
        board.Draw();
        RenderD7::OnScreen(Top);
        RenderD7::DrawText(0, 0, 0.7f, C2D_Color32(255, 255, 255, 255), RenderD7::GetFramerate());
        RenderD7::DrawText(0, 30, 0.7f, C2D_Color32(255, 255, 255, 255), std::to_string(board.D_VectorSize()) + "/" + std::to_string((int)v.max_size()));
        RenderD7::DrawText(0, 50, 0.7f, C2D_Color32(255, 255, 255, 255), "CPU: " + std::to_string(C3D_GetProcessingTime()*6.0f) + "/" + std::to_string(C3D_GetProcessingTime()));
        RenderD7::DrawText(0, 70, 0.7f, C2D_Color32(255, 255, 255, 255), "GPU: " + std::to_string(C3D_GetDrawingTime()*6.0f) + "/" + std::to_string(C3D_GetDrawingTime()));
        
        //RenderD7::DrawMetrikOvl();
        RenderD7::FrameEnd();
    }
    RenderD7::Exit::Main();
}
