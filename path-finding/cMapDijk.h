#pragma once
#include <vector>
#include <queue>
#include <utility>

using std::vector;
using std::priority_queue;
using std::pair;

using position_type = pair<int, int>;

static constexpr position_type empty_pos = std::make_pair(-1, -1);

//CELL의 높이는 0~10으로 잡자
struct cCellDijk
{
    bool is_wall;
    int height;

    bool is_visit;
    int min_distance;
    position_type last_cell;

    cCellDijk()
        :is_wall(false), height(3), is_visit(false), min_distance(0x7fffffff), last_cell(empty_pos)
    {
    }

    void Reset_Dijk_Value()
    {
        is_visit = false;
        min_distance = 0x7fffffff;
        last_cell = empty_pos;
    }
};

struct dijk_queue
{
    int distance;
    position_type target;

    dijk_queue(int d, const position_type& t)
        :distance(d), target(t)
    {
    }

    bool operator<(const dijk_queue& _other) const
    {
        return _other.distance < distance;
    }
};

class cMapDijk
{
public:
    static constexpr int CELL_SIZE = 50;

    HBRUSH wall_brush;
    HBRUSH select_brush;
    HBRUSH target_brush;
    HBRUSH now_dijk_brush;
    vector<HBRUSH> height_brushes;
    vector<HBRUSH> visited_height_brushes;

    vector<vector<cCellDijk>> cell_table;

    position_type find_start;
    position_type find_end;
    
    bool is_find_start;
    int remain_loop_count;

    priority_queue<dijk_queue> dijk_open;
public:
    cMapDijk();
    ~cMapDijk();

    void Init();
    void Release();
    //마우스 입력을 받아서 높이를 높이거나, 벽을 만든다.
    void Update();
    void Render(HDC hdc);

    void Update_Find();
    void Update_Input();

    position_type GetCursorIdx();
    bool IsVaildCursorIdx(const position_type& pt);

    void AddOpenList(position_type now_pos, int now_distance, int now_height, int y, int x);
};

