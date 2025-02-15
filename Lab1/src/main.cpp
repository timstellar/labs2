#include "../include/Group.hpp"
#include <iostream>

int main() {
    Group group;
    Group::Student student1 = {"Alice", "1", {5, 4, 3}, {"Math", "Science", "History"}};
    Group::Student student2 = {"Bob", "2", {2, 3, 4}, {"Math", "Science", "History"}};
    Group::Student student3 = {"Charlie", "3", {5, 5, 5}, {"Math", "Science", "History"}};

    group.AddStudent(student1);
    group.AddStudent(student2);
    group.AddStudent(student3);

    std::cout << "Students in the group:" << std::endl;
    for (const auto& student : group.GetStudents()) {
        std::cout << "Name: " << student.Name << ", ID: " << student.StudentId << std::endl;
    }

    auto foundStudent = group.FindStudentByIdAndName("2", "Bob");
    if (foundStudent) {
        std::cout << "Found student: " << foundStudent->Name << " with ID: " << foundStudent->StudentId << std::endl;
    } else {
        std::cout << "Student not found." << std::endl;
    }

    group.DeleteStudent("2", "Bob");
    std::cout << "Students in the group after deletion:" << std::endl;
    for (const auto& student : group.GetStudents()) {
        std::cout << "Name: " << student.Name << ", ID: " << student.StudentId << std::endl;
    }

    return 0;
}