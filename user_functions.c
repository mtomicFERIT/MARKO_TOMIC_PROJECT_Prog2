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
//-----------------------------//
#define MAX_P 32
//-----------------------------//
extern FILE* textFilePointer;

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

void checkSelection(int selection) {

	enum startMenu { EXIT, AREG, LOGIN, LOGOUT, DELETE, SORTSEARCH, ERASE_MENU, FILE_MENU };
	if (selection == EXIT) {
		freeAllAccounts(textFilePointer);
		memsetZeros(textFilePointer);
		printf("\n>Exiting application...");
		exit(0);
	}
	else if (selection == AREG) {
		accountRegistration();
		//copyToTxt();
	}
	else if (selection == LOGIN) {
		//displayAccountMenu();
		//chooseAccount();
		//loginToAccount();
	}
	else if (selection == LOGOUT) {
		//displayAccountMenu();
		//chooseAccount();
		//logoutOfAccount();
	}
	else if (selection == DELETE) {
		//displayAccountMenu();
		//chooseAccount();
		//deleteAccount();
	}
	else if (selection == SORTSEARCH) {
		
	}
	else if (selection == ERASE_MENU) {
		
	}
	else if (selection == FILE_MENU) {

	}

}

//// ACCOUNT REGISTRATION

void accountRegistration() {
	PROFILE profileDatabase[MAX_P] = { 0 };
	PROFILE* regProfile = NULL;
	int regIter = 0;
	int accQuantity = 0;

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
		printf("\n>User successfully registered!\n");
	}
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

void copyToTxt(PROFILE* currentProfile, FILE* storage) {
	isPointerValidProfile(currentProfile);
	if (storage == NULL) {
		perror("\nStorage file pointer pointed at null!\n");
		printf(">Storage not accessible.");
	}

	fprintf(storage, "\n");
	fprintf(storage, "Username: %s \n", currentProfile->username);
	fprintf(storage, "Region: %s \n", currentProfile->region);
	fprintf(storage, "Hobby: %s \n", currentProfile->userHobby);
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

void deleteAccount(PROFILE* profileArray, int* numAccounts, int targetID, PROFILE** activeSession) {
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

	if (*activeSession != NULL && *activeSession == &profileArray[foundIndex]) {
		printf(">Notice: Deleting the currently active account. Logging out...\n");
		*activeSession = NULL;
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

int compareByID(PROFILE* firstAcc, PROFILE* secondAcc) {
	return firstAcc->userID > secondAcc->userID;
}

int compareByAge(PROFILE* firstAcc, PROFILE* secondAcc) {
	return firstAcc->age > secondAcc->age;
}

int compareByUsername(PROFILE* firstAcc, PROFILE* secondAcc) {
	return strcmp(firstAcc->username, secondAcc->username) > 0;
}

int compareByRegions(PROFILE* firstAcc, PROFILE* secondAcc) {
	return strcmp(firstAcc->region, secondAcc->region) > 0;
}

int compareByHobbies(PROFILE* firstAcc, PROFILE* secondAcc) {
	return strcmp(firstAcc->userHobby, secondAcc->userHobby) > 0;
}

void searchByUsername(char* username, char* usernameMatch) {

}

void searchByRegion(char* region, char* regionMatch) {

}

void searchByHobby(char* hobby, char* hobbyMatch) {

}