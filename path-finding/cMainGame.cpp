#include "pch.h"
#include "cMainGame.h"

void cMainGame::Init()
{
    map.Init();
}

void cMainGame::Release()
{
    map.Release();
}

void cMainGame::Update()
{
    g_KeyManager.Update();
    map.Update();
}

void cMainGame::Render(HDC hdc)
{
    map.Render(hdc);
}
