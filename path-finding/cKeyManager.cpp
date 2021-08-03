#include "pch.h"
#include "cKeyManager.h"
#include <iostream>

cKeyManager::cKeyManager()
{
    last_state.fill(false);
    now_state.fill(false);
}

void cKeyManager::Update()
{
    last_state = now_state;
    for (int i = 0; i < 256; ++i)
    {
        now_state[i] = GetAsyncKeyState(i) & 0x8000;
    }
}

bool cKeyManager::IsOnceKeyDown(int key)
{
    return !last_state[key] && now_state[key];
}

bool cKeyManager::IsOnceKeyUp(int key)
{
    return last_state[key] && !now_state[key];
}

bool cKeyManager::IsNowKeyDown(int key)
{
    return now_state[key];
}
