#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

class Student {
private:
	string name;
	vector<int> grades;
public:
	Student() {
		name = "";
	}
	Student(string name1, vector<int> grades1) {
		name = name1;
		for (unsigned int i = 0; i < grades1.size(); i++) {
			grades.push_back(grades1[i]);
		}
	}
	vector<int>& GetGrades() { //<----------
		return grades;
	}
	string GetName() {
		return name;
	}
	void SetGrades(vector<int>&v) {
		if(!v.empty()) {
			for (unsigned int i = 0; i < v.size(); i++) {
				grades.push_back(v[i]);
			}
		}
	}
	void SetName(string name1) {
		name = name1;
	}
	void AddGrade(int k) {
		grades.push_back(k);
	}
	double AverageGrade() { //find the average of all grades 
		double average=0.0;
		int sum = 0;
		for (unsigned int i = 0; i < grades.size(); i++) {
			sum =sum + grades[i];
		}
		average = (double) sum / grades.size();
		return average;
	}
	int CountGrades() { // counts the number of grades
		int counter = 0;
		for (unsigned int i = 0; i < grades.size(); i++) {
			counter++;
		}
		return counter;
	}
	bool DeleteGrade(int n) { //deletes all grades with value of n
		bool deleted = false;
		for (unsigned int i = 0; i < grades.size();) {
			if (grades[i] == n) {
				grades.erase(grades.begin() + i);
				deleted = true;
			}
			else
				i++;
		}
		return deleted;
	}
	bool IsGood() { // if the student doesnt have grade = 2 and his average grade is >=4.5
		bool bad_grade = false;
		for (unsigned int i = 0; i < grades.size(); i++) {
			if (grades[i] == 2) {
				bad_grade = true;
			}
		}
		if (this->AverageGrade()>= 4.50 ) {
			if (bad_grade == false) {
				return true;
			}
			else
				return false;
		}
		return false;
	}
	bool operator<=(Student& obj) {
		return this->AverageGrade() <= obj.AverageGrade();
	}
	void print() {
		cout << "Name: " << name << endl;
		cout << "Grades: " << endl;
		for (unsigned int i = 0; i < grades.size(); i++) {
			cout << i + 1 << ". " << grades[i] << endl;
		}
	}
	void print_vector_only() {
		cout << "\nGrades: " << endl;
		for (unsigned int i = 0; i < grades.size(); i++) {
			cout << i + 1 << ". " << grades[i] << endl;
		}
	}
	friend ostream& operator<<(ostream& ostr, const Student& obj) {
		ostr << obj.name << endl;
		for (unsigned int i = 0; i < obj.grades.size(); i++) {
			ostr << i + 1 << ". " << obj.grades[i] << endl;
		}
		return ostr;
	}
	friend istream& operator>>(istream& istr, Student& obj) {
		if (&istr == &cin) {
			int num;
			cout << "Input name: "; istr >> obj.name;
			cout << "Input grades separated by spaces(use a non integer value to stop the process): ";
			while (cin >> num) {
				obj.grades.push_back(num);
			}
		}
		else {
			istr >> obj.name;
		}
		return istr;
	}
	bool BadGrade() {
		bool bad_grade = false;
		for (unsigned int i = 0; i < grades.size(); i++) {
			if (grades[i] == 2) {
				bad_grade = true;
			}
		}
		return bad_grade;
	}
};



int main() {
	vector<int> first_vector = {3, 4, 6, 5, 5, 6};
	Student S1("Maria", first_vector);
	cout << "Student1" << endl;
	S1.print();
	//--------------------------------------------------------------------------------------------------------
	cout << "\nAverage grade of Studen1: " << S1.AverageGrade();
	//--------------------------------------------------------------------------------------------------------
	cout << "\nNumber of grades of Student1: " << S1.CountGrades();
	//--------------------------------------------------------------------------------------------------------
	if (S1.DeleteGrade(3)) {
		cout << "\nAfter deleting grades equal to 3 of Student1: "; 
		//S1.GetGrades(); cout << endl;
		S1.print_vector_only();
	}
	else
		cout << "\n Grades equal to 3 not found.";
	S1.AddGrade(3); // adding back the deleted grade
	//--------------------------------------------------------------------------------------------------------
	if (S1.IsGood()) {
		cout << "\nStudent1 average grade is greater than 4.50." << endl;
	}
	else
		cout << "\nStudent1 average grade isn't greater than 4.50" << endl;
	//--------------------------------------------------------------------------------------------------------
	cout << "Try oustream funcion for Student1: " << endl;
	cout << S1 << endl;
	//--------------------------------------------------------------------------------------------------------
	vector<int> second_vector = { 6, 6, 6, 5, 5, 6 };
	Student S2("Haki", second_vector);
	cout << "\nStudent2: " << endl;
	S2.print();
	if (S1 <= S2) {
		cout << "\nStudent2 avergae grade is higher than Student1." << endl;
	}
	else cout << "\nStudent1 average grade is higher than Student2." << endl;
	//--------------------------------------------------------------------------------------------------------
	vector<int> third_vector = { 3, 3, 5, 4, 4, 5 };
	vector<int> forth_vector = { 2, 2, 3, 5, 4, 4 };
	vector<int> fifth_vector = { 5, 6, 6, 4, 5, 5 };
	Student S3("Emil", third_vector);
	Student S4("Natali", forth_vector);
	Student S5("Ralica", fifth_vector);
	//--------------------------------------------------------------------------------------------------------
	list<Student> list_of_students = { S1, S2, S3, S4, S5 };
	cout << "\nList of Students: " << endl;
	for (auto i = list_of_students.cbegin(); i != list_of_students.end(); i++) {
		cout << *i << endl;
	}
	//--------------------------------------------------------------------------------------------------------
	int sum_of_list = 0;
	double average_of_list = 0.0;
	list<Student>::iterator itr = list_of_students.begin();
	for (unsigned int i = 0; i < list_of_students.size(); i++ ) {
		sum_of_list += (*itr).AverageGrade();
		itr++;
	}
	average_of_list = (double)sum_of_list / list_of_students.size(); 
	cout << "\nAverage grade of the list is: " << (double)average_of_list << endl; 
	//--------------------------------------------------------------------------------------------------------
	double max = 0.0;
	list<Student>::iterator itr1 = list_of_students.begin();
	for (auto const& i : list_of_students) {
		if ((*itr1).AverageGrade() > max) {
			max = (*itr1).AverageGrade();
		}
		itr1++;
	}
	list<Student>::iterator itr2 = list_of_students.begin();
	for (auto const& i : list_of_students) {
		if ((*itr2).AverageGrade()==max) {
			cout << "\nThe student with the highest grade is: ";
			cout << (*itr2).GetName();
		}
		itr2++;
	}
	//--------------------------------------------------------------------------------------------------------
	
	int counter_failed = 0;
	list<Student> failed;
	list<Student>::iterator itr3 = list_of_students.begin();
	list<Student>::iterator for_deletement;

	for (unsigned int i = 0; i < list_of_students.size(); i++) {
		if ((*itr3).BadGrade()) {
			counter_failed++;
			for_deletement = itr3;
			failed.push_back(*itr3);
			list_of_students.erase(for_deletement);
		}
		else{
			itr3++;
		}
	}
	cout << "\nThe number of stutdents who failed at atleast one subject is: " << counter_failed;
	cout << "\nList of failed students: " << endl;
	for (auto i = failed.cbegin(); i != failed.end(); i++) {
		cout << *i << endl;
	}
	//--------------------------------------------------------------------------------------------------------
	Student S6;
	cout << "Input data for Student6" << endl;
	cin >> S6;
	cout << "\nStudent6: " << endl;
	cout << S6;
	cout << "\n Student 6 grades: " << endl;
	S6.GetGrades();

	system("pause");
	return 0;
}