#include "pch.h"
#include "cMap.h"

cMap::cMap()
    :cell_table(WINSIZEY / CELL_SIZE, vector<cCell>(WINSIZEX / CELL_SIZE)), wall_brush(nullptr)
{
}

cMap::~cMap()
{
}

void cMap::Init()
{
    //벽 색깔은 검정색
    wall_brush = CreateSolidBrush(RGB(0, 0, 0));
    height_brushes.resize(11);
    //i가 작으면 초록색, 높으면 주황색을 띄는 색깔을 만든다.
    for (int i = 0; i < 11; ++i)
        height_brushes[i] = CreateSolidBrush(RGB(20 * i, 0x99, 0));
}

void cMap::Release()
{
    DeleteObject(wall_brush);
    for (auto iter : height_brushes)
        DeleteObject(iter);
}

void cMap::Update()
{
    if (g_KeyManager.IsOnceKeyDown(VK_LBUTTON))
    {
        POINT mouse_pos;
        GetCursorPos(&mouse_pos);
        ScreenToClient(hWnd, &mouse_pos);

        int y_idx = mouse_pos.y / CELL_SIZE;
        int x_idx = mouse_pos.x / CELL_SIZE;

        if(y_idx >= 0 && y_idx < cell_table.size() && x_idx >= 0 && x_idx < cell_table[0].size())
            cell_table[y_idx][x_idx].is_wall = !cell_table[y_idx][x_idx].is_wall;
    }
}

void cMap::Render(HDC hdc)
{
    for (int i = 0; i < cell_table.size(); ++i)
    {
        for (int j = 0; j < cell_table[0].size(); ++j)
        {
            auto& target_cell = cell_table[i][j];
            if (target_cell.is_wall)
                SelectObject(hdc, wall_brush);
            else
                SelectObject(hdc, height_brushes[target_cell.height]);

            Rectangle(hdc, j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE);
        }
    }
}