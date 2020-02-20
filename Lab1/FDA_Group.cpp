#include "FDA_Group.h"

//add a student
int		Group::add_student()
{
	Student* new_student = new Student();
	new_student->naming();
	//(*new_student).printing();
	group.push_back(new_student);
	//cout << "List length: " << group.size() << "\n";
	return (0);
}

//print the list
void	Group::print_list()
{
	if (!group.empty())
	{
		for (auto it = group.begin(); it != group.end(); it++)
		{
			if (*it != NULL)
			{
				Student* student = *it;
				student->printing();
			}
			cout << "\n";
		}
	}
}

//read the list from file
void	Group::read_file()
{
	string	file_path;
	string	line;

	file_path = "C:\\Users\\ASUS\\Desktop\\group2.txt";
	ifstream in(file_path);
	cout << "Write a path to your file:\n";
	//cin >> file_path;
	//in.open(file_path);
	if (in.is_open())
	{
		while (getline(in, line))
		{
			//cout << line << "\n";
			Student*	new_student = new Student;
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
void	Group::print_list_file()
{
	ofstream out("C:\\Users\\ASUS\\Desktop\\group2.txt");
	if (out.is_open())
	{
		for (auto& student: group)
		{
			student->printing_file(&out);
			cout << "\n";
		}
	}
}

//clear the list
int		Group::clear_group()
{
	for (auto& it : group)
	{
		delete it;
	}
	group.clear();
	
	return (0);
}