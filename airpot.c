#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_NAME_LEN 50
#define MAX_ADDRESS_LEN 100
#define MAX_IP_LEN 20
#define MAX_MESSAGE_LENGTH 100
struct aircrafts
{
char input[100];
char name[MAX_NAME_LEN];
char location[MAX_NAME_LEN];
char origin_address[MAX_ADDRESS_LEN];
char destination_address[MAX_ADDRESS_LEN];
float weight;
int number;
char ip_address[MAX_IP_LEN];
int nseats;
float price;
char cname[100];
char fuel[100];
int speed;
char callsign[10];
char message[MAX_MESSAGE_LENGTH];
}ac;

void insertfile()
{
int i,n;
printf("enter how many aircrafts");
scanf("%d",&n);
FILE *fp;
fp = fopen("txt.txt","a");
for(i=0;i<n;i++)
{
printf("Enter the name:");
scanf("%s",&ac.name);
printf("Enter the location:");
scanf("%s",&ac.location);
printf("Enter the origin address:");
scanf("%s",&ac.origin_address);
printf("Enter the destinantion address:");
scanf("%s",&ac.destination_address);
printf("Enter the weight:");
scanf("%f",&ac.weight);
printf("Enter the number");
scanf("%d",&ac.number);
printf("Enter the ip address:");
scanf("%s",&ac.ip_address);
printf("Enter no. of seats");
scanf("%d",&ac.nseats);
printf("Enter time");
scanf("%f",&ac.price);
printf("Enter Company name");
scanf("%s",&ac.cname);
printf("Enter fuel name");
scanf("%s",&ac.fuel);
printf("Enter Speed");
scanf("%d",&ac.speed);
}
fwrite(&ac,sizeof(ac),1,fp);
fclose(fp);
}
/* TO DISPLAY RECORDS*/
void displayfile()
{
FILE *fp1;
fp1 = fopen("txt.txt","r");
printf("Name\tOrigin\tDestination\tWeight\tNumber\tIpaddress\tSeats\tTime\tcname\tFuelname\tSpeed\n\n");
while (fread(&ac,sizeof(ac),1,fp1))
printf("%s\t%s\t%s\t\t%0.2f\t%d\t%s\t\t%d\t%0.2f\t%s\t%s\t\t%d\n",ac.name,ac.origin_address,ac.destination_address,ac.weight,ac.
number,ac.ip_address,ac.nseats,ac.price,ac.cname,ac.fuel,ac.speed);
fclose(fp1);
}
// TO SEARCH THE GIVEN RECORD
void searchfile()
{
FILE *fp2;
int x;
printf("\nEnter the no you want to search : ");
scanf("%d", &x);
if (x!=ac.number)
printf("\nNo %d is not available in the file\n",x);
else
{
fp2 = fopen("txt.txt", "r");
while (fread(&ac,sizeof(ac),1,fp2))
{
if (x==ac.number)
{
printf("\nName= %s", ac.name);
printf("\nLocation=%s",ac.location);
printf("\nOriginal address = %s",ac.origin_address);
printf("\nDestination address = %s",ac.destination_address);
printf("\nWeight= %.2f",ac.weight);
printf("\nnumber = %d",ac.number);
printf("\nIp address= %s",ac.ip_address);
printf("\nNseats=%d",ac.nseats);
printf("\nTime=%.2f",ac.price);
printf("\nCompany name=%s",ac.cname);
printf("\nFuel name=%s",ac.fuel);
printf("\nSpeed=%d",ac.speed);
}
}
fclose(fp2);
}
}
void deletefile()
{
FILE *fp3;
FILE *fp31;
int x, s;
printf("Enter the no you want to delete :");
scanf("%d", &x);
if (x!=ac.number)
printf("No %d is not available in the file\n",x);
else
{
fp3=fopen("txt.txt", "r");
fp31=fopen("ammu.txt", "w");
while (fread(&ac, sizeof(ac), 1, fp3))
{
s =ac.number;
if (s != x)
fwrite(&ac,sizeof(ac), 1, fp31);
}
fclose(fp3);
fclose(fp31);
fp3= fopen("txt.txt", "w");
fp31=fopen("ammu.txt", "r");
while (fread(&ac, sizeof(ac), 1, fp31))
fwrite(&ac,sizeof(ac), 1, fp3);
printf("\nRECORD DELETED\n");
fclose(fp3);
fclose(fp31);
}
}
void checkfile()
{
FILE *fp4;
int x=0;
fp4=fopen("txt.txt","r");
printf("enter the number you want to check : ");
scanf("%d",&x);
while (fread(&ac,sizeof(ac),1,fp4))
{
if(x==ac.number)
{
printf("\nIt is present in the file\n\n");
}
else
{
printf("\nIt is not present in the file\n\n");
}
}
fclose(fp4);
}
/*TO SORT THE RECORD */
void sort()
{
int x[20],y[20],count1=0,count = 0,i,j,temp,temp1;
FILE *fpo;
fpo = fopen("txt.txt","r");
while(fread(&ac,sizeof(ac),1,fpo))
{
x[count] = ac.price;
count++;
}
for (i=0;i<count-1; i++)
{
for (j=i+1;j<count;j++)
{
if (x[i]>x[j])
{
temp= x[i];
x[i] = x[j];
x[j] = temp;
}
}
}
printf("The aircraft names in the order of aircraft numbers :\n\n");
printf("Time -- Name of the Aircraft\n");
for (i=0;i<count; i++)
{
rewind(fpo);
while (fread(&ac,sizeof(ac),1,fpo))
{
if (x[i]==ac.number)
{
printf("\n %d\t %s",ac.number,ac.name);
}
}
}
printf("\n");
}
void processMessage(message)
{
printf("Received message fromaircraft %s: %s\n",ac.callsign,ac.message);
// Process the message and provide a response
if (strcmp(ac.message, "REQUEST PERMISSION TO LAND") == 0)
{
printf("Permission granted. You are cleared to land, %s.\n",
ac.callsign);
} else if (strcmp(ac.message, "REQUEST TAKEOFF") == 0)
{
printf("Permission granted. You are cleared for takeoff, %s.\n",
ac.callsign);
} else if (strcmp(ac.message, "REQUEST EMERGENCY LANDING") == 0)
{
printf("Emergency landing approved. Proceed withcaution, %s.\n",ac.callsign);
} else
{
printf("Unknown request from %s: %s\n",ac.callsign,ac.message);
}
}
void ask(){
char input[100];
int x;
printf("Air Tower Simulation\n");
printf("====================\n");
while (x=!0) {
printf("\nEnter aircraft callsign: ");
scanf("%s", ac.callsign);
printf("Enter message: ");
getchar(); // Clear newline character from previous input
fgets(ac.message, MAX_MESSAGE_LENGTH, stdin);
// Remove trailing newline character
ac.message[strcspn(ac.message, "\n")] = '\0';
processMessage();
printf("\nDo you want to continue? (y/n): ");
scanf("%s", input);
if (strcmp(input, "n") == 0) {
break;
}
}}
int main()
{
int c;
do
{
printf("\n\t---Select your choice-------- \n");
printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
printf("\n\t4. DELETE\n\t5. CHECK\n\t6. SORT");
printf("\n\t7. LANDING MESSAGE\n\t8. EXIT");
printf("\n\n------------------------------------------\n");
printf("\nEnter your choice:");
scanf("%d", &c);
printf("\n");
switch (c)
{
case 1:
insertfile();
break;
case 2:
displayfile();
break;
case 3:
searchfile();
break;
case 4:
deletefile();
break;
case 5:
checkfile();
break;
case 6:
sort();
break;
case
7:
ask();
processMessage();
break;
case 8:
printf("TASK HAS BEEN COMPLETED");
exit(1);
break;
default:
printf("\nYour choice is wrong\nPlease try again.. \n");
break;
}
}while(c!=0);
}
