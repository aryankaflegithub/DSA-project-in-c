#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASKS 50

typedef struct {
    int id;
    char title[50];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int numTasks = 0;

void displayMenu() {
    printf(" Menu \n");
    printf("1. Add Task\n");
    printf("2. Update Task\n");
    printf("3. Delete Task\n");
    printf("4. Search Task\n");
    printf("5. Sort Tasks\n");
    printf("6. Display All Tasks\n");
    printf("0. Exit\n");
}

void addTask() {
    if (numTasks >= MAX_TASKS) {
        printf("Cannot add more tasks. Task limit reached.\n");
        return;
    }

    Task newTask;
    newTask.id = numTasks + 1;
    printf("Enter task title: ");
    scanf("%s", newTask.title);
    printf("Is task completed? (1 for yes, 0 for no): ");
    scanf("%d", &newTask.completed);

    tasks[numTasks++] = newTask;
    printf("Task added successfully.\n");
}

void updateTask() {
    int id, found = 0;
    printf("Enter task ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == id) {
            printf("Enter new title: ");
            scanf("%s", tasks[i].title);
            printf("Is task completed? (1 for yes, 0 for no): ");
            scanf("%d", &tasks[i].completed);
            found = 1;
            printf("Task updated successfully.\n");
            break;
        }
    }

    if (!found)
        printf("Task with ID %d not found.\n", id);
}

void deleteTask() {
    int id, found = 0;
    printf("Enter task ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == id) {
            for (int j = i; j < numTasks - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            numTasks--;
            found = 1;
            printf("Task deleted successfully.\n");
            break;
        }
    }

    if (!found)
        printf("Task with ID %d not found.\n", id);
}

void searchTask() {
    char keyword[50];
    printf("Enter keyword to search for: ");
    scanf("%s", keyword);

    printf("Search Results:\n");
    for (int i = 0; i < numTasks; i++) {
        if (strstr(tasks[i].title, keyword) != NULL) {
            printf("ID: %d, Title: %s, Priority: %s, Completed: %s\n",
                   tasks[i].id, tasks[i].title, tasks[i].priority,
                   tasks[i].completed ? "Yes" : "No");
        }
    }
}

void sortTasks() {
    for (int i = 0; i < numTasks - 1; i++) {
        for (int j = 0; j < numTasks - i - 1; j++) {
            if (strcmp(tasks[j].title, tasks[j + 1].title) > 0) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
    printf("Tasks sorted successfully.\n");
}

void displayTasks() {
    printf("All Tasks \n");
    for (int i = 0; i < numTasks; i++) {
        printf("ID: %d, Title: %s, Priority: %s, Completed: %s\n",
               tasks[i].id, tasks[i].title, tasks[i].priority,
               tasks[i].completed ? "Yes" : "No");
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addTask();
                break;
            case 2:
                updateTask();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                searchTask();
                break;
            case 5:
                sortTasks();
                break;
            case 6:
                displayTasks();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 0);

    return 0;
}

