#include "../include/Group.hpp"
#include <cstddef>
#include <algorithm>

void Group::SortByName(std::vector<Student>& students){
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.Name < b.Name;
    });
}

float mean(const Group::Student& student){
    if(student.Ratings.empty()){
        return 0.f;
    }
    float res = 0.f;
    for(const auto mark : student.Ratings){
        res += mark;
    }
    return res / student.Ratings.size();
}

void Group::SortByRating(std::vector<Student>& students){
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return mean(a) < mean(b);
    });
}

size_t Group::CountTwoness(const std::vector<Student>& students){
    size_t counter = 0;
    for(const auto& student : students){
        if(std::find(student.Ratings.begin(), student.Ratings.end(), 2) != student.Ratings.end()){
            counter++;
        }
    }
    return counter;
}

size_t Group::CountExcellent(const std::vector<Student>& students){
    size_t count = 0;
    for(const auto& student : students){
        if(std::all_of(student.Ratings.begin(), student.Ratings.end(), [](unsigned mark) { return mark == 5; })){
            count++;
        }
    }
    return count;
}

std::vector<Group::Student> Group::VectorMathExcellent(const std::vector<Student>& students){
    std::vector<Student> res{};
    for(const auto& student : students){
        for(size_t i = 0; i < std::min(student.Ratings.size(), student.Subjects.size()); ++i){
            if(student.Subjects.at(i) == "Math" && student.Ratings.at(i) == 5){
                res.push_back(student);
                break;
            }
        }
    }
    return res;
}

std::vector<std::string> Group::StudentsId(const std::vector<Student>& students){
    std::vector<std::string> ids{};
    for(const auto& student : students){
        if(std::find(ids.begin(), ids.end(), student.StudentId) == ids.end()){
            ids.push_back(student.StudentId);
        }
    }
    return ids;
}

std::vector<Group> Group::Groups(const std::vector<Student>& students){
    std::vector<Group> groups;

    auto contain_group_name = [&groups](const std::string& name) -> std::size_t{
        for(size_t i = 0; i < groups.size(); ++i){
            if(groups.at(i).GetId() == name){
                return i;
            }
        }
        return static_cast<std::size_t>(-1);
    };

    for(const auto& student : students){
        auto ind = contain_group_name(student.StudentId);
        if(ind == static_cast<std::size_t>(-1)){
            Group newGroup;
            newGroup.SetId(student.StudentId);
            newGroup.SetStudents({student});
            groups.push_back(newGroup);
        }
        else{
            auto students = groups.at(ind).GetStudents();
            students.push_back(student);
            groups.at(ind).SetStudents(students);
        }
    }

    return groups;
}

std::optional<Group::Student> Group::FindStudentByIdAndName(const std::string& studentId, const std::string& name) const {
    for (const auto& student : Students) {
        if (student.StudentId == studentId && student.Name == name) {
            return student;
        } else if (student.Name == name) {
            return student;
        }
    }
    return std::nullopt;
}

void Group::AddStudent(const Student& student) {
    Students.push_back(student);
}

bool Group::DeleteStudent(const std::string& studentId, const std::string& name) {
    auto it = std::remove_if(Students.begin(), Students.end(), [&](const Student& student) {
        return student.StudentId == studentId && student.Name == name;
    });
    if (it != Students.end()) {
        Students.erase(it, Students.end());
        return true;
    }
    return false;
}