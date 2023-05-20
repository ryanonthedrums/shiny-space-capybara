#include "q1.hpp"

// double sumScores(const Student *ptr);

Student *makeStudent(int N)
{
	ifstream ifs;
	int i = 0;
	ifs.open("grades.txt");
	Student *ptr = new Student[N];
	while (ifs >> (ptr + i)->first >> (ptr + i)->last >> (ptr + i)->ssn)
	{
		for (int sci = 0; sci < SCN; sci++)
		{
			ifs >> (ptr + i)->score.sc[sci];
		}
		ifs >> (ptr + i)->score.grade;
		i += 1;
	}
	ifs.close();

	return ptr;
}

void printStudent(Student *ptr, int N)
{
	double sctemp1;
	cout << "******************* Student Information ******************** \n";
	for (int i = 0; i < N; i++)
	{
		sctemp1 = 0;
		cout << setw(20) << right << (ptr + i)->first << "\t" << setw(20) << left << (ptr + i)->last << "\t" << (ptr + i)->ssn << "\t ";
		for (int j = 0; j < SCN; j++)
		{

			cout << (ptr + i)->score.sc[j] << "\t";
			sctemp1 += (ptr + i)->score.sc[j];
		}
		cout << (ptr + i)->score.grade << "\t\t\t\t";
		cout << sctemp1 << "\t";
		cout << endl;
	}
}
void sortStudent(Student *ptr, int N, string field, int asc)
{
    // int i, j;
    // for (i = 0; i < N - 1; i++)
    //     for (j = 0; j < N - i - 1; j++)
    //         if (sumScores(ptr[j]) > sumScores(ptr[j + 1]))
    //             swap(ptr[j], ptr[j + 1]);
}

double sumScores(const Student *ptr)
{
	// double sum = 0;
	// for (int i = 0; i < SCN; i++) {
    //     sum += ptr.scores[i];
    // }
    // return sum;
}
