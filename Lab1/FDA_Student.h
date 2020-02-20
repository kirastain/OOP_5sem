
#ifndef FDA_1_STUDENT
#define FDA_1_STUDENT

#include <string>
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

	int		naming();
	void	printing();
	void	naming_file(string line);
	void	printing_file(ofstream* out);


};
#endif // !FDA_1_STUDENT
