#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structures
typedef struct {
    char id[10];
    char lastname[50];
    char firstname[50];
    float bac_grade;
} Student;

typedef struct {
    char theme[50];
    Student student1;
    Student student2;
    float difficulty;
} Project;


void addStudent(Student *newStudent); // Function to add a student
void addProject(Project *newProject, Student *students, int numStudents); // Function to add a project
void assignStudentsToProject(Project *project, Student *students, int numStudents); // Function to assign students to a project
void displayStudents(Student *students, int numStudents); // Function to display students in descending order of BAC grade
void displayProjects(Project *projects, int numProjects); // Function to display projects in ascending order of difficulty
void searchTheme(Project *projects, int numProjects, char *studentID);  // Function to search for the theme of a student
int getch();


int main() {
    int choice;
    int numStudents = 0;
    int numProjects = 0;
    Student students[100]; // Assuming a maximum of 100 students
    Project projects[100]; // Assuming a maximum of 100 projects

    do {
    	system("cls");
        printf("-------Menu-------------------------------------\n");
        printf("1. Add a project\n");
        printf("2. Add a student\n");
        printf("3. Assign two students to a project\n");
        printf("4. Display the list of students in descending order of their BAC grade\n");
        printf("5. Display the list of projects in ascending order of their difficulties\n");
        printf("6. Search for the theme of a student\n");
        printf("7. Exit\n");
        printf("------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProject(&(projects[numProjects]), students, numStudents);
                numProjects++;
                break;
            case 2:
                addStudent(&(students[numStudents]));
                numStudents++;
                break;
            case 3:
                assignStudentsToProject(&(projects[numProjects - 1]), students, numStudents);
                break;
            case 4:
                displayStudents(students, numStudents);
                break;
            case 5:
                displayProjects(projects, numProjects);
                break;
            case 6:
                searchTheme(projects, numProjects, "1234"); // Hardcoding studentID for the example
                break;
            case 7:
                printf("Thank you very much.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
        
        getch();
        
    } while (choice != 7);

    return 0;
}


void addStudent(Student *newStudent){
    
	printf("Enter student ID: ");
    scanf("%s", newStudent->id);
    printf("Enter last name: ");
    scanf("%s", newStudent->lastname);
    printf("Enter first name: ");
    scanf("%s", newStudent->firstname);
    printf("Enter BAC grade: ");
    scanf("%f", &newStudent->bac_grade);
}

void addProject(Project *newProject, Student *students, int numStudents){
    
	printf("Enter project theme: ");
    getchar();
    scanf("%[^\n]", newProject->theme);
    assignStudentsToProject(newProject, students, numStudents); // Assign students to the project
    printf("Enter project difficulty: ");
    scanf("%f", &newProject->difficulty);
}

void assignStudentsToProject(Project *project, Student *students, int numStudents){
	
    printf("Enter index for Student 1 (0 to %d): ", numStudents - 1);
    int studentIndex1;
    scanf("%d", &studentIndex1);

    if (studentIndex1 >= 0 && studentIndex1 < numStudents) {
        project->student1 = students[studentIndex1];
    } else {
        return;
    }

    printf("Enter index for Student 2 (0 to %d, excluding Student 1): ", numStudents - 2);
    int studentIndex2;
    scanf("%d", &studentIndex2);

    if (studentIndex2 >= 0 && studentIndex2 < numStudents && studentIndex2 != studentIndex1) {
        project->student2 = students[studentIndex2];
    } else {
        return;
    }
}

void displayStudents(Student *students, int numStudents){
    // Sorting students based on BAC grade in descending order
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[i].bac_grade < students[j].bac_grade) {
                // Swap the students
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // Display the sorted list
    printf("\nList of students in descending order of BAC grade:\n");
    printf("ID		firstname	lastname	BAC_grade\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s		%s		%s		%.2f\n", students[i].id ,students[i].firstname, students[i].lastname, students[i].bac_grade);
    }
}

void displayProjects(Project *projects, int numProjects){
    // Sorting projects based on difficulty in ascending order
    for (int i = 0; i < numProjects - 1; i++) {
        for (int j = i + 1; j < numProjects; j++) {
            if (projects[i].difficulty > projects[j].difficulty) {
                // Swap the projects
                Project temp = projects[i];
                projects[i] = projects[j];
                projects[j] = temp;
            }
        }
    }

    // Display the sorted list
    printf("\nList of projects in ascending order of difficulty:\n");
    for (int i = 0; i < numProjects; i++) {
        printf("Project Theme: %s, Difficulty: %.2f\n", projects[i].theme, projects[i].difficulty);
    }
}

void searchTheme(Project *projects, int numProjects, char *studentID){
	
    printf("Enter student ID to search for theme: ");
    char searchID[10];
    scanf("%s", searchID);

   for (int i = 0; i < numProjects; i++) {
	    if (strcmp(projects[i].student1.id, searchID) == 0 || strcmp(projects[i].student2.id, searchID) == 0) {
	        printf("Theme for student %s: %s\n", searchID, projects[i].theme);
	        return;
	    }
	}
	
	printf("Student with ID %s not found.\n", searchID);   
}