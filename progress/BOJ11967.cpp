#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int dis[103][103];

vector<pair<int, int>> board[103][103];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void lighton()
{
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (pair<int, int> c : board[cur.first][cur.second])
        {
            dis[c.first][c.second] = 0;
            q.push(c);
        }
    }
}

int bfs()
{
    int ans = 0;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        cout << cur.first << ' ' << cur.second << '\n';
        ans++;
        q.pop();


        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx <= 0 || nx > n || ny <= 0 || ny > n)
                continue;
            if (dis[nx][ny] != 0)
                continue;

            dis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    return ans;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        fill(dis[i], dis[i] + n + 1, -1);
    }

    while (m--)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        board[x][y].push_back({a, b});
    }

    q.push({1, 1});
    lighton();
    q.push({1,1});
    int ans = bfs();

    cout << ans;
}