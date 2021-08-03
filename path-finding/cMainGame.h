#pragma once
#include "cMapAStar.h"
#include "cMapDijk.h"
class cMainGame final
{
private:
    cMapAStar map;
public:
    void Init();
    void Release();
    void Update();
    void Render(HDC hdc);
};

