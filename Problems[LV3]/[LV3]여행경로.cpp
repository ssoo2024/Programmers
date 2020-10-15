#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer;
bool findAll = false;
vector<vector<string>> temp;

void find(vector<vector<string>> tickets, string from, int count) {
	if (count == tickets.size()) {
		answer.push_back(from);
		temp.push_back(answer);
		answer.pop_back();
		return;
	}
	for (int i = 0; i < tickets.size(); i++) {
		if ((from == "0" && tickets[i][0] == "ICN") || (tickets[i][2] != "0" && tickets[i][0] == from)) {
			tickets[i][2] = "0";
			answer.push_back(tickets[i][0]);
			find(tickets, tickets[i][1], count + 1);
			answer.pop_back();
			tickets[i][2] = "1";
		}
	}
}
vector<string> solution(vector<vector<string>> tickets) {
	for (int i = 0; i < tickets.size(); i++)
		tickets[i].push_back("1");

	sort(tickets.begin(), tickets.end());
	find(tickets, "0", 0);

	return temp[0];
}