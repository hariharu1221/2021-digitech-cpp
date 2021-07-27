#include <iostream>
#include <algorithm>
#include "cTimer.h"

using namespace std;

constexpr int loop_count = 10;
constexpr int insert_count = 100000;

#include <vector>
#include "cMyVector.h"
void vector_test()
{
    cTimer<double> timer;
    cMyVector<double> my_time_data(loop_count);
    double my_total_data = 0;

    for (int i = 0; i < loop_count; ++i)
    {
        timer.Play();
        cMyVector<int> cMyVec;
        for (int j = 0; j < insert_count; ++j)
            cMyVec.insert(0,j);

        my_time_data[i] = timer.Pause();
        my_total_data += my_time_data[i];
    }

    sort(my_time_data.begin(), my_time_data.end());
    cout << "직접 만든 벡터의 " << insert_count << "개 추가에 걸리는 시간" << endl;
    cout << "평균 소요 시간 : " << my_total_data / loop_count << "초\t";
    cout << "최소 소요 시간 : " << my_time_data[0] << "초\t";
    cout << "최대 소요 시간 : " << my_time_data[loop_count - 1] << "초" << endl;

    vector<double> stl_time_data(loop_count);
    double stl_total_data = 0;

    for (int i = 0; i < loop_count; ++i)
    {
        timer.Play();
        vector<int> cStlVec;
        for (int j = 0; j < insert_count; ++j)
            cStlVec.insert(cStlVec.begin(), j);

        stl_time_data[i] = timer.Pause();
        stl_total_data += stl_time_data[i];
    }

    sort(stl_time_data.begin(), stl_time_data.end());
    cout << "STL 벡터의 " << insert_count << "개 추가에 걸리는 시간" << endl;
    cout << "평균 소요 시간 : " << stl_total_data / loop_count << "초\t";
    cout << "최소 소요 시간 : " << stl_time_data[0] << "초\t";
    cout << "최대 소요 시간 : " << stl_time_data[loop_count - 1] << "초" << endl;
}

#include <list>
#include "cMyList.h"
void list_test()
{
    cTimer<double> timer;
    cMyVector<double> my_time_data(loop_count);
    double my_total_data = 0;

    for (int i = 0; i < loop_count; ++i)
    {
        timer.Play();
        cMyList<int> cMyList;
        for (int j = 0; j < insert_count; ++j)
            cMyList.push_front(j);

        my_time_data[i] = timer.Pause();
        my_total_data += my_time_data[i];
    }

    sort(my_time_data.begin(), my_time_data.end());
    cout << "직접 만든 리스트의 " << insert_count << "개 추가에 걸리는 시간" << endl;
    cout << "평균 소요 시간 : " << my_total_data / loop_count << "초\t";
    cout << "최소 소요 시간 : " << my_time_data[0] << "초\t";
    cout << "최대 소요 시간 : " << my_time_data[loop_count - 1] << "초" << endl;

    vector<double> stl_time_data(loop_count);
    double stl_total_data = 0;

    for (int i = 0; i < loop_count; ++i)
    {
        timer.Play();
        list<int> cStlList;
        for (int j = 0; j < insert_count; ++j)
            cStlList.push_front(j);

        stl_time_data[i] = timer.Pause();
        stl_total_data += stl_time_data[i];
    }

    sort(stl_time_data.begin(), stl_time_data.end());
    cout << "STL 리스트의 " << insert_count << "개 추가에 걸리는 시간" << endl;
    cout << "평균 소요 시간 : " << stl_total_data / loop_count << "초\t";
    cout << "최소 소요 시간 : " << stl_time_data[0] << "초\t";
    cout << "최대 소요 시간 : " << stl_time_data[loop_count - 1] << "초" << endl;
}

#include <set>
#include <unordered_set>
#include <algorithm>

//AVL Tree(이해나 구현은 쉽지만 성능이 아쉬운 자료구조)
//red-black Tree

//자가균형 이진트리들
//1234
//1
//  2
//      3
//          4

//AVL Tree (탐색속도는 확실한데... 넣고뺄때 속도가 좀 많이 아쉬움)
// 속도가 아쉬워서 안씀
// 1 2 3 4 5 6 7 8 9 10
//
//         4
//     2        8
//  1    3    6    9
//          5   7      10
//
//
// 가장 높은 차수가 가장 낮은 차수랑 2이상 차이나지 못하게

//red-black
// 검 빨 검 빨 검 빨 검 빨 (8)
// 검 검 검 검 (4)
// 검 빨 검 검 빨 검 (6)
//
// 가장 높은 차수가 가장 낮은 차수랑 2배이상 차이나지 못하게
// 어떻게? 빨강이 2연속으로 못나오게 만든다

void compare_data_structure()
{
    set<int> s;
}

int main()
{
    unordered_set<int> data;
    int arr[997] = {0};

    for (auto iter : { 312332, 7777, 79374, 14141, 818 })
    {
        arr[iter % 997] = iter;
    }

    cout << arr[773 % 997] << endl;

    return 0;
}