/ Remove a car from the garage
void removeCar(Garage *g, char *plate) {
    if (isEmpty(g)) {
        printf("Car %s is not in the garage.\n", plate);
        return;
    }

    int moves = 0;
    Car movedCars[MAX_CAPACITY];  // Temporary storage for moved cars
    int movedCount = 0;

    // Move the cars blocking the desired car out
    while (g->top >= 0 && strcmp(g->garage[g->top].licensePlate, plate) != 0) {
        // Move the cars that are blocking the desired car out
        printf("Car %s moved out.\n", g->garage[g->top].licensePlate);
        movedCars[movedCount++] = g->garage[g->top];  // Store the moved car
        g->garage[g->top].moveCount++;
        g->top--;
        moves++;

    }

    if (g->top >= 0) {
        // The target car is found and ready to depart
        printf("Car %s departed. Moved %d times.\n", plate, moves);
        g->top--;  // Remove the car from the garage
    } else {
        printf("Car %s is not in the garage.\n", plate);
    }

    // Restore the moved cars back to the garage in the original order
    for (int i = 0; i < movedCount; i++) {
        g->top++;
        g->garage[g->top] = movedCars[i];
        printf("Car %s restored to the garage.\n", g->garage[g->top].licensePlate);
    }
}
