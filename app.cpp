#include	<iostream>
#include 	<fstream>
#include	<string>
#include	<cstdlib>
#include	"List.h"
#include	"Student.h"

#include <sstream>

using namespace std;


bool CreateStuList(const char*, List*);
bool DeleteStudent(List*, char*);
bool PrintList(List, int);
bool InsertExamResult(const char*, List*);
bool PrintStatistic(List);
bool FilterStudent(List, List*, char*, int, int);
bool UpdateIDandPhone(List*);
bool FindPotentialFirstClass(List, List*, char*);
int menu();

using namespace std;


int main() {

    // Global variables initialization
    int choice;
    char* id, stuID[12];
    List studentList, firstClassList, filteredStudentList;
    const char* filename = "student.txt";
    const char* examResultsFilename = "exam.txt";

    // The main menu
    do {

        choice = menu();
        rewind(stdin);

        switch (choice)
        {
        case 1: {

            // Read student information from student.txt and store into a linked list
            CreateStuList(filename, &studentList);

            system("pause");
            system("cls");
            break;
        }

        case 2: {

            // Delete a student from the linked list based on student ID
            cout << "\n*Student Record You Want To Delete Based On Student ID: ";
            cin >> stuID;
            id = stuID;

            if (!DeleteStudent(&studentList, id))
                cout << "\n      Student Record " << stuID << " Cannot Be Found In The List!!\n";
            else
                cout << "\n  - Succesfully Remove " << stuID << " From The List. -\n";

            system("pause");
            system("cls");
            break;
        }

        case 3: {

            // Choose the source: 1 for screen, 2 for file
            int source = 1; // Display to screen (source = 1)

            // Invoke the function
            bool result = PrintList(studentList, source);
            if (!result) {
                cout << "The list is empty or there was an error." << endl;
            }

            // Display to file (source = 2)
            source = 2;
            result = PrintList(studentList, source);
            if (!result) {
                cout << "The list is empty or there was an error." << endl;
            }

            system("pause");
            system("cls");
            break;
        }

        case 4: {

            // Insert student exam result into the linked list
            if (InsertExamResult(examResultsFilename, &studentList)) {
                cout << "Exam results inserted successfully." << endl;
            }
            else {
                cout << "Failed to insert exam results." << endl;
            }

            system("pause");
            system("cls");
            break;
        }

        case 5: {

            // Find and print the statistics for the student list
            bool result = PrintStatistic(studentList);
            if (!result) {
                cout << "The list is empty." << endl;
            }

            system("pause");
            system("cls");
            break;
        }

        case 6: {

            // Example criteria to filter student
            char course[3] = "CS";
            int year = 2020;
            int totalcredit = 8;

            // Assume list1 which is studentList is filled with student data
            // Filter and print out student who matches the criteria
            if (FilterStudent(studentList, &filteredStudentList, course, year, totalcredit)) {
                if (!filteredStudentList.empty())
                    PrintList(filteredStudentList, 1); // Display to screen (source = 1) 

                else
                    cout << "There is no student matches the criteria." << endl;

            }
            else
                cout << "Operation failed. Either list1 is empty or list2 was not empty initially." << endl;


            system("pause");
            system("cls");
            break;
        }

        case 7: {

            // Update the student ID and phone number for all the students in list list
            if (UpdateIDandPhone(&studentList)) {
                cout << "Successfully updated student IDs and phone numbers." << endl;
                PrintList(studentList, 1); // display to screen (source = 1) 
            }
            else {
                cout << "Failed to update student IDs and phone numbers." << endl;
            }

            system("pause");
            system("cls");
            break;
        }

        case 8: {

            char course[] = "CS"; // Example course

            // Assume list1 which is studentList is filled with student data
            // Find and print out student who matches the criteria
            if (FindPotentialFirstClass(studentList, &firstClassList, course))
            {
                if (!firstClassList.empty())
                    PrintList(firstClassList, 1); // Display to screen (source = 1) 

                else
                    cout << "There is no student in " << course << " that has potential to get first class" << endl;
            }
            else
                cout << "Operation failed. Either list1 is empty or list2 was not empty initially." << endl;


            system("pause");
            system("cls");
            break;
        }

        case 9: {
            cout << "\n*******************************************" << endl;
            cout << "* Thanks For Using The System. =) *" << endl;
            cout << "*           Have a Nice Day !             *" << endl;
            cout << "\t      __________           _____          ____        _____________                 \n";
            cout << "\t      |          |        |     |        |    |      |             |                \n";
            cout << "\t      |  ______    |       |     |      |    |       |             |                \n";
            cout << "\t      |  |     |     |      |     |    |    |        |     ________|                \n";
            cout << "\t      |  |     /    /        |     |  |    |         |    |                         \n";
            cout << "\t      |  |____/  __/__________|_____||____|__________|____|________                 \n";
            cout << "\t      |         |                                            |     |                \n";
            cout << "\t      |         |   T H A N K   Y O U   V E R Y   M U C H    |_____|                \n";
            cout << "\t      |         |____________________________________________|                      \n";
            cout << "\t      |  ________     |          |     |             |    |                         \n";
            cout << "\t      |  |       |     |         |     |             |    |_________                \n";
            cout << "\t      |  |       /    /          |     |             |             |                \n";
            cout << "\t      |  |______/    /           |     |             |             |                \n";
            cout << "\t      |____________/             |_____|             |_____________|                \n";
            cout << "*******************************************" << endl;
            system("pause");
            break;
        }

        default:
            system("pause");
            system("cls");
        }

        system("pause");

    } while (choice != 9);

    return 0;
}


// Functions defination

bool CreateStuList(const char* filename, List* list)
{
    ifstream in;
    in.open(filename);
    string line, temp_id, temp_name, temp_course, temp_phone_no, surplus;
    int numOfStudent = 0;
    Student student, temp;
    Node* cur, * pre;

    if (in.is_open())       // Open the file (student.txt)
    {

        while (!in.eof())   // Read the file
        {

            in >> surplus >> surplus >> surplus >> temp_id >> surplus >> surplus;
            in.ignore();
            getline(in, temp_name);
            in >> surplus >> surplus >> temp_course >> surplus >> surplus >> surplus >> temp_phone_no;

            // Copy string and store in array
            strcpy_s(student.id, temp_id.c_str());
            strcpy_s(student.name, temp_name.c_str());
            strcpy_s(student.course, temp_course.c_str());
            strcpy_s(student.phone_no, temp_phone_no.c_str());

            list->insert(student);  // Insert details from student.txt into linked list
            numOfStudent++;
        }

        cout << "\n\nREAD FILE" << endl;
        cout << endl << numOfStudent << " records have been successfully read." << endl << endl;

    }
    else
        cout << "Unable to open this file!" << endl;


    // Check the records inside linked list, and remove any duplicate records
    // Special case: empty linked list
    if (list->empty())
    {
        cout << "\n\nCannot check for redundant for empty list." << endl;
        return false;
    }

    pre = list->head;
    cur = pre->next;

    // Normal case: traverse the linked list and remove the duplicate records
    while (cur != NULL)
    {
        if (!pre->item.compareID(cur->item) == 0)
        {
            pre->next = cur->next;
            cout << "Duplicated record dectected, remove " << cur->item.name << "\n\n";
            delete(cur);
            cur = pre->next;
            numOfStudent--;
            cout << endl << numOfStudent << " records left after removed duplicate record." << "\n\n";
        }
        else
        {
            pre = cur;
            cur = pre->next;
        }
    }
    return true;	// Means not duplicate

    in.close();
}

bool DeleteStudent(List* list, char* id)
{
    Student student;

    // Special case: empty linked list
    if (list->empty()) {
        cout << "\n-   ERROR!! There Is No Record Available to Be Delete   -\n";
        return false;
    }

    for (int i = 1; i <= list->size(); i++) {

        list->get(i, student);      // Get student's ID and save into student
        if (strcmp(student.id, id) == 0) {
            list->remove(i);     // If condition met, delete the details of student's info from linked list
            return true;
        }
    }

    return false;
}

bool PrintList(List list, int source)
{
    int stuCount = 0;   // To count how many student

    // Special case: empty linked list
    if (list.empty()) {
        return false; // Empty linked list, return false
    }

    ostream* out = &cout; // Default to printing to screen
    ofstream file;

    // Display to file (source = 2)
    if (source == 2) {
        file.open("student_result.txt");

        // Special case: file (student_result.txt) not found
        if (!file.is_open()) {
            cout << "Failed to open file: student_result.txt" << endl;
            return false;
        }
        out = &file; // Change the output stream to file
    }

    for (Node* node = list.head; node != nullptr; node = node->next) {
        Student& student = node->item;
        stuCount++;

        // Print student details
        *out << "\n******************************************************STUDENT " << stuCount << "******************************************************\n\n";
        student.print(*out);

        // The student with no exam
        if (student.exam_cnt == 0) {
            *out << "THIS STUDENT HAVEN’T TAKEN ANY EXAM YET\n";
        }

        // Display student's exam infomation
        else {
            *out << "--------------------------------------------------PAST EXAM RESULT:--------------------------------------------------\n\n";
            for (int i = 0; i < student.exam_cnt; ++i) {
                student.exam[i].print(*out);
            }
        }
        *out << "\n******************************************************STUDENT " << stuCount << "******************************************************\n\n";
    }

    if (file.is_open()) {
        file.close();
    }

    return true;
}

bool InsertExamResult(const char* filename, List* list)
{

    ifstream file(filename);

    // Special case: file (exam.txt) not found
    if (!file) {
        cout << "Failed to open file: " << filename << endl;
        return false;
    }

    // Read exam.txt file and save into linked list 
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string studentId;
        string space = " ";
        int trimester, year, numOfSubjects;
        iss >> studentId >> trimester >> year >> numOfSubjects;
        ostream* out = &cout; // Default to printing to screen

        Exam exam;
        exam.trimester = trimester;
        exam.year = year;
        exam.numOfSubjects = numOfSubjects;

        for (int i = 0; i < numOfSubjects; ++i) {
            Subject subject;
            iss >> subject.subject_code >> subject.subject_name >> subject.credit_hours >> subject.marks;

            // To remove underscore line from the subject name
            for (int z = 0; z <= i; ++z)
            {
                string tempSubjectName = "";
                for (int j = 0; j <= sizeof(subject.subject_name); j++){

                    if (subject.subject_name[j] == '_')
                    {
                        subject.subject_name[j] = ' ';
                        tempSubjectName += subject.subject_name[j];
                    }
                    else
                        tempSubjectName += subject.subject_name[j];

                }
                strcpy_s(subject.subject_name, tempSubjectName.c_str());    // Copy string and store it in array
            }

            exam.sub[i] = subject;
        }

        // Calculate GPA for this exam
        exam.calculateGPA();

        // Find the student by ID and insert the exam result
        for (Node* cur = list->head; cur != nullptr; cur = cur->next) {
            if (strcmp(cur->item.id, studentId.c_str()) == 0) {
                // Ensure the student has not exceeded the exam limit
                if (cur->item.exam_cnt < 10) {
                    cur->item.exam[cur->item.exam_cnt++] = exam;
                    cur->item.calculateCurrentCGPA(); // Recalculate the CGPA after adding the new exam
                    cout << "Exam result inserted for student ID " << studentId << endl;
                }
                else {
                    cout << "Maximum exam limit reached for student ID " << studentId << endl;
                }
                break; // Exit the loop once the student is found
            }
        }
    }

    file.close();
    return true; // File processed successfully
}

bool PrintStatistic(List list)
{
    // Special case: empty linked list
    if (list.empty()) {
        return false; // Return false if the list is empty
    }

    int totalStudents = 0, csStudents = 0, iaStudents = 0, ibStudents = 0, cnStudents = 0, ctStudents = 0;
    double totalCGPA = 0.0, totalSubjects = 0, totalCredits = 0;

    for (Node* node = list.head; node != nullptr; node = node->next) {
        Student& student = node->item;
        totalStudents++;
        totalCGPA += student.current_cgpa;

        // Increment course counters
        if (strcmp(student.course, "CS") == 0) csStudents++;
        else if (strcmp(student.course, "IA") == 0) iaStudents++;
        else if (strcmp(student.course, "IB") == 0) ibStudents++;
        else if (strcmp(student.course, "CN") == 0) cnStudents++;
        else if (strcmp(student.course, "CT") == 0) ctStudents++;

        for (int i = 0; i < student.exam_cnt; ++i) {
            totalSubjects += student.exam[i].numOfSubjects;
            for (int j = 0; j < student.exam[i].numOfSubjects; ++j) {
                totalCredits += student.exam[i].sub[j].credit_hours;
            }
        }
    }

    double averageCGPA = totalCGPA / totalStudents;
    double averageSubjectsPerSemester = totalSubjects / totalStudents;
    double averageCreditsPerSemester = totalCredits / totalStudents;

    // Print the statistics
    cout << "Total Students: " << totalStudents << "\n"
        << "\tCS Students – " << csStudents << "\n"
        << "\tIA Students – " << iaStudents << "\n"
        << "\tIB Students – " << ibStudents << "\n"
        << "\tCN Students – " << cnStudents << "\n"
        << "\tCT Students – " << ctStudents << "\n\n"
        << "\tAverage CGPA: " << fixed << setprecision(5) << averageCGPA << "\n"
        << "\tAverage Subjects Taken Per Semester: " << fixed << setprecision(2) << averageSubjectsPerSemester << "\n"
        << "\tAverage Credits Earned Per Semester: " << fixed << setprecision(2) << averageCreditsPerSemester << "\n" << endl;

    return true;
}

bool FilterStudent(List list1, List* list2, char* course, int year, int totalcredit)
{

    // Check if list1 is empty or list2 is not empty
    if (list1.empty() || !list2->empty())
        return false;

    for (Node* node = list1.head; node != nullptr; node = node->next) {     // Traverse the studentList
        Student& student = node->item;

        // Extract the year enrolled from student's ID
        int enrolledYear = atoi(string(student.id, 2).c_str()) + 2000;

        // Check if student matches the criteria
        if (strcmp(student.course, course) == 0 && enrolledYear == year && student.totalCreditsEarned >= totalcredit)

            // Insert the student who matches the criteria into list2
            list2->insert(student);
    }

    return true;
}

bool UpdateIDandPhone(List* list)
{
    // Special case: linked list is null or empty
    if (list == nullptr || list->empty()) {
        return false;
    }

    for (Node* node = list->head; node != nullptr; node = node->next) {     // Traverse the node
        Student& student = node->item;

        // Update ID
        string newID;
        if (strcmp(student.course, "CS") == 0) newID = "BCS";
        else if (strcmp(student.course, "IA") == 0) newID = "BIA";
        else if (strcmp(student.course, "IB") == 0) newID = "BIB";
        else if (strcmp(student.course, "CN") == 0) newID = "BCN";
        else if (strcmp(student.course, "CT") == 0) newID = "BCT";
        newID += student.id;
        strcpy_s(student.id, newID.c_str()); // Copy new ID into Student struct

        // Update Phone
        string phone(student.phone_no);
        phone.erase(remove(phone.begin(), phone.end(), '-'), phone.end()); // Remove dashes

        if ((phone[0] - '0') % 2 == 0) { // Even
            phone = "02" + phone;
        }

        else { // Odd
            phone = "01" + phone;
        }
        strcpy_s(student.phone_no, phone.c_str()); // Copy new phone_no into Student struct
    }

    return true;
}

bool FindPotentialFirstClass(List list1, List* list2, char* course)
{

    // Special case: list1 is empty or list2 is not empty
    if (list1.empty() || !list2->empty()) {
        return false;
    }

    //bool found = false;

    for (Node* node = list1.head; node != nullptr; node = node->next) {     // Traverse the studentList

        Student& student = node->item;
        if (strcmp(student.course, course) == 0 && student.exam_cnt >= 3) {

            int highGPACount = 0;       // Number of trimester that have GPA >= 3.75
            bool isEligible = true;

            for (int i = 0; i < student.exam_cnt; ++i) {

                if (student.exam[i].gpa >= 3.75 && student.totalCreditsEarned >= 12) {
                    highGPACount++;
                }

                else if (student.exam[i].gpa < 3.5) {
                    isEligible = false;
                    break;
                }
            }
            if (isEligible && highGPACount >= 3) {
                list2->insert(student); // Insert potential first class student into list2
                //found = true;
                return true;
            }
        }
    }

    //return found;
    return true;
}

int menu()
{

    // Menu with choice from 1 to 9
    int menu;

    cout << "----------------- Menu ---------------------------------" << endl;
    cout << "-                                                      -" << endl;
    cout << "-          *1. Create student list*                    -" << endl;
    cout << "-          *2. Delete Student*                         -" << endl;
    cout << "-          *3. Print student list*                     -" << endl;
    cout << "-          *4. Insert exam result*                     -" << endl;
    cout << "-          *5. Print Exam Statistic*                   -" << endl;
    cout << "-          *6. Filter Student*                         -" << endl;
    cout << "-          *7. Update Student’s ID and Phone*          -" << endl;
    cout << "-          *8. Find Potential First Class Student*     -" << endl;
    cout << "-          *9.Exit*                                    -" << endl;
    cout << "-                                                      -" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "\n         *Enter your choice : ";
    cin >> menu;

    return menu;
}