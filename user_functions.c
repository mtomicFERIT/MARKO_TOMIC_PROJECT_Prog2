//// USER_FUNCTIONS.C
#pragma once
#define _CRT_SECURE_NO_WARNINGS
//// LIBRARIES
#include "project_functions.h"
#include "storage_functions.h"
#include "sort_find.h"
//// DEFAULT
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <corecrt_search.h>
//#include <corecrt.h>
//// GLOBAL VARIABLES & INLINE FUNCTIONS
// MACROS
#define MAX_P 32
//
extern int accQuantity;
extern PROFILE* activeSession;
extern FILE* textFilePointer;
extern PROFILE profileArray[32];
extern PROFILE* pArrayPTR;
PROFILE* targetAccount;
PROFILE** activeDelSession;

int confirmAction() {
	char request = '0';
	printf("\n");
	printf(">Are you sure you wish to proceed?\n Enter 'Y' to confirm, or 'N' to exit: \n");
	scanf(" %c", &request);
	if (request == 'Y' || request == 'y') {
		return 0;
	}
	else if (request == 'N' || request == 'n') {
		printf(">Exiting program...");
		exit(EXIT_SUCCESS);
	}
	else {
		printf(">Something went wrong while requesting confirmation of a decision.");
		confirmAction();
		return 0;
	}
}
//// MAKING THE MAIN MENU SELECTION
void checkSelection(int selection, PROFILE* currentProfile, PROFILE* pArrayPTR, int numProfiles) {

	enum startMenu { EXIT, AREG, LOGIN, LOGOUT, DELETE, SORTSEARCH, FILE_MENU };
	if (selection == EXIT) {
		freeAllAccounts(textFilePointer);
		memsetZeros(textFilePointer);
		printf("\n>Exiting application...");
		exit(0);
	}
	else if (selection == AREG) {
		int arIter;
		accountRegistration();
		for (arIter = 0; arIter < accQuantity; arIter++) {
			copyToTxt(&pArrayPTR[arIter], textFilePointer);
		}
	}
	else if (selection == LOGIN) {
		chooseAccount(profileArray, accQuantity);
		loginToAccount(profileArray, accQuantity);
	}
	else if (selection == LOGOUT) {
		chooseAccount(profileArray, accQuantity);
		logoutOfAccount(activeSession);
	}
	else if (selection == DELETE) {
		chooseAccount(profileArray, accQuantity);
		deleteAccount(profileArray, accQuantity, targetAccount, activeDelSession);
	}
	else if (selection == SORTSEARCH) {
		sortMenu(pArrayPTR, numProfiles);
	}
	else if (selection == FILE_MENU) {
		fileMenu(textFilePointer, "account_storage.txt");
	}

}

//// ACCOUNT REGISTRATION

void accountRegistration() {
	PROFILE profileDatabase[MAX_P] = { 0 };
	PROFILE* regProfile = NULL;
	int regIter = 0;

	printf("How many accounts to register?\n");
	//scanf("%d", &accQuantity);
	if (scanf("%d", &accQuantity) != 1) {
		printf(">Invalid input! Returning...\n\n");
		while (getchar() != '\n');
		accountRegistration();
	}
	if (accQuantity > MAX_P) {
		printf(">System capacity is %d accounts. Adjusting to the maximum amount.\n\n", MAX_P);
		accQuantity = MAX_P;
		accountRegistration();
	}
	for (regIter = 0; regIter < accQuantity; regIter++) {
		regProfile = &profileDatabase[regIter];

		regProfile->userID = regIter;
		printf("\n");
		storeAccount(regProfile); // +. copyToTxt(regProfile);
		
		printf(">Registering User %d (System ID: %d) \n\n", regIter + 1, regProfile->userID);

		enterUsername(regProfile);
		enterPassword(regProfile);
		enterEmail(regProfile);
		enterAge(regProfile);
		enterRegion(regProfile);
		enterHobby(regProfile);

		printAccount(regProfile);
		copyToTxt(regProfile, textFilePointer);
		printf("\n>User successfully registered!\n");
	}
	return;
	//queryMainMenu;
}
/*
	int userID;
	int age;
	char username[30];
	char password[30];
	char email[50];
	char region[50];
	char userHobby[30];
*/

void enterUsername(PROFILE* profilePTR) {
	char username[30] = { 0 };
	char* usernamePTR = username;

	while (1) {
		printf(">Enter account username: \n");
		scanf("%29s", usernamePTR);
		if (isdigit(username[0]) == 0 && ispunct(username[0]) == 0) {
			strcpy(profilePTR->username, username);
			break;
		}
		else {
			printf(">The first symbol of a username cannot be a digit or interpunction!\n");
		}
	}
}

void hidePassword(char* passwordPTR) {
	int passPos;
	char hiddenPassword[30] = { 0 };

	for (passPos = 0; passwordPTR[passPos] != '\0'; passPos++) {
		hiddenPassword[passPos] = '*';
	}
	hiddenPassword[passPos] = '\0';

	printf("Your password is %d digits long.\n", passPos);
	printf("%s\n", hiddenPassword);
}

void enterPassword(PROFILE* profilePTR) {
	char password[30] = { 0 };
	char* passwordPTR = password;

	char passVerif[30] = { 0 };
	char* passVerifPTR = passVerif;

	while (1) {
		printf(">Enter password: \n");
		scanf("%29s", passwordPTR);
		hidePassword(passwordPTR);

		printf(">Enter password again for verification: \n");
		scanf("%29s", passVerifPTR);
		hidePassword(passVerifPTR);

		if (strcmp(password, passVerif) == 0) {
			printf(">Password verified!");
			strcpy(profilePTR->password, password);
			break;
		}
		else {
			printf(">Passwords not matching!\n Please enter your password again.\n");

			memset(password, 0, sizeof(password));
			memset(passVerif, 0, sizeof(passVerif));
		}
	}
}

void enterEmail(PROFILE* profilePTR) {
	int emIter;
	int flagDot = 0;
	int flagMonkey = 0;
	char email[50] = { 0 };
	char* emailPTR = email;

	while (1) {
		printf("\n");
		printf(">Enter e-mail: \n");
		scanf("%49s", emailPTR);
		printf("\n");
		printf(">Validating e-mail...\n");

		for (emIter = 0; email[emIter] != '\0'; emIter++) {
			if (email[emIter] == '@') {
				printf("\t>Monkey (@) detected at index %d.\n", emIter + 1);
				flagMonkey = 1;
				break;
			}
		}
		if (flagMonkey == 1) {
			for (/*emIter = 0*/; email[emIter] != '\0'; emIter++) {
				if (email[emIter] == '.') {
					flagDot = 1;
					printf("\t>Dot detected at index %d.\n", emIter + 1);
					break;
				}
			}
		}
		if (flagMonkey == 1 && flagDot == 1) {
			printf(">E-mail is valid! \n");
			strcpy(profilePTR->email, email);
			break;
		}

		else {
			if (flagMonkey == 0) {
				printf("\t>Your e-mail address is missing a monkey sign (@)!\n");
			}
			if (flagDot == 0) {
				printf("\t>Your e-mail adress must feature at least one dot!\n");
			}
			printf(">Please enter your e-mail address again.\n\n");
			flagMonkey = 0;
			flagDot = 0;
			memset(email, 0, sizeof(email));
		}
	}
}

void enterAge(PROFILE* profilePTR) {
	int userAge = 0;

	while (1) {
		printf(">Enter your age: \n");
		//scanf("%d", &userAge);

		if (scanf("%d", &userAge) != 1) {
			printf(">Please enter a number! \n");
			while (getchar() != '\n');
			continue;
		}

		if (userAge <= 12 || userAge > 122) {
			printf(">Please enter a credible age. \n");
			userAge = 0;
		}
		else {
			profilePTR->age = userAge;
			printf(">Age has been retrieved. \n");
			break;
		}
	}
}

void enterRegion(PROFILE* profilePTR) {
	int iter;
	char userRegion[50] = { 0 };
	char* regionPTR = userRegion;
	int flagNotAllowed = 0;

	while (1) {
		printf(">Region/Country: \n");
		scanf("%49s", regionPTR);
		flagNotAllowed = 0;

		for (iter = 0; userRegion[iter] != '\0'; iter++) {
			if (ispunct(userRegion[iter]) || isdigit(userRegion[iter])) {
				flagNotAllowed = 1;
				break;
			}
		}

		if (flagNotAllowed == 0) {
			strcpy(profilePTR->region, userRegion);
			break;
		}
		else {
			printf(">Please use characters only!\n");
			memset(userRegion, 0, sizeof(userRegion));
		}
	}
}

void enterHobby(PROFILE* profilePTR) {
	int i;
	char hobby[30] = { 0 };
	char* hobbyPTR = hobby;
	int flagNotAllowed = 0;

	while (1) {
		printf(">Hobby: \n");
		scanf("%29s", hobbyPTR);
		flagNotAllowed = 0;

		for (i = 0; hobby[i] != '\0'; i++) {
			if (ispunct(hobby[i]) || isdigit(hobby[i])) {
				flagNotAllowed = 1;
				break;
			}
		}

		if (flagNotAllowed == 0) {
			strcpy(profilePTR->userHobby, hobby);
			break;
		}
		else {
			printf(">Please use characters only!\n");
			memset(hobby, 0, sizeof(hobby));
		}
	}
}

void printAccount(PROFILE* currentProfile) {
	isPointerValidProfile(currentProfile);

	printf("\n");
	printf("+====================================================================+\n");
	printf("| PROFILE #%d", currentProfile->userID);
	printf("| \n");
	printf("| Username: %s \n", currentProfile->username);
	printf("| Region: %s \n", currentProfile->region);
	printf("| Hobby: %s \n", currentProfile->userHobby);
	printf("| Age: %d \n", currentProfile->age);
	printf("| \n");
	printf("+====================================================================+\n");
}

void copyToTxt(const PROFILE* currentProfile, FILE* storage) {
	if (currentProfile == NULL) {
		fprintf(stderr, "\n>Error: profile pointer is NULL!");
	}
	if (storage == NULL) {
		fprintf(stderr, "\n>Error: Storage file pointer pointed at NULL!\n");
		printf(">Storage not accessible.");
		return;
	}

	fprintf(storage, "\n");
	fprintf(storage, "Username: %s \n", currentProfile->username ? currentProfile->username : "Unknown");
	fprintf(storage, "Region: %s \n", currentProfile->region ? currentProfile->region : "Unknown");
	fprintf(storage, "Hobby: %s \n", currentProfile->userHobby ? currentProfile->userHobby : "Unknown");
	fprintf(storage, "Age: %d \n", currentProfile->age);
	fprintf(storage, "Account ID: %d \n", currentProfile->userID);
}

//// LOG INTO ACCOUNT // LOG OUT OF ACCOUNT // ACCOUNT SELECT
PROFILE* chooseAccount(PROFILE* profileArray, int numAccounts) {
	PROFILE* selectedAccount = NULL;
	int i;
	int chosenAccID = 0;

	if (numAccounts == 0) {
		printf(">There are no available accounts to choose from!\n\n");
		return NULL;
	}

	while (1) {
		displayAccountMenu(profileArray, numAccounts);
		printf(">Insert the ID of the profile you wish to select: \n");
		scanf("%d", &chosenAccID);

		if (scanf("%d", &chosenAccID) != 1) {
			printf(">Error: Invalid input! Please enter a number.\n\n");
			while (getchar() != '\n');
			continue;
		}
		
		for (i = 0; i <= numAccounts; i++) {
			if (profileArray[i].userID == chosenAccID) {
				selectedAccount = &profileArray[i];
				targetAccount = selectedAccount;
				printf("\n>Profile with ID %d found and selected.\n", selectedAccount->userID);
				printAccount(selectedAccount);

				return selectedAccount;
			}
		}

		printf(">Error: Profile with ID %d does not exist! Please try again.\n\n", chosenAccID);
	}
}

PROFILE* loginToAccount(PROFILE* profileArray, int numAccounts) {
	
	PROFILE* selectedAccount = chooseAccount(profileArray, numAccounts);
	if (selectedAccount == NULL) {
		printf(">Login failed! No account selected.\n");
		return NULL;
	}

	char inputPassword[30] = { 0 };
	int attempts = 3;

	while (attempts > 0) {
		printf("\n>Enter password for user %s: \n", selectedAccount->username);
		scanf("%29s", inputPassword);

		if (strcmp(selectedAccount->password, inputPassword) == 0) {
			printf("\n>>> Login successful! Welcome back, %s. <<<\n", selectedAccount->username);
			return selectedAccount; 
		}
		else {
			attempts--;
			printf(">Incorrect password! Attempts remaining: %d\n", attempts);
		}
	}

	printf(">Too many incorrect attempts. Login blocked for this session.\n");
	return NULL;
}

PROFILE* logoutOfAccount(PROFILE* activeSession) {
	if (activeSession == NULL) {
		printf(">Error: No user is currently logged in.\n");
		return NULL;
	}

	printf("\n>>> User %s has been successfully logged out. <<<\n", activeSession->username);

	// Vraćamo NULL kako bismo poništili aktivnu sesiju
	return NULL;
}

//// ACCOUNT DELETION (FINDING INDEX, MOVING ACCOUNTS, DECREASING CURRENT AMOUNT)

void deleteAccount(PROFILE* profileArray, int* numAccounts, int targetID, PROFILE** activeDelSession) {
	int i, j;
	int foundIndex = -1;

	for (i = 0; i < *numAccounts; i++) {
		if (profileArray[i].userID == targetID) {
			foundIndex = i;
			break;
		}
	}
	if (foundIndex == -1) {
		printf(">Error: Account with ID %d not found.\n", targetID);
		return;
	}

	if (*activeDelSession != NULL && *activeDelSession == &profileArray[foundIndex]) {
		printf(">Notice: Deleting the currently active account. Logging out...\n");
		*activeDelSession = NULL;
	}

	for (j = foundIndex; j < *numAccounts - 1; j++) {
		profileArray[j] = profileArray[j + 1];
	}
	memset(&profileArray[*numAccounts - 1], 0, sizeof(PROFILE));
	(*numAccounts)--;
	printf(">Account with ID %d has been successfully deleted.\n", targetID);
}

//// SORTING & SEARCHING ACCOUNTS
//
// GENERIC PROFILE SORTING (BUBBLE SORT)

enum sortMenuOptions {
	ESCAPE_SMENU, SORT_UNA, SORT_URA, SORT_A, SORT_R, SORT_H, SORT_ID, SEARCH_U,
	SEARCH_AOT, SEARCH_AYT, SEARCH_R, SEARCH_H, SEARCH_ID
};

void sortMenu(PROFILE* profiles, int numProfiles) {
	int sortMenuSelect = 0;

	printf(">SORT-SEARCH MENU ------------------------------------------------ \n");
	printf("\n");
	printf("\t %d - Exit \n", ESCAPE_SMENU);
	printf("\n");
	printf(">SORTING\n");
	printf("\t %d - Sort accounts by username (in alphabetic order) \n", SORT_UNA);
	printf("\t %d - Sort accounts by username (in reverse alphabetic order) \n", SORT_URA);
	printf("\t %d - Sort accounts by age \n", SORT_A);
	printf("\t %d - Sort accounts by region \n", SORT_R);
	printf("\t %d - Sort accounts by hobbies \n", SORT_H);
	printf("\t %d - Sort accounts by ID \n", SORT_ID);
	printf("\n");
	printf(">SEARCHING\n");
	printf("\t %d - Search accounts by username (in alphabetic order) \n", SEARCH_U);
	printf("\t %d - Search accounts by age (older than age set) \n", SEARCH_AOT);
	printf("\t %d - Search accounts by age (younger than age set) \n", SEARCH_AYT);
	printf("\t %d - Search accounts by region (checks if regions match) \n", SEARCH_R);
	printf("\t %d - Search accounts by hobby (checks if hobbies match) \n", SEARCH_H);
	printf("\t %d - Search accounts by ID (first to last) \n", SEARCH_ID);
	printf("\n");
	printf(">SORT-SEARCH MENU ------------------------------------------------ \n");
	printf("\n");
	printf(">Please input a number to select an action: \t");

	while (1) {
		if (scanf("%d", &sortMenuSelect) != 1) {
			printf(">Please enter a valid number!\n");
			while (getchar() != '\n');
			continue;
		}
		//if (sortMenuSelect < 0 || sortMenuSelect >= 13) {
		//	printf(">Selection number is out of bounds!\n Please try again.\n\n");
		//	continue;
		//}
		break;
	}

	switch (sortMenuSelect) {
		//
	case ESCAPE_SMENU: {
		printf(">Escaping SORT-SEARCH menu...\n");
		break;
	}
					 //
	case SORT_UNA: {
		int (*criteria)(PROFILE*, PROFILE*) = compareByUsernameNAlph;
		genericSort(profiles, numProfiles, criteria);
		break;
	}
				 //
	case SORT_URA: {
		int (*criteria)(PROFILE*, PROFILE*) = compareByUsernameRAlph;
		genericSort(profiles, numProfiles, criteria);
		break;
	}
				 //
	case SORT_A: {
		int (*criteria)(PROFILE*, PROFILE*) = compareByAge;
		genericSort(profiles, numProfiles, criteria);
		break;
	}
			   //
	case SORT_R: {
		genericSort(profiles, numProfiles, compareByRegions);
		break;
	}
			   //
	case SORT_H: {
		genericSort(profiles, numProfiles, compareByHobbies);
		break;
	}
			   //
	case SORT_ID: {
		int (*criteria)(PROFILE*, PROFILE*) = compareByID;
		genericSort(profiles, numProfiles, criteria);
		break;
	}
				//
	case SEARCH_U: {
		char soughtUsername[30] = { 0 };
		char* soughtUsernamePTR = soughtUsername;
		if (scanf("%29s", soughtUsername) != 1) {
			printf(">Please enter a valid character!");
		}
		genericSearch(profiles, numProfiles, soughtUsernamePTR, matchByUsername);
		break;
	}
				 //
	case SEARCH_AOT: {
		int cutoffAge = 19;
		char choiceSearch = '0';
		printf("Do you want to change the default cutoff age for this specific search?\n");
		printf("The default is set to %d.\n", cutoffAge);
		scanf("%c", &choiceSearch);
		if (choiceSearch == 'Y' || choiceSearch == 'y') {
			printf(">Enter minimum age cutoff: ");
			if (scanf("%d", &cutoffAge) == 1) {
				genericSearch(profiles, numProfiles, &cutoffAge, matchOlderThan);
				break;
			}
		}
		else {
			genericSearch(profiles, numProfiles, &cutoffAge, matchYoungerThan);
			break;
		}
	}
				   //
	case SEARCH_AYT: {
		int cutoffAge = 19;
		char choiceSearch = '0';
		printf("Do you want to change the default cutoff age for this one search?\n");
		printf("The default is set to %d.\n", cutoffAge);
		scanf("%c", &choiceSearch);
		if (choiceSearch == 'Y' || choiceSearch == 'y') {
			printf(">Enter minimum age cutoff: ");
			if (scanf("%d", &cutoffAge) == 1) {
				genericSearch(profiles, numProfiles, &cutoffAge, matchYoungerThan);
				break;
			}
		}
		else {
			genericSearch(profiles, numProfiles, &cutoffAge, matchYoungerThan);
			break;
		}
	}
				   //
	case SEARCH_R: {
		char soughtRegion[50] = { 0 };
		char* soughtRegionPTR = soughtRegion;
		while (1) {
			if (scanf("%49s", soughtRegion) != 1) {
				printf(">Please enter a valid character!");
				while (getchar() != '\n');
				continue;
			}
			break;
		}
		genericSearch(profiles, numProfiles, soughtRegionPTR, matchByRegion);
		break;
	}
				 //
	case SEARCH_H: {
		char soughtHobby[30] = { 0 };
		char* soughtHobbyPTR = soughtHobby;
		while (1) {
			if (scanf("%29s", soughtHobby) != 1) {
				printf(">Please enter a valid character!");
				while (getchar() != '\n');
				continue;
			}
			break;
		}
		genericSearch(profiles, numProfiles, soughtHobbyPTR, matchByHobby);
		break;
	}
				 //
	case SEARCH_ID: {
		int soughtID = 0;
		printf(">Enter account ID to search for:  ");
		if (scanf("%d", &soughtID) != 1) {
			printf(">Invalid ID number!\n");
			while (getchar() != '\n');
		}
		else {
			genericSearch(profiles, numProfiles, &soughtID, matchByID);
		}
		break;
	}
	default: {
		printf(">Selection is out of bounds!\n");
		queryMainMenu();
	}
	}
}

int compareByID(PROFILE* firstAcc, PROFILE* secondAcc) {
	return firstAcc->userID > secondAcc->userID;
}

int compareByAge(PROFILE* firstAcc, PROFILE* secondAcc) {
	return firstAcc->age > secondAcc->age;
}

int compareByUsernameNAlph(PROFILE* firstAcc, PROFILE* secondAcc) {
	return strcmp(firstAcc->username, secondAcc->username) > 0;
}

int compareByUsernameRAlph(PROFILE* firstAcc, PROFILE* secondAcc) {
	return strcmp(firstAcc->username, secondAcc->username) < 0;
}

int compareByRegions(PROFILE* firstAcc, PROFILE* secondAcc) {
	return strcmp(firstAcc->region, secondAcc->region) > 0;
}

int compareByHobbies(PROFILE* firstAcc, PROFILE* secondAcc) {
	return strcmp(firstAcc->userHobby, secondAcc->userHobby) > 0;
}

void genericSort(PROFILE* profileArray, int numAccounts, int (*compareFunc)(PROFILE*, PROFILE*)) {
	int i, j;
	PROFILE temp;

	for (i = 0; i < numAccounts - 1; i++) {
		for (j = 0; j < numAccounts - i - 1; j++) {

			if (compareFunc(&profileArray[j], &profileArray[j + 1])) {

				temp = profileArray[j];
				profileArray[j] = profileArray[j + 1];
				profileArray[j + 1] = temp;

			}
		}
	}
	printf(">Array successfully sorted using the selected criteria.\n");
}

int matchByUsername(PROFILE* p, void* searchTerm) {
	char* targetUsername = (char*)searchTerm;
	return strcmp(p->username, targetUsername) == 0;
}

int matchOlderThan(PROFILE* p, void* searchTerm) {
	int targetAge = *(int*)searchTerm;
	return p->age > targetAge;
}

int matchYoungerThan(PROFILE* p, void* searchTerm) {
	int targetAge = *(int*)searchTerm;
	return p->age < targetAge;
}

int matchByRegion(PROFILE* p, void* searchTerm) {
	char* targetRegion = (char*)searchTerm;
	return strcmp(p->region, targetRegion) == 0;
}

int matchByHobby(PROFILE* p, void* searchTerm) {
	char* targetHobby = (char*)searchTerm;
	return strcmp(p->userHobby, targetHobby) == 0;
}

int matchByID(PROFILE* p, void* searchTerm) {
	int targetID = *(int*)searchTerm;
	return p->userID > targetID;
}

void genericSearch(PROFILE* profileArray, int numAccounts, void* searchTerm, 
										int (*matchFunc)(PROFILE*, void*)) {
	int i;
	int foundCount = 0;

	printf("\n---------------- SEARCH RESULTS ------------------\n");

	for (i = 0; i < numAccounts; i++) {
		
		if (matchFunc(&profileArray[i], searchTerm)) {
			printAccount(&profileArray[i]); 
			foundCount++;
		}
	}

	if (foundCount == 0) {
		printf(">No profiles matched the given search criteria.\n");
	}
	else {
		printf(">Found %d matching profile(s).\n", foundCount);
	}
	printf("---------------------------------------------------\n\n");
}

