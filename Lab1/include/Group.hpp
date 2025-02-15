#include <iostream>
#include <string>
#include <vector>
#include <optional>

class Group {

public:
  struct Student
  {
    std::string Name;
    std::string StudentId;
    std::vector<unsigned> Ratings;
    std::vector<std::string> Subjects;
  };

  // Getter and Setter for Id
  std::string GetId() const { return Id; }
  void SetId(const std::string& id) { Id = id; }

  // Getter and Setter for Students
  std::vector<Student> GetStudents() const { return Students; }
  void SetStudents(const std::vector<Student>& students) { Students = students; }

  void SortByName(std::vector<Student>&);
  void SortByRating(std::vector<Student>&);
  size_t CountTwoness(const std::vector<Student>&);
  size_t CountExcellent(const std::vector<Student>&);
  std::vector<Student> VectorMathExcellent(const std::vector<Student>&);
  std::vector<std::string> StudentsId(const std::vector<Student>&);
  std::vector<Group> Groups(const std::vector<Student>&);

  // Function to find a student by ID and name
  std::optional<Student> FindStudentByIdAndName(const std::string& studentId, const std::string& name) const;

  // Functions to add and delete a student
  void AddStudent(const Student& student);
  bool DeleteStudent(const std::string& studentId, const std::string& name);

private:
  std::string Id;
  std::vector<Student> Students;
};