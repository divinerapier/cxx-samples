#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

class Student {
   public:
    std::string name;
    int num;
    int age;
    char gender;
};

int write(std::ostream &fs, const Student &s) {
    json obj;
    obj["name"] = s.name;
    obj["num"] = s.num;
    obj["age"] = s.age;
    obj["gender"] = s.gender;
    fs << obj.dump() << std::endl;
    return 0;
}

std::vector<Student> read(std::istream &fs) {
    std::vector<Student> vec;
    std::string line;
    while (std::getline(fs, line)) {
        std::cout << line << std::endl;
        json obj = json::parse(line);
        int gender = obj["gender"];
        Student s = Student{obj["name"], obj["num"], obj["age"], (char)gender};
        vec.push_back(s);
    }

    return vec;
}

int main() {
    std::ofstream out("output.txt");
    std::ifstream in("output.txt");

    std::string name_list[10] = {
        "Bob", "Jerry", "Tim", "Smith", "Jack", "Tony",
    };
    for (int i = 0; i < 6; i++) {
        Student s = Student{name_list[i], i * 10, i * i, (char)(i & 0x01)};
        write(out, s);
    }
    out.flush();
    out.close();
    auto students = read(in);

    for (auto &s : students) {
        printf("name: %s  num: %d  age: %d  gender: %d\n", s.name.c_str(),
               s.num, s.age, s.gender);
    }
    in.close();
}