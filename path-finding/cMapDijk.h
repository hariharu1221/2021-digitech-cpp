#pragma once
#include <vector>

using std::vector;

//CELL의 높이는 0~10으로 잡자
struct cCellDijk
{
    bool is_wall;
    int height;

    cCellDijk()
        :is_wall(false), height(5)
    {
    }
};

class cMapDijk
{
public:
    static constexpr int CELL_SIZE = 50;

    HBRUSH wall_brush;
    vector<HBRUSH> height_brushes;

    vector<vector<cCellDijk>> cell_table;
public:
    cMapDijk();
    ~cMapDijk();

    void Init();
    void Release();
    //마우스 입력을 받아서 높이를 높이거나, 벽을 만든다.
    void Update();
    void Render(HDC hdc);
};

