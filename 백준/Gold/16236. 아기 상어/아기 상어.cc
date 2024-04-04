#include <iostream>
#include <queue>

using namespace std;

int arr[21][21];
bool visited[21][21];
int n;

int s_y;
int s_x;
int s_size=2;
int ate;
int ans;

int dy[4] = {-1,0,0,1};
int dx[4] = {0,-1,1,0};

bool bfs();

int main(void)
{
    cin >> n;

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin >> arr[i][j];
            if(arr[i][j]==9)
            {
                s_y = i;
                s_x = j;
                arr[i][j] = 0;
            }
        }
    }

    while(1)
    {
        if(!bfs())
            break;
    }
    cout << ans << "\n";
}

bool bfs()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            visited[i][j] = false;
        }
    }

    int fy=n;
    int fx=n;
    int fd = 6000;
    queue<pair<pair<int, int>, int > > q;
    q.push({{s_y,s_x},0});
    visited[s_y][s_x] = true;
    while(!q.empty())
    {
        auto iter = q.front();
        int cy = iter.first.first;
        int cx = iter.first.second;
        int cd = iter.second;
        if(cd >= fd)
        {
            s_y = fy;
            s_x = fx;
            ans += fd;
            ++ate;
            if(ate == s_size)
            {
                ate = 0;
                ++s_size;
            }
            arr[fy][fx] = 0;
            return true;
        }
        q.pop();
        for(int i=0; i<4; ++i)
        {
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=n || visited[ny][nx]==true || arr[ny][nx] > s_size)
                continue;
            visited[ny][nx]=true;
            if(arr[ny][nx]>0 && arr[ny][nx] < s_size)
            {
                if(fd>=cd+1)
                {
                    fd = cd+1;
                    if(fy>=ny)
                    {
                        if(fy == ny)
                        {
                            if(fx >=nx)
                                fx = nx;
                        }
                        else
                        {
                            fy = ny;
                            fx = nx;
                        }
                    }
                }
                //s_y = ny;
                //s_x = nx;
                //ans += cd+1;
                //cout << "y:" << s_y << ", x:" << s_x << endl;
                //return true;
            }
            q.push({{ny,nx},cd+1});
        }
    }
    return false;
}