/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Section    : ZRA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "core.h"

#include "clinic.h"


void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}


void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}


void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}


void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, empty = 0;
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            empty++;
        }
        else
        {
            displayPatientData(&patient[i], fmt);
        }
    }
    if (empty == max)
    {
        printf("*** No records found ***\n");
    }
    printf("\n");
}


void searchPatientData(const struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");

        selection = inputIntRange(0, 2);
        putchar('\n');

        switch (selection)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

void addPatient(struct Patient patient[], int max)
{
    int index = -1, i, quit = 1, full = 0;
    for (i = 0; i < max && quit; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            index = i;
            quit = 0;
        }
        else
        {
            full++;
        }
    }
    if (full == max)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n\n");
    }
}


void editPatient(struct Patient patient[], int max)
{
    int patientNumber, index;

    printf("Enter the patient number: ");
    patientNumber = inputIntRange(1, 99999);
    putchar('\n');
    index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        menuPatientEdit(&patient[index]);
    }
}


void removePatient(struct Patient patient[], int max)
{
    int patientNumber, index;
    char decision;

    printf("Enter the patient number: ");
    patientNumber = inputIntRange(1, 99999);
    putchar('\n');
    index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        displayPatientData(&patient[index], FMT_FORM);
        putchar('\n');
        printf("Are you sure you want to remove this patient record? (y/n): ");
        decision = inputCharOption("yn");
        if (decision == 'y')
        {
            patient[index].patientNumber = 0;
            strcpy(patient[index].name, "\0");
            strcpy(patient[index].phone.number, "\0");
            strcpy(patient[index].phone.description, "\0");
            printf("Patient record has been removed!\n\n");
        }
        else if (decision == 'n')
        {
            printf("Operation aborted.\n\n");
        }
    }
}


void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNumber, index;

    printf("Search by patient number: ");
    patientNumber = inputIntRange(1, 99999);
    putchar('\n');
    index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
    {
        printf("*** No records found ***\n\n");
    }
    else
    {
        displayPatientData(&patient[index], FMT_FORM);
        putchar('\n');
    }
}


void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, none = 0;
    char phoneNumber[PHONE_LEN];

    printf("Search by phone number: ");
    inputCString(phoneNumber, 10, 10);
    putchar('\n');
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        int index, quit = 1;
        for (index = 0; index < PHONE_LEN && quit; index++)
        {
            if (patient[i].phone.number[index] != phoneNumber[index])
            {
                quit = 0;
            }
        }
        if (quit)
        {
            displayPatientData(&patient[i], FMT_TABLE);
        }
        else
        {
            none++;
        }
    }
    if (none == max)
    {
        printf("\n*** No records found ***\n");
    }
    putchar('\n');
}


int nextPatientNumber(const struct Patient patient[], int max)
{
    int index, nextNum = 0, exit = 1;
    for (index = 0; index < max && exit; index++)
    {
        int i, largest = 1, quit = 1;
        for (i = 0; i < max && quit; i++)
        {
            if (patient[index].patientNumber < patient[i].patientNumber)
            {
                largest = 0;
                quit = 0;
            }
        }
        if (largest == 1)
        {
            nextNum = patient[index].patientNumber + 1;
            exit = 0;
        }
    }
    return nextNum;
}

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int result = -1, i, quit = 1;

    for (i = 0; i < max && quit; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            result = i;
            quit = 0;
        }
    }

    return result;
}


void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
}

void inputPhoneData(struct Phone* phone)
{
    int selection;

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(1, 4);
    putchar('\n');
    switch (selection)
    {
    case 4:
        strcpy(phone->number, "\0");
        strcpy(phone->description, "TBD");
        break;
    case 1:
        strcpy(phone->description, "CELL");
        printf("Contact: CELL\n");
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        putchar('\n');
        break;
    case 2:
        strcpy(phone->description, "HOME");
        printf("Contact: HOME\n");
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        putchar('\n');
        break;
    case 3:
        strcpy(phone->description, "WORK");
        printf("Contact: WORK\n");
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        putchar('\n');
        break;
    }
}