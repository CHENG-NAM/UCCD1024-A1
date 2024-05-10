# UCCD1024-A1

UCCD1024
DATA STRUCTURES AND 
ALGORITHMIC PROBLEM SOLVING

ASSIGNMENT 1 LINKED LISTS
DUE DATE: WEEK 9, FRIDAY BEFORE 5.00PM

PLEASE READ THE QUESTION CAREFULLY BEFORE YOU START.

1.	OBJECTIVE

(a) To review and strengthen concepts about linked lists through an application development.
(b) To review techniques of dynamic data structure creation and manipulation. 



2.	EQUIPMENT

Hardware: The PCs in the lab for conducting your practical. 
Software: The Microsoft Visual Studio 2022. Your program will only be tested  
                 by the markers using Visual Studio 2022.  



3.	INDIVIDUAL OR GROUP PROJECT:

Form a group of 1 to 2 persons (CAN BE FROM DIFFERENT PRACTICAL SESSION). Select one person to be the leader. Only one person need to upload the Assignment to WBLE for submission. (YOU NEED TO FILL IN THE GROUP MEMBERS INFORMATION IN THE README.TXT PROVIDED. MARKS WILL BE DEDUCTED IF THE README.TXT IS NOT FILLED IN.)



4.	DESCRIPTION OF PROJECT:

In this project, you need to write the functions given in the main() that will store and manage student information in FICT using linked lists. Three structures have been created, which are Student struct, Exam struct, and Subject struct. Student struct is used to store student information and the Exam struct is used to store information for past exam for a student in a trimester. The Subject struct is used to store information for a subject taken by student. Refer to the Figure1.doc given for the representation of the types of linked list that you are going to create. Below are the details for each of the struct:





PLEASE DO NOT CHANGE (ADD/REMOVE) ANY ATTRIBUTES OR FUNCTIONS IN LIST, NODE, STUDENT, EXAM AND SUBJECT STRUCTS GIVEN TO YOU. MARKS WILL BE DEDUCTED IF YOU DO SO.

Student Struct:

Refer to the file Student.h for all the members in the struct. Refer to the table below for the format of the data stores for each attribute in Student struct.

Attributes	Format
name	A c-string with 30 characters
id	A c-string to represent id. Student id consists of 7 digits with the first 2 digit represent years enroll. E,g.: 1300345
course	Use 2 characters to represent:
CS – Computer Science
IA – Information Systems Engineering
IB – Business Information Systems
CN – Communication and Networking
CT – Computer Engineering 
phone_no	A 7 digits number in the following format: 123-4567
current_cpga	The latest cgpa for a student with 5 decimal places. E.g.: 3.51762
totalCreditsEarned	Total credits earned so far.
exam 	An array to store past exam for a student according to trimester. This array can store up to 10 trimester result.
exam_cnt	A counter to keep track of the number of past exam result store in exam array.

The following member functions are given in the struct:

1.	Constructor Student() to initialized name, id, course and phone_no to empty string (use strcpy) and current_cgpa, exam_cnt and totalCreditsEarned to 0. 

2.	Function bool compareName1 (Student) to compare student name using >= operator. You can use this function to compare which student’s name come first according to alphabetical order. It is used in the second insert function.  

3.	Function bool compareID (Student) to compare student id using == operator. You can use this function to search for student in a linked list based on id.

4.	Function void print(ostream &) to print Student struct variable. The argument pass to the function is used to determine which stream to print the output.

5.	Function bool calculateCurrentCGPA() to calculate the current cgpa for a student. 


Exam Struct:

Refer to the file Exam.h for all the members in the struct. Refer to the table below for the format of the data stores for each attribute in Exam struct.

Attributes	Format
trimester	Store the trimester of the exam using integer to represent the 3 trimester in a year as follow:
1 – January Trimester
5 – May Trimester
10 – October Trimester
year	A four digit integer to represent the year of the exam. 
gpa	GPA obtained for a trimester. Use 5 decimal points to represent the value.
numOfSubjects	The number of subjects taken in that trimester.
sub[]	The subject information taken in that trimester. Each element is an object of class Subject. Maximum only 6 subjects can be taken and minimum is 1 subject.

The following member functions are given in the Exam struct:

1.	Constructor Exam() to initialized trimester, year, gpa and numOfSubjects to 0. 

2.	Function bool calculateGPA() to calculate the gpa for an exam in a trimester 
based on the grade and number of subjects take. Refer to file Figure2.doc for the   grade point based on the marks obtained.

3.	Function void print(ostream &) to print the Exam struct variable. The argument   pass to the function is used to determine which stream to print the output. 

Subject Struct:

Refer to the file Subject.h for all the members in the Subject struct. Refer to the table below for the format of the data stores for each attribute in Subject struct.

Attributes	Format
subject_code	A string with 10 characters to represent a code for a subject. First four characters represent must be alphabet and last four are digits.
subject_name	A string represents the subject names. 
credit_hours	Number of credit hours for a subject.
marks	Marks obtained for a subject. Range is from 1 to 100.

The following member functions are given in the Subject struct:

1.	Constructor Subject() to initialized subject_code and subject_name to empty string (use strcpy) and credit_hours, and marks to 0. 

2.	Function const char *getGrade() to return the grade (A+, A, B+, …) for a subject based on the marks. Refer to file Figure2.doc for the grade return based on the marks obtained.

3.	Function double getGradePoint() to return the grade point for a subject based on the marks obtained. Refer to file Figure2.doc for the grade point return.

4.	Function void print(ostream &) to print Subject struct variable. The argument pass to the function is used to determine which stream to print the output. 


main() Tasks:

You need to write the following functions in main().

1.	Write a function bool CreateStuList(const char *filename, List *list) to read student information from a file and store in a linked list. Ensure there is no duplicate record of student stored in the list. The function will return true if successfully read and false otherwise. A sample of the textfile is in “student.txt”.

2.	Write a function bool DeleteStudent(List *list, char *id) to delete a student from the linked list based on student id. The function will return true if successfully delete and false if student cannot be found in the list.

3.	Write a function bool PrintList(List list, int source) that will display information to the screen. Function return false if list is empty and true otherwise. The source variable will indicate whether to display to screen (source = 1) or file (source = 2). If write to file, use the filename “student_result.txt” to write. A sample of each of the output option is given in text file in folder sample output. If the student’s exam_cnt = 0, then print “THIS STUDENT HAVEN’T TAKEN ANY EXAM YET”. You can design your own output format but the necessary details must be there.   

4.	Write a function bool InsertExamResult(const char *filename, List *list) to insert student exam result to the linked list. Open the file with filename and read every record and find the student to insert the exam based on their id. A sample of the text file is in “exam.txt”.  Read every record in the file and put the exam info in an exam struct variable. Then find the correct student based on id to insert the exam struct variable. You need to calculate the current cgpa every time you insert a new exam to a student. 


5.	Write a function bool PrintStatistic(List list) that will find and print the statistics for the student list as below. Average subject taken per semester is based on how many subjects are taken averagely for one student in one semester. Similar for average credit hours earned per semester. The function will return false for empty list and true otherwise.

      Sample Output:

      Total Students:  20 
            CS Students – 6
            IA Students – 5
            IB Students – 3
            CN Students – 3
            CT Students – 3
 
      Average CGPA: 3.15670
      	      Average Subjects Taken Per Semester: 3.23
                  Average Credits Earned Per Semester: 10.57

6.	The function bool FilterStudent(List list1, List *list2, char *course, int year, int totalcredit) that will filter student in list1 according to course, year and totalcredit earned. For example, if the value passes in for course = “CS”, year = 2020 and totalcredit = 30, you need to traverse list1 to find all CS students that are enrolled in 2020 and the totalCreditsEarned is >= 30. If a student fulfills all the three conditions, then insert to list2. You can extract the year enrolled from the student id where the first 2 digits represent year enrolled (e.g.: if id is 2000345 then year enrolled is 2020). Call PrintList function in main after function call to display list2 content to screen. The function will return false if list1 is empty or if list2 is not empty when it is passed to the function. Otherwise, return true. (Note: list1 content will remain the same after function call)


7.	Write a function bool UpdateIDandPhone(List *list) that will update the student ID and phone number for all the students in list list.  The student ID will be updated according to their as shown in Table 1 below. To update phone number, you need to change all the phone numbers in list list from 7 digits to 9 digits as shown in Table 2. If the first digit in the phone number starts with odd number, add a leading digit 01 and remove the dash. If the first digit is even number, add a leading 02 and remove dash. The function will return false if list is empty or true otherwise. Call PrintList function in main to display the student list to screen after return from the function to display the changes in every student. 

Table 1 Current ID and Updated ID

Course	Current ID	Updated ID
CS	1207893	BCS1207893
IA	1109236	BIA1109236
IB	1223456	BIB1223456
CN	1207832	BCN1207832
CT	1103672	BCT1103672


Table 2 Original Phone Numbers and Updated Phone Numbers

	Original phone numbers	Updated phone numbers
Case 1 (start with odd digit)	123-4567	011234567
Case 2 (start with even digit)	659-8776	026598776



8.	Write a function bool FindPotentialFirstClass(List list1, List *list2, char *course) to find potential student that has the potential to get first class in list list1 according to course. A student is considered to have potential to get first class if he/she gets GPA >= 3.75000 for >= 3 trimesters and other trimesters GPA cannot be < 3.50000. For each of the trimester with GPA>=3.75000 he/she must has taken >= 12 credit hours. Copy all the students that fulfill these criteria into list list2. list1 content will not be changed after function call. Call function Printlist in main after function call to print list2 in screen. If there is no student that fulfills these criteria, then print the message “There is no student in CS that has potential to get first class”.  The function will return false if list1 is empty or if list2 is not empty when it is passed to the function, otherwise return true. Note: If a student has taken < 3 exams then you don’t have to check if this student has potential for first class


9.	Write a int menu() function that contain menu with choice from 1 to 9 above to let user choose that task. Function will return the choice chosen. Make sure user can continuously choose for the menu until exit choice is chosen. Sample menu is displayed below:

1. Create student list
2. Delete Student
3. Print student list
4. Insert exam result
5. Print Exam Statistic
6. Filter Student
7. Update Student’s ID and Phone
8. Find Potential First Class Student
9. Exit.

	
	Test run


Although each of the above tasks is to be implemented as a single function, you can create additional sub-function(s) to handle portions of the function if it’s necessary.  This is especially true if the original function is too long or contains more than one functionally related group of statements.  You must test for all conditions that might possibly arise; print out error messages as needed.

A sample of text files student.txt and exam.txt is attached together with the question. The content of text file will be changed (while still adhering to the same data format) during grading in order to test your programs' robustness.  The objective is to ensure that you do not hardcode your program to work exclusively for the given sample student records. PLEASE CREATE YOUR OWN OR ADD MORE DATA TO THE SAMPLE TEXT FILES GIVEN TO YOU TO MAKE SURE YOU HAVE TESTED YOUR PROGRAM FOR ALL POSSIBLE CASES THAT YOU CAN THINK OF. MAKE SURE THE FORMAT OF YOUR OWN TEXT FILES MUST BE SAME FORMAT AS THE ONE GIVEN HERE TO ENSURE YOUR PROGRAM CAN READ THE SAME FORMAT WHEN WE MARK YOUR PROGRAM.  

Format of text file EXAM.TXT are as follow:

id	trimester 	year	numOfSubjects	list of subjects (for every subject store unit code, unit name, credit hours and marks obtained)

5.	ERROR HANDLING

We will first test your work with error-free inputs from files.  It would be ideal if your programs can also do appropriate error handling like

•	Input file cannot be found
•	Duplicate records are read in

Duplicate records should be ignored and appropriate error statement should be printed.  Apart from these, you do not need to worry about other types of errors. For all errant situations, the program should recover and still run as usual.

6.	SUBMISSION

(a)	This assignment is due according to the due date posted on WBLE. You must do the submission through WBLE. You should create one folder using your name (if you do in group of two, then you need to put both person’s name as the folder name) and then copy all your source code files (*.h, and *.cpp) into this folder. You should also FILL IN the readme file provided that contains the information stated in (b). Any extra data input files that you create to test your program also need to be submitted. Compress this folder into a zip file and submit only this zip file to WBLE. ONLY ONE MEMBER NEEDS TO UPLOAD THE ZIP FILE IN WBLE FOR SUBMISSION.

(b)	The readme file should contain the following information: All group member name, id, course and practical session.


(c)	The grading of your work will be based on the following criteria:

•	Correctness of program (whether the functions work according to  
      specifications);
•	Structure, organization, presentation of codes;
•	Documentation of codes (how easy to understand your codes); avoid excessive comments, such as commenting every line of your code.
•	Comprehensiveness of the test cases.

7.	ACADEMIC HONESTY AND COLLABORATION

Cooperation is recommended in understanding various concepts and system features. But the actual solution of the assignments, the programming and debugging must be your individual work, except for what you specifically credit to other sources. (Your grade will be based on your own contribution.) For example, copying without attribution any part of someone else’s program is plagiarism, even if you modify it and even if the source is a textbook. You can document the credit to other sources at the start of your program code listing. The University takes acts of cheating and plagiarism very seriously: first time violators may fail the coursework component of UCCD1024.  Any wholly (or partly) copied (or being copied) programs will receive zero mark. 




9.	REFERENCES

[1]	Text and reference books for UCCD1024.
[2]	http://msdn.microsoft.com/en-us/visualc/aa336395
