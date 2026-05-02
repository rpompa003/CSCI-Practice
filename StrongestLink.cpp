/***************************************
The Strongest Link
Author: Rafael Pompa
Date Completed: 4/8/2026
Description: This program would print out the numbers of questions you got correct in a row.
***************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include "LinkedList.hpp"

using namespace std;

//making a question class to store one question and its answers
class Question
{
public:
string Askingquestion;
string answer1;
string answer2;
string answer3;
string answer4;
int correctIndex;

//making a constructor to initializes all variables
Question(string q, string option1, string option2, string option3, string option4, int index)
{
Askingquestion = q;
answer1 = option1;
answer2 = option2;
answer3 = option3;
answer4 = option4;
correctIndex = index;
}

// returning the question prompt
string getPrompt()
{
return Askingquestion;
}

// returns answer option based on index (0–3)
string getAnswerOptionByIndex(int index)
{
if (index == 0) return answer1;
if (index == 1) return answer2;
if (index == 2) return answer3;
if (index == 3) return answer4;

return "";
}

// returning correct answer index
int getCorrectAnswerIndex()
{
return correctIndex;
}
};

// Function that reads the file and fills linked list
bool populateQuestionListFromFile(LinkedList<Question> &list)
{
ifstream inFile("SampleQuestions.txt");

// checking if file opened correctly
if (!inFile.is_open())
return false;

string line;
string fullLine;

// Reading the file
while (getline(inFile, line))
{
fullLine += line;

//
if (fullLine.find(';') != string::npos)
{
stringstream ss(fullLine);
array<string, 6> questionData;

// Parse question data
getline(ss, questionData.at(0), ';');
getline(ss, questionData.at(1), ';');
getline(ss, questionData.at(2), ';');
getline(ss, questionData.at(3), ';');
getline(ss, questionData.at(4), ';');
getline(ss, questionData.at(5), ';');

string Index = questionData.at(1);

//   Convert index to int
if (!Index.empty())
{
stringstream indexStream(Index);
int index;

if (indexStream >> index)
{
index = index - 1; // convert to 0-based

// creating a new question object
Question newQuestion(
questionData.at(0),
questionData.at(2),
questionData.at(3),
questionData.at(4),
questionData.at(5),
index);

// adding to linked list
list.pushBack(newQuestion);
}
}

fullLine.clear();
}
}

inFile.close();
return true;
}

int main()
{
LinkedList<Question> questions;

// loading questions
bool loaded = populateQuestionListFromFile(questions);

// if it didn't load correctly
if (!loaded)
{
cout << "Error loading file." << endl;
return 0;
}

cout << "Welcome to The Strongest Link!" << endl << endl;

// setting up the variables
int questionNumber = 1;
int currentStreak = 0;
int bestStreak = 0;

// creating a iterator
LinkedList<Question>::Iterator iter = questions.generateIterator();

// Looping through questions
while (iter.hasNext())
{
Question current = *(iter.current());

// Displaying the questions
cout << "Question " << questionNumber << ":" << endl;
cout << current.getPrompt() << endl << endl;

// Displaying answer options
for (int i = 0; i < 4; i++)
{
cout << i + 1 << ". " << current.getAnswerOptionByIndex(i) << endl;
}

cout << endl;
cout << "Enter answer number: ";

int userAnswer;
cin >> userAnswer;

//   Convert to 0-based index
int SampleQuestionAnswer = userAnswer - 1;

//   Check if correct using required function
if (SampleQuestionAnswer == current.getCorrectAnswerIndex())
{
cout << "Correct!" << endl << endl;
currentStreak++;

//   Update best streak
if (currentStreak > bestStreak)
bestStreak = currentStreak;
}
else
{
cout << "Incorrect!" << endl << endl;
currentStreak = 0;
}

//   Move to next question
iter.next();
questionNumber++;
}

// outpuing the final result
cout << "Your strongest link was " << bestStreak
<< " correctly answered question(s) in a row. Thanks for playing!" << endl;

return 0;
}