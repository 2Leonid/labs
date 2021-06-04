#ifndef _STUDENTS_HPP_
#define _STUDENTS_HPP_ 1
#include <string>


class Person {
	private:
		std::string firstName;
		std::string middleName;
		std::string lastName;
	public:
        Person() {}

        Person(std::string name1,std::string name2, std::string name3) : firstName(name1), middleName(name2), lastName(name3) {}
		std::string Get_First_Name(){
            return firstName;
        }
        std::string Get_Middle_Name(){
            return middleName;
        }
        std::string Get_Last_Name(){
            return lastName;
        }
        void Set_First_Name(std::string str){
            firstName = str;
        }
        void Set_Middle_Name(std::string str){
            middleName = str;
        }
        void Set_Last_Name(std::string str){
            lastName = str;
        }

        std::string WhoIs(){
            return "Person";
        }
};

class Student : public Person {
    private:
        std::string Group;
    public:
        Student(){
            Group;
        }
        Student(std::string name1, std::string name2, std::string name3, std::string group){
            Set_First_Name(name1);
            Set_Middle_Name(name2);
            Set_Last_Name(name3);
            Group = group;
        }
        std::string Get_Group(){
            return Group;
        }

        void Set_Group(std::string grp){
            Group = grp;
        }

        std::string WhoIs(){
            return "Student";
        }
};

class Teacher : public Person{
    private:
        std::string subject;
    public:
        Teacher(std::string name1, std::string name2, std::string name3, std::string group){
            Set_First_Name(name1);
            Set_Middle_Name(name2);
            Set_Last_Name(name3);
            subject = group;
        }
        std::string Get_Subject(){
            return subject;
        }

        void Set_Subject(std::string grp){
            subject = grp;
        }

        std::string WhoIs(){
            return "Teacher";
        }
};

#endif