//// ACCOUNT_CONFIG.C // ACCOUNT SETTINGS CONFIGURATION ////
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
#include <io.h>
#include <errno.h>

//// GLOBAL VARIABLES // ACCOUNT_CONFIG.C
// MACROS
#define MAX_P 32
//
extern int accQuantity;
extern PROFILE* activeSession;
extern FILE* textFilePointer;
extern PROFILE profileArray[32];
extern PROFILE* pArrayPTR;
extern PROFILE* targetAccount;
extern PROFILE** activeDelSession;

//// ACCOUNT SETTINGS CONFIGURATION // ALTERING SETTINGS
enum settings { S_CANCEL, S_USERNAME, S_PASSWORD, S_EMAIL, S_REGION, S_HOBBY };

int alterSetting(PROFILE* currentProfile) {
    if (currentProfile == NULL) {
        printf(">Error: Invalid profile data!\n");
        return S_CANCEL;
    }
    int accSettingChosen = 0;

    printf("\n");
    printf(">ACCOUNT SETTINGS ---------------------------------\n");
    printf("%d - Change username  (Current: %s)\n", S_USERNAME, currentProfile->username);
    printf("%d - Change password  (Current: [HIDDEN])\n", S_PASSWORD);
    printf("%d - Change e-mail     (Current: %s)\n", S_EMAIL, currentProfile->email);
    printf("%d - Change region    (Current: %s)\n", S_REGION, currentProfile->region);
    printf("%d - Change hobby     (Current: %s)\n", S_HOBBY, currentProfile->userHobby);
    printf("%d - Cancel and exit menu\n", S_CANCEL);
    printf(">ACCOUNT SETTINGS ---------------------------------\n");

    while (1) {
        printf("Select a setting to modify: ");
        if (scanf("%d", &accSettingChosen) != 1) {
            printf(">Please enter a valid number!\n");
            while (getchar() != '\n');
            continue;
        }

        if (accSettingChosen < S_CANCEL || accSettingChosen > S_HOBBY) {
            printf(">Invalid option. Choose a number between %d and %d.\n", S_CANCEL, S_HOBBY);
            continue;
        }
        break;
    }

    switch (accSettingChosen) {

    case S_USERNAME: {
        printf("Enter new username: ");
        scanf("%29s", currentProfile->username);
        printf(">Username updated successfully!\n");
        break;
    }

    case S_PASSWORD: {
        printf("Enter new password: ");
        scanf("%29s", currentProfile->password);
        printf(">Password updated successfully!\n");
        break;
    }

    case S_EMAIL: {
        printf("Enter new email: ");
        scanf("%49s", currentProfile->email);
        printf("> Email updated successfully!\n");
        break;
    }

    case S_REGION: {
        printf("Enter new region: ");
        scanf("%49s", currentProfile->region);
        printf(">Region updated successfully!\n");
        break;
    }

    case S_HOBBY: {
        printf("Enter new hobby: ");
        scanf("%29s", currentProfile->userHobby);
        printf(">Hobby updated successfully!\n");
        break;
    }

    case S_CANCEL: {
        printf(">Modifications canceled.\n");
        break;
    }

    }
    return accSettingChosen;
}

//// CHANGING SPECIFIC SETTING(S)
void changeUsername(PROFILE* user_account) {

}
