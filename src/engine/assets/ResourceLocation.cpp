#include "ResourceLocation.h"

ResourceLocation::ResourceLocation(const char* path)
{
    this->rsc = LoadTexture(path);
    this->width  = this->rsc.width;
    this->height = this->rsc.height;
}


ResourceLocation::~ResourceLocation()
{
    UnloadTexture(this->rsc);
}

Texture2D ResourceLocation::getResource()
{
    return this->rsc;
}