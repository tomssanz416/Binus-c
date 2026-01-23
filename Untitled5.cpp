#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_STR 64

typedef enum {
    ROLE_CEO = 1,
    ROLE_CTO,
    ROLE_DIREKTUR,
    ROLE_MANAJER,
    ROLE_LEADER,
    ROLE_STAFF
} RoleType;

typedef union {
    RoleType roleId;
} Role;

typedef struct {
    char username[MAX_STR];
    char email[MAX_STR];
    char password[MAX_STR];
    Role role;
} Account;

typedef struct LoginSystem LoginSystem;
struct LoginSystem {
    Account accounts[MAX_ACCOUNTS];
    int count;

    void (*init)(LoginSystem *self);
    int  (*menu)(void);
    void (*input)(int method, char *idOut, char *passOut);
    int  (*validate)(LoginSystem *self, int method, const char *id, const char *pass, Account **foundOut);
    void (*welcome)(Account *acc);
};

static void readLine(char *buf, int size) {
    if (fgets(buf, size, stdin)) {
        size_t n = strlen(buf);
        if (n > 0 && buf[n - 1] == '\n') buf[n - 1] = '\0';
    }
}

static void initSystem(LoginSystem *self) {
    self->count = MAX_ACCOUNTS;

    strcpy(self->accounts[0].username, "CEO");
    strcpy(self->accounts[0].email, "ceo@company.com");
    strcpy(self->accounts[0].password, "ceo123");
    self->accounts[0].role.roleId = ROLE_CEO;

    strcpy(self->accounts[1].username, "CTO");
    strcpy(self->accounts[1].email, "cto@company.com");
    strcpy(self->accounts[1].password, "cto123");
    self->accounts[1].role.roleId = ROLE_CTO;

    strcpy(self->accounts[2].username, "Direktur");
    strcpy(self->accounts[2].email, "direktur@company.com");
    strcpy(self->accounts[2].password, "dir123");
    self->accounts[2].role.roleId = ROLE_DIREKTUR;

    strcpy(self->accounts[3].username, "Manajer");
    strcpy(self->accounts[3].email, "manajer@company.com");
    strcpy(self->accounts[3].password, "man123");
    self->accounts[3].role.roleId = ROLE_MANAJER;

    strcpy(self->accounts[4].username, "Leader");
    strcpy(self->accounts[4].email, "leader@company.com");
    strcpy(self->accounts[4].password, "lead123");
    self->accounts[4].role.roleId = ROLE_LEADER;

    strcpy(self->accounts[5].username, "Staff");
    strcpy(self->accounts[5].email, "staff@company.com");
    strcpy(self->accounts[5].password, "staff123");
    self->accounts[5].role.roleId = ROLE_STAFF;

    strcpy(self->accounts[6].username, "Moderator");
    strcpy(self->accounts[6].email, "moderator@company.com");
    strcpy(self->accounts[6].password, "momod");
    self->accounts[6].role.roleId = ROLE_STAFF;

    strcpy(self->accounts[7].username, "User1");
    strcpy(self->accounts[7].email, "user1@company.com");
    strcpy(self->accounts[7].password, "user1123");
    self->accounts[7].role.roleId = ROLE_STAFF;

    strcpy(self->accounts[8].username, "User2");
    strcpy(self->accounts[8].email, "user2@company.com");
    strcpy(self->accounts[8].password, "user2123");
    self->accounts[8].role.roleId = ROLE_LEADER;

    strcpy(self->accounts[9].username, "Admin");
    strcpy(self->accounts[9].email, "admin@company.com");
    strcpy(self->accounts[9].password, "admin123");
    self->accounts[9].role.roleId = ROLE_MANAJER;
}

static int showMenu(void) {
    int choice;

    printf("=================================\n");
    printf("|       Basic Login Systems     |\n");
    printf("=================================\n");
    printf("1. Login menggunakan Username\n");
    printf("2. Login menggunakan Email\n");
    printf("0. Keluar\n");
    printf("---------------------------------\n");
    printf("Pilih menu: ");

    if (scanf("%d", &choice) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        return -1;
    }
    getchar();
    return choice;
}

static void inputCredential(int method, char *idOut, char *passOut) {
    if (method == 1) {
        printf("Enter Username: ");
        readLine(idOut, MAX_STR);
    } else {
        printf("Enter Email: ");
        readLine(idOut, MAX_STR);
    }

    printf("Enter Password: ");
    readLine(passOut, MAX_STR);
}

static int validateCredential(LoginSystem *self, int method, const char *id, const char *pass, Account **foundOut) {
    int i;
    *foundOut = NULL;

    for (i = 0; i < self->count; i++) {
        Account *acc = &self->accounts[i];  // pointer (struct berindex)

        if (method == 1) {
            if (strcmp(acc->username, id) == 0) {
                if (strcmp(acc->password, pass) == 0) {
                    *foundOut = acc;
                    return 1;
                }
                return 0;
            }
        } else {
            if (strcmp(acc->email, id) == 0) {
                if (strcmp(acc->password, pass) == 0) {
                    *foundOut = acc;
                    return 1;
                }
                return 0;
            }
        }
    }
    return 0;
}

static const char *roleName(RoleType r) {
    switch (r) {
        case ROLE_CEO: return "CEO";
        case ROLE_CTO: return "CTO";
        case ROLE_DIREKTUR: return "Direktur";
        case ROLE_MANAJER: return "Manajer";
        case ROLE_LEADER: return "Leader";
        default: return "Staff";
    }
}

static void welcomeUser(Account *acc) {
    printf("Login Successful\n");
    printf("Selamat Datang %s\n", roleName(acc->role.roleId));
}

int main(void) {
    LoginSystem sys;
    sys.init = initSystem;
    sys.menu = showMenu;
    sys.input = inputCredential;
    sys.validate = validateCredential;
    sys.welcome = welcomeUser;

    sys.init(&sys);

    while (1) {
        int choice = sys.menu();

        if (choice == 0) {
            printf("Program selesai.\n");
            break;
        }

        if (choice != 1 && choice != 2) {
            printf("Menu tidak valid.\n\n");
            continue;
        }

        while (1) {
            char id[MAX_STR], pass[MAX_STR];
            Account *found = NULL;

            sys.input(choice, id, pass);

            if (sys.validate(&sys, choice, id, pass, &found)) {
                sys.welcome(found);
                return 0;
            } else {
                printf("Email/Username or Password Wrong, Please try again\n\n");
            }
        }
    }

    return 0;
}

