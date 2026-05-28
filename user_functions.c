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
	printf(">Are you sure you wish to proceed?\n Enter 'Y' to confirm, or 'N' to go back: \n");
	scanf(" %c", &request);
	if (request == 'Y' || request == 'y') {
		return 0;
	}
	else if (request == 'N' || request == 'n') {
		printf(">Reverting previous choice...");
		return 1;
	}
	else {
		printf("\t>Something went wrong while requesting confirmation of a decision.");
		return -1;
	}
}

void checkSelection(int selection) {

	enum startMenu { EXIT, AREG, LOGIN, LOGOUT, DELETE, ADEACT, ACONFIG, MEM_ERASE, T_CLEAR, T_RUNTIME };
	if (selection == EXIT) {
		printf("\n>Exiting application...");
		freeAllAccounts(textFilePointer);
		memsetZeros(textFilePointer);
		exit(0);
	}
	else if (selection == AREG) {
		accountRegistration();
		//copyToTxt();
	}
	else if (selection == LOGIN) {
		//displayAccountMenu();
		//chooseAccount();
		//accountLogin();
	}
	else if (selection == LOGOUT) {
		//displayAccountMenu();
		//chooseAccount();
		//accountLogout();
	}
	else if (selection == DELETE) {
		//displayAccountMenu();
		//chooseAccount();
		//deleteAccount();
	}
	else if (selection == ADEACT) {
		//displayAccountMenu();
		//chooseAccount();
		//deactivateAccount();
	}
	else if (selection == ACONFIG) {
		//displayAccountMenu();
		//chooseAccount();
		//settingsMenu();
		//chooseSetting();
		// 
		//configureName();
		// ...
	}
	else if (selection == MEM_ERASE) {
		//freeAllAccounts();
		//memsetZeros();
		//clearFileTxt();
	}
	else if (selection == T_CLEAR) {
		//refreshPage();
	}
	else if (selection == T_RUNTIME) {
		//fetchRuntime();
		//displayTotalRuntime();
	}
}

//// REGISTRATION

void accountRegistration() {
	printf(">REGISTRATION WINDOW ------------------------------------------------ \n");
	printf(">Register new User: \n");
	printf("\t>Username: \n");
	//void enterUsername();
	printf("\t>E-mail: \n");
	//void enterEmail();
	printf("\t>Country/Region: \n");
	//void enterRegion();
	printf("\t>Gender: \n");
	//void enterGender();
	printf("\t>Birthday: \n");
	//void enterDate();
	printf("\t>Interests/hobbies: \n");
	//void enterHobby();
	printf(">REGISTRATION WINDOW ------------------------------------------------ \n ");
}
/*
	char username[24];
	char* const password;
	char* const email;
	char* const confirmEmail;
	char* const region;
	char gender; //prima jedan znak // F (female), M (male), N (nonbinary), O (other)
	DATE* birthday;
	char userHobby[30];
	DATE* userSince;
	short userID;
*/

void enterUsername(char* nickname, PROFILE* currentProfile) {
	//scanf("%[^\n]", &nickname);
}

void enterEmail(char* email, char* emailVerif, PROFILE* currentProfile) {
	/*scanf("%[^\n]", &email);
	printf("\t>Confirm e-mail: \n");
	scanf("%[^\n]", &emailVerif);
	do {
		enterEmail(email, emailVerif);
		if (emailVerif != email) {
			printf("\t\t>Could not verify e-mail! Please try again.");
		}
	} while (emailVerif != email);
	if (emailVerif == email) {
		printf("\t\t>E-mail verification successful.");
	}*/
}

void enterRegion(char* region, PROFILE* currentProfile) {

}

void enterGender(char oneLetter, PROFILE* currentProfile) { //(char oneLetter, PROFILE* currentProfile) {...}
	scanf(" %c", &oneLetter);
	if (oneLetter == 'F' || oneLetter == 'M' || oneLetter == 'N' || oneLetter == 'O') {
		//store to currentProfile
	}
	else {
		printf(">Gender could not be logged. Please choose only one among the options provided.");
	}
}

void enterDate(DATE* chosenDate, PROFILE* currentProfile) {
	scanf("%d", &(chosenDate->day));
	if (chosenDate->day > 31 || chosenDate->day < 1) {
		printf(">Invalid day! Please enter again.");
	}
	scanf("%d", &(chosenDate->month));
	if (chosenDate->month > 12 || chosenDate->month < 1) {
		printf(">Invalid month! Please enter again.");
	}
	scanf("%d", &(chosenDate->year));
	if (chosenDate->year > 2026 || chosenDate->year < 1903) {
		printf(">Invalid year! Please enter again.");
	}
}

void enterHobby(char* hobbyPointer, PROFILE* currentProfile) {

}

void copyToTxt(PROFILE* currentProfile, FILE* storage) {

}

//// LOG INTO ACCOUNT
void chooseAccount() {

}

void accountLogin() {

}

//// LOG OUT OF ACCOUNT
void accountLogout() {

}

//// DELETION

void deleteAccount() {

}

//// DEACTIVATION

void deactivateAccount() {

}

//// CLEAR TERMINAL
void refreshPage() {

}

//// TOTAL VSTUDIO TERMINAL RUNTIME
FMTIME fetchDisplayRuntime() {
	FMTIME totalRuntime;
	//return totalRunTime;
}


//// SORTING & SEARCHING ACCOUNTS
void searchByUsername(char* username, char* usernameMatch) {

}

void searchByRegion(char* region, char* regionMatch) {

}

void searchByHobby(char* hobby, char* hobbyMatch) {

}

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

