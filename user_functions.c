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
	int regIter = 0;
	int accQuantity = 0;
	printf("How many accounts to register?\n");
	scanf("%d", &accQuantity);

	for (regIter = 0; regIter < accQuantity; regIter++) {
		printf("\n");
		printf(">REGISTRATION WINDOW ------------------------------------------------ \n");
		printf(">Register new User: \n");
		//void enterUsername();
		//void enterPassword();
		//void enterEmail();
		printf("\t>Age:\n");
		//void enterAge();
		printf("\t>Country/Region: \n");
		//void enterRegion();
		printf("\t>Interests/Hobbies: \n");
		//void enterHobby();
		printf(">REGISTRATION WINDOW ------------------------------------------------ \n ");
	}

}
/*
	short userID;
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
	printf("%31s\n", hiddenPassword);
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
					printf(">Dot detected at index %d.\n", emIter + 1);
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

}

void enterRegion(PROFILE* profilePTR) {

}

void enterHobby(PROFILE* profilePTR) {

}

void printAccount() {
	PROFILE* currentProfile;
	currentProfile = NULL;
	printf("Username: %31s \n", currentProfile->username);
	printf("Region: %51s \n", currentProfile->region);
	printf("Hobby: %31s \n", currentProfile->userHobby);
	printf("Age: %d \n", currentProfile->age);
	printf("Account ID: %d \n", currentProfile->userID);
}

void copyToTxt(PROFILE* currentProfile, FILE* storage) {
	fprintf(storage, "\n");
	fprintf(storage, "Username: %31s \n", currentProfile->username);
	fprintf(storage, "Region: %51s \n", currentProfile->region);
	fprintf(storage, "Hobby: %31s \n", currentProfile->userHobby);
	fprintf(storage, "Age: %d \n", currentProfile->age);
	fprintf(storage, "Account ID: %d \n", currentProfile->userID);
}

//// LOG INTO ACCOUNT
void chooseAccount() {

}

void loginToAccount() {

}

//// LOG OUT OF ACCOUNT
void logoutOfAccount() {

}

//// DELETION

void deleteAccount() {

}

//// SORTING & SEARCHING ACCOUNTS

void sortGeneric(int iter, PROFILE* profile) {

}

void sortByAlphabet(int iter, PROFILE* profile) {

}

void sortByUser(int iter, PROFILE* profile) {

}

void sortByRegion(int iter, PROFILE* profile) {

}

void sortByHobby(int iter, PROFILE* profile) {

}

void searchByUsername(char* username, char* usernameMatch) {

}

void searchByRegion(char* region, char* regionMatch) {

}

void searchByHobby(char* hobby, char* hobbyMatch) {

}