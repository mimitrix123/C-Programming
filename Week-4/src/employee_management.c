#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "employees.dat"
#define NAME_SIZE 100
#define DEPT_SIZE 80

typedef struct {
    int id;
    char name[NAME_SIZE];
    int age;
    char department[DEPT_SIZE];
    float salary;
} Employee;

static void clear_input_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard invalid input */
    }
}

static void read_line(const char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
}

static int read_int(const char *prompt) {
    int value;

    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            clear_input_buffer();
            return value;
        }

        printf("Invalid input. Please enter a number.\n");
        clear_input_buffer();
    }
}

static float read_float(const char *prompt) {
    float value;

    while (1) {
        printf("%s", prompt);
        if (scanf("%f", &value) == 1) {
            clear_input_buffer();
            return value;
        }

        printf("Invalid input. Please enter a number.\n");
        clear_input_buffer();
    }
}

static void print_employee(const Employee *employee) {
    printf("\nID         : %d\n", employee->id);
    printf("Name       : %s\n", employee->name);
    printf("Age        : %d\n", employee->age);
    printf("Department : %s\n", employee->department);
    printf("Salary     : %.2f\n", employee->salary);
}

static int employee_exists(int id) {
    FILE *file = fopen(DATA_FILE, "rb");
    Employee employee;

    if (file == NULL) {
        return 0;
    }

    while (fread(&employee, sizeof(Employee), 1, file) == 1) {
        if (employee.id == id) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

static void add_employee(void) {
    Employee employee;
    FILE *file;

    employee.id = read_int("Enter employee ID: ");

    if (employee.id <= 0) {
        printf("ID must be positive.\n");
        return;
    }

    if (employee_exists(employee.id)) {
        printf("An employee with ID %d already exists.\n", employee.id);
        return;
    }

    read_line("Enter name: ", employee.name, sizeof(employee.name));
    employee.age = read_int("Enter age: ");
    read_line("Enter department: ", employee.department, sizeof(employee.department));
    employee.salary = read_float("Enter salary: ");

    if (employee.age <= 0 || employee.salary < 0) {
        printf("Invalid age or salary.\n");
        return;
    }

    file = fopen(DATA_FILE, "ab");
    if (file == NULL) {
        perror("Unable to open employee data file");
        return;
    }

    if (fwrite(&employee, sizeof(Employee), 1, file) != 1) {
        perror("Unable to save employee");
    } else {
        printf("Employee added successfully.\n");
    }

    fclose(file);
}

static void list_employees(void) {
    FILE *file = fopen(DATA_FILE, "rb");
    Employee employee;
    int count = 0;

    if (file == NULL) {
        printf("No employee records found.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========\n");

    while (fread(&employee, sizeof(Employee), 1, file) == 1) {
        printf("\nEmployee #%d", ++count);
        print_employee(&employee);
    }

    fclose(file);

    if (count == 0) {
        printf("No employee records found.\n");
    }
}

static void search_employee(void) {
    int id = read_int("Enter employee ID to search: ");
    FILE *file = fopen(DATA_FILE, "rb");
    Employee employee;
    int found = 0;

    if (file == NULL) {
        printf("No employee records found.\n");
        return;
    }

    while (fread(&employee, sizeof(Employee), 1, file) == 1) {
        if (employee.id == id) {
            print_employee(&employee);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

static void update_employee(void) {
    int id = read_int("Enter employee ID to update: ");
    FILE *file = fopen(DATA_FILE, "r+b");
    Employee employee;

    if (file == NULL) {
        printf("No employee records found.\n");
        return;
    }

    while (fread(&employee, sizeof(Employee), 1, file) == 1) {
        if (employee.id == id) {
            printf("\nCurrent record:");
            print_employee(&employee);

            read_line("Enter new name: ", employee.name, sizeof(employee.name));
            employee.age = read_int("Enter new age: ");
            read_line("Enter new department: ", employee.department, sizeof(employee.department));
            employee.salary = read_float("Enter new salary: ");

            if (employee.age <= 0 || employee.salary < 0) {
                printf("Invalid age or salary. Update cancelled.\n");
                fclose(file);
                return;
            }

            if (fseek(file, -(long)sizeof(Employee), SEEK_CUR) != 0) {
                perror("Unable to position file for update");
                fclose(file);
                return;
            }

            if (fwrite(&employee, sizeof(Employee), 1, file) != 1) {
                perror("Unable to update employee");
            } else {
                printf("Employee updated successfully.\n");
            }

            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Employee with ID %d not found.\n", id);
}

static void delete_employee(void) {
    int id = read_int("Enter employee ID to delete: ");
    FILE *source = fopen(DATA_FILE, "rb");
    FILE *temp = fopen("employees.tmp", "wb");
    Employee employee;
    int found = 0;

    if (source == NULL) {
        printf("No employee records found.\n");
        return;
    }

    if (temp == NULL) {
        perror("Unable to create temporary file");
        fclose(source);
        return;
    }

    while (fread(&employee, sizeof(Employee), 1, source) == 1) {
        if (employee.id == id) {
            found = 1;
            continue;
        }

        if (fwrite(&employee, sizeof(Employee), 1, temp) != 1) {
            perror("Unable to write temporary data");
            fclose(source);
            fclose(temp);
            remove("employees.tmp");
            return;
        }
    }

    fclose(source);
    fclose(temp);

    if (!found) {
        remove("employees.tmp");
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    if (remove(DATA_FILE) != 0) {
        perror("Unable to replace employee data file");
        remove("employees.tmp");
        return;
    }

    if (rename("employees.tmp", DATA_FILE) != 0) {
        perror("Unable to rename temporary file");
        return;
    }

    printf("Employee deleted successfully.\n");
}

static void menu(void) {
    printf("\n========== EMPLOYEE MANAGEMENT SYSTEM ==========\n");
    printf("1. Add Employee\n");
    printf("2. View All Employees\n");
    printf("3. Search Employee\n");
    printf("4. Update Employee\n");
    printf("5. Delete Employee\n");
    printf("6. Exit\n");
}

int main(void) {
    int choice;

    while (1) {
        menu();
        choice = read_int("Enter your choice: ");

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                list_employees();
                break;
            case 3:
                search_employee();
                break;
            case 4:
                update_employee();
                break;
            case 5:
                delete_employee();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select 1-6.\n");
        }
    }
}
