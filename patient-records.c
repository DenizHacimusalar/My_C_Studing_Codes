#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PATIENTS 1000
#define MAX_NAME_LENGTH 50
#define EMERGENCY_THRESHOLD 39.0
#define FEVER_THRESHOLD 37.5
#define FILE_NAME "patient_records.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float temperature;
    int heart_rate;
    char symptoms[100];
    time_t timestamp;
} Patient;

Patient patients[MAX_PATIENTS];
int patient_count = 0;

void add_patient();
void display_patients();
void check_emergencies();
void save_to_file();
void load_from_file();

int main() {
    int choice;
    load_from_file();

    while (1) {
        printf("\nEmergency Patient Monitoring System\n");
        printf("1. Add New Patient\n");
        printf("2. Display All Patients\n");
        printf("3. Check Emergency Cases\n");
        printf("4. Save Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_patient();
                break;
            case 2:
                display_patients();
                break;
            case 3:
                check_emergencies();
                break;
            case 4:
                save_to_file();
                break;
            case 5:
                save_to_file();
                printf("Exiting program. Data saved.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void add_patient() {
    if (patient_count >= MAX_PATIENTS) {
        printf("Error: Maximum patient limit reached!\n");
        return;
    }

    Patient* p = &patients[patient_count];

    printf("Enter patient name: ");
    fgets(p->name, MAX_NAME_LENGTH, stdin);
    p->name[strcspn(p->name, "\n")] = 0;

    printf("Enter age: ");
    scanf("%d", &p->age);
    getchar();

    printf("Enter temperature (Celsius): ");
    scanf("%f", &p->temperature);
    getchar();

    printf("Enter heart rate (BPM): ");
    scanf("%d", &p->heart_rate);
    getchar();

    printf("Enter symptoms: ");
    fgets(p->symptoms, 100, stdin);
    p->symptoms[strcspn(p->symptoms, "\n")] = 0;

    p->timestamp = time(NULL);
    patient_count++;

    if (p->temperature >= EMERGENCY_THRESHOLD) {
        printf("WARNING: Patient requires immediate attention!\n");
    }
}

void display_patients() {
    if (patient_count == 0) {
        printf("No patients in the system.\n");
        return;
    }

    for (int i = 0; i < patient_count; i++) {
        printf("\nPatient %d:\n", i + 1);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Temperature: %.1f\n", patients[i].temperature);
        printf("Heart Rate: %d BPM\n", patients[i].heart_rate);
        printf("Symptoms: %s\n", patients[i].symptoms);
        printf("Recorded: %s", ctime(&patients[i].timestamp));
    }
}

void check_emergencies() {
    int emergencies = 0;

    for (int i = 0; i < patient_count; i++) {
        if (patients[i].temperature >= EMERGENCY_THRESHOLD ||
            patients[i].heart_rate > 120 ||
            patients[i].heart_rate < 50) {
            printf("\nEMERGENCY CASE:\n");
            printf("Name: %s\n", patients[i].name);
            printf("Temperature: %.1f\n", patients[i].temperature);
            printf("Heart Rate: %d BPM\n", patients[i].heart_rate);
            emergencies++;
        }
    }

    if (emergencies == 0) {
        printf("No emergency cases found.\n");
    } else {
        printf("\nTotal emergency cases: %d\n", emergencies);
    }
}

void save_to_file() {
    FILE* file = fopen(FILE_NAME, "wb");
    if (!file) {
        printf("Error: Unable to open file for writing!\n");
        return;
    }

    fwrite(&patient_count, sizeof(int), 1, file);
    fwrite(patients, sizeof(Patient), patient_count, file);
    fclose(file);
    printf("Data saved successfully!\n");
}

void load_from_file() {
    FILE* file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("No existing records found. Starting fresh.\n");
        return;
    }

    fread(&patient_count, sizeof(int), 1, file);
    fread(patients, sizeof(Patient), patient_count, file);
    fclose(file);
    printf("Loaded %d patient records.\n", patient_count);
}
