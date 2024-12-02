#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // Use this for Sleep() in Windows

#define MAX_EVENTS 10

// Structure to hold event information
typedef struct {
    char name[50];
    int day, month, year, hour, minute;
} Event;

// Function prototypes
void addEvent(Event *events, int *eventCount);
void simulateClock(Event *events, int eventCount);
int isTimeMatch(Event *event, int day, int month, int year, int hour, int minute);

int main() {
    Event events[MAX_EVENTS];
    int eventCount = 0;

    int choice;
    do {
        printf("\n--- Event Reminder ---\n");
        printf("1. Add Event\n");
        printf("2. Start Virtual Clock\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (eventCount < MAX_EVENTS)
                    addEvent(events, &eventCount);
                else
                    printf("Event list is full!\n");
                break;
            case 2:
                simulateClock(events, eventCount);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to add an event
void addEvent(Event *events, int *eventCount) {
    Event *newEvent = &events[*eventCount];
    printf("Enter event name: ");
    scanf(" %[^\n]", newEvent->name);
    printf("Enter event date (DD MM YYYY): ");
    scanf("%d %d %d", &newEvent->day, &newEvent->month, &newEvent->year);
    printf("Enter event time (HH MM): ");
    scanf("%d %d", &newEvent->hour, &newEvent->minute);

    (*eventCount)++;
    printf("Event added successfully!\n");
}

// Function to simulate the virtual clock
void simulateClock(Event *events, int eventCount) {
    int day = 1, month = 1, year = 2024, hour = 0, minute = 0;

    printf("Starting virtual clock...\n");
    while (1) {
        printf("\nCurrent Virtual Time: %02d/%02d/%04d %02d:%02d\n", day, month, year, hour, minute);

        // Check events
        for (int i = 0; i < eventCount; i++) {
            if (isTimeMatch(&events[i], day, month, year, hour, minute)) {
                printf("Reminder: Event '%s' is happening now!\n", events[i].name);
            }
        }

        // Simulate time passage (increment minute)
        sleep(1); // Pause for 1 second to simulate clock
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
                day++;
                // Simplified month-end logic
                if ((month == 2 && day > 28) || (month == 4 || month == 6 || month == 9 || month == 11 && day > 30) || day > 31) {
                    day = 1;
                    month++;
                    if (month > 12) {
                        month = 1;
                        year++;
                    }
                }
            }
        }
    }
}

// Function to check if event time matches current virtual time
int isTimeMatch(Event *event, int day, int month, int year, int hour, int minute) {
    return event->day == day && event->month == month && event->year == year &&
           event->hour == hour && event->minute == minute;
}
