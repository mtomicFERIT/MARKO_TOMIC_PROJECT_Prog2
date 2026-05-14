//// USER_FUNCTIONS.C
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <corecrt_search.h>
//#include <corecrt.h>
#include "project_functions.h"
#include "storage_functions.h"
#include "sort_find.h"

int confirmAction() {
	char request = '32';
	printf("\n");
	printf("Are you sure you wish to proceed?\n Enter 'Y' to confirm, or 'N' to go back: \n");
	scanf(" %c", &request);
	if (request == 'Y' || request == 'y') {
		return 0;
	}
	else if (request == 'N' || request == 'n') {
		printf("\t>Reverting previous choice...");
		return 1;
	}
	else {
		printf("\t>Something went wrong while requesting confirmation of a decision.");
		return -1;
	}
}

void checkSelection(int selection) {
	
	enum startMenu{ EXIT, AREG, LOGIN, LOGOUT, DELETE, ADEACT, ACONFIG, MEM_ERASE, T_CLEAR, T_RUNTIME };
	if (selection == EXIT) {
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
		// ...
		//configure...();
	}
	else if (selection == MEM_ERASE) {
		//freeAllAccounts();
		//memsetZeros();
		//clearFileTxt();
	}
	else if (selection == T_CLEAR) {
		//clearTerminal();
		//goToBeginning();
	}
	else if (selection == T_RUNTIME) {
		//fetchTaskRuntime();
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

void enterUsername(const char* nickname) {
	//scanf("%[^\n]", &nickname);
}

void enterEmail(const char* email, const char* emailVerif) {
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

void enterRegion(const char* region) {

}

void enterGender(char oneLetter) {

}

void enterDate(DATE* chosenDate) {

}

void enterHobby(char* hobbyPointer) {

}

//// DEACTIVATION

void accountDeactivation() {

}

//// DELETION

void accountDeletion() {

}

//// SORTING & SEARCHING ACCOUNTS

//void searchByParam(PROFILE *user_account, const char* profile_parameter) {

//}

void sortProfiles() {

}
