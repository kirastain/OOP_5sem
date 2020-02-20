
#ifndef FDA_1_GROUP
#define FDA_1_GROUP

#include "FDA_Student.h"

using namespace std;
class Group
{

public:
	std::list<Student*>	group;

	int					add_student();
	void				print_list();
	void				read_file();
	void				print_list_file();
	int					clear_group(void);

};
#endif