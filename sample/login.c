
#include <stdio.h>
#include <string.h>
#include <assert.h>

struct Account {
    char username[1024];
    char password[1024];
};

int login (struct Account[], int);
int validateAccount(struct Account[], int, char[], char[]);
void runTests();

int main(int argc, char *argv[]) {

    if(argc > 1 && strcmp(argv[1], "test") == 0) {
        runTests();
        return 0;
    }

    struct Account account_one;
    struct Account account_two;
    struct Account account_three;
    struct Account account_four;

    strcpy(account_one.username, "acct1");
    strcpy(account_one.password, "acct1");
    strcpy(account_two.username, "acct2");
    strcpy(account_two.password, "acct2");
    strcpy(account_three.username, "acct3");
    strcpy(account_three.password, "acct3");
    strcpy(account_four.username, "acct4");
    strcpy(account_four.password, "acct4");
    
    struct Account accounts[4] = { account_one, account_two, account_three, account_four };
    int size = 4;

    login(accounts, size);

    return 0;
}

int login(struct Account accounts[], int size) {

    char input_username[1024];
    char input_password[1024];

    do {

        printf("Username: ");
        scanf("%s", input_username);

        printf("Password: ");
        scanf("%s", input_password);

        int status = validateAccount(accounts, size, input_username, input_password);

        if(status == 0) {
            printf("\nLogin Successfull \n\n");
            return 0;
        }
        else {
            printf("\nInvalid credentials. Try again \n\n");
        }

    } while(1);

}

int validateAccount(struct Account accounts[], int size, char input_username[], char input_password[]) {

    for(int i = 0; i < size; i++) {
        if(strcmp(input_username, accounts[i].username) == 0 && strcmp(input_password, accounts[i].password) == 0) {
            return 0;
        }
    }

    return 1;

}

void runTests() {

    struct Account mock_account;

    strcpy(mock_account.username, "acct_test");
    strcpy(mock_account.password, "acct_test");
    
    struct Account test_accounts[1] = { mock_account };
    int test_size = 1;

    // # test 1: valid credentials should return 0
    assert(validateAccount(test_accounts, test_size, "acct_test", "acct_test") == 0);

    // # test 2: invalid password should return 1
    assert(validateAccount(test_accounts, test_size, "acct_test", "asda") == 1);

    // # test 3: invalid username should return 1
    assert(validateAccount(test_accounts, test_size, "asds", "acct_test") == 1);

    // # test 4: both invalid should return 1
    assert(validateAccount(test_accounts, test_size, "asdasd", "asdas") == 1);

    printf("all unit tests passed successffully\n");
}
