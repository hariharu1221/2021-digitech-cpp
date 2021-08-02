#pragma once
#include "cMap.h"
class cMainGame final
{
private:
    cMap map;
public:
    void Init();
    void Release();
    void Update();
    void Render(HDC hdc);
};

