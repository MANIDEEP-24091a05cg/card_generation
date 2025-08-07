#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void check(char password[50])
{
    int lower=0,upper=0,digit=0,special=0,temp=0;
    if(strlen(password))
    {
        for(int i = 0; i < strlen(password); i++)
        {
            if(islower(password[i]))
            {
                lower=1;
            }
            if(isupper(password[i]))
            {
                upper=1;
            }
            if(isdigit(password[i]))
            {
                digit=1;
            }
            if(ispunct(password[i]))
            {
                special=1;
            }
        }
        lower!=0 ? temp+=1 : printf("your password should contain at least one lowercase letter\n");
        upper!=0 ? temp+=1 : printf("your password should contain at least one uppercase letter\n");
        digit!=0 ? temp+=1 : printf("your password should contain at least one digit\n");
        special!=0 ? temp+=1 : printf("your password should contain at least one special character\n");
        if (temp == 4 && strlen(password) > 12) 
        {
            printf("your password is strong\n");
        }
        else if (temp >= 3 && strlen(password) > 8 && strlen(password) <= 12) 
        {
            printf("your password is medium\n");
        }
        else 
        {
            printf("your password is weak\n");
        }

    }
}
int main()
{
    char password[50];
    printf("Enter the password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; 
    check(password);
    return 0;
}