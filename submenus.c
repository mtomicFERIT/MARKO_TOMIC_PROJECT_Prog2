//// SUBMENUS.C
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

enum startMenu { EXIT, AREG, LOGIN, LOGOUT, DELETE, SORTSEARCH, ERASE_MENU, FILE_MENU }OPTIONS;

void menuMain() {
	int selection = 0;

	printf(">Loading... \n");
	printf(">MAIN MENU ------------------------------------------------ \n");
	printf("\n");
	printf("\t %d - Exit \n", EXIT);
	printf("\t %d - Register new account \n", AREG);
	printf("\t %d - Log into an already existing account \n", LOGIN);
	printf("\t %d - Log out of your account \n", LOGOUT);
	printf("\t %d - Delete your account \n", DELETE);
	printf("\t %d - Sort & search profiles \n", SORTSEARCH);
	//printf("\t %d - Configure account settings \n", ACONFIG);
	printf("\t %d - Access memory menu \n", ERASE_MENU);
	printf("\t %d - Access storage text file menu \n", FILE_MENU);
	printf("\n");
	printf(">MAIN MENU ------------------------------------------------ \n");
	printf("\n");
	printf(">Please input a number to select an action: \t");

	do {
		scanf("%d", &selection);
		if (selection < 0 || selection >= 7) {
			printf(">Selection cannot be decimal or negative!\n");
			printf(">Selection must be in range from 0 to 7.\n");
			printf(">Please input a new number to select an action: \t");
		}
		else if ((isalpha(selection))) {
			printf(">Please enter a number!\n");
			printf(">Exiting program... \t");
			exit(EXIT_FAILURE);
		}
	} while ((selection < 0 || selection >= 7));

	printf("\n>Selection memorised.\n");
	printf(">Option selected: %d\n", selection);

	checkSelection(selection);

}

int queryMainMenu() {
	char queryAnswer = 'a';
	printf("Would you like to return to the main menu? Type 'Y' for yes.\n");
	scanf("%c", &queryAnswer);
	if (queryAnswer == 'Y' || queryAnswer == 'y') {
		menuMain();
		return 0;
	}
	else {
		return 1;
	}
}

void displayAccountMenu(PROFILE* profileArray, int numAccounts) {
	int di;
	int flagLastProfile = 0;
	printf("\n");
	printf("ACCOUNT MENU -------------------------------------");
	printf("\n");
	printf(">CURRENTLY AVAILABLE ACCOUNTS: \n");
	if (numAccounts <= 0) {
		printf(">There are no accounts to choose from.\n");
		printf(">You must register some accounts first!\n");
	}
	else {
		for (di = 0; di < numAccounts; di++) {
			//printf("[%d]. ", i + 1);
			printAccount(&profileArray[di]);
		}
		printf("ACCOUNT MENU -------------------------------------");
	}
	printf("\n");
	printf("ACCOUNT MENU -------------------------------------");
}

void memoryMenu() {
	//enum eraseMenu {DEL_ACC, DEL_ALL}OPTIONS_MEM;
}

void fileMenu() {
	//enum txtMenu {RENAME, CLEAN}OPTIONS_TXT;
}

void settingsMenu() {
	//displayAccountMenu();
	//chooseAccount();
	//settingsMenu();
	//chooseSetting();
	// ...
	//configureName();
	// ...
}