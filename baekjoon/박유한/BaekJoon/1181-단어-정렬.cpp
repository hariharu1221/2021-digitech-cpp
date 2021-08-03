//풀이1
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

struct string_compare
{
    bool operator()(const string& s1, const string& s2) const
    {
        if (s1.size() != s2.size())
            return s1.size() < s2.size();
        return s1 < s2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<string, string_compare> s;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;

        s.insert(str);
    }

    for (auto& iter : s)
        cout << iter << "\n";

    return 0;
}

//풀이2
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    stable_sort(s.begin(), s.end(), [](const string& s1, const string& s2) {
        if (s1.size() != s2.size())
            return s1.size() < s2.size();
        return s1 < s2;
    });

    s.erase(unique(s.begin(), s.end()), s.end());

    for (auto& iter : s)
        cout << iter << "\n";

    return 0;
}
*/

//풀이3
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    stable_sort(s.begin(), s.end());
    stable_sort(s.begin(), s.end(), [](const string& s1, const string& s2) {
        return s1.size() < s2.size();
        });

    s.erase(unique(s.begin(), s.end()), s.end());

    for (auto& iter : s)
        cout << iter << "\n";

    return 0;
}
*/