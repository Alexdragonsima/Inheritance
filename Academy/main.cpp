#include<iostream>
#include<string>
using namespace std;

#define delimiter "\n---------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this -> last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	//				Constructors
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//				methods:
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << endl;
	}
};

#define STUDENTS_TAKE_PARAMETERS  const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENTS_GIVE_PARAMETERS  speciality, group, rating, attendance

class Student : public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//					constructors

	Student	(HUMAN_TAKE_PARAMETERS,STUDENTS_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	Student(const Human& human,STUDENTS_TAKE_PARAMETERS) :Human(human)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;

	}
	~Student()
	{
		cout << "SDestructor\t" << this << endl;
	}

	//					methods

	void print()const override
	{
		Human::print();				//������ ����� ������� �������� ����� � ��������
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality,int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher :public Human
{
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	//				constructors

	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor\t" << this << endl;
	}

	//				methods

	void print()const override
	{
		Human::print();
		cout << speciality << " " << experience << " years" << endl;
	}
};

#define GRADUATE_TAKE_PARAMETRS const std::string& subject
#define GRADUATE_GIVE_PARAMETRS subject

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	//					constructor;
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENTS_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETRS) :Student(HUMAN_GIVE_PARAMETERS, STUDENTS_GIVE_PARAMETERS)
	{
		this->subject = subject;
		cout << "GConstructor:\t" << this << endl;
	}
	Graduate(const Student& student,const std::string& subject) :Student(student)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//						methods

	void print()const override
	{
		Student::print();
		cout << subject << endl;
	}
};

//#define INHERITANCE_1
//#define INHERITANCE_2

#define POLYMORPHISM

void main()
{
	setlocale(LC_ALL, "");

	cout << "HelloAcademy" << endl;
#ifdef INHERITANCE_1
	Human human(" Richter", " Jeffrey", 40);
	human.print();
	cout << delimiter << endl;


	Student student(" Pinkman", " Jessie", 20, " Chemistry", " WW_220", 95, 90);
	student.print();
	cout << delimiter << endl;

	Teacher teacher(" White", " Walter", 50, "Chemistry", 25);
	teacher.print();
	cout << delimiter << endl;

	Graduate graduate("Schrider", "Hank", 40, "Criminalistic", "OBN", 50, 70, "How to catch Heisenberg");
	graduate.print();
	cout << delimiter << endl;

#endif // INHERITANCE_1
#ifdef INHERITANCE_2

	Human human("Vercetty", "Tommy", 30);
	human.print();
	cout << delimiter << endl;

	Student student(human, "Theft", "Vice", 95, 98);
	student.print();
	cout << delimiter << endl;

	Graduate graduate(student, "How to get money");
	graduate.print();
	cout << delimiter << endl;

#endif // INHERITANCE_2

	//Polymorphism (poly-�����, morphis-�����)
	//1) adHoc Polymorphism
	//2) Inclusion polymorphism 

	//1) ��������� �� ������� ���� (base-clas pointer);	//Generalization
	//2) virtual function
	//        VFPTR-Virtual Functions Pointers


	Human* group[] =
	{
		new Student (" Pinkman", " Jessie ",20, "Chemistry", " WW_220", 95, 90),
		new Teacher (" White", "   Walter ",50, "Chemistry", 25),
		new Graduate(" Schrider", "Hank   ",40, "Criminalistic", "OBN", 50, 70, "How to catch Heisenberg"),
		new Student (" Vercetti", "Tommy  ",30, "Thieft","Vice",95,98),
		new Teacher (" Diaz", "    Ricardo",50, "Weapons distribution",20)
	};

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->print();
		cout << delimiter << endl;
	} 
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}