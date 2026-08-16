# Week 4 – C Programming: Structures & File Handling

This repository contains complete solutions for the Week 4 assignments and mini project from the supplied assignment sheet.

## Topics
- Structures & Nested Structures
- File Handling (Read/Write)
- Command Line Arguments

## Assignments
1. Create a `Student` structure with Name, Age, and Marks.
2. Write structure data to a file and read it back.
3. Count the number of lines in a file.
4. Append data to an existing file.
5. Mini Project: Employee Management System with File Storage.

## Requirements
- GCC compiler
- VS Code or any C-compatible IDE

## Compile

From the project root:

```bash
gcc src/assignment1_student_structure.c -o assignment1
gcc src/assignment2_structure_file.c -o assignment2
gcc src/assignment3_count_lines.c -o assignment3
gcc src/assignment4_append_file.c -o assignment4
gcc src/employee_management.c -o employee_management
```

On Windows, the generated executables will normally have `.exe`.

## Run

```bash
./assignment1
./assignment2
./assignment3 data/sample.txt
./assignment4
./employee_management
```

For Windows PowerShell:

```powershell
.\assignment1.exe
.\assignment2.exe
.\assignment3.exe data\sample.txt
.\assignment4.exe
.\employee_management.exe
```

## Mini Project Features
- Add employee
- View all employees
- Search employee by ID
- Update employee
- Delete employee
- Persistent binary file storage
- Input validation
- Menu-driven interface

The employee data is stored in `employees.dat` in the program's working directory.
