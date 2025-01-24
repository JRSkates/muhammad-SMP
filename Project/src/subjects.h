#ifndef _SUBJECTS_H_
#define _SUBJECTS_H_

// This structure represents a subject
// subject_name: A fixed-length string for the name of the subject
// teacher_fullname: A fixed-length string for the name of the teacher teaching the subject
// next: A pointer to the next subject in a linked list
struct Subject
{
    // Seg Fault
    // char *subject_name;
    // char *teacher_fullname;
    char subject_name[20];
    char teacher_fullname[20];
    struct Subject *next;
};

// This structure links a subject to a grade for a student

// subj_ptr: A pointer to a struct Subject (the subject being graded)
// grade: A single-character grade
// next: A pointer to the next subject-grade pair in a linked list
struct subject_grade
{
    struct Subject *subj_ptr;
    char grade[5];
    struct subject_grade *next;
};


// Function declarations
struct Subject *create_subject(char **subject_name, char **teacher_fullname);
void add_subject(struct Subject **head, char **subject_name, char **teacher_fullname);
struct Subject *find_subject(struct Subject **head, char **subject_name);
void display_all_subjects(struct Subject **head);
void find_teacher_of_subject(struct Subject **head, char **subject_name);

#endif // _SUBJECTS_H_