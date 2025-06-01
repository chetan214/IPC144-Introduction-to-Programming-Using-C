/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
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
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
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

// Add a new patient record to the patient array
// (Copy your code from MS#2)
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

// Edit a patient record from the patient array
// (Copy your code from MS#2)
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

// Remove a patient record from the patient array
// (Copy your code from MS#2)
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

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    int i, empty = 0, members[50], index = 0;

    displayScheduleTableHeader(&data->appointments->date, IS_ALL_RECORDS);
    for (i = 0; i < data->maxAppointments; i++)
    {
        if (data->appointments[i].patientNumber == 0)
        {
            empty++;
        }
        else
        {
            members[index] = i;
            index++;
        }
    }
    if (empty == data->maxAppointments)
    {
        printf("*** No records found ***\n");
    }
    else
    {
        displayAppointmentByDate(index, members, INCLUDE_DATE_FIELD, data);
    }
    printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    struct Date date;

    inputDate(&date);
    putchar('\n');
    searchAppointmentByDate(data, &date);
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment appoint[], const int maxAppoint, struct Patient patient[], const int maxPatient)
{
    int passPatient = 1, passTimeslot = 1, passInterval = 1;
    struct Appointment appInput = { 0 };
    int i, index, result, quit;
    do
    {
        int full = 0;
        quit = 1;

        if (passPatient)
        {
            printf("Patient Number: ");
            appInput.patientNumber = inputIntRange(0, 99999);
        }
        if (passTimeslot)
        {
            inputDate(&appInput.date);
        }
        if (passInterval)
        {
            printf("Hour (0-23)  : ");
            appInput.time.hour = inputIntRange(0, 23);
            printf("Minute (0-59): ");
            appInput.time.min = inputIntRange(0, 59);
        }
        for (i = 0; i < maxAppoint && quit; i++)
        {
            if (appoint[i].patientNumber == 0)
            {
                index = i;
                quit = 0;
            }
            else
            {
                full++;
            }
        }
        if (full == maxAppoint)
        {
            printf("\nERROR: Appointment listing is FULL!\n\n");
            return;
        }
        else
        {
            result = findPatientIndexByPatientNum(appInput.patientNumber, patient, maxPatient);
            if (result == -1)
            {
                printf("\nERROR: Patient record not found!\n\n");
            }
            else
            {
                passPatient = 0;
                quit = 1;
                for (i = 0; i < maxAppoint && quit; i++)
                {
                    if (appoint[i].date.year == appInput.date.year
                        && appoint[i].date.month == appInput.date.month
                        && appoint[i].date.day == appInput.date.day
                        && appoint[i].time.hour == appInput.time.hour
                        && appoint[i].time.min == appInput.time.min)
                    {
                        printf("\nERROR: Appointment timeslot is not available!\n\n");
                        quit = 0;
                    }
                }
                if (quit)
                {
                    passTimeslot = 0;
                    quit = 1;
                    for (i = 0; i < maxAppoint && quit; i++)
                    {
                        if (appInput.time.hour < START_HOUR || appInput.time.hour > END_HOUR
                            || (appInput.time.hour == END_HOUR && appInput.time.min > 0)
                            || appInput.time.min % INTERVAL != 0)
                        {
                            printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", START_HOUR, END_HOUR, INTERVAL);
                            quit = 0;
                        }
                    }
                    if (quit)
                    {
                        passInterval = 0;
                    }
                }
            }
        }
    } while (passPatient || passTimeslot || passInterval);

    appoint[index] = appInput;

    printf("\n*** Appointment scheduled! ***\n\n");
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment appoint[], const int maxAppoint, struct Patient patient[], const int maxPatient)
{
    int number, index, i, quit = 1, result;
    char decision;
    struct Date date;

    printf("Patient Number: ");
    number = inputIntRange(0, 99999);
    index = findPatientIndexByPatientNum(number, patient, maxPatient);
    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        inputDate(&date);
        for (i = 0; i < maxAppoint && quit; i++)
        {
            if (appoint[i].patientNumber == number
                && appoint[i].date.year == date.year
                && appoint[i].date.month == date.month
                && appoint[i].date.day == date.day)
            {
                result = i;
                quit = 0;
            }
        }
        if (quit)
        {
            printf("ERROR: Appointment record not found!\n\n");
        }
        else
        {
            putchar('\n');
            displayPatientData(&patient[index], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");
            decision = inputCharOption("yn");
            if (decision == 'y')
            {
                appoint[result].date.year = 0;
                appoint[result].date.month = 0;
                appoint[result].date.day = 0;
                appoint[result].time.hour = 0;
                appoint[result].time.min = 0;
                appoint[result].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }
            else if (decision == 'n')
            {
                printf("\nOperation aborted.\n\n");
            }
        }
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
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

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, none = 0, j;
    char phoneNumber[PHONE_LEN + 1];

    printf("Search by phone number: ");
    inputCString(phoneNumber, 10, 10);
    putchar('\n');
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        int quit = 1;

        for (j = 0; j < PHONE_LEN && quit; j++)
        {
            if (patient[i].phone.number[j] != phoneNumber[j])
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

// Get the next highest patient number
// (Copy your code from MS#2)
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

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
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

// Search appointment records by date
void searchAppointmentByDate(const struct ClinicData* data, const struct Date* date)
{
    int i, none = 0, members[50], index = 0;

    displayScheduleTableHeader(date, 0);
    for (i = 0; i < data->maxAppointments; i++)
    {
        if (data->appointments[i].date.year == date->year
            && data->appointments[i].date.month == date->month
            && data->appointments[i].date.day == date->day)
        {
            members[index] = i;
            index++;
        }
        else
        {
            none++;
        }
    }
    if (none == data->maxAppointments)
    {
        printf("\n*** No records found ***\n");
    }
    else
    {
        displayAppointmentByDate(index, members, 0, data);
    }
    putchar('\n');
}

// Display appointment records stored by date and time
void displayAppointmentByDate(int count, int members[], int fmt, const struct ClinicData* data)
{
    int sortedIndices[50];
    int i, j;

    for (i = 0; i < count; i++) {
        sortedIndices[i] = members[i];
    }
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            struct Appointment* a1 = &data->appointments[sortedIndices[j]], * a2 = &data->appointments[sortedIndices[j + 1]];

            if ((a1->date.year > a2->date.year) ||
                (a1->date.year == a2->date.year && a1->date.month > a2->date.month) ||
                (a1->date.year == a2->date.year && a1->date.month == a2->date.month && a1->date.day > a2->date.day) ||
                (a1->date.year == a2->date.year && a1->date.month == a2->date.month && a1->date.day == a2->date.day &&
                    (a1->time.hour > a2->time.hour || (a1->time.hour == a2->time.hour && a1->time.min > a2->time.min))))
            {
                int temp = sortedIndices[j];
                sortedIndices[j] = sortedIndices[j + 1];
                sortedIndices[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < count; i++)
    {
        int index = sortedIndices[i];
        if (index >= 0)
        {
            int patientIndex = findPatientIndexByPatientNum(data->appointments[index].patientNumber, data->patients, data->maxPatient);
            if (patientIndex != -1)
            {
                displayScheduleData(&data->patients[patientIndex], &data->appointments[index], fmt);
            }
        }
    }
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
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

// Get user input for phone contact information
// (Copy your code from MS#2)
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

//Get user input for date
void inputDate(struct Date* date)
{
    printf("Year        : ");
    date->year = inputIntRange(0, 9999);
    printf("Month (1-12): ");
    date->month = inputIntRange(1, 12);
    switch (date->month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("Day (1-31)  : ");
        date->day = inputIntRange(1, 31);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("Day (1-30)  : ");
        date->day = inputIntRange(1, 30);
        break;
    case 2:
        if (date->year % 4 == 0)
        {
            printf("Day (1-29)  : ");
            date->day = inputIntRange(1, 29);
        }
        else
        {
            printf("Day (1-28)  : ");
            date->day = inputIntRange(1, 28);
        }
        break;
    }
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int counter = 0, quit = 1;
    FILE* fptr = NULL;

    fptr = fopen(datafile, "r");

    if (fptr != NULL)
    {
        while (quit && fscanf(fptr, "%d|%[^|]|%[^|]|%[^\n]",
            &patients[counter].patientNumber, patients[counter].name,
            patients[counter].phone.description, patients[counter].phone.number) != EOF)
        {
            counter++;
            if (counter >= max)
            {
                quit = 0;
            }
        }
    }
    fclose(fptr);

    return counter;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int counter = 0, quit = 1;
    FILE* fptr = NULL;

    fptr = fopen(datafile, "r");

    if (fptr != NULL)
    {
        while (quit && fscanf(fptr, "%d,%d,%d,%d,%d,%d",
            &appoints[counter].patientNumber, &appoints[counter].date.year, &appoints[counter].date.month,
            &appoints[counter].date.day, &appoints[counter].time.hour, &appoints[counter].time.min) != EOF)
        {
            counter++;

            if (counter >= max)
            {
                quit = 0;
            }
        }
    }
    fclose(fptr);

    return counter;
}