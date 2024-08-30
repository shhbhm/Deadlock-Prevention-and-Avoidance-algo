#include<bits/stdc++.h>
using namespace std;

void calculate_safe_state();
void initialize_process();

int alloc[10][3], req[10][3], max_res[10][3], avail[10][3];
int process_count, available[3];
bool executed[10], is_safe;

int main () {
	int continue_execution = 1;
	cout << "enter the number of processes: ";
	cin >> process_count;
	cout << "\n";
	cout << "enter the available resources: ";
	cin >> available[0] >> available[1] >> available[2];

	for (int i = 0; i < process_count; ++i)
	{
		cout << "\n\n\t\tprocess p" << i + 1 << " details\n";
		cout << "enter allocation: ";
		cin >> alloc[i][0] >> alloc[i][1] >> alloc[i][2];
		cout << "enter maximum resource demand: ";
		cin >> max_res[i][0] >> max_res[i][1] >> max_res[i][2];
		req[i][0] = max_res[i][0] - alloc[i][0];
		req[i][1] = max_res[i][1] - alloc[i][1];
		req[i][2] = max_res[i][2] - alloc[i][2];
	}

	cout << "\n\n\t\tresource allocation table\n\n";
	cout << "available resources: " << available[0] << " " << available[1] << " " << available[2] << "\n\n";
	cout << "process    max    allocation    need\n";
	for (int i = 0; i < process_count; ++i)
	{
		cout << "  p" << i + 1 << "    ";
		cout << "  " << max_res[i][0] << " " << max_res[i][1] << " " << max_res[i][2] << "     ";
		cout << " " << alloc[i][0] << " " << alloc[i][1] << " " << alloc[i][2] << "     ";
		cout << " " << req[i][0] << " " << req[i][1] << " " << req[i][2];
		cout << "\n";
	}
	cout << "\n\n";

	calculate_safe_state();

	while (continue_execution) {
		int choice, process_no;
		cout << "\n\nchoose an option:\n\n";
		cout << "1. change max resource demand of a process\n";
		cout << "2. change resource allocation of a process\n";
		cout << "3. change available resources\n";
		cout << "4. exit\n\n";
		cin >> choice;

		if (choice == 1) {
			cout << "\n\nenter process number: ";
			cin >> process_no;
			cout << "\nenter new maximum resource demand: ";
			cin >> max_res[process_no - 1][0] >> max_res[process_no - 1][1] >> max_res[process_no - 1][2];
		}
		else if (choice == 2) {
			cout << "\n\nenter process number: ";
			cin >> process_no;
			cout << "\nenter new allocation: ";
			cin >> alloc[process_no - 1][0] >> alloc[process_no - 1][1] >> alloc[process_no - 1][2];
		}
		else if (choice == 3) {
			cout << "\nenter available resources: ";
			cin >> available[0] >> available[1] >> available[2];
		}
		else {
			break;
		}

		calculate_safe_state();
	}

	return 0;
}

void calculate_safe_state() {
	initialize_process();
	int i, j;

	for (i = 0; i < process_count; ++i)
	{
		for (j = 0; j < process_count; ++j)
		{
			while (executed[j] && j < process_count - 1) {
				j++;
			}

			if (req[j][0] <= available[0] && req[j][1] <= available[1] && req[j][2] <= available[2]) {
				if (!executed[j]) {
					executed[j] = true;
					available[0] += alloc[j][0];
					available[1] += alloc[j][1];
					available[2] += alloc[j][2];
					cout << "\nprocess p" << j + 1;
					cout << "\navailable resources: " << available[0] << " " << available[1] << " " << available[2] << "\n";
					cout << "\nprocess executed without deadlock";
					is_safe = true;
					break;
				}
			}
		}

		if (!is_safe) {
			cout << "\n\t\t\tdeadlock detected\n\n";
			break;
		} else {
			is_safe = false;
		}
	}
}

void initialize_process() {
	is_safe = false;
	for (int i = 0; i < 10; ++i) {
		executed[i] = false;
	}
}
