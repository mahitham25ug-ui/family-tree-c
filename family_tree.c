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

void link_parents(Person *child, Person *father, Person *mother) { 
    child->father = father; 
    child->mother = mother; 
} 
 
void print_family_relationships(const Person *me) {
    printf("\n FAMILY TREE RELATIONSHIPS \n");

    printf("1. YOURSELF:\n");
    printf("- Name: %s | Age: %d\n", me->name, me->age);

    if (me->father != NULL) {
        printf("2. PARENTS:\n");
        printf("- Father: %s | Age: %d\n",
               me->father->name, me->father->age);

        if (me->mother != NULL) {
            printf("- Mother: %s | Age: %d\n",
                   me->mother->name, me->mother->age);
        }

        printf("3. PATERNAL GRANDPARENTS (via Father's Pointers):\n");
        if (me->father->father != NULL) {
            printf("- Grandfather: %s | Age: %d\n",
                   me->father->father->name, me->father->father->age);
        }
        if (me->father->mother != NULL) {
            printf("- Grandmother: %s | Age: %d\n",
                   me->father->mother->name, me->father->mother->age);
        }
    }

    if (me->mother != NULL) {
        printf("4. MATERNAL GRANDPARENTS (via Mother's Pointers):\n");
        if (me->mother->father != NULL) {
            printf("- Grandfather: %s | Age: %d\n",
                   me->mother->father->name, me->mother->father->age);
        }
        if (me->mother->mother != NULL) {
            printf("- Grandmother: %s | Age: %d\n",
                   me->mother->mother->name, me->mother->mother->age);
        }
    }
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
 
    link_parents(people[4], people[0], people[1]); 
    link_parents(people[5], people[2], people[3]); 
    link_parents(people[6], people[4], people[5]); 
 
    print_family_relationships(people[6]); 
 
    for (int i = 0; i < 7; i++) { 
        free(people[i]); 
    } 
 
    return 0; 
}    
