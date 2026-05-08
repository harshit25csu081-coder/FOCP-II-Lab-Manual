File update on Rollno search criteria-update marks
/*Scenario: Update a Student’s Marks in File
Read data from file
101 Rahul 75
102 Aman 80
103 Neha 65
Update marks of a specific student
Write back to same file*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("final.txt", ios::in | ios::out);

    if(!file) {
        cout << "File not found!";
        return 0;
    }

    int id, marks;
    string name;

    int search_id = 102;

    while(file >> id >> name >> marks) {
        if(id == search_id) {
            cout << "Old Marks: " << marks << endl<<"read pointer position :"<<file.tellg();

            // Move file pointer back to overwrite marks
            file.seekp((to_string(marks).length()), ios::cur);

            marks = 89;
            file << marks;

            cout << "Marks updated!";
            break;
        }
    }

    file.close();
}