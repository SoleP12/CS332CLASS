#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LISTINGS 1000
#define LINESIZE 1024

//Example2a Define struct outside of functions
struct listing {
    int id, host_id, minimum_nights, number_of_reviews;
    int calculated_host_listings_count, availability_365;
    char *host_name, *neighbourhood_group, *neighbourhood, *room_type;
    float latitude, longitude, price;
};

//Example 2b Function to parse a line into a struct listing
struct listing getfields(char* line) {
    struct listing item;

    item.id = atoi(strtok(line, ","));
    item.host_id = atoi(strtok(NULL, ","));
    item.host_name = strdup(strtok(NULL, ","));
    item.neighbourhood_group = strdup(strtok(NULL, ","));
    item.neighbourhood = strdup(strtok(NULL, ","));
    item.latitude = atof(strtok(NULL, ","));
    item.longitude = atof(strtok(NULL, ","));
    item.room_type = strdup(strtok(NULL, ","));
    item.price = atof(strtok(NULL, ","));
    item.minimum_nights = atoi(strtok(NULL, ","));
    item.number_of_reviews = atoi(strtok(NULL, ","));
    item.calculated_host_listings_count = atoi(strtok(NULL, ","));
    item.availability_365 = atoi(strtok(NULL, ","));

    return item;
}

// Function to display a listing
void displayListing(struct listing item) {
    printf("ID: %d, Host ID: %d, Host Name: %s, Neighborhood Group: %s\n",
        item.id, item.host_id, item.host_name, item.neighbourhood_group);
    printf("Neighborhood: %s, Latitude: %.2f, Longitude: %.2f, Room Type: %s\n",
        item.neighbourhood, item.latitude, item.longitude, item.room_type);
    printf("Price: %.2f, Min Nights: %d, Reviews: %d, Listings Count: %d, Availability: %d\n\n",
        item.price, item.minimum_nights, item.number_of_reviews,
        item.calculated_host_listings_count, item.availability_365);
}

// Main function to read and display listings
int main() {
    //Example2c
    FILE *fptr = fopen("listings.csv", "r");
    if (fptr == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char line[LINESIZE];
    struct listing list_items[MAX_LISTINGS];

    // Example 2d
    int count = 0;
    // Skip header line
    fgets(line, LINESIZE, fptr);

    // Read lines
    while (fgets(line, LINESIZE, fptr) != NULL && count < MAX_LISTINGS) {
        list_items[count++] = getfields(line);
    }

    //Example 2e Display listings
    for (int i = 0; i < count; i++) {
        displayListing(list_items[i]);
    }
    
    fclose(fptr);
    return 0;
}



// gcc -o jlplayerlab6 jlplayerlab6.c
// ./jlplayerlab6







