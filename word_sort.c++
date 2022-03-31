#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<long long> s;

	int n, i, twin;
	long long x, cnt;
	twin = 0;
	cnt = 0;
	cin >> n;

	cin >> x;
	s.push(x);

	for (i = 1; i < n; i++) {
		cin >> x;
		if (s.top() > x) {
			cnt++;
			s.push(x);
		}
		else {
			while (!s.empty()) {
				if (s.top() > x) {
					s.push(x);
					break;
				}
				else if (s.top() == x) {
					s.push(x);
					twin++;
					cnt--;
				}
				cnt++;
				s.pop();
			}
			if (s.empty()) s.push(x);
			else cnt++;
		}
	}
	cout << cnt;
}

//3015