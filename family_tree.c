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
int main(void) {
    Person *me = create_person("Mahitha", 19);
    if (me == NULL) { 
        return 1; 
    } 
    printf("Name: %s\n", me->name);
    printf("Age: %d\n", me->age);
    free(me);
    return 0;
}
