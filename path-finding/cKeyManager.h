#pragma once
#include <array>

using std::array;

class cKeyManager
{
private:
    array<bool, 256> last_state;
    array<bool, 256> now_state;

public:
    cKeyManager();
    void Update();
    bool IsOnceKeyDown(int key);
    bool IsOnceKeyUp(int key);
    bool IsNowKeyDown(int key);
};

