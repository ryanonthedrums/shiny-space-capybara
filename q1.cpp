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
********************************************************************************************************

#include "q1.hpp"

double sumScores(const Student &ptr);
void sortStudent(Student *ptr, int N, bool (*comp)(const Student &s1, const Student &s2));

Student *makeStudent(int N) {
	ifstream ifs;
	int i = 0;
	ifs.open("grades.txt");
	Student *ptr = new Student[N];
	while (ifs >> (ptr + i)->first >> (ptr + i)->last >> (ptr + i)->ssn) {
		for (int sci = 0; sci < SCN; sci++) {
			ifs >> (ptr + i)->score.sc[sci];
		}
		ifs >> (ptr + i)->score.grade;
		i += 1;
	}
	ifs.close();

	return ptr;
}

void printStudent(Student *ptr, int N) {
	double sctemp1;
	cout << "******************* Student Information ******************** \n";
	for (int i = 0; i < N; i++) {
		sctemp1 = 0;
		cout << setw(20) << right << (ptr + i)->first << "\t" << setw(20) << left << (ptr + i)->last << "\t" << (ptr + i)->ssn << "\t ";
		for (int j = 0; j < SCN; j++) {

			cout << (ptr + i)->score.sc[j] << "\t";
			sctemp1 += (ptr + i)->score.sc[j];
		}
		cout << (ptr + i)->score.grade << "\t\t\t\t";
		cout << sctemp1 << "\t";
		cout << endl;
	}
}

bool compFirstNameAsc(const Student &s1, const Student &s2) {
	return s1.first < s2.first;
}

bool compFirstNameDesc(const Student &s1, const Student &s2) {
	return s1.first > s2.first;
}

bool compNameAsc(const Student &s1, const Student &s2) {
	if (s1.last == s2.last) {
		return s1.first < s2.first;
	}
	return s1.last < s2.last;
}

bool compNameDesc(const Student &s1, const Student &s2) {
	if (s1.last == s2.last) {
		return s1.first > s2.first;
	}
	return s1.last > s2.last;
}

bool compScoreAsc(const Student &s1, const Student &s2) {
	return sumScores(s1) < sumScores(s2);
}

bool compScoreDesc(const Student &s1, const Student &s2) {
	return sumScores(s1) > sumScores(s2);
}

void sortStudent(Student *ptr, int N, string field, int asc) {
	if (field == "first") {
		if (asc) {
			sortStudent(ptr, N, compFirstNameAsc);
		} else {
			sortStudent(ptr, N, compFirstNameDesc);
		}
	} else if (field == "name") {
		if (asc) {
			sortStudent(ptr, N, compNameAsc);
		} else {
			sortStudent(ptr, N, compNameDesc);
		}
	} else if (field == "score") {
		if (asc) {
			sortStudent(ptr, N, compScoreAsc);
		} else {
			sortStudent(ptr, N, compScoreDesc);
		}
	}
}

double sumScores(const Student &ptr) {
	double sum = 0;
	for (int i = 0; i < SCN; i++) {
		sum += ptr.score.sc[i];
	}
	return sum;
}

void sortStudent(Student *ptr, int N, bool (*comp)(const Student &s1, const Student &s2)) {
	int i, j;
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - i - 1; j++)
			if (comp(ptr[j + 1], ptr[j]))
				swap(ptr[j], ptr[j + 1]);
}

// ptr[j]   the same as *(ptr + j)
// bool (*comp)(const Student &s1, const Student &s2)




*******************************************************************************************************************

#include "q1.hpp"

double sumScores(const Student &ptr);
void sortStudent(Student *ptr, int N, bool (*comp)(const Student &s1, const Student &s2));

Student *makeStudent(int N) {
	ifstream ifs;
	int i = 0;
	ifs.open("grades.txt");
	Student *ptr = new Student[N];
	while (ifs >> (ptr + i)->first >> (ptr + i)->last >> (ptr + i)->ssn) {
		for (int sci = 0; sci < SCN; sci++) {
			ifs >> (ptr + i)->score.sc[sci];
		}
		ifs >> (ptr + i)->score.grade;
		i += 1;
	}
	ifs.close();

	return ptr;
}

void printStudent(Student *ptr, int N) {
	double sctemp1;
	cout << "******************* Student Information ******************** \n";
	for (int i = 0; i < N; i++) {
		sctemp1 = 0;
		cout << setw(20) << right << (ptr + i)->first << "\t" << setw(20) << left << (ptr + i)->last << "\t" << (ptr + i)->ssn << "\t ";
		for (int j = 0; j < SCN; j++) {

			cout << (ptr + i)->score.sc[j] << "\t";
			sctemp1 += (ptr + i)->score.sc[j];
		}
		cout << (ptr + i)->score.grade << "\t\t\t\t";
		cout << sctemp1 << "\t";
		cout << endl;
	}
}

// bool compFirstNameAsc(const Student &s1, const Student &s2) {
// 	return s1.first < s2.first;
// }

// bool compFirstNameDesc(const Student &s1, const Student &s2) {
// 	return s1.first > s2.first;
// }

// bool compNameAsc(const Student &s1, const Student &s2) {
// 	if (s1.last == s2.last) {
// 		return s1.first < s2.first;
// 	}
// 	return s1.last < s2.last;
// }

// bool compNameDesc(const Student &s1, const Student &s2) {
// 	if (s1.last == s2.last) {
// 		return s1.first > s2.first;
// 	}
// 	return s1.last > s2.last;
// }

// bool compScoreAsc(const Student &s1, const Student &s2) {
// 	return sumScores(s1) < sumScores(s2);
// }

// bool compScoreDesc(const Student &s1, const Student &s2) {
// 	return sumScores(s1) > sumScores(s2);
// }

// void sortStudent(Student *ptr, int N, string field, int asc) {
// 	if (field == "first") {
// 		if (asc) {
// 			sortStudent(ptr, N, compFirstNameAsc);
// 		} else {
// 			sortStudent(ptr, N, compFirstNameDesc);
// 		}
// 	} else if (field == "name") {
// 		if (asc) {
// 			sortStudent(ptr, N, compNameAsc);
// 		} else {
// 			sortStudent(ptr, N, compNameDesc);
// 		}
// 	} else if (field == "score") {
// 		if (asc) {
// 			sortStudent(ptr, N, compScoreAsc);
// 		} else {
// 			sortStudent(ptr, N, compScoreDesc);
// 		}
// 	}
// }

double sumScores(const Student &ptr) {
	double sum = 0;
	for (int i = 0; i < SCN; i++) {
		sum += ptr.score.sc[i];
	}
	return sum;
}

// Using function pointers
// void sortStudent(Student *ptr, int N, bool (*comp)(const Student &s1, const Student &s2)) {
// 	int i, j;
// 	for (i = 0; i < N - 1; i++)
// 		for (j = 0; j < N - i - 1; j++)
// 			if (comp(ptr[j + 1], ptr[j]))
// 				swap(ptr[j], ptr[j + 1]);
// }

// bool hasSmallerAsciiName(const Student &s1, const Student &s2) {
// 	if (s1.last == s2.last) {
// 		return s1.first < s2.first;
// 	}
// 	return s1.last < s2.last;
// }

string fullName(const Student &s) {
	return s.last + " " + s.first;
}

void sortScoreAsc(Student *ptr, int N) {
	int i, j;
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - i - 1; j++)
			if (sumScores(ptr[j]) > sumScores(ptr[j + 1]))
				swap(ptr[j], ptr[j + 1]);
}

void sortScoreDesc(Student *ptr, int N) {
	int i, j;
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - i - 1; j++)
			if (sumScores(ptr[j]) < sumScores(ptr[j + 1]))
				swap(ptr[j], ptr[j + 1]);
}

void sortNameAsc(Student *ptr, int N) {
	int i, j;
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - i - 1; j++)
			if (fullName(ptr[j]) > fullName(ptr[j + 1]))
				swap(ptr[j], ptr[j + 1]);
}

void sortNameDesc(Student *ptr, int N) {
	int i, j;
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - i - 1; j++)
			if (fullName(ptr[j]) < fullName(ptr[j + 1]))
				swap(ptr[j], ptr[j + 1]);
}

// void sortFirstNameAsc(Student *ptr, int N) {
// 	int i, j;
// 	for (i = 0; i < N - 1; i++)
// 		for (j = 0; j < N - i - 1; j++)
// 			if (ptr[j].first > ptr[j + 1].first)
// 				swap(ptr[j], ptr[j + 1]);
// }

// void sortFirstNameDesc(Student *ptr, int N) {
// 	int i, j;
// 	for (i = 0; i < N - 1; i++)
// 		for (j = 0; j < N - i - 1; j++)
// 			if (ptr[j].first < ptr[j + 1].first)
// 				swap(ptr[j], ptr[j + 1]);
// }

void sortStudent(Student *ptr, int N, string field, int asc) {
	if (field == "name") {
		if (asc) {
			sortNameAsc(ptr, N);
		} else {
			sortNameDesc(ptr, N);
		}
	} else if (field == "score") {
		if (asc) {
			sortScoreAsc(ptr, N);
		} else {
			sortScoreDesc(ptr, N);
		}
	} // else if (field == "firstname") {
	// 	if (asc) {
	// 		sortFirstNameAsc(ptr, N);
	// 	} else {
	// 		sortFirstNameDesc(ptr, N);
	// 	}
	// }
}


// ptr[j]   the same as *(ptr + j)
// bool (*comp)(const Student &s1, const Student &s2)