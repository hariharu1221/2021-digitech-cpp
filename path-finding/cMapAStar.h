#pragma once
#include <vector>

using std::vector;

//CELL의 높이는 0~10으로 잡자
struct cCellAStar
{
    bool is_wall;
    int height;

    cCellAStar()
        :is_wall(false), height(5)
    {
    }
};

class cMapAStar
{
public:
    static constexpr int CELL_SIZE = 50;

    HBRUSH wall_brush;
    vector<HBRUSH> height_brushes;

    vector<vector<cCellAStar>> cell_table;
public:
    cMapAStar();
    ~cMapAStar();

    void Init();
    void Release();
    //마우스 입력을 받아서 높이를 높이거나, 벽을 만든다.
    void Update();
    void Render(HDC hdc);
};

