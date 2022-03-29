#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n;

	stack<pair<int, int>> s;

	cin >> x;
	s.push({ x,1 });

	for (int i = 2; i <= n; i++) {
		cin >> x;
		if (s.top().first > x) {
			s.push({ x, i });
		}
	}
}

// aewfawefasdf