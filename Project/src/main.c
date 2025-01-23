#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Subject
{
    // Seg Fault
    // char *subject_name;
    // char *teacher_fullname;
    char subject_name[20];
    char teacher_fullname[20];
    struct Subject *next;
};

struct subject_grade
{
    struct Subject *subj_ptr;
    char grade[1];
    struct subject_grade *next;
};

struct Student
{
    char *student_name;
    struct subject_grade *subj_grade_ptr; // ptr to a linked list of subject grade
    struct Student *next;
};

struct Subject *create_subject(char **subject_name, char **teacher_fullname)
{
    struct Subject *new_subject = malloc(sizeof(struct Subject));

    if (new_subject == NULL)
    {
        printf("memory allocation failed\n");
        return NULL;
    }

    strncpy(new_subject->subject_name, *subject_name, strlen(*subject_name));
    strncpy(new_subject->teacher_fullname, *teacher_fullname, strlen(*teacher_fullname));
    // printf("%s %s\n", new_subject->subject_name, new_subject->teacher_fullname);
    return new_subject;
}

void add_subject(struct Subject **head, char **subject_name, char **teacher_fullname)
{
    struct Subject *new_subj = create_subject(subject_name, teacher_fullname);

    if (*head == NULL)
    {
        *head = new_subj;
        return;
    }

    struct Subject *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_subj;
}

struct Subject *find_subject(struct Subject **head, char **subject_name)
{
    struct Subject *temp = *head;

    while (strncmp(temp->subject_name, *subject_name, strlen(*subject_name)))
    {
        if (temp->next == NULL)
            return NULL;

        temp = temp->next;
    }

    return temp;
}

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

void display_all_subjects(struct Subject **head)
{
    struct Subject *temp = *head;
    while (temp->next != NULL)
    {
        printf("%s\n", temp->subject_name);
        temp = temp->next;
    }
}

struct Student *create_student(char **student_name, char **subject_name, char **grade)
{
    struct Student *new_student = malloc(sizeof(struct Student));

    if (new_student == NULL)
    {
        printf("memory allocation failed\n");
        return NULL;
    }

    strncpy(new_student->student_name, *student_name, strlen(*student_name));

    return new_student;
}

void add_student(struct Student **head, char **student_name, char **subj_name, char **grade)
{
    struct Student *new_student = create_student(student_name, subj_name, grade);

    if (*head == NULL)
    {
        *head = new_student;
        return;
    }

    struct Student *temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_student;
}

struct Student *find_student(struct Student **head, char **student_name)
{
    struct Student *temp = *head;

    while (strncmp(temp->student_name, *student_name, strlen(*student_name)))
    {
        if (temp->next == NULL)
            return NULL;

        temp = temp->next;
    }

    return temp;
}

struct Student *find_students_of_subject(struct Student **head, char **student_name)
{
    struct Student *temp = *head;

    while (temp->next != NULL)
    {

        int len = sizeof(temp->student_name);

        temp = temp->next;
    }

    while (strncmp(temp->student_name, *student_name, strlen(*student_name)))
    {
        if (temp->next == NULL)
            return NULL;

        temp = temp->next;
    }

    return temp;
}

int main(void)
{

    struct Subject *head = NULL;

    char *subj_name = "Maths";
    char *teacher_fullname = "John";

    add_subject(&head, &subj_name, &teacher_fullname);
    add_subject(&head, &subj_name, &teacher_fullname);

    display_all_subjects(&head);

    char *random = "Random";

    struct Subject *found = find_subject(&head, &random);

    if (found == NULL)
    {
        printf("Subject Not Found\n");
    }
    else
    {
        printf("It worked: %s\n", found->subject_name);
    }

    struct Subject *found_teacher = find_teacher_of_subject(&head, &teacher_fullname);

    if (found == NULL)
    {
        printf("Subject Not Found\n");
    }
    else
    {
        printf("It worked: %s\n", found->subject_name);
    }

    // Student

    char *stu_name = "John";
    char *subj_str = "Maths";
    char *grade = "A"; // Change or keep

    struct Student *stu_head = NULL;

    add_student(&stu_head, &stu_name, &subj_str, &grade);

    return 0;
}