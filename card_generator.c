#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp,*tempfp;
char allergies_arr[100][50];
int allergies_count = 0;
struct student
{
    char name[50];
    char student_id[15];
    char blood_group[5];
    char allergies[50];
    char medical_issue[100];
    char mail_id[100];
};
int password()
{
    int pass;
    printf("Enter the password:");
    scanf("%d",&pass);
    getchar();
    if (pass==1234567890)
    {
        return 1;
    }
    else
    {
        printf("password is invalid\n");
        printf("relogin\n");
    }
    return 0;
}
void save_counter(int val);
int load_counter() {
    FILE *cf = fopen("counter.txt", "r");
    int val = 20; 
    if (cf != NULL) 
    {
        fscanf(cf, "%d", &val);
        fclose(cf);
    }
    else
    {
        save_counter(20);
        val=20;
    }
    return val;
}

void save_counter(int val) 
{
    FILE *cf = fopen("counter.txt", "w");
    if (cf != NULL) {
        fprintf(cf, "%d", val);
        fclose(cf);
    }
    else
    {
        printf("not saved\n");
    }
}
char* generate()
{
    char a[]="2025AB";
    char* id=(char*)malloc(15*sizeof(char));
    if (id == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    int c=load_counter();
    c++;
    sprintf(id,"%s%03d",a,c);
    save_counter(c);
    return id;
}
void remove_newline(char *str)
{
    str[strcspn(str,"\n")]=0;
}
int unique_allergies(char allergy[50])
{
    for(int i=0;i<allergies_count;i++)
    {
        if(strcmp(allergies_arr[i],allergy)==0)
        {
            return 0; 
        }
    }
    return 1; 
}
int valid_email(struct student s)
{
    int count=0,count1=0;
    for(int i=0;s.mail_id[i]!='\0';i++)
    {
        if(s.mail_id[i]=='@')
        {
            count++;
        }
        if(s.mail_id[i]=='.')
        {
            count1++;
        }
        if(s.mail_id[i]=='@' && s.mail_id[i+1]=='.')
        {
            printf("Invalid email ID. Please include a domain after '@'.\n");
            return 0;
        }
        if(s.mail_id[i]=='.' && s.mail_id[i+1]=='@')
        {
            printf("Invalid email ID. Please remove '.' before '@'.\n");
            return 0;
        }
        if(s.mail_id[i]==' ')
        {
            printf("Invalid email ID. Please remove spaces.\n");
            return 0;
        }
    }
    if(count==0)
    {
        printf("Invalid email ID. Please include '@'.\n");
        return 0;
    }
    else if(count>1)
    {
        printf("Invalid email ID. Please include only one '@'.\n");
        return 0;
    }
    if(count1==0)
    {
        printf("Invalid email ID. Please include '.' after '@'.\n");
        return 0;
    }
    count=0;
    for(int i=0;s.mail_id[i]!='\0';i++)
    {
        if(s.mail_id[i]=='@')
        {
            break;
        }
        count++;
    }
    if(count==0)
    {
        printf("Invalid email ID. Please include a username before '@'.\n");
        return 0;
    }
    return 1;
}
void export_card(struct student s)
{
    char filename[100];
    sprintf(filename, "%s_card.txt", s.student_id);
    FILE *card_fp = fopen(filename, "w");
    if (card_fp == NULL) 
    {
        printf("Error creating student card file.\n");
        return;
    }
    fprintf(card_fp, "--------------------------------\n");
    fprintf(card_fp, "         STUDENT CARD           \n");
    fprintf(card_fp, "--------------------------------\n");
    fprintf(card_fp, "NAME           : %s\n", s.name);
    fprintf(card_fp, "STUDENT ID     : %s\n", s.student_id);
    fprintf(card_fp, "BLOOD GROUP    : %s\n", s.blood_group);
    fprintf(card_fp, "ALLERGIES      : %s\n", s.allergies);
    fprintf(card_fp, "MEDICAL ISSUE  : %s\n", s.medical_issue);
    fprintf(card_fp, "MAIL_ID        : %s\n", s.mail_id);
    fprintf(card_fp, "EMERGENCY PH.NO: 6308887742\n");
    fprintf(card_fp, "--------------------------------\n");
    fclose(card_fp);
    printf("Student card generated successfully.\n");
}
void register_a_form()
{
    struct student s;
    char line[250],check[50];
    fp=fopen("data1.txt","a+");
    if(fp==NULL)
    {
        printf("file not found");
        return;
    }
    getchar();
    printf("enter your full name:");
    fgets(s.name,sizeof(s.name),stdin);
    remove_newline(s.name);
    printf("enter your blood_group:");
    fgets(s.blood_group,sizeof(s.blood_group),stdin);
    remove_newline(s.blood_group);
    printf("enter your allergies:");
    fgets(s.allergies,sizeof(s.allergies),stdin);
    remove_newline(s.allergies);
    printf("enter your medical_issue:");
    fgets(s.medical_issue,sizeof(s.medical_issue),stdin);
    remove_newline(s.medical_issue);
    printf("enter your mail_id:");
    fgets(s.mail_id,sizeof(s.mail_id),stdin);
    while(!valid_email(s)) 
    {
        printf("Please enter a valid email ID: ");
        fgets(s.mail_id, sizeof(s.mail_id), stdin);
    }
    remove_newline(s.mail_id);
    strcpy(check,s.mail_id);
    rewind(fp);
    char file_mail_id[100];
    int already_registered = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char dummy_name[50], dummy_id[15], dummy_bg[5], dummy_allergies[50], dummy_medical[100];
        sscanf(line, "%49[^,],%14[^,],%4[^,],%49[^,],%99[^,],%99[^\n]", dummy_name, dummy_id, dummy_bg, dummy_allergies, dummy_medical, file_mail_id);
        remove_newline(file_mail_id); 
        if (strcmp(check, file_mail_id) == 0) 
        {
            printf("You are already registered with this email ID.\n");
            printf("Registration failed.\n");
            already_registered = 1;
            break;
        }
    }
    if (already_registered) 
    {
        fclose(fp);
        return;
    }
    char *generated_id = generate();
    strcpy(s.student_id, generated_id); 
    printf("Your Student ID: %s\n", s.student_id);
    fprintf(fp, "%s,%s,%s,%s,%s,%s\n", s.name, s.student_id, s.blood_group, s.allergies, s.medical_issue, s.mail_id);
    printf("Data saved successfully.\n");
    printf("Do you want to export your card? (1 for yes, 0 for no): ");
    int a;
    scanf("%d", &a);
    getchar(); 
    if(a==1)
    {
        export_card(s);
    }
    free(generated_id); 
    fclose(fp);
}
void staff(char id[20])
{
    int temp=0;
    struct student s;
    char line[250],change[50],value[50];
    fp=fopen("data1.txt","r");
    tempfp=fopen("temp.txt","w");
    if(fp==NULL||tempfp==NULL)
    {
        printf("file not found\n");
        return;
    }
    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",s.name,s.student_id,s.blood_group,s.allergies,s.medical_issue,s.mail_id);
        remove_newline(s.student_id);
        if(strcmp(s.student_id,id)==0)
        {
            printf("--------------------------------\n");
            printf("         STUDENT INFO           \n");
            printf("--------------------------------\n");
            printf("NAME           :%s\n",s.name);
            printf("STUDENT ID     :%s\n",s.student_id);
            printf("BLOOD GROUP    :%s\n",s.blood_group);
            printf("ALLERGIES      :%s\n",s.allergies);
            printf("MEDICAL ISSUE  :%s\n",s.medical_issue);
            printf("MAIL_ID        :%s\n",s.mail_id);
            printf("---------------------------------\n");
            temp=1;
            getchar();
            printf("WHICH DATA IS GOING TO CHANGE(name/blood_group/allergies/medical_issue/mail_id):");
            fgets(change,sizeof(change),stdin);
            remove_newline(change);
            printf("Enter new %s:",change);
            fgets(value,sizeof(value),stdin);
            remove_newline(value);
            if(strcmp(change,"name")==0)
                strcpy(s.name,value);
            else if(strcmp(change,"blood_group")==0)
                strcpy(s.blood_group,value);
            else if(strcmp(change,"allergies")==0)
                strcpy(s.allergies,value);
            else if(strcmp(change,"medical_issue")==0)
                strcpy(s.medical_issue,value);
            else if (strcmp(change, "mail_id") == 0)
            {
                FILE *checkfp = fopen("data1.txt", "r");
                struct student temp_s;
                char temp_line[250];
                int mail_exists = 0;
                while (fgets(temp_line, sizeof(temp_line), checkfp))
                {
                    sscanf(temp_line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",temp_s.name, temp_s.student_id, temp_s.blood_group,temp_s.allergies, temp_s.medical_issue, temp_s.mail_id);
                    remove_newline(temp_s.mail_id);
                    if (strcmp(temp_s.mail_id, value) == 0 && strcmp(temp_s.student_id, id) != 0)
                    {
                        mail_exists = 1;
                        break;
                    }
                }
                fclose(checkfp);
                if (mail_exists)
                {
                    printf("This email ID already exists. Mail ID not updated.\n");
                }
                else
                {
                    strcpy(s.mail_id, value);
                }
            }
            else
            {
                printf("Invalid field name! No changes made.\n");
            }
        }
        
        fprintf(tempfp,"%s,%s,%s,%s,%s,%s\n",s.name,s.student_id,s.blood_group,s.allergies,s.medical_issue,s.mail_id);
        
    }
    fclose(fp);
    fclose(tempfp);
    if(temp==0)
    {
        printf("student_id not found\n");
        remove("temp.txt");
    }
    else
    {
        remove("data1.txt");
        rename("temp.txt","data1.txt");
        printf("Data updated..\n");
    }
}
void student(char id[20])
{
    int temp=0;
    struct student s;
    char line[250];
    fp=fopen("data1.txt","r");
    if(fp==NULL)
    {
        printf("empty file\n");
        return;
    }
    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",s.name,s.student_id,s.blood_group,s.allergies,s.medical_issue,s.mail_id);
        remove_newline(s.student_id);
        if(strcmp(s.student_id,id)==0)
        {
            printf("--------------------------------\n");
            printf("         STUDENT INFO           \n");
            printf("--------------------------------\n");
            printf("NAME           :%s\n",s.name);
            printf("STUDENT ID     :%s\n",s.student_id);
            printf("BLOOD GROUP    :%s\n",s.blood_group);
            printf("ALLERGIES      :%s\n",s.allergies);
            printf("MEDICAL ISSUE  :%s\n",s.medical_issue);
            printf("MAIL_ID        :%s\n",s.mail_id);
            printf("EMERGENCE PH.NO:6308887742\n");
            printf("--------------------------------\n");
            temp=1;
            break;
        }
    }
    fclose(fp);
    if(temp==0)
    {
        printf("student_id not found\n");
    }
}
void forgot_student_id() 
{
    char name_input[50];
    char email_input[100];
    struct student s;
    char line[250];
    int found = 0;
    printf("Enter your full name: ");
    fgets(name_input, sizeof(name_input), stdin);
    remove_newline(name_input);
    printf("Enter your email ID: ");
    fgets(email_input, sizeof(email_input), stdin);
    remove_newline(email_input);
    fp = fopen("data1.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open data file.\n");
        return;
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%49[^,],%14[^,],%4[^,],%49[^,],%99[^,],%99[^\n]", 
               s.name, s.student_id, s.blood_group, s.allergies, s.medical_issue, s.mail_id);
        remove_newline(s.mail_id);
        remove_newline(s.name); 

        if (strcmp(s.name, name_input) == 0 && strcmp(s.mail_id, email_input) == 0) {
            printf("Your Student ID is: %s\n", s.student_id);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found == 0) 
    {
        printf("No matching record found for the provided name and email ID.\n");
    }
}
void make_a_group()
{
    char line[250];
    int a;
    struct student s;
    char arr[][4]={"A+","A-","B+","B-","O+","O-","AB+","AB-"};
    int arr1[8]={0};
    int count=0,i=0,b;
    printf("1.blood group\n");
    printf("2.allergies\n");
    printf("3.exit\n");
    printf("Enter your choice:");
    scanf("%d", &a);
    getchar();
    fp=fopen("data1.txt","r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    if(a==1)
    {
        b=8;
        while(b!=0)
        {
            while(fgets(line,sizeof(line),fp)!=NULL)
            {
                sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",s.name,s.student_id,s.blood_group,s.allergies,s.medical_issue,s.mail_id);
                remove_newline(s.blood_group);
                if(strcmp(s.blood_group,arr[i])==0)
                {
                    count++;
                }
            }
            arr1[i]=count;
            count=0;
            i++;
            rewind(fp);
            b--;
        }
        for(int j=0;j<8;j++)
        {
            printf("%s: %d\n", arr[j], arr1[j]);
        }
        printf("Do you want any blood group specificly? (1 for yes, 0 for no): ");
        scanf("%d", &b);
        getchar(); 
        if(b==1)
        {
            for(i=0;i<8;i++)
            {
                printf("%d.%s\n",i+1,arr[i]);
            }
            printf("Enter your choice:");
            scanf("%d", &i);
            getchar();
            while(fgets(line,sizeof(line),fp)!=NULL)
            {
                sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",s.name,s.student_id,s.blood_group,s.allergies,s.medical_issue,s.mail_id);
                remove_newline(s.blood_group);
                if(strcmp(s.blood_group,arr[i-1])==0)
                {
                    printf("NAME           :%s\n",s.name);
                    printf("STUDENT ID     :%s\n",s.student_id);
                    printf("BLOOD GROUP    :%s\n",s.blood_group);
                    printf("ALLERGIES      :%s\n",s.allergies);
                    printf("MEDICAL ISSUE  :%s\n",s.medical_issue);
                    printf("MAIL_ID        :%s\n",s.mail_id);
                    printf("--------------------------------\n");
                }
            }
        }
    }
    else if(a==2)
    {
        int count = 0,i=0;
        char allergies_arr1[100];
        rewind(fp);
        while(fgets(line,sizeof(line),fp)!=NULL)
        {
            sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",s.name,s.student_id,s.blood_group,s.allergies,s.medical_issue,s.mail_id);
            remove_newline(s.allergies);
            if(unique_allergies(s.allergies))
            {
                strcpy(allergies_arr[allergies_count++], s.allergies);
            }
        }
        rewind(fp);
        b=allergies_count;
        while(b!=0)
        {
            while(fgets(line,sizeof(line),fp)!=NULL)
            {
                sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",s.name,s.student_id,s.blood_group,s.allergies,s.medical_issue,s.mail_id);
                remove_newline(s.allergies);
                if(strcmp(s.allergies, allergies_arr[i])==0)
                {
                    count++;
                }
            }
            allergies_arr1[i]=count;
            count=0;
            i++;
            rewind(fp);
            b--;
        }
        for(int j=0;j<allergies_count;j++)
        {
            printf("%s: %d\n", allergies_arr[j], allergies_arr1[j]);
        }
        printf("Do you want any allergies specificly? (1 for yes, 0 for no): ");
        scanf("%d", &b);
        getchar();
        if(b==1)
        {
            for(i=0;i<allergies_count;i++)
            {
                printf("%d.%s\n",i+1,allergies_arr[i]);
            }
            printf("Enter your choice:");
            scanf("%d", &i);
            getchar();
            while(fgets(line,sizeof(line),fp)!=NULL)
            {
                sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",s.name,s.student_id,s.blood_group,s.allergies,s.medical_issue,s.mail_id);
                remove_newline(s.allergies);
                if(strcmp(s.allergies, allergies_arr[i-1])==0)
                {
                    printf("NAME           :%s\n",s.name);
                    printf("STUDENT ID     :%s\n",s.student_id);
                    printf("BLOOD GROUP    :%s\n",s.blood_group);
                    printf("ALLERGIES      :%s\n",s.allergies);
                    printf("MEDICAL ISSUE  :%s\n",s.medical_issue);
                    printf("MAIL_ID        :%s\n",s.mail_id);
                    printf("--------------------------------\n");
                }
            }
        }
    }
    fclose(fp);

}
int main()
{
    int a;
    char id[20];
    while(1)
    {
        printf("1.login\n");
        printf("2.register\n");
        printf("3.exit\n");
        printf("Enter your choice:");
        scanf("%d",&a);
        if(a==2)
        {
            register_a_form();
        }
        else if(a==1)
        {
            printf("1.login as a staff\n");
            printf("2.student\n");
            printf("3.forgot student id\n");
            printf("Enter your choice:");
            scanf("%d",&a);
            getchar();
            if(a==2)
            {
                printf("enter the student id:");
                fgets(id,sizeof(id),stdin);
                remove_newline(id);
                student(id);
            }
            else if(a==1)
            {
                if(password())
                {
                    printf("1.make a group\n");
                    printf("2.Edit student details:\n");
                    printf("Enter your choice:");
                    scanf("%d",&a);
                    if(a==1)
                    {
                        make_a_group();
                    }
                    else if(a==2)
                    {
                        printf("enter the student id:");
                        fgets(id,sizeof(id),stdin);
                        remove_newline(id);
                        staff(id);
                    }
                    else
                    {
                        printf("Invalid choice.\n");
                    }
                }
            }
            else if(a==3)
            {
                 forgot_student_id();
            }
        }
        else
        {
            exit(0);
        }
    }
    return 0;
}