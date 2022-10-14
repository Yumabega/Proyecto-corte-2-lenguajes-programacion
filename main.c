#include <stdio.h>
#include <string.h>

#define limitStudents 3
#define limitQualities 3
#define defaultPass "123456"

struct teachers {
    char *name;
    char *user;
    char *pass;
};
struct teachers teacher = {"Mario", "profe", defaultPass};

struct students {
    char *name;
    char *user;
    char *pass;
    float notes[limitQualities];
};
struct students studentsList[limitStudents] = {
        {"Juan",  "juan",  defaultPass},
        {"Pedro", "pedro", defaultPass},
        {"Maria", "maria", defaultPass},
};
struct students currentStudent;

void teacherFunc() {
    int teachIngress = 0;
    int opts[limitStudents];
    for (int i = 0; i < limitStudents; ++i) {
        opts[i] = i;
    }
    while (!opts[teachIngress]){
        printf("Para cual estudiante quiere ingresar notas:\n");
        for (int i = 0; i < limitStudents; ++i) {
            printf("%d) Estudiante: %s\n", i+1, studentsList[i].name);
        }
        scanf("%d", &teachIngress);
    }
    teachIngress--;
    int counter = 0;
    float note = 0;
    while (counter < limitQualities){
        printf("Ingrese la nota (%d) para el estudiante '%s':\n", (counter+1), studentsList[teachIngress].name);
        scanf("%f", &note);
        studentsList[teachIngress].notes[counter] = note;
        counter++;
    }
    printf("Gracias por ingresar las notas del estudiante '%s'. Se procede a cerrar sesión\n\n", studentsList[teachIngress].name);
};

void studentFunc(){
    int opt;
    float average = 0;
    float max = 0;
    while (opt != 1 && opt != 2 && opt != 3){
        printf("Ingrese una opcion:\n");
        printf("1) Consultar notas\n");
        printf("2) Promedio notas\n");
        printf("3) Valor más alto notas\n");
        scanf("%d", &opt);
    }
    switch(opt) {
        case 1:
            printf("Sus notas son:\n");
            for (int i = 0; i < limitQualities; ++i) {
                printf("Nota #%d: %f\n", i+1, currentStudent.notes[i]);
            }
            break;
        case 2:
            for (int i = 0; i < limitQualities; ++i) {
                average = average + currentStudent.notes[i];
            }
            printf("Su promedio es: %f\n", average);
            break;
        case 3:
            for (int i = 0; i < limitQualities; ++i) {
                if( max < currentStudent.notes[i] ){
                    max = currentStudent.notes[i];
                }
            }
            printf("Su nota maxima es: %f\n", max);
            break;
    }
    printf("Gracias por ingresar y consultar su información. Se procede a cerrar sesión\n\n");
}

void login() {
    char user[10];
    char pass[10];
    int type = 0;

    printf("Ingrese su usuario:\n");
    scanf("%s", user);

    printf("Ingrese su contraseña:\n");
    scanf("%s", pass);

    if (strcmp(teacher.user, user) == 0 && strcmp(teacher.pass, pass) == 0) {
        printf("Hola profesor: %s\n", teacher.name);
        type = 1;
    }

    for (int i = 0; i < limitStudents; ++i) {
        if (strcmp(studentsList[i].user, user) == 0 && strcmp(studentsList[i].pass, pass) == 0) {
            printf("Hola Estudiante: %s\n", studentsList[i].name);
            currentStudent = studentsList[i];
            type = 2;
            break;
        }
    }
    if (type == 1) {
        teacherFunc();
        login();
    } else if (type == 2) {
        studentFunc();
        login();
    }
}

int main() {
    printf("Bienvenido Colegio Casita Azul\n");
    login();
    return 0;
}
