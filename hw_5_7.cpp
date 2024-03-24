#include <iostream>

using namespace std;

int main() {
    int gradesCount[6] = { 0 }; // 初始化一个大小为6的数组，所有元素初始值为0
    int grade;

    cout << "Enter grades for each student (0-5). Enter a negative number to finish:" << endl;
    while (true) {
        cin >> grade;
        if (grade < 0) {
            // 当输入一个负数时结束循环
            break;
        }
        if (grade >= 0 && grade <= 5) {
            // 有效成绩，增加对应成绩的计数
            gradesCount[grade]++;
        }
        else {
            cout << "Invalid grade. Please enter a number between 0 and 5." << endl;
        }
    }

    // 输出直方图
    cout << "\nGrade histogram:" << endl;
    for (int i = 0; i < 6; ++i) {
        cout << gradesCount[i] << " grade(s) of " << i << endl;
    }

    return 0;
}
