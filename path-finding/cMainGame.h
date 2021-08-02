#pragma once
#include "cMapDijk.h"
class cMainGame final
{
private:
    cMapDijk map;
public:
    void Init();
    void Release();
    void Update();
    void Render(HDC hdc);
};

