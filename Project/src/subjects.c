#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "subjects.h"

// Creates a new Subject node and initializes it with the given subject_name and teacher_fullname

// Allocates memory for a new Subject
// Copies subject_name and teacher_fullname into the new node.
// Sets the next pointer to NULL
struct Subject *create_subject(char **subject_name, char **teacher_fullname) {
    struct Subject *new_subject = malloc(sizeof(struct Subject));
    if (new_subject == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Safely copy the subject name and teacher name
    strncpy(new_subject->subject_name, *subject_name, sizeof(new_subject->subject_name) - 1);
    new_subject->subject_name[sizeof(new_subject->subject_name) - 1] = '\0'; // Null-terminate
    strncpy(new_subject->teacher_fullname, *teacher_fullname, sizeof(new_subject->teacher_fullname) - 1);
    new_subject->teacher_fullname[sizeof(new_subject->teacher_fullname) - 1] = '\0'; // Null-terminate

    new_subject->next = NULL; // Initialize next pointer
    return new_subject;
}

// Adds a new Subject to the linked list of subjects

// Creates a new Subject node using create_subject
// Adds the new node to the end of the linked list
void add_subject(struct Subject **head, char **subject_name, char **teacher_fullname) {
    struct Subject *new_subj = create_subject(subject_name, teacher_fullname);
    if (new_subj == NULL) {
        return; // Memory allocation failed
    }

    if (*head == NULL) {
        *head = new_subj; // First subject in the list
        return;
    }

    struct Subject *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_subj; // Add new subject to the end of the list
}

// searches for a subject in the linked list by name

// Traverses the list of Subject nodes
// Compares the subject_name field of each node to the input
struct Subject *find_subject(struct Subject **head, char **subject_name) {
    if (head == NULL || *head == NULL) {
        return NULL; // No subjects in the list
    }

    struct Subject *temp = *head;
    while (temp != NULL) {
        // Compare subject names
        if (strncmp(temp->subject_name, *subject_name, sizeof(temp->subject_name)) == 0) {
            return temp; // Subject found
        }
        temp = temp->next;
    }
    return NULL; // Subject not found
}

// Finds the first subject taught by a specific teacher

// Traverses the subject list and compares teacher_fullname with teacher_name
// Returns the matching Subject or NULL
struct Subject *find_teacher_of_subject(struct Subject **head, char **teacher_name)
{
    struct Subject *temp = *head;

    while (strncmp(temp->teacher_fullname, *teacher_name, strlen(*teacher_name)))
    {
        if (temp->next == NULL)
            return NULL;

        temp = temp->next;
    }

    return temp;
}

//  prints all the subjects and their corresponding teachers in the linked list
void display_all_subjects(struct Subject **head) {
    if (head == NULL || *head == NULL) {
        printf("No subjects available.\n");
        return;
    }

    struct Subject *temp = *head;
    while (temp != NULL) {
        printf("Subject: %s, Teacher: %s\n", temp->subject_name, temp->teacher_fullname);
        temp = temp->next;
    }
}