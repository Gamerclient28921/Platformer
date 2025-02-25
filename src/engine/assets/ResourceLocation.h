#pragma once
#include <string>
#include <__msvc_filebuf.hpp>
#include <raylib.h>

class ResourceLocation
{
private:
    Texture2D rsc;
public:
    int width;
    int height;

    ResourceLocation(const char*);
    ~ResourceLocation();


    Texture2D getResource();
};
