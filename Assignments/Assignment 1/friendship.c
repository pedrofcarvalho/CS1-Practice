
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAP 10
#define MAX_LEN 100

// not efficient
// array (n) of arrays (2) of strings (char array)

// Typedefs
typedef struct UserList UserList;
typedef struct User User;

// The struct for storing all users
struct UserList {
	User ** arr;
	int cap, size;
};

// The struct to store the information for a user
struct User {
	char * name;
	char ** friends;
	int cap, size;
};

// Prototypes
UserList * createUserList();
void addFriendToUser(User *, char *);
void addFriendshipFromInput(UserList *);
void printAllFriendships(UserList *);
void destroyAllUsers(UserList *);
User * createUser(char *);
void expandUser(User *);
void expandUserList(UserList *);
void addUserToUserList(UserList *, char *);
int findIndex(UserList *, char *);

// The main method
int main() {
	// Build the data structure
	UserList * all_users = createUserList();
	
	// Read in all the friendships
	int num_friendships;
	scanf("%d", &num_friendships);
	for (int i = 0; i < num_friendships; i++) {
		addFriendshipFromInput(all_users);
	}
	
	// Print out frienships
	printAllFriendships(all_users);
	
	// Destroy friendships
	destroyAllUsers(all_users);
	
	// Exit program
	return 0;
}


// Array List 1 Creation
UserList * createUserList() {
	// TODO
}

// Add a friendship by reading in the two strings
void addFriendshipFromInput(UserList * user_list) {
	// TODO
}

// Expand the user list
void expandUser(User * u) {
	// TODO
}

// Add to array list function
void addFriendToUser(User * u, char * name) {
	// TODO
}

// Print out all the friendships in the user list
void printAllFriendships(UserList * user_list) {
	// TODO
}

// Method to free the memory belonging to the entire user list
void destroyAllUsers(UserList * user_list) {
	// TODO
}

// Method to create a user from a given name
User * createUser(char * name) {
	// TODO
}

// Method to expand the user list
void expandUserList(UserList * user_list) {
	// TODO
}

// Method to add a single user to the user list
void addUserToUserList(UserList * user_list, char * name) {
	// TODO
}

// Method to find the index from of a user from the user list given the users name
int findIndex(UserList * user_list, char * name_to_find) {
	// TODO
}

