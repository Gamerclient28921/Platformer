#pragma once

enum class ScreenType : uint8_t
{
    GameScreen = 0
};

class Screen
{
private:
    Font font;
public:
    ScreenType type;
    bool renderDebugMenu;
    
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
        position.x = (float)x;
        position.y = (float)y;
        
        DrawTextEx(this->font, text, position, size, 1, color);
    }
};
