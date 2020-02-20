#include "FDA_Student.h"



int		Student::naming()
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

void	Student::printing()
{
	cout << "Name: " << name << "\tAge: " << age << "\tIndex: " << index;
}

//input file  ifstream&)
void	Student::naming_file(string line)
{
	int i = 0;
	while (line[i] != '\t')
		i++;
	name = line.substr(0, i);
	line = line.substr(i + 1, line.length() - i - 1);
	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	age = stoi(line.substr(0, i));
	line = line.substr(i + 1, line.length() - i - 1);
	index = stof(line);

}

//output file ofstream&
void	Student::printing_file(ofstream* out)
{
	*out << name << "\t" << age << "\t" << index;
	*out << '\n';
}