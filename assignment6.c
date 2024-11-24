
#include <stdio.h>
#include <string.h>


struct Employee {
    int employeeID;
    float salary;
    char name[50];
};


void inputEmployeeData(struct Employee emp[], int index) {
    printf("Enter Teacher ID: ");
    scanf("%d", &emp[index].employeeID);
    printf("Enter Teacher Name: ");
    getchar(); 
    fgets(emp[index].name, sizeof(emp[index].name), stdin);
    emp[index].name[strcspn(emp[index].name, "\n")] = 0; 
    printf("Enter Teacher Salary: ");
    scanf("%f", &emp[index].salary);
}


void displayEmployeeData(struct Employee emp) {
    printf("%-10d %-25s %-10.2f\n", emp.employeeID, emp.name, emp.salary);
}


void displayAllEmployees(struct Employee emp[], int count) {
    if (count == 0) {
        printf("No teacher to display.\n");
        return;
    }
    printf("\n%-10s %-25s %-10s\n", "ID", "Name", "Salary");
    for (int i = 0; i < count; i++) {
        displayEmployeeData(emp[i]);
    }
}


void searchEmployeeByID(struct Employee emp[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (emp[i].employeeID == id) {
            printf("\nTeacher Found:\n");
            displayEmployeeData(emp[i]);
            return;
        }
    }
    printf("Teacher with ID %d not found.\n", id);
}


int main() {
    struct Employee employees[100]; 
    int numEmployees = 0, choice;

    while (1) {
        
        printf("\n1. Add Teacher\n");
        printf("2. Display All teacher\n");
        printf("3. Search Teacher by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
           
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
               
                if (numEmployees < 100) {
                    inputEmployeeData(employees, numEmployees);
                    numEmployees++;
                } else {
                    printf("Teacher list is full!\n");
                }
                break;

            case 2:
                
                displayAllEmployees(employees, numEmployees);
                break;

            case 3: {
                
                if (numEmployees == 0) {
                    printf("No Teacher to search.\n");
                    break;
                }
                int searchID;
                printf("Enter Teacher ID to search: ");
                scanf("%d", &searchID);
                searchEmployeeByID(employees, numEmployees, searchID);
                break;
            }

            case 4:
                
                printf("Exiting the program,Thankyou for the visit.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

