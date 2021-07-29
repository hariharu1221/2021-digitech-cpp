#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//set을 이용한 정렬 방법
void solve_by_set(int n)
{
    //이진탐색트리 (red-black tree를 이용한 정렬 방법이다)
    set<int> s;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    for (auto iter : s)
        cout << iter << "\n";
}

//multiset을 이용한 정렬 방법
void solve_by_multiset(int n)
{
    //multiset은 값의 중복을 허용한다.
    //그래서 1,5,3,1,4,3 같은 같은 값이 여러개 있어도 정렬이 가능하다.
    multiset<int> s;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    for (auto iter : s)
        cout << iter << "\n";
}

//priority queue (우선순위 큐)를 이용한 구현 방법
void solve_by_priority_queue(int n)
{
    //아래 힙소트에서 priority_queue의 내부 구현을 파악할수 있다.
    //C++에서의 priority_queue는 내부에 vector를 가지고 있기 때문에
    //미리 할당해둔 vector를 사용해, 여러번 vector가 확장되는것을 막는다.
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    //기본적으로 priority_queue는 큰 수부터 반환하기 때문에
    //작은수를 먼저 반환해야하는 지금의 상황에서는
    //기본으로 적용되어있는 less<int>대신 greater<int>를 사용한다.
    priority_queue<int, vector<int>, greater<int>> q(greater<int>(), v);

    while (!q.empty())
    {
        cout << q.top() << "\n";
        q.pop();
    }
}

//counting sort (카운팅 소트)를 이용한 구현 방법
void solve_by_counting_sort(int n)
{
    //다른 정렬방법들과 달리 약간 독특하다.
    //들어올 수 있는 숫자의 크기가 크지 않거나, 들어오는 범위가 제한적일 경우
    //모든 들어온 숫자의 수를 센다음, 작은 숫자부터 출력하는 방식이다.

    //상황에 따라 메모리와 속도를 모두 잡을수 있는 정렬 방법이기도 하다.
    //대신 string과 같은 자료형이나 float형등, 정수형의 인덱스로 표현할수 없는 경우에는
    //counting_sort를 사용할 수 없다.

    //이와 비슷한 아이디어로 만들어진 자료구조를 hash_table이라 생각해볼 수도 있다.
    constexpr int count_n = 10000;
    vector<int> count(count_n + 1);

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        ++count[temp];
    }

    for (int i = 1; i <= count_n; ++i)
    {
        //count[i]에 저장된 개수만큼 i를 출력
        for (int j = 0; j < count[i]; ++j)
            cout << i << "\n";
    }
}

//bubble sort(버블정렬)로 정렬하기
void solve_by_bubble_sort(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = n - 1; i > 0; --i)
    {
        //버블정렬은 가장 큰 숫자가 뒤로 가게 정렬하는 방법이다.
        //마치 물속에 있는 기포가 위로 떠오르듯이 큰 숫자가 위로 올라온다 해서 붙은 이름이다.

        //코드 구현이 제일 간단하고 직관적이라 자주 설명하지만 실 성능은 거의 나락
        for (int j = 0; j < i; ++j)
        {
            if (v[j] < v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

//selection sort(선택정렬)로 정렬하기
void solve_by_selection_sort(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n - 1; ++i)
    {
        //선택정렬은 앞에서 부터 순서대로
        //이미 정렬된 숫자를 제외한 수 중에서 가장 작은 숫자가 현재 인덱스에 오게 하는 정렬 방법이다.
        int min_val = v[i];
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (min_val > v[j])
            {
                min_val = v[j];
                min_idx = j;
            }
        }
        swap(v[i], v[min_idx]);
    }
}

//insertion sort(삽입정렬)로 정렬하기
void solve_by_insertion_sort(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 1; i < n - 1; ++i)
    {
        //삽입 정렬은 가장 작은 데이터가 앞에 오게 만드는 정렬 방식이다.
        //정렬되지 않은 인덱스를 기준으로 뒤로 검사해가면서, 본인보다 작은 데이터가 있으면 앞으로 옮긴다.
        int target = v[i];
        int j = i - 1; //j가 밖에 있는 이유는 v[i]가 들어갈 위치를 저장해두기 위함

        //v[i]가 들어가야할 위치를 찾는다
        for (; j >= 0 && v[j] > target; --j)
            v[j + 1] = v[j];

        v[j + 1] = target;
    }
}

void quick_sort(vector<int>& v, int s, int e)
{
    if (s + 1 > e)
        return;

    int target = v[s];
    int l = s + 1;
    int r = e;

    do
    {
        //l이 target보다 큰 순간까지 반복
        while (l <= r && v[l] < target)
            ++l;
        //r이 target보다 작은 순간까지 반복
        while (r >= l && v[r] > target)
            --r;
        //l < r이 아닌 상황이면, 반복문을 탈출할 때가 되었기 때문에 탈출 시켜야 함
        if(l < r)
            swap(v[l], v[r]);
    } while (l < r);

    swap(v[s], v[r]);
    quick_sort(v, s, r - 1);
    quick_sort(v, r + 1, e);
}

void solve_by_quick_sort(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    quick_sort(v, 0, n - 1);

    for (auto iter : v)
        cout << iter << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    solve_by_quick_sort(n);
}