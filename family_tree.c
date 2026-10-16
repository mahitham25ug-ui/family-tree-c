#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person* create_person(const char *name, int age)
{
    Person *person = malloc(sizeof(Person));

    if (person == NULL){
        return NULL;
        }

    strcpy(person->name, name);
    person->age = age;
    person->father = NULL;
    person->mother = NULL;
    return person;
}

void read_person_info(const char *role, char *name_out, int *age_out) {
    printf("Enter name of %s: ", role);
    scanf(" %49[^\n]", name_out);

    printf("Enter age of %s: ", role);
    scanf("%d", age_out);
}

int main(void) {
    char name[7][50]; 
    int age[7]; 
    Person *people[7]; 
 
    read_person_info("paternal grandfather", name[0], &age[0]); 
    read_person_info("paternal grandmother", name[1], &age[1]); 
    read_person_info("maternal grandfather", name[2], &age[2]); 
    read_person_info("maternal grandmother", name[3], &age[3]); 
    read_person_info("father", name[4], &age[4]); 
    read_person_info("mother", name[5], &age[5]); 
    read_person_info("yourself", name[6], &age[6]); 
    for (int i = 0; i < 7; i++) { 
        people[i] = create_person(name[i], age[i]); 
        if (people[i] == NULL) { 
            for (int j = 0; j < i; j++) { 
                free(people[j]); 
            } 
            return 1; 
        } 
    } 
    printf("\nFamily members entered:\n"); 
    for (int i = 0; i < 7; i++) { 
        printf("%s, Age: %d\n", people[i]->name, people[i]->age); 
    } 
    for (int i = 0; i < 7; i++) { 
        free(people[i]); 
    } 
    return 0;
}
