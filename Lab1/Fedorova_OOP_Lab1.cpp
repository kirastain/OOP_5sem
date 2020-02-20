// Fedorova_OOP_Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*#include <string>
#include <iostream>
#include <stdio.h>
#include <list>
#include <fstream>

using namespace std;

class Student
{

public:
	string	name;
	int		age = 0;
	float	index = -1;

	int		naming()
	{
		cout << "Name: ";
		cin >> name;
		while (age <= 0 || age >= 99)
		{
			cout << "Age: ";
			cin >> age;
		}
		while (index < 0 || index > 5)
		{
			cout << "Index: ";
			cin >> index;
		}
		return (0);
	}

	void	printing()
	{
		cout << "Name: " << name << "\tAge: " << age << "\tIndex: " << index;
	}

	//input file  ifstream&)
	void	naming_file(string line)
	{
		int i = 0;
		while (line[i] != '\t')
			i++;
		name = line.substr(0, i);
		line = line.substr(i+1, line.length() - i - 1);
		i = 0;
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		age = stoi(line.substr(0, i));
		line = line.substr(i+1, line.length() - i - 1);
		index = stof(line);

	}

	//output file ofstream&
	void	printing_file(ofstream *out)
	{
		*out << "Name: " << name << "\tAge: " << age << "\tIndex: " << index;
		*out << '\n';
	}
};

class Group
{

public:
	std::list<Student*> group;

	//add a student
	int		add_student()
	{
		Student* new_student = new Student();
		(*new_student).naming();
		//(*new_student).printing();
		group.push_back(new_student);
		//cout << "List length: " << group.size() << "\n";
		return (0);
	}

	//print the list
	void	print_list()
	{
		if (!group.empty())
		{
			for (list<Student*>::iterator it = group.begin(); it != group.end(); it++)
			{
				Student student = **it;
				student.printing();
				cout << "\n";
			}
		}
	}

	//read the list from file
	void read_file()
	{
		string file_path;
		string line;
		file_path = "C:\\Users\\ASUS\\Desktop\\group1.txt";
		ifstream in(file_path);
		cout << "Write a path to your file:\n";
		//cin >> file_path;
		//in.open(file_path);
		if (in.is_open())
		{
			while (getline(in, line))
			{
				//cout << line << "\n";
				Student* new_student = new Student;
				(*new_student).naming_file(line);
				group.push_back(new_student);
			}
		}
		else
		{
			cout << "File error\n";
		}
	}

	//add the list to the file
	void print_list_file()
	{
		ofstream out("C:\\Users\\ASUS\\Desktop\\group2.txt");
		if (out.is_open())
		{
			for (list<Student*>::iterator it = group.begin(); it != group.end(); it++)
			{
				Student student = **it;
				student.printing_file(&out);
				cout << "\n";
			}
		}
	}

	//clear the list
	int		clear_group(void)
	{
		group.clear();
		/*for (list<Student*>::iterator it = group.begin(); it != group.end(); it++)
		{
			//group.erase(it);
		} */
		/*return (0);
	}
};*/

#include "FDA_Group.h"

using namespace std;

int main()
{
	int i = -1;
	Group group;

	while (i != 0)
	{
		cout << "Choose option: " << "\n" <<
			"1. Add a student\n" <<
			"2. Print the list of students\n" <<
			"3. Read a group list from a file\n" <<
			"4. Write the list in a file\n" <<
			"9. Clear the list\n" <<
			"0. Exit\n\n";
		cin >> i;

		switch (i) {
		case 1:
			group.add_student();
			//group.print_list();
			break;
		case 2:
			group.print_list();
			break;
		case 3:
			group.read_file();
			break;
		case 4:
			group.print_list_file();
			break;
		case 9:
			group.clear_group();
			break;
		default:
			cout << "Incorrent input. Try again.\n";
		}
		cout << "\n";
		

	}
	return (0);
}
