#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Info {
	int num, fixArr, res, fix;
};

struct compareFix {
	bool operator()(const Info& a, const Info& b)
	{
		// 1. 먼저 정비에 도착한 고객부터
		if (a.fixArr > b.fixArr) return true;

		// 2. 동시에 왔으면 접수 창구번호 낮은 고객부터
		if (a.fixArr == b.fixArr && a.res > b.res) return true;

		return false;
	}
};

int N, M, K, A, B;

// 접수 창구 시간
int resTime[10];

// 정비 창구 시간
int fixTime[10];

// 고객 방문 시간
vector<int> Time[10001];

// 현재 창구 확인
int nowRes[10];
int nowFix[10];

// 진행시간 확인
int workRes[10];
int workFix[10];

// 고객 정보 저장
Info Clients[1100];

queue<Info> resQ;
priority_queue<Info, vector<Info>, compareFix> fixPQ;

void init()
{
	for (int i = 0; i < 1001; i++) Time[i].clear();
}

void input()
{
	cin >> N >> M >> K >> A >> B;

	// 접수 창구
	for (int i = 1; i <= N; i++) cin >> resTime[i];

	// 정비 창구
	for (int i = 1; i <= M; i++) cin >> fixTime[i];

	// 고객 도착
	for (int i = 1; i <= K; i++)
	{
		int arrTime;
		cin >> arrTime;

		Clients[i].num = i;

 		Time[arrTime].push_back(i);
	}
}

void solve()
{
	int finished = 0;
	int nowTime = 0;

	while (finished != K) 
	{
		for (int i = 0; i < Time[nowTime].size(); i++)
		{
			resQ.push(Clients[Time[nowTime][i]]);
		}

		for (int i = 1; i <= N; i++)
		{
			if (nowRes[i] != 0) workRes[i]++;

			if (workRes[i] == resTime[i])
			{
				Clients[nowRes[i]].fixArr = nowTime;
				fixPQ.push(Clients[nowRes[i]]);
				nowRes[i] = 0;
				workRes[i] = 0;
			}
		}


		if (!resQ.empty()) {
			for (int i = 1; i <= N; i++)
			{
				if (nowRes[i] != 0) continue;

				if (nowRes[i] == 0)
				{
					nowRes[i] = resQ.front().num;
					Clients[resQ.front().num].res = i;
					resQ.pop();
				}

				if (resQ.empty()) break;
			}
		}

		for (int i = 1; i <= M; i++)
		{
			if (nowFix[i] != 0) workFix[i]++;

			if (workFix[i] == fixTime[i])
			{
				finished++;
				nowFix[i] = 0;
				workFix[i] = 0;
			}
		}

		if (!fixPQ.empty())
		{
			for (int i = 1; i <= M; i++)
			{
				if (nowFix[i] != 0) continue;

				if (nowFix[i] == 0)
				{
					nowFix[i] = fixPQ.top().num;
					Clients[fixPQ.top().num].fix = i;
					fixPQ.pop();
				}

				if (fixPQ.empty()) break;
			}
		}

		nowTime++;
	}

	int de = -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();

		solve();

		int ans = 0;

		for (int i = 1; i <= K; i++)
		{
			if (Clients[i].res == A && Clients[i].fix == B)
				ans += i;
		}

		if (ans == 0) ans = -1;

		cout << "#" << tc << " " << ans << "\n";
	}

}