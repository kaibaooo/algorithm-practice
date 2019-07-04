// n = number of jobs
// s = start time of each job
// t = end time of each job

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int main() {
	int n = 0;
	int* s = NULL;
	int* t = NULL;
	P* data = NULL;
	cin >> n;
	s = (int*)malloc(sizeof(int) * n);
	t = (int*)malloc(sizeof(int) * n);
	data = (P*)malloc(sizeof(P) * n);
	for(int i = 0;i<n;i++) {
		cin >> s[i] >> t[i];
		data[i].first = t[i];
		data[i].second = s[i];
	}
	sort(data, data + n);
	int ans = 0;
	int currentT = 0;
	for (int i = 0; i < n; i++) {
		if (currentT < data[i].second) {
			ans++;
			currentT = data[i].first;
		}
	}
	cout << ans << endl;

	return 0;
}
