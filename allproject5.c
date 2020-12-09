#include<stdio.h>
#include<string.h>
int count=0;
int charlie;
struct user{
	char id[8];
	char first[50];
	char last[50];
	char phone[15];
	char con[30];
	char pass[30];
	char email[50];
}info[500];

void regist();void logout();void editSTD();void STDm();void AD();void login();void rewrite();void mainmenu();void editAD();void show();void del();void search();

int main(){
int i=0;
FILE *read;
	read=fopen("studentinfo.txt","r");
	if(fscanf(read,"%s",info[i].id) != EOF){
	re: fscanf(read,"%s",info[i].first);
        fscanf(read,"%s",info[i].last);
        fscanf(read,"%s",info[i].phone);
        fscanf(read,"%s",info[i].email);
        fscanf(read,"%s",info[i].pass);
	i++;
	if(fscanf(read,"%s",info[i].id)!=EOF){
		goto re;
        }
	}
	fclose(read);
	count=i;
	mainmenu();
	return 0;
}

void regist(){

    int i;
    FILE *fp;

    printf("[Registaion]\n\n");

    justin: printf("Please enter the following information\n");
            printf("ID: ");
            scanf("%s",&info[count].id);
                for(i=0;info[count].id[i]!='\0';i++);
                while(i!=7){
                    i=0;
                    printf("[ERROR] You can use only 7 digits for ID\n");
                    printf("[Re-type] ID: ");
                    scanf("%s",&info[count].id);
                    for(i=0;info[count].id[i]!='\0';i++);
                }
                i=0;
                if(info[count].id[0]=='0'&&info[count].id[1]=='0'){
                    printf("[ERROR] You can't register as admin (ID:00XXXXX)\n");
                    goto justin;
                }
                for(i=0;i<count;i++){
                if(strcmp(info[i].id,info[count].id)==0){
                    printf("This ID is already register\n");
                    goto justin;
                }
                }

	printf("First Name: ");
	scanf("%s",&info[count].first);

	printf("Last Name: ");
	scanf("%s",&info[count].last);

	printf("Phone Number: ");
	scanf("%s",&info[count].phone);
        for(i=0;info[count].phone[i]!='\0';i++);
        while(i!=10){
            i=0;
            printf("[ERROR] You must use only 10 digit numbers for phone number\n");
            printf("[Re-type] Phone Number: ");
            scanf("%s",&info[count].phone);
            for(i=0;info[count].phone[i]!='\0';i++);
        }
        i=0;

	printf("Email: ");
	scanf("%s",&info[count].email);
        do{
            char *a,*b;
            a = strstr(info[count].email,"@");
            if (a){
                b = strstr(a,".");
                if(b){
                    i++;
                }
                else{
                    printf("[ERROR] You must contain character .\n");
                    printf("[Re-type] Email: ");
                    scanf("%s",&info[count].email);
                }
            }
            else{
                printf("[ERROR] You must contain character @\n");
                printf("[Re-type] Email: ");
                scanf("%s",&info[count].email);
            }
        }while(i<1);
        i=0;

	printf("Password: ");
	scanf("%s",&info[count].pass);
        for(i=0;info[count].pass[i]!='\0';i++);
        while(i<8){
            i=0;
            printf("[ERROR] You must use at least 8 characters for password\n");
            printf("[Re-type] Password: ");
            scanf("%s",&info[count].pass);
            for(i=0;info[count].pass[i]!='\0';i++);
        }
        i=0;

	printf("Confirmed Password: ");
	scanf("%s",&info[count].con);

        int ret;
        ret = strcmp(info[count].pass,info[count].con);

        while(ret != 0) {
            printf("[ERROR] These passwords don't match\n");
            printf("[Re-type] Confirmed Password: ");
            scanf("%s",&info[count].con);
            ret = strcmp(info[count].pass,info[count].con);
        }

    if((fp=fopen("studentinfo.txt","a"))!=NULL){
        fputs(info[count].id,fp);
        fputs(" ",fp);
        fputs(info[count].first,fp);
        fputs(" ",fp);
        fputs(info[count].last,fp);
        fputs(" ",fp);
        fputs(info[count].phone,fp);
        fputs(" ",fp);
        fputs(info[count].email,fp);
        fputs(" ",fp);
        fputs(info[count].pass,fp);
        fputs("\n",fp);
    fclose(fp);
	count++;
	}

	printf("--End of the Registration Process--\n");
	printf("\nCongratulation!! %s,",info[count-1].first);
	printf("\nNow you can login to the ICT Contact Management System and start to\nsearch for ICT faculty staffs' and friends' information.\n\n");
	mainmenu();
}

void logout(){
    printf("[Logout Page]\n");
    printf("\nGoodbye!!!\n\n");
    mainmenu();
}

void editSTD(){
int i;
char num;
	polar:  printf("[Edit My Contact Information]\n");
            printf("\n[STUDENT] ID: %s\n",info[charlie].id);
            printf("[1] First Name: \n");
            printf("[2] Last Name: \n");
            printf("[3] Phone Number: \n");
            printf("[4] Email: \n");
            printf("[5] Password: \n");
            printf("Please enter the choice to edit: ");
            scanf(" %c",&num);
	if(num=='1'){
		printf("\n[Re-Input] First Name: ");
		scanf("%s",&info[charlie].first);
		printf("Record successfully updated!!\n");
		rewrite();
	}
	else if(num=='2'){
		printf("\n[Re-Input] Last Name: ");
		scanf("%s",&info[charlie].last);
		printf("Record successfully updated!!\n");
		rewrite();
	}
	else if(num=='3'){
		printf("\n[Re-Input] Phone Number: ");
		scanf("%s",&info[charlie].phone);
        for(i=0;info[charlie].phone[i]!='\0';i++);
        while(i!=10){
            i=0;
            printf("[ERROR] You must use only 10 digit numbers for phone number\n");
            printf("[Re-type] Phone Number: ");
            scanf("%s",&info[charlie].phone);
            for(i=0;info[charlie].phone[i]!='\0';i++);
        }
        i=0;
        printf("Record successfully updated!!\n");
        rewrite();
	}
	else if(num=='4'){
			printf("\n[Re-Input] Email: ");
			scanf("%s",&info[charlie].email);
     	   do{
            char *a,*b;
            a = strstr(info[charlie].email,"@");
            if (a){
                b = strstr(a,".");
                if(b){
                    i++;
                }
                else{
                    printf("[ERROR] You must contain character .\n");
                    printf("[Re-type] Email: ");
                    scanf("%s",&info[charlie].email);
                }
            }
            else{
                printf("[ERROR] You must contain character @\n");
                printf("[Re-type] Email: ");
                scanf("%s",&info[charlie].email);
            }
        }while(i<1);
        i=0;
        printf("Record successfully updated!!\n");
        rewrite();
	}
	else if(num=='5'){
		printf("\n[Re-Input] Password: ");
		scanf("%s",&info[charlie].pass);
        for(i=0;info[charlie].pass[i]!='\0';i++);
        while(i<8){
            i=0;
            printf("[ERROR] You must use at least 8 characters for password\n");
            printf("[Re-type] Password: ");
            scanf("%s",&info[charlie].pass);
            for(i=0;info[charlie].pass[i]!='\0';i++);
        }
        i=0;
        printf("Record successfully updated!!\n");
        rewrite();

	}
	else if(num!='1'||num!='2'||num!='3'||num!='4'||num!='5'){
        printf("[ERROR] Invalid code\n");
        printf("[Re-type] ");
        goto polar;
	}
	STDm();
	}

void editAD(){
    int i,jj;
    char num,id[8];

	rose:  printf("[Edit User's Contact]\n");
            printf("\n[ADMIN] ID: %s\n",info[charlie].id);
            printf("\nPlease enter the id for editing: ");
	kevin: scanf("%s",id);
            for(i=0;i<count;i++){
                if(strcmp(info[i].id,id)==0){
                    jj=i;
                    goto condo;
                }
            }
                if(i==count){
                    printf("[ERROR] There is no matched id in the system.\n");
                    printf("[Re-Type] Please enter the id for editing: ");
                    goto kevin;
                }
    condo:  if(info[jj].id[0]=='0'&&info[jj].id[1]=='0'){
                printf("\n[ADMIN] ID: %s\n",info[jj].id);
                printf("[1] First Name: \n");
                printf("[2] Last Name: \n");
                printf("[3] Phone Number: \n");
                printf("[4] Email: \n");
                printf("[5] Password: \n");
                printf("Please enter the choice to edit: ");
                scanf(" %c",&num);
            }
            else{
                printf("\n[ADMIN] ID: %s\n",info[jj].id);
                printf("[1] First Name: \n");
                printf("[2] Last Name: \n");
                printf("[3] Phone Number: \n");
                printf("[4] Email: \n");
                printf("[5] Password: \n");
                printf("Please enter the choice to edit: ");
                scanf(" %c",&num);
            }
	if(num=='1'){
		printf("\n[Re-Input] First Name: ");
		scanf("%s",&info[jj].first);
		printf("Record successfully updated!!\n");
		rewrite();
	}
	else if(num=='2'){
		printf("\n[Re-Input] Last Name: ");
		scanf("%s",&info[jj].last);
		printf("Record successfully updated!!\n");
		rewrite();
	}
	else if(num=='3'){
		printf("\n[Re-Input] Phone Number: ");
		scanf("%s",&info[jj].phone);
        for(i=0;info[jj].phone[i]!='\0';i++);
        while(i!=10){
            i=0;
            printf("[ERROR] You must use only 10 digit numbers for phone number\n");
            printf("[Re-type] Phone Number: ");
            scanf("%s",&info[jj].phone);
            for(i=0;info[jj].phone[i]!='\0';i++);
        }
        i=0;
        printf("Record successfully updated!!\n");
        rewrite();
	}
	else if(num=='4'){
			printf("\n[Re-Input] Email: ");
			scanf("%s",&info[jj].email);
     	   do{
            char *a,*b;
            a = strstr(info[jj].email,"@");
            if (a){
                b = strstr(a,".");
                if(b){
                    i++;
                }
                else{
                    printf("[ERROR] You must contain character .\n");
                    printf("[Re-type] Email: ");
                    scanf("%s",&info[jj].email);
                }
            }
            else{
                printf("[ERROR] You must contain character @\n");
                printf("[Re-type] Email: ");
                scanf("%s",&info[jj].email);
            }
        }while(i<1);
        i=0;
        printf("Record successfully updated!!\n");
        rewrite();
	}
	else if(num=='5'){
		printf("\n[Re-Input] Password: ");
		scanf("%s",&info[jj].pass);
        for(i=0;info[jj].pass[i]!='\0';i++);
        while(i<8){
            i=0;
            printf("[ERROR] You must use at least 8 characters for password\n");
            printf("[Re-type] Password: ");
            scanf("%s",&info[jj].pass);
            for(i=0;info[jj].pass[i]!='\0';i++);
        }
        i=0;
        printf("Record successfully updated!!\n");
        rewrite();
	}
    else if(num!='1'||num!='2'||num!='3'||num!='4'||num!='5'){
        printf("[ERROR] Invalid code\n");
        printf("[Re-type] ");
        goto rose;
    }
	AD();
	}

void login(){
	char id[8],pass[30];
	int i;
	printf("[Login Page]\n");
	printf("\nPlease enter your ID: ");
	scanf("%s",&id);
	printf("Please enter your Password: ");
	scanf("%s",&pass);

	Recheck:for(i=0;i<=count;i++){
        if(strcmp(info[i].id,id)==0&&strcmp(info[i].pass,pass)==0&&info[i].id[0]=='0'&&info[i].id[1]=='0'){
            charlie=i;
            AD();
            return;
        }
        else if(strcmp(info[i].id,id)==0&&strcmp(info[i].pass,pass)==0){
            charlie=i;
            STDm();
            return;
        }
        if(i==count){
            printf("[ERROR] Wrong ID or Password!!!\n");
            printf("[Re-Type] Please enter your ID: ");
            scanf("%s",&id);
            printf("[Re-Type] Please enter your Password: ");
            scanf("%s",&pass);
            goto Recheck;
        }
	}
}

void STDm(){
    char choice;
    printf("\nNow you are logged in as a student in the system.\n");
    printf("You can start using the following functions.\n\n");
    printf("[1] Edit My Contact Information\n");
    printf("[2] Show all Contacts\n");
    printf("[3] Search for a Contact\n");
    printf("[0] Logout\n");
    printf("Please enter the choice: ");
    scanf(" %c",&choice);
    if(choice=='1'){
        editSTD();
    }
    else if(choice=='2'){
        show();
    }
    else if(choice=='3'){
        search();
    }
    else if(choice=='0'){
        logout();
    }
    else if(choice!='1'||choice!='2'||choice!='3'||choice!='0'){
        printf("[ERROR] Invalid code\n");
        printf("[Re-type] ");
        STDm();
    }
}

void AD(){
    char choice;
    printf("\nNow you are logged in as an admin in the system.\n");
    printf("You can start using the following functions.\n\n");
    printf("[1] Edit User's Contact\n");
    printf("[2] Show all Contacts\n");
    printf("[3] Search for a Contact\n");
    printf("[4] Delete User's Contact\n");
    printf("[0] Logout\n");
    printf("Please enter the choice: ");
    scanf(" %c",&choice);
    if(choice=='1'){
        editAD();
    }
    else if(choice=='2'){
        show();
    }
    else if(choice=='3'){
        search();
    }
    else if(choice=='4'){
        del();
    }
    else if(choice=='0'){
        logout();
    }
    else if(choice!='1'||choice!='2'||choice!='3'||choice!='4'||choice!='0'){
        printf("[ERROR] Invalid code\n");
        printf("[Re-type] ");
        AD();
    }
}

void rewrite(){
FILE *refile;
int i=0;
	refile=fopen("studentinfo.txt","w");
	kim:fprintf(refile,"%s %s %s %s %s %s\n",info[i].id,info[i].first,info[i].last,info[i].phone,info[i].email,info[i].pass);
        i++;
        if(i<count){
            goto kim;
        }
	fclose(refile);
}

void mainmenu(){
	char num;
	printf("===============================\n");
	printf("ICT Contact Management Systems\n");
	printf("===============================\n");
	printf("[1] User Registration\n");
	printf("[2] Login\n");
	printf("[0] Exit\n");
	printf("-----------------------\n");
	printf("Enter the choice: ");
	scanf(" %c",&num);
	printf("\n");

	while(num!='1'&&num!='2'&&num!='0'){
        num=0;
        printf("[ERROR]Incorrect code\n");
        printf("[Re-type]Enter the choice: ");
        scanf(" %c",&num);
        printf("\n");
	}
	if(num=='1'){
		regist();
	}
	if(num=='2'){
		login();
	}
	if(num=='0'){
        return;
	}
}

void show(){
int i;
char *role;
    printf("[Show all Contacts]\n\n");
    printf("===============================\n");
    printf("        All Contacts\n");
    printf("===============================\n\n");
    printf("ID      FirstName      LastName           Role       Phone Number Email\n");
    printf("======================================================================================\n");
    for(i=0;i<count;i++){
    if(info[i].id[0]=='0'&&info[i].id[1]=='0'){
        role = "Admin";
    }
    else{
        role = "Student";
    }
    printf("%-7s %-14s %-18s %-10s %-12s %s\n",info[i].id,info[i].first,info[i].last,role,info[i].phone,info[i].email);
    }
    printf("======================================================================================\n\n");

    if(info[charlie].id[0]=='0'&&info[charlie].id[1]=='0'){
        AD();
    }
    else{
        STDm();
    }
}

void del(){
int i,jj;
char id[8],de;
    printf("[Delete User’s Contact]\n\n");
    printf("[ADMIN] ID: %s\n\n",info[charlie].id);
    ervin: printf("Please enter the id for deleting: ");
    charlot: scanf("%s",id);

	for(i=0;i<count;i++){
        if(strcmp(info[i].id,id)==0){
            jj=i;
            goto psd;
        }
	}
        if(i==count){
            printf("[ERROR] There is no matched id in the system.\n");
            printf("[Re-Type] Please enter the id for editing: ");
            goto charlot;
        }
  psd:  printf("[STUDENT]\n\n");
        printf("ID: %s\n",info[jj].id);
        printf("First Name: %s\n",info[jj].first);
        printf("Last Name: %s\n",info[jj].last);
        printf("Phone Number: %s\n",info[jj].phone);
        printf("Email: %s\n",info[jj].email);
  adam: printf("Do you want to delete this contact information(Y/N)? ");
        scanf("%c",&de);
        if(de=='Y'){
                for(i=jj;i<count;i++)
                {
                    info[i]=info[i+1];
                }
                count--;
                rewrite();
            printf("Record Sucessfully Deleted!!!\n\n");
            AD();
        }
        else if(de=='N'){
           goto ervin;
        }
        else{
            printf("[ERROR] Invalid code\n");
            printf("[Re-type] ");
            goto adam;
        }
}

void search(){
    int i,j,c,d=0,x,p;
    char name[50],*role,*a;

    printf("[Search for a Contacts]\n\n");
    printf("===============================\n");
    printf("Contacts Information\n");
    printf("===============================\n\n");
    printf("Please input First Name for searching: ");
    AAA:scanf("%s",name);
    for(i=0;i<=count;i++)
    {
        c=0;
        if(info[i].id[0]=='0'&&info[i].id[1]=='0'){
            role = "Admin";
        }
        else{
            role = "Student";
        }
        for(x=0;x<2;x++){
                if(x==0){
                    for(p=0;name[p]!='\0';p++){
                        if(p==0){
                    if(name[p]>=97 && name[p]<=122){
					name[p]-=32;
                    }
                    }
                    else if(p>0){
                    if(name[p]>=65 && name[p]<=90){
					name[p]+=32;
                    }
                    }
                    }
                    }
                else{
					name[0]+=32;
                }
        if(strstr(info[i].first,name)!=NULL)
        {
            d++;
            if(d==1){printf("ID      FirstName      LastName           Role       Phone Number Email\n");
                printf("======================================================================================\n");
            }
            printf("%-7s %-14s %-18s %-10s %-12s %s\n",info[i].id,info[i].first,info[i].last,role,info[i].phone,info[i].email);
        }
    }
    }
    if(d==0){
            printf("[ERROR] There is no person Name '%s' in the system.\n",name);
            printf("[Re-Type] Please input First Name for searching: ");
            goto AAA;
    }
    else{printf("======================================================================================\n");}
    if(info[charlie].id[0]=='0'&&info[charlie].id[1]=='0'){
            AD();
        }
        else{
            STDm();
        }
}
