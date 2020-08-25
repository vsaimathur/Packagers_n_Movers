#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct customer
{
    char address[50];
    char toname[20];
    char name[20];
    int distance;
}customer;

typedef struct queue
{
    char address[50];
    char toname[20];
    int distance;
    char name[20];
    struct queue *link;
    
}queue;

queue *f = NULL;
queue *r = NULL;

customer dp1[15]={0},dp2[12]={0},dp3[9]={0},dp4[6]={0},dp5[3]={0};/*These are the delivery persons queues where the data of customers is stored*/
int c[5]={0};/*These are counter for no of customers there near the delivery persons*/
int day=1;
int insertWaitingList(char *name,int distance,char *toname,char *address)
{
    queue *temp = (queue*)malloc(sizeof(queue));
    strcpy(temp->name,name);
    strcpy(temp->toname,toname);
    strcpy(temp->address,address);
    temp->distance = distance;
    temp->link = NULL;
    if(r == NULL)
    {
        f = temp;
        r = temp;
    }
    else
    {
        r->link = temp;
        r = r->link;
    }
    return 0;
}
int add(customer *d,char *name,int distance,char *toname,char *address)
{
    strcpy(d->address,address);
    strcpy(d->toname,toname);
    strcpy(d->name,name);
    d->distance = distance;
    return 0;
}
int addCustomer(char *name,int distance,char *toname,char *address)
{
    if(distance<=0)
    {
        printf("Sorry! The distance entered is incorrect");
    }
    else
    {
        if(distance<=5)
        {
            if(c[0]<15)
            {
                add(&dp1[c[0]],name,distance,toname,address);
                c[0]++;
            }
            else
            {
                insertWaitingList(name,distance,toname,address);
                return -1;
            }
        }
        else if(distance>5 && distance<=10)
        {
            if(c[1]<12)
            {
                add(&dp2[c[1]],name,distance,toname,address);
                c[1]++;
            }
            else
            {
                insertWaitingList(name,distance,toname,address);
                return -1;
            }
        }
        else if(distance>10 && distance<=15)
        {
            if(c[2]<9)
            {
                add(&dp3[c[2]],name,distance,toname,address);
                c[2]++;
            }
            else
            {
                insertWaitingList(name,distance,toname,address);
                return -1;
            }
        }
        else if(distance>15 && distance<=20)
        {
            if(c[3]<6)
            {
                add(&dp4[c[3]],name,distance,toname,address);
                c[3]++;
            }
            else
            {
                insertWaitingList(name,distance,toname,address);
                return -1;
            }
        }
        else if(distance>20 && distance<=25)
        {
            if(c[4]<3)
            {
                add(&dp5[c[4]],name,distance,toname,address);
                c[4]++;
            }
            else
            {
                insertWaitingList(name,distance,toname,address);
                return -1;
            }
        }
        else
        {
            printf("Sorry! We don't provide our facilities till that distance...\n\n");
            return -2;
        }
    }
    return 0;
}
int addQueue_deleteWaitingList()
{
    queue *p =f;
    if(f == NULL)
    {
        printf("WaitingList is Empty...\n");
    }
    else
    {
        addCustomer(f->name,f->distance,f->toname,f->address);
        f = f->link;
        free(p);
        if(f == NULL)
        {
            r = NULL;
        }
    }
    return 0;
}
int displayWaitingList()
{
    queue *p = f;
    printf("Packages in WaitingList:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("%-19s%-20s%-20s%-20s\n","Customer name","Distance","Receiving Name","Address");
    printf("-----------------------------------------------------------------------------\n");
    while(p!=NULL)
    {
        printf("%-20s%-20d%-20s%-20s\n",p->name,p->distance,p->toname,p->address);
        printf("-----------------------------------------------------------------------------\n");
        p = p->link;
    }
    return 0;
}
int showBill(char *name,int distance)
{
    int bill;
    if(distance<=5)
    {
        bill = 100;
    }
    else if(distance>5 && distance<=10)
    {
        bill = 200;
    }
    else if(distance>10 && distance<=15)
    {
        bill = 300;
    }
    else if(distance>15 && distance<=20)
    {
        bill = 400;
    }
    else if(distance>20 && distance<=25)
    {
        bill = 500;
    }
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("%s, Your Bill is Rs.%d/-\nThank You for coming to us...\n\n",name,bill);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    return 0;
}
int reinitialize_dp()
{
    memset(dp1,0,15*sizeof(customer));
    memset(dp2,0,12*sizeof(customer));
    memset(dp3,0,9*sizeof(customer));
    memset(dp4,0,6*sizeof(customer));
    memset(dp5,0,3*sizeof(customer));
    memset(c, 0, sizeof(c));
    return 0;
}
int displayDeliveredPackagesList()
{
    int i;
    printf("Packages delivered: \n\n");
    printf("Packages delivered by delivery person 1 is :\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("%-19s%-20s%-20s%-20s%-20s\n","S.no","Name","Distance","Receiving Name","Address");
    printf("----------------------------------------------------------------------------------------------\n");
    for(i=0;i<c[0];i++)
    {
        printf("%-20d%-20s%-20d%-20s%-20s\n",i+1,dp1[i].name,dp1[i].distance,dp1[i].toname,dp1[i].address);
        printf("----------------------------------------------------------------------------------------------\n");
    }
    printf("\nPackages delivered by delivery person 2 is :\n"); 
    printf("----------------------------------------------------------------------------------------------\n");
    printf("%-19s%-20s%-20s%-20s%-20s\n","S.no","Name","Distance","Receiving Name","Address");
    printf("----------------------------------------------------------------------------------------------\n");   
    for(i=0;i<c[1];i++)
    {            
        printf("%-20d%-20s%-20d%-20s%-20s\n",i+1,dp2[i].name,dp2[i].distance,dp2[i].toname,dp2[i].address);        
        printf("----------------------------------------------------------------------------------------------\n");
    }
    printf("\nPackages delivered by delivery person 3 is :\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("%-19s%-20s%-20s%-20s%-20s\n","S.no","Name","Distance","Receiving Name","Address");
    printf("----------------------------------------------------------------------------------------------\n");
    for(i=0;i<c[2];i++)
    {
        printf("%-20d%-20s%-20d%-20s%-20s\n",i+1,dp3[i].name,dp3[i].distance,dp3[i].toname,dp3[i].address);
        printf("----------------------------------------------------------------------------------------------\n");
    }
    printf("\nPackages delivered by delivery person 4 is :\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("%-19s%-20s%-20s%-20s%-20s\n","S.no","Name","Distance","Receiving Name","Address");
    printf("----------------------------------------------------------------------------------------------\n");
    for(i=0;i<c[3];i++)
    {
        printf("%-20d%-20s%-20d%-20s%-20s\n",i+1,dp4[i].name,dp4[i].distance,dp4[i].toname,dp4[i].address);
        printf("----------------------------------------------------------------------------------------------\n");
    }
    printf("\nPackages delivered by delivery person 5 is :\n");
    printf("----------------------------------------------------------------------------------------------\n");
    printf("%-19s%-20s%-20s%-20s%-20s\n","S.no","Name","Distance","Receiving Name","Address");
    printf("----------------------------------------------------------------------------------------------\n");
    for(i=0;i<c[4];i++)
    {
        printf("%-20d%-20s%-20d%-20s%-20s\n",i+1,dp5[i].name,dp5[i].distance,dp5[i].toname,dp5[i].address);
        printf("----------------------------------------------------------------------------------------------\n");
    }
    return 0;
}
int addWaitingPackages()
{
    int count = 0;
    while(r != NULL && count<45)
    {
        addQueue_deleteWaitingList();
        count++;
    }
    return 0;
}
int addPackage_showStatus()
{
    int dist,no,check,i;
    char name[20],toname[20],addr[50];
    printf("Enter number of customers...\n");
    scanf("%d",&no);
    fflush(stdin);
    addWaitingPackages();
    for(i=0;i<no;i++)
    {  
        printf("************************************************************************************************************************\n");
        printf("Enter the name of customer:\n");
        scanf(" %[^\n]s",name);
        printf("Enter the Receiving Person's Name:\n");
        scanf(" %[^\n]s",toname);
        printf("Enter the location(in K/m) to deliver the package:\n");
        scanf("%d",&dist);
        printf("Enter the address to deliver the package:\n");
        scanf(" %[^\n]s",addr);
        check = addCustomer(name,dist,toname,addr);
        if(check == 0)
        {
            printf("Your order will be delivered today...\n");
            showBill(name,dist);
        }
        else if(check == -1)
        {
            printf("Sorry, all our delivery slots are full today, your order will be delivered soon...\n");
            showBill(name,dist);
        }
    }
    printf("All the packages Scheduled for delivery today are delivered...\n");    
    return 0;
}
int main()
{
    int choice1,choice2,flag = 1;
    while(1)
    {
        printf("Enter 1 if the company is working today else Enter 0...\n");
        scanf("%d",&choice2);
        if(choice2!= 1)
        {
            break;
        }
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("DAY %d\n",day);
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        if(day != 1)
        {
            reinitialize_dp();
        }
        while(1 && flag)
        {
            printf("************************************************************************************************************************\n");
            printf("\t\t\tDASHBOARD\t\t\t\n");
            printf("************************************************************************************************************************\n");
            printf("1. Add Packages And Display Satus\n2. Display Waiting List\n3. Display Orders Delivered Today\n4. Exit\n");
            printf("Enter your choice\n");
            scanf("%d",&choice1);
            switch(choice1)
            {
                case 1: addPackage_showStatus();
                break;
                case 2: displayWaitingList();
                break;
                case 3: displayDeliveredPackagesList();
                break;
                case 4: flag = 0;
                break;
                default : printf("ERROR : Enter valid choice!!\n");
                break;
            }
            
        }   
        day++;
        flag = 1;
    }
    
    return 0;
}