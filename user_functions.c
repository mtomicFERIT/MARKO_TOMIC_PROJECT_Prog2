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

int confirmAction(char request) {
	if (request == 'Y' || request == 'y') {
		return 0;
	}
	else if (request == 'N' || request == 'n') {
		printf("\n\t>Reverting previous choice...");
		return 1;
	}
	else {
		printf("\n>Something went wrong while requesting confirmation of a decision.");
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

void accountRegistration() {
	printf(">REGISTRATION WINDOW ------------------------------------------------ \n");
	printf(">Register new User: \n");
	printf("\t>Username: \n");
	//void enterUsername(const char* username);
	printf("\t>E-mail: \n");
	//void enterEmail(const char*);
	printf("\t>Confirm e-mail: \n");
	//const char* confirmEmail(const char*);
	printf("\t>Country: \n");
	//void enterRegion(const char* region);
	printf("\t>Gender: \n");
	//void enterGender(char oneLetter);
	printf("\t>Age in years: \n");
	//void enterDateOfBirth(DATE* age);
	printf("\t>Interests/hobbies: \n");
	//void enterHobby(char* hobbyPointer);
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
	short userID;
	//short hasAdminPerms; // (0 - No, 1 - Yes)
*/

void enterUsername(char* const username) {

}



void accountDeactivation() {

}

void accountDeletion() {

}

//void searchByParam(PROFILE *user_account, const char* profile_parameter) {

//}

void quicksortProfiles() {

}
