CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: assignment1 assignment2 assignment3 assignment4 employee_management

assignment1: src/assignment1_student_structure.c
	$(CC) $(CFLAGS) $< -o $@

assignment2: src/assignment2_structure_file.c
	$(CC) $(CFLAGS) $< -o $@

assignment3: src/assignment3_count_lines.c
	$(CC) $(CFLAGS) $< -o $@

assignment4: src/assignment4_append_file.c
	$(CC) $(CFLAGS) $< -o $@

employee_management: src/employee_management.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f assignment1 assignment2 assignment3 assignment4 employee_management *.exe *.o *.out
