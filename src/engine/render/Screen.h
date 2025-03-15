#pragma once

enum class ScreenType : int
{
    GameScreen = 0,
    MenuScreen,
};

class Screen
{
private:
    Font font;
    Screen* previouseScreen;
public:
    ScreenType type;
    bool renderDebugMenu;
    float windowWidth =  1280.f;
    float windowHeight = 720.f;
    
    void render();

    Screen(const Font& font)
    {
        init(font);
    }
    
    void init(const Font& Font)
    {
        this->font = Font;
    }
    
    void DrawText(const char* text, int x, int y, float size, Color color)
    {
        Vector2 position;
        position.x = static_cast<float>(x);
        position.y = static_cast<float>(y);
        
        DrawTextEx(this->font, text, position, size, 1, color);
    }
};
