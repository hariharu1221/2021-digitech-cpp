#pragma once
#include <vector>
#include <queue>
#include <utility>

using std::vector;
using std::priority_queue;
using std::pair;

using position_type = pair<int, int>;

static constexpr position_type empty_astar_pos = std::make_pair(-1, -1);

//CELL의 높이는 0~5로 잡자
struct cCellAStar
{
    bool is_wall;
    int height;

    bool is_visit;
    position_type last_cell;

    int f;
    int g;
    int h;

    cCellAStar()
        :is_wall(false), height(3), f(0x7fffffff), g(0x3fffffff), h(0x3fffffff), is_visit(false), last_cell(empty_astar_pos)
    {
    }

    void Reset_AStar_Value()
    {
        is_visit = false;
        last_cell = empty_astar_pos;

        f = 0x7fffffff;
        g = 0x3fffffff;
        h = 0x3fffffff;
    }
};

struct AStar_queue
{
    int f;
    position_type target;

    AStar_queue(int _f, const position_type& t)
        :f(_f), target(t)
    {
    }

    bool operator<(const AStar_queue& _other) const
    {
        return _other.f < f;
    }
};

class cMapAStar
{
public:
    static constexpr int CELL_SIZE = 50;

    HBRUSH wall_brush;
    HBRUSH select_brush;
    HBRUSH target_brush;
    HBRUSH now_AStar_brush;
    vector<HBRUSH> height_brushes;
    vector<HBRUSH> visited_height_brushes;

    vector<vector<cCellAStar>> cell_table;

    position_type find_start;
    position_type find_end;

    bool is_find_start;
    int remain_loop_count;

    priority_queue<AStar_queue> AStar_open;
public:
    cMapAStar();
    ~cMapAStar();

    void Init();
    void Release();
    //마우스 입력을 받아서 높이를 높이거나, 벽을 만든다.
    void Update();
    void Render(HDC hdc);

    void Update_Find();
    void Update_Input();

    position_type GetCursorIdx();
    bool IsVaildCursorIdx(const position_type& pt);

    void AddOpenList(position_type now_pos, int now_g, int now_height, int y, int x);
};

