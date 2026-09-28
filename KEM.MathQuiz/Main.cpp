#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string QuizPath = "C:\\Temp\\Quiz.txt";
    string AnswersPath = "C:\\Temp\\QuizResults.txt";
	string line;

    vector<string> question;

	ifstream ifs(QuizPath);
    while (getline(ifs, line))
    {
		question.push_back(line);
    }
	ifs.close();

    srand(time(NULL));

	ofstream ofs(AnswersPath);

    for (int i = 0; i < 3; i++)
    {
        int randomNumber = rand() % 9 + 1;

        cout <<"Question " <<  i + 1 << ": " <<  question[randomNumber] << " = "<< "\n";
		cout << "Enter your answer:";
        int answer;
        cin >> answer;
        ofs << question[randomNumber] << " = " << answer << "\n";
        cout << "\n";
    }
    ofs.close();
    cout << "Results Saved to QuizResults.txt ";

    (void)_getch();
    return 0;
}