#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Structures
typedef struct EditHistory {
    char field[30];
    char oldValue[50];
    char newValue[50];
    struct EditHistory* next;
} EditHistory;

typedef struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
    char designation[30];
    EditHistory* history;
    struct Employee* next;
} Employee;

// Global Head Pointer for Employees
Employee* head = NULL;

// Function Prototypes
void addEmployee();
void editEmployee();
void deleteEmployee();
void viewEmployeeDetails();
void viewEditHistory();
void generatePaySlip();
void displayAllEmployees();
void saveToFile();
void loadFromFile();
Employee* findEmployeeById(int id);
void addEditHistory(Employee* emp, const char* field, const char* oldValue, const char* newValue);

// Enum for Menu Options
typedef enum {
    Add_Employee = 1,
    Edit_Employee,
    Delete_Employee,
    Search_Employee,
    Editing_History,
    Payroll,
    Employees,
    Exit
} MenuOption;

// Main Function
int main() {
    loadFromFile(); // Load data from file
    int choice;
    do {
        printf("\nEmployee Payroll System with Editing History\n");
        printf("1. Add Employee\n");
        printf("2. Edit Employee\n");
        printf("3. Delete Employee\n");
        printf("4. Search Employee\n");
        printf("5. Editing History\n");
        printf("6. Payroll\n");
        printf("7. Display All Employees\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch ((MenuOption)choice) {
            case Add_Employee:
                addEmployee();
                break;
            case Edit_Employee:
                editEmployee();
                break;
            case Delete_Employee:
                deleteEmployee();
                break;
            case Search_Employee:
                viewEmployeeDetails();
                break;
            case Editing_History:
                viewEditHistory();
                break;
            case Payroll:
                generatePaySlip();
                break;
            case Employees:
                displayAllEmployees();
                break;
            case Exit:
                saveToFile();
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != Exit);

    return 0;
}

// Function to Add Employee
void addEmployee() {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    newEmployee->history = NULL;
    newEmployee->next = NULL;

    printf("Enter Employee ID: ");
    scanf("%d", &newEmployee->id);

    if (findEmployeeById(newEmployee->id) != NULL) {
        printf("Employee with ID %d already exists!\n", newEmployee->id);
        free(newEmployee);
        return;
    }

    printf("Enter Name: ");
    getchar(); // Consume newline
    fgets(newEmployee->name, 50, stdin);
    newEmployee->name[strcspn(newEmployee->name, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(newEmployee->department, 30, stdin);
    newEmployee->department[strcspn(newEmployee->department, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &newEmployee->salary);

    printf("Enter Designation: ");
    getchar(); // Consume newline
    fgets(newEmployee->designation, 30, stdin);
    newEmployee->designation[strcspn(newEmployee->designation, "\n")] = '\0';

    if (head == NULL) {
        head = newEmployee;
    } else {
        Employee* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEmployee;
    }

    printf("Employee added successfully!\n");
}

// Function to Find Employee by ID
Employee* findEmployeeById(int id) {
    Employee* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to Edit Employee
void editEmployee() {
    int id, choice;
    char newValue[50];
    printf("Enter Employee ID to edit: ");
    scanf("%d", &id);

    Employee* emp = findEmployeeById(id);
    if (emp == NULL) {
        printf("Employee with ID %d not found!\n", id);
        return;
    }

    printf("Select field to edit (1. Name, 2. Department, 3. Salary, 4. Designation): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter new Name: ");
            getchar();
            fgets(newValue, 50, stdin);
            newValue[strcspn(newValue, "\n")] = '\0';
            addEditHistory(emp, "Name", emp->name, newValue);
            strcpy(emp->name, newValue);
            break;
        case 2:
            printf("Enter new Department: ");
            getchar();
            fgets(newValue, 30, stdin);
            newValue[strcspn(newValue, "\n")] = '\0';
            addEditHistory(emp, "Department", emp->department, newValue);
            strcpy(emp->department, newValue);
            break;
        case 3:
            printf("Enter new Salary: ");
            float newSalary;
            scanf("%f", &newSalary);
            sprintf(newValue, "%.2f", emp->salary);
            addEditHistory(emp, "Salary", newValue, (char[50]){0});
            emp->salary = newSalary;
            break;
        case 4:
            printf("Enter new Designation: ");
            getchar();
            fgets(newValue, 30, stdin);
            newValue[strcspn(newValue, "\n")] = '\0';
            addEditHistory(emp, "Designation", emp->designation, newValue);
            strcpy(emp->designation, newValue);
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    printf("Employee details updated successfully!\n");
}

// Function to Add Edit History
void addEditHistory(Employee* emp, const char* field, const char* oldValue, const char* newValue) {
    EditHistory* newHistory = (EditHistory*)malloc(sizeof(EditHistory));
    strcpy(newHistory->field, field);
    strcpy(newHistory->oldValue, oldValue);
    strcpy(newHistory->newValue, newValue);
    newHistory->next = emp->history;
    emp->history = newHistory;
}

// Function to Delete Employee
void deleteEmployee() {
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    Employee* temp = head;
    Employee* prev = NULL;

    while (temp != NULL) {
        if (temp->id == id) {
            if (prev == NULL) {
                head = temp->next; // If deleting the first node
            } else {
                prev->next = temp->next;
            }
            // Free memory for the employee and its history
            EditHistory* hist = temp->history;
            while (hist != NULL) {
                EditHistory* toFree = hist;
                hist = hist->next;
                free(toFree);
            }
            free(temp);
            printf("Employee with ID %d deleted successfully!\n", id);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Employee with ID %d not found!\n", id);
}

// Function to View Employee Details
void viewEmployeeDetails() {
    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    Employee* emp = findEmployeeById(id);
    if (emp == NULL) {
        printf("Employee with ID %d not found!\n", id);
        return;
    }

    printf("Employee Found:\n");
    printf("ID: %d\n", emp->id);
    printf("Name: %s\n", emp->name);
    printf("Department: %s\n", emp->department);
    printf("Salary: %.2f\n", emp->salary);
    printf("Designation: %s\n", emp->designation);
}

// Function to View Edit History
void viewEditHistory() {
    int id;
    printf("Enter Employee ID to view edit history: ");
    scanf("%d", &id);

    Employee* emp = findEmployeeById(id);
    if (emp == NULL) {
        printf("Employee with ID %d not found!\n", id);
        return;
    }

    EditHistory* hist = emp->history;
    if (hist == NULL) {
        printf("No editing history for Employee ID %d.\n", id);
        return;
    }

    printf("Editing History for Employee ID %d:\n", id);
    while (hist != NULL) {
        printf("Field Updated: %s\n", hist->field);
        printf("Old Value: %s\n", hist->oldValue);
        printf("New Value: %s\n", hist->newValue);
        printf("-----------------------------\n");
        hist = hist->next;
    }
}

// Function to Generate Pay Slip
void generatePaySlip() {
    int id, choice;
    printf("Enter Employee ID to generate pay slip: ");
    scanf("%d", &id);

    Employee* emp = findEmployeeById(id);
    if (emp == NULL) {
        printf("Employee with ID %d not found!\n", id);
        return;
    }

    printf("Select pay slip type (1. Monthly, 2. Quarterly, 3. Yearly): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Monthly Pay Slip for %s: %.2f\n", emp->name, emp->salary);
            break;
        case 2:
            printf("Quarterly Pay Slip for %s: %.2f\n", emp->name, emp->salary * 3);
            break;
        case 3:
            printf("Yearly Pay Slip for %s: %.2f\n", emp->name, emp->salary * 12);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// Function to Display All Employees
void displayAllEmployees() {
    if (head == NULL) {
        printf("No employees in the system.\n");
        return;
    }

    printf("Employee ID | Name             | Department      | Salary     | Designation\n");
    printf("-----------------------------------------------------------------------------\n");

    Employee* temp = head;
    while (temp != NULL) {
        printf("%-11d | %-16s | %-15s | %-10.2f | %s\n",
               temp->id, temp->name, temp->department, temp->salary, temp->designation);
        temp = temp->next;
    }
}

// Function to Save Employees to File
void saveToFile() {
    FILE* file = fopen("employees.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for saving!\n");
        return;
    }

    Employee* temp = head;
    while (temp != NULL) {
        fwrite(temp, sizeof(Employee) - sizeof(EditHistory*) - sizeof(Employee*), 1, file);
        temp = temp->next;
    }
    fclose(file);
    printf("Employee data saved to file successfully.\n");
}

// Function to Load Employees from File
void loadFromFile() {
    FILE* file = fopen("employees.dat", "rb");
    if (file == NULL) {
        printf("No previous data found. Starting fresh...\n");
        return;
    }

    Employee temp;
    while (fread(&temp, sizeof(Employee) - sizeof(EditHistory*) - sizeof(Employee*), 1, file)) {
        Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
        *newEmployee = temp;
        newEmployee->history = NULL;
        newEmployee->next = NULL;

        if (head == NULL) {
            head = newEmployee;
        } else {
            Employee* last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newEmployee;
        }
    }
    fclose(file);
    printf("Employee data loaded from file successfully.\n");
}

