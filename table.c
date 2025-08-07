#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct student{   
    char subject[50];
    char faculty[25];
    char time_slot[20];
    char room_number[10];
    char day[10]; 
}s;
FILE *fp;
void entries(){
    int a;
    fp=fopen("data3.txt","a");
    do
    {
        printf("do you want entrie the data(1)/(0):");
        scanf("%d",&a);
        getchar();
        if(a==0)
        {
            break;
        }
        else{
            printf("Enter the subject:");
            fgets(s.subject,sizeof(s.subject),stdin);
            s.subject[strcspn(s.subject, "\n")] = 0;
            printf("Enter the faculty:");
            fgets(s.faculty,sizeof(s.faculty),stdin);
            s.faculty[strcspn(s.faculty, "\n")] = 0;
            printf("Enter the time_slot:");
            fgets(s.time_slot,sizeof(s.time_slot),stdin);
            s.time_slot[strcspn(s.time_slot, "\n")] = 0;
            printf("Enter the room_number:");
            fgets(s.room_number,sizeof(s.room_number),stdin);
            s.room_number[strcspn(s.room_number, "\n")] = 0;
            printf("Enter the day:");
            fgets(s.day,sizeof(s.day),stdin);
            s.day[strcspn(s.day, "\n")] = 0;
            fprintf(fp,"%s,%s,%s,%s,%s\n",s.subject,s.faculty,s.time_slot,s.room_number,s.day);
        }
    }while(1);
    fclose(fp);
}
void detect()
{
    FILE *conflict;
    fp=fopen("data3.txt","r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", fp);
        return;
    }
    struct student num[100];
    int count = 0;
    char line[256];
    while (fgets(line,sizeof(line),fp)!=NULL) 
    {
        sscanf(line, "%49[^,],%24[^,],%19[^,],%9[^,],%9[^\n]", num[count].subject, num[count].faculty, num[count].time_slot, num[count].room_number, num[count].day);
        count++;
    }
    fclose(fp);
    int temp=0;
    conflict = fopen("conflict.txt", "w");
    if (conflict == NULL) {
        printf("Error: Cannot open file conflict.txt\n");
        return;
    }
    for(int i=0;i<count;i++)
    {
        for(int j=i+1;j<count;j++)
        {
            if(strcmp(num[i].time_slot,num[j].time_slot)==0 && strcmp(num[i].day,num[j].day)==0)
            {
                if(strcmp(num[i].faculty,num[j].faculty)==0)
                {
                    temp=1;
                    printf("Faculty clash\n");
                    printf("%s (%s , %s)\n",num[i].faculty,num[i].subject,num[i].room_number);
                    printf("%s (%s , %s)\n",num[j].faculty,num[j].subject,num[j].room_number);
                    printf("--------------------------------\n");
                    fprintf(conflict, "Faculty clash:\n %s (%s , %s) \n %s (%s , %s)\n", num[i].faculty, num[i].subject, num[i].room_number, num[j].faculty, num[j].subject, num[j].room_number);
                    fprintf(conflict,"--------------------------------\n");
                }
                if(strcmp(num[i].room_number,num[j].room_number)==0)
                {
                    temp=1;
                    printf("Room clash\n");
                    printf("%s (%s , %s)\n",num[i].room_number,num[i].subject,num[i].faculty);
                    printf("%s (%s , %s)\n",num[j].room_number,num[j].subject,num[j].faculty);
                    printf("--------------------------------\n");
                    fprintf(conflict, "Room clash:\n %s (%s , %s) \n %s (%s , %s)\n", num[i].room_number, num[i].subject, num[i].faculty, num[j].room_number, num[j].subject, num[j].faculty);
                    fprintf(conflict, "--------------------------------\n");
                }
            }
        }
    }
    if(temp==0)
    {
        printf("No clashes are Found");
        fprintf(conflict, "No clashes are Found\n");
    }
    fclose(conflict);
}
void main()
{
 entries();
 detect();   
   
}