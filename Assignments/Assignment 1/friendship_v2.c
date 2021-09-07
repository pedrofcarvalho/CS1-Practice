
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAP 5
#define MAX_LEN 100

// Typedefs
typedef struct UserList UserList;
typedef struct User User;

// The struct for storing all users
struct UserList
{
	User ** arr; // not 2d array really (array of pointers)
	int cap, size;
};

// The struct to store the information for a user
struct User
{
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
	for (int i = 0; i < num_friendships; i++)
    {
		addFriendshipFromInput(all_users);
	}

	// Print out friendships
	printAllFriendships(all_users);

	// Destroy friendships
	destroyAllUsers(all_users);

	// Exit program
	return 0;
}


// Array List 1 Creation
UserList * createUserList()
{
    UserList * ret; // dangling pointer (doesn't point to anything)

    // Meaningful code here
    ret = (UserList *) calloc(1, sizeof(UserList));
    // arr (User **), size (int), cap (int)
    // (*ret).size = 0;
    ret->size = 0;
    ret->cap = DEFAULT_CAP;
    ret->arr = (User **) calloc(DEFAULT_CAP, sizeof(User *));

    return ret;
}

// Method to create a user from a given name
User * createUser(char * name)
{
    User * ret;

    ret = (User *) malloc(sizeof(User));

    // Copy in the correct name
    ret->name = (char *) calloc(strlen(name) + 1, sizeof(char));
    // ret->name = (char *) calloc(MAX_LEN + 1, sizeof(char));

    strcpy(ret->name, name);

    // Array list values
    ret->friends = (char **) calloc(DEFAULT_CAP, sizeof(char *));
    ret->size = 0;
    ret->cap = DEFAULT_CAP;

    return ret;
}

// Add a friendship by reading in the two strings
void addFriendshipFromInput(UserList * user_list)
{
    char name1[MAX_LEN + 1];
    char name2[MAX_LEN + 1]; // +1 for null terminator

    // Read in the friends
    scanf("%s%s", name1, name2);

    // find the index of the inputted friends
    int index1 = findIndex(user_list, name1);
    int index2 = findIndex(user_list, name2);

    // Get the users from the list
    User * u1 = user_list->arr[index1];
    User * u2 = user_list->arr[index2];

    // add the friends to the corresponding users
    addFriendToUser(u1, name2);
    addFriendToUser(u2, name1);
}

// Expand the user list
void expandUser(User * u) {
    // name, friends (of the friends), size, cap
    // * (pointer or array)
    // ** (pointer or array) of (pointer or array)
    int newCap = u->cap * 2;
    u->friends = (char **) realloc(u->friends, newCap * sizeof(char *));
    u->cap = newCap;
}

// Add to array list function
void addFriendToUser(User * u, char * name) { // add to an array list
    // u is an array list
    if (u->size == u->cap) {
        expandUser(u);
    }

    // u->friends[u->size] = name; // TODO fix this please
    u->friends[u->size] = calloc(strlen(name) + 1, sizeof(char));
    strcpy(u->friends[u->size], name);
    u->size++;
}

// Print out all the friendships in the user list
void printAllFriendships(UserList * user_list) {
    for (int i = 0; i < user_list->size; i++) {
        User * curUser = user_list->arr[i];

        // Print out the current user's information
        printf("%s has the following friends\n", curUser->name);
        for (int j = 0; j < curUser->size; j++) { // looping through cur user's friends
            printf("%s ", curUser->friends[j]);
        }

        printf("\n\n"); // separate users with blank lines
    }
}

// Method to free the memory belonging to the entire user list
void destroyAllUsers(UserList * user_list)
{
    for (int i = 0; i < user_list->size; i++)
    {
        User * curUser = user_list->arr[i];

        // Remove the friends' friends
        for (int j = 0; j < curUser->size; j++)
        {
            free(curUser->friends[j]);
        }

        free(curUser->friends);

        // Remove the name
        free(curUser->name);

        // Remove the user
        free(curUser);
    }

    free(user_list->arr);
    free(user_list);
    // Nothing come after this!!!
}

// Method to expand the user list
void expandUserList(UserList * user_list) {
    int newCap = user_list->cap * 2;
    user_list->arr = (User **) realloc(user_list->arr, newCap * sizeof(User *));
    user_list->cap = newCap;
}

// Method to add a single user to the user list
void addUserToUserList(UserList * user_list, char * name) {
    if (user_list->cap == user_list->size) {
        expandUserList(user_list);
    }

    user_list->arr[user_list->size] = createUser(name);
    user_list->size++; // update the number of users
}

// Method to find the index from of a user from the user list given the users name
int findIndex(UserList * user_list, char * name_to_find)
{
    int ret;

    for (int i = 0; i < user_list->size; i++)
    {
        User * curUser = user_list->arr[i];

        if (strcmp(name_to_find, curUser->name) == 0) // check if the friends are equal
        {
            // We found the user at index i
            return i;
        }
    }

    // We did not find the user :(
    addUserToUserList(user_list, name_to_find);
    ret = user_list->size - 1; // the index of the last value in the array

    return ret;
}














