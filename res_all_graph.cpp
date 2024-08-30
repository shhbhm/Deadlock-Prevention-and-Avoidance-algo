#include<iostream>
using namespace std;

int main()
{
    int res_matrix[6][6], proc_list[5];
    int res_check = 0, i, j, num_proc, rows, cols, deadlock_count = -1;

    cout << "resource allocation graph simulation using a 4x3 matrix\n";
    cout << "this setup has 4 processes and 3 types of resources\n";
    cout << "enter the number of processes: ";
    cin >> num_proc;

    cout << "enter process ids (0-4):\n";
    for (i = 0; i < num_proc; i++) {
        cin >> proc_list[i]; // enter process ids
    }

    cout << "enter the number of rows for the resource matrix: ";
    cin >> rows; // should be 4
    cout << "enter the number of columns for the resource matrix: ";
    cin >> cols; // should be 3

    cout << "enter the resource allocation matrix:\n";
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            cin >> res_matrix[i][j]; // populate the resource matrix
        }
    }

    cout << "process sequence:\n";
    for (i = 0; i < num_proc; i++) {
        cout << "p" << proc_list[i] << endl; // display process sequence
    }

    cout << "resource matrix and process ids:\n";
    cout << "A " << " B " << " C " << endl;
    for (i = 0; i < 1; i++) {
        for (j = 0; j < 1; j++) {
            cout << res_matrix[0][0] << "  " << res_matrix[0][1] << "  " << res_matrix[0][2] << "       <--   " << proc_list[0] << endl;
            cout << res_matrix[1][0] << "  " << res_matrix[1][1] << "  " << res_matrix[1][2] << "       <--   " << proc_list[1] << endl;
            cout << res_matrix[2][0] << "  " << res_matrix[2][1] << "  " << res_matrix[2][2] << "       <--   " << proc_list[2] << endl;
            cout << res_matrix[3][0] << "  " << res_matrix[3][1] << "  " << res_matrix[3][2] << "       <--   " << proc_list[3] << endl;
        }
    }

    cout << "check for potential resource competition or deadlock\n";
    cout << "enter a resource value to check for collision: ";
    cin >> res_check;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (res_check == res_matrix[i][j]) {
                cout << "resource match at [row][col]: " << i << " " << j << endl;
                deadlock_count += 1;
            }
        }
    }

    cout << "possible deadlock occurrences: " << deadlock_count << endl;
    return 0;
}
