#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>   //for tolower function
FILE *f;  //global declaration for storing student 
FILE *lp;  //global declartion for storing login info
char escape,con;
int flag=0;
 struct student_data    //for storing students information
 {
     char student_name[100];
     char student_id[20];
     char email[100];
     char address[100];
     char phone_number[12];
     char crn[4];
     char major[50];
 } data;      //nicknamed the student_data as data only

struct login_data{          //for storing login information
    char username[50];
    char password[50];
 } lgn;            //typedef login_data as lgn

//function prototyping

void headMessage(char*);
void welcomeMessage();
void login_storage();   //function to store credential
void login();           //to check credential and allow access
void main_body();       //main menu
void faculty();
void major_eng();
void add_student_bct();
void add_student_bce();
void add_student_bee();
void major_mgmt();
void add_student_bca();
void add_student_bba();
void add_student_bbm();
void disp_student();
void disp_student_eng();
void disp_student_bct();
void disp_student_bce();
void disp_student_bee();
void disp_student_mgmt();
void disp_student_bca();
void disp_student_bba();
void disp_student_bbm();
void search();
void modify();
void delete();
void login_update();


int main(){
    login_storage();
    welcomeMessage();
    login();
    return 0;
}

void headMessage(char *title)
{
    printf("\n\n\n\t\t\t\t\t\t##########################################################################");
    printf("\n\t\t\t\t\t\t############                                                  ############");
    printf("\n\t\t\t\t\t\t############    Student Database Management System (SDBMS)    ############");
    printf("\n\t\t\t\t\t\t############                                                  ############");
    printf("\n\t\t\t\t\t\t###########################################################################");
    printf("\n\t\t\t\t\t\t---------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t%s",title);
    printf("\n\t\t\t\t\t\t----------------------------------------------------------------------------\n");
}
void welcomeMessage()
{
    headMessage("www.pulchowklibrarysystem.com");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t  **_**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t\t\t\t        ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~");
    printf("\n\t\t\t\t\t\t        ~                  WELCOME                  ~");
    printf("\n\t\t\t\t\t\t        ~                    TO                     ~");
    printf("\n\t\t\t\t\t\t        ~                  STUDENT                  ~");
    printf("\n\t\t\t\t\t\t        ~              DATABSE MANAGEMENT           ~");
    printf("\n\t\t\t\t\t\t        ~                  SYSTEM                   ~");
    printf("\n\t\t\t\t\t\t        ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~");
    printf("\n\t\t\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t\t\t\t Enter any key to continue.....");
    getch();
}


void login_storage(){       //to sore login info 
    if(lp=fopen("login.txt","r")){   // checks if the file exist ,r is for read only
        fread(&lgn,sizeof(struct login_data),1,lp);//l not 1
        fclose(lp);
    }
    else{
    strcpy(lgn.username,"admin");   //if theres no file then this will be assigned as user and pass
    strcpy(lgn.password,"admin");
    }

}


void login(){
    int count=0;      //to count the incorrect credential 
    char user[50] ,pass[50];   //string declaration
    headMessage("Login");
    do{
		printf("\n\t\t\t\t\t\tEnter Username and Password");
		printf("\n\t\t\t\t\t\tUsername:");
		scanf(" %[^\n]" ,user);  //[^\n] identifies space as a string as well

		printf("\n\t\t\t\t\t\tPassword:");
		scanf(" %[^\n]" ,pass);
		if(strcmp(user,lgn.username)==0 && strcmp(pass,lgn.password)==0){ //check the username and password
            printf("\n\t\t\t\t\t\tlogged in\n");
            printf("\n\t\t\t\t\t\t\t\t\tpress any key to continue");
            getch();
            main_body();    //calling menu option on right credentials
            break;  //exit the loop if login is sucessfully
		}
		else{
            printf("\n\t\t\t\t\t\tThe entered username or password is wrong.\n");
            printf("\n\t\t\t\t\t\t\t\t\tTry again.\n");
            count++;
		}
		}while(count < 3);

		if(count>=3){ //wrong credential input above 3 times
            printf("Acess denied.");
            getch();
		}
    
}

void main_body(){
    int choice;        //integer declaration to store the choice number
        printf("\n\n\t\t\t1>.Add Student");
        printf("\n\n\t\t\t2>.Display Student");
        printf("\n\n\t\t\t3>.Search Student");
        printf("\n\n\t\t\t4>.Modify Data Records");
        printf("\n\n\t\t\t5>.Delete Student Data");
        printf("\n\n\t\t\t6>.Update login info");
        printf("\n\n\t\t\t7>.Exit");
        printf("\n\n\t\t\tEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){    //switch case to call in the function according to input
            case 1:
            faculty();
            break;
            case 2:
            disp_student();
            break;
            case 3:
            search();
            break;
            case 4:
            modify();
            break;
            case 5:
            delete();
            break;
            case 6:
            login_update();
            break;
            case 7:
            printf("Exiting program.\n");
            exit(0); // Terminate the program

            default:
            printf("\n\t\t\tTry valid character");
            printf("\n\n\t\t\tPress any key to continue");
            getch();
        }

} 


//lowering case function
void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);       //tolower function lowercases indivial char
    }
}



//catergorising part
void faculty(){ 
    char faculty_choice[10];      //to categorise in faculty
    printf("\n\t\t\t\t\t\t\t\t======Enter Faculty=====\n\n");
    printf("\n\t\t\tEngineering(Eng): ");
    printf("\n\t\t\tManagement(Mgmt):");
    printf("\n\t\t\tEnter the faculty (short form): ");
    scanf("%s",faculty_choice);
    toLowerCase(faculty_choice);
    if ((strcmp(faculty_choice, "eng")) == 0) {
       major_eng();
    }
    else if ((strcmp(faculty_choice, "mgmt")) == 0) {
       major_mgmt();
    }

    else if (!flag){
        printf("\n\t\t\tEnter valid major from list");
        printf("\n\t\t\tpress any key to continue");
        getch();
        faculty();   
    }
       
}


//engineering section
void major_eng() {    //function to sort out data according to major
    char major_choice[5]; // Allow enough space for the major choice (4 characters) + null terminator.
    printf("\n\t\t\t\t\t\t\t\t======Enter Students Major=====\n\n");
    printf("\n\n\t\t\tComputer Engineering (BCT)");
    printf("\n\n\t\t\tCivil Engineering (BCE)");
    printf("\n\n\t\t\tElectrical Engineering (BEE)");
    printf("\n\n\t\t\tType esc to return to main menu.");

    printf("\n\n\t\t\tEnter the major (short form): ");
    scanf("%s", major_choice);
    toLowerCase(major_choice);
    
    if ((strcmp(major_choice, "bct")) == 0) {
        add_student_bct();
    }
    else if((strcmp(major_choice, "bce")) == 0){
        add_student_bce();
    }
    else if((strcmp(major_choice, "bee")) == 0){
        add_student_bee();
    }
    else if((strcmp(major_choice, "esc")) == 0){
        main_body();
    }
    else{
        printf("\n\t\t\tEnter valid major from list");
        printf("\n\t\t\tpress any key to continue");
    }
    printf("\n\n\n\t\t\tEnter esc key to exit");
    printf("\nt\t\tTo input further data press any key");
    fflush(stdout);
    escape=getch();    //takes in the key to proceed
    if(escape==27)    //The ascii value of esc is 27 
    main_body();
    else
    major_eng();
    
}
  

void add_student_bct(){
    if((f=fopen("recordsbct.txt","a+"))==NULL){   //a+ is append + read mode
        //file doesn't exist scenario
        printf("Sorry, cannot open the file.");
        exit(1);  
    }
   
    do{
        printf("\n\t\t\t\t\t\t\t\t======Add student info=====\n\n");
        printf("\n\t\t\t Enter the name:");
        scanf(" %[^\n]",data.student_name);
        printf("\n\t\t\t Enter CRN:");
        scanf(" %[^\n]",data.crn);
        strcpy(con,"KIC079BCT0");
        printf("test");
        strcat(con,data.crn);
        printf("test");
        strcpy(data.student_id,con);
        printf("test");
        toLowerCase(data.student_id);
        printf("\n\t\t\t Enter Email:");
        scanf(" %[^\n]",data.email);
        printf("\n\t\t\t Enter Address:");
        scanf(" %[^\n]",data.address);
        printf("\n\t\t\t Enter Phone Number:");
        scanf(" %[^\n]",data.phone_number);       //to avoid overflow
        fflush(stdin); // Clear the input buffer
        strcpy(data.major, "BCT");
        fwrite(&data,sizeof(data),1,f);
        break;
    }while(1);
    fclose(f);
}

void add_student_bce(){
    if((f=fopen("recordsbce.txt","a+"))==NULL){   //a+ is append + read mode
        //file doesn't exist scenario
        printf("Sorry, cannot open the file.");
        exit(1);  
    }
    do{
        printf("\n\t\t\t\t\t\t======Add student info=====\n\n");
        printf("\n\t\t\t Enter the name:");
        scanf(" %[^\n]",data.student_name);
        printf("\n\t\t\t Enter ID:");
        scanf(" %[^\n]",data.student_id);
        toLowerCase(data.student_id);
        printf("\n\t\t\t Enter Email:");
        scanf(" %[^\n]",data.email);
        printf("\n\t\t\t Enter Address:");
        scanf(" %[^\n]",data.address);
        printf("\n\t\t\t Enter Phone Number:");
        scanf(" %[^\n]",data.phone_number);       //to avoid overflow
        fflush(stdin); // Clear the input buffer
        strcpy(data.major, "BCE");      //to assign faculty to respective data
        fwrite(&data,sizeof(data),1,f);
        break;
    }while(1);
    fclose(f);
}

void add_student_bee(){
    if((f=fopen("recordsbee.txt","a+"))==NULL){   //a+ is append + read mode
        //file doesn't exist scenario
        printf("Sorry, cannot open the file.");
        exit(1);  
    }
    do{
        printf("\n\t\t\t======Add student info=====\n\n");
        printf("\n\t\t\t Enter the name:");
        scanf(" %[^\n]",data.student_name);
        printf("\n\t\t\t Enter ID:");
        scanf(" %[^\n]",data.student_id);
        toLowerCase(data.student_id);
        printf("\n\t\t\t Enter Email:");
        scanf(" %[^\n]",data.email);
        printf("\n\t\t\t Enter Address:");
        scanf(" %[^\n]",data.address);
        printf("\n\t\t\t Enter Phone Number:");  //numbers above 10 digit will be stored in buffer
        scanf(" %[^\n]",data.phone_number);       //to avoid overflow
        fflush(stdin); // Clear the input buffer
        strcpy(data.major, "BEE");
        fwrite(&data,sizeof(data),1,f);
        break;
    }while(1);
    fclose(f);
}




//management section
void major_mgmt(){      //function to sort out data for management
char major_choice_mgmt[10];
    printf("\n\t\t\t======Enter Students Major=====\n\n");
    printf("\n\n\t\t\tComputer Administration(BCA)");
    printf("\n\n\t\t\tBusiness Administration(BBA)");
    printf("\n\n\t\t\tBusiness Management (BBM)");
    printf("\n\n\t\t\tEnter the major (short form): ");
    scanf("%s",major_choice_mgmt);
    toLowerCase(major_choice_mgmt);
    if ((strcmp(major_choice_mgmt, "bca")) == 0) {
        add_student_bca();
    }
    else if((strcmp(major_choice_mgmt, "bba")) == 0){
        add_student_bba();
    }
    else if((strcmp(major_choice_mgmt, "bbm")) == 0){
        add_student_bbm();
    }
    else{
        printf("\n\t\t\tEnter valid major from list");
        printf("\n\t\t\tpress any key to continue");
    }
    printf("\n\n\n\t\t\tEnter esc key to exit");
    printf("\nt\t\tTo input further data press any key");
    escape=getch();    //takes in the key to proceed
    if(escape==27)    //The ascii value of esc is 27 
    main_body();
    else
    major_mgmt();

}
void add_student_bca(){
    if((f=fopen("recordsbca.txt","a+"))==NULL){   //a+ is append + read mode
        //file doesn't exist scenario
        printf("Sorry, cannot open the file.");
        exit(1);  
    }
    do{
        printf("\n\t\t\t======Add student info=====\n\n");
        printf("\n\t\t\t Enter the name:");
        scanf(" %[^\n]",data.student_name);
        printf("\n\t\t\t Enter ID:");
        scanf(" %[^\n]",data.student_id);
        toLowerCase(data.student_id);
        printf("\n\t\t\t Enter Email:");
        scanf(" %[^\n]",data.email);
        printf("\n\t\t\t Enter Address:");
        scanf(" %[^\n]",data.address);
        printf("\n\t\t\t Enter Phone Number:");
        scanf(" %[^\n]",data.phone_number);       //to avoid overflow
        fflush(stdin); // Clear the input buffer
        strcpy(data.major, "BCA");
        fwrite(&data,sizeof(data),1,f);
        break;
    }while(1);
    fclose(f);
}
void add_student_bba(){
    if((f=fopen("recordsbba.txt","a+"))==NULL){   //a+ is append + read mode
        //file doesn't exist scenario
        printf("Sorry, cannot open the file.");
        exit(1);  
    }
    do{
        printf("\n\t\t\t======Add student info=====\n\n");
        printf("\n\t\t\t Enter the name:");
        scanf(" %[^\n]",data.student_name);
        printf("\n\t\t\t Enter ID:");
        scanf(" %[^\n]",data.student_id);
        toLowerCase(data.student_id);
        printf("\n\t\t\t Enter Email:");
        scanf(" %[^\n]",data.email);
        printf("\n\t\t\t Enter Address:");
        scanf(" %[^\n]",data.address);
        printf("\n\t\t\t Enter Phone Number:");
        scanf(" %[^\n]",data.phone_number);       //to avoid overflow
        fflush(stdin); // Clear the input buffer
        strcpy(data.major, "BBA");
        fwrite(&data,sizeof(data),1,f);
        break; 
    }while(1);
    fclose(f);
}
void add_student_bbm(){
    if((f=fopen("recordsbbm.txt","a+"))==NULL){   //a+ is append + read mode
        //file doesn't exist scenario
        printf("Sorry, cannot open the file.");
        exit(1);  
    }
    do{
        printf("\n\t\t\t======Add student info=====\n\n");
        printf("\n\t\t\t Enter the name:");
        scanf(" %[^\n]",data.student_name);
        printf("\n\t\t\t Enter ID:");
        scanf(" %[^\n]",data.student_id);
        toLowerCase(data.student_id);
        printf("\n\t\t\t Enter Email:");
        scanf(" %[^\n]",data.email);
        printf("\n\t\t\t Enter Address:");
        scanf(" %[^\n]",data.address);
        printf("\n\t\t\t Enter Phone Number:");
        scanf(" %[^\n]",data.phone_number);       //to avoid overflow
        fflush(stdin); // Clear the input buffer
        strcpy(data.major, "BBM");
        fwrite(&data,sizeof(data),1,f);
        break; 
    }while(1);
    fclose(f);
}



//displaying secition
void disp_student(){
    char faculty_choice[10];      //to categorise in faculty
    printf("\n\t\t\t======Enter Faculty=====\n\n");
    printf("\n\t\t\tEngineering(Eng): ");
    printf("\n\t\t\tManagement(Mgmt):");
    printf("\n\t\t\tEnter the faculty (short form): ");
    printf("\n\n\t\t\tType esc to return to main menu.");
    scanf("%s",faculty_choice);
    toLowerCase(faculty_choice);
    if ((strcmp(faculty_choice, "eng")) == 0) {
        disp_student_eng();
    }
    else if((strcmp(faculty_choice, "mgmt")) == 0) {
        disp_student_mgmt();
    }
    else if((strcmp(faculty_choice, "esc")) == 0){
        main_body();
    }
    else{
        printf("\n\t\t\tEnter valid major from list");
        printf("\n\t\t\tpress any key to continue");
        getch();
        disp_student();   
    } 

}
void disp_student_eng(){
    char major_choice[5];
    printf("\n\t\t\t======Enter Students Major=====\n\n");
    printf("\n\n\t\t\tComputer Engineering (BCT)");
    printf("\n\n\t\t\tCivil Engineering (BCE)");
    printf("\n\n\t\t\tElectrical Engineering (BEE)");
    printf("\n\n\t\t\tType esc to return.");
    printf("\n\n\t\t\tEnter the major (short form): ");
    scanf("%s", major_choice);
    toLowerCase(major_choice);
    
    if ((strcmp(major_choice, "bct")) == 0) {
        disp_student_bct();
    }
    else if ((strcmp(major_choice, "bce")) == 0) {
        disp_student_bce();
    }
    else if ((strcmp(major_choice, "bee")) == 0) {
        disp_student_bee();
    }
    else if ((strcmp(major_choice, "esc")) == 0) {
        main_body();
    }

    else{
        printf("\n\t\t\tEnter valid major from list");
        getch();

    }
    printf("\n\n\t\t\tPress esc to return to main menu");
    printf("\n\t\t\telse press any key to proceed");

    escape=getch();    //takes in the key to proceed
    if(escape==27)    //The ascii value of esc is 27 
    main_body();
    else
    disp_student_eng();

}

void disp_student_bct()
{
	if((f=fopen("recordsbct.txt","r"))==NULL)
    {
		printf("Cannot open the file");
		exit(1);
    }
    int flag=0;
        printf("\n\n\t\t\tBCT STUDENT DATA\n");
    while((fread(&data,sizeof(data),1,f))==1)
    {
        printf("\t\t\t**************************");
        flag=1;
		printf("\n\n\n\t\t\tName:%s\n\t\t\tID:%s\n\t\t\tEmail:%s\n\t\t\tAddress:%s\n\t\t\tPhone Number:%s\n\t\t\tMajor:%s\n"
        ,data.student_name,data.student_id,data.email ,data.address,data.phone_number,data.major);
		
    }
    if(!flag){
	printf("\n\n\t\t\tBCT STUDENT DATA\n");
	printf("\t\t\t**************************");
	printf("\n\n\n\n\n\n\t\t\t::No Records Available::");
    printf("\n\n\n\t\t\tpress any key to continue");

    }
    fclose(f);
}

void disp_student_bce(){
        if((f=fopen("recordsbce.txt","r"))==NULL){   //a+ is append + read mode
        //file doesn't exist scenario
        printf("Sorry, cannot open the file.");
        exit(1);  
    }
        printf("\n\n\t\t\t BCE STUDENT DATA\n");
        printf("\t\t\t**************************");
        int flag=0;
    while((fread(&data,sizeof(data),1,f))==1){
        flag=1;
		printf("\n\n\n\t\t\tName:%s\n\t\t\tID:%s\n\t\t\tEmail:%s\n\t\t\tAddress:%s\n\t\t\tPhone Number:%s\n\t\t\tMajor:%s\n"
        ,data.student_name,data.student_id,data.email ,data.address,data.phone_number,data.major);

    }
    if(!flag){
    printf("\n\n\t\t\tBCE STUDENT DATA\n");
	printf("\t\t\t**************************");
	printf("\n\n\n\n\n\n\t\t\t::No Records Available::");
    printf("\n\n\n\t\t\tpress any key to continue");
    }
    fclose(f);
}
void disp_student_bee(){
    if((f=fopen("recordsbee.txt","r"))==NULL){   //a+ is append + read mode
        //file doesn't exist scenario
        printf("Sorry, cannot open the file.");
        exit(1);  
    }
    printf("\n\n\t\t\t BEE STUDENT DATA\n");
    int flag=0;
    while((fread(&data,sizeof(data),1,f))==1){
        flag=1;
        printf("\t\t\t**************************");
		printf("\n\n\n\t\t\tName:%s\n\t\t\tID:%s\n\t\t\tEmail:%s\n\t\t\tAddress:%s\n\t\t\tPhone Number:%s\n\t\t\tMajor:%s\n"
        ,data.student_name,data.student_id,data.email ,data.address,data.phone_number,data.major);
    }
    if(!flag){
    printf("\n\n\t\t\tBEE STUDENT DATA\n");
	printf("\t\t\t**************************");
	printf("\n\n\n\n\n\n\t\t\t::No Records Available::");
    printf("\n\n\n\t\t\tpress any key to continue");
    }
    fclose(f);
}

//management sec of displaying
void disp_student_mgmt(){
    char major_choice_mgmt[10];
    printf("\n\t\t\t======Enter Students Major=====\n\n");
    printf("\n\n\t\t\tComputer Administration(BCA)");
    printf("\n\n\t\t\tBusiness Administration(BBA)");
    printf("\n\n\t\t\tBusiness Management (BBM)");
    printf("\n\n\t\t\tType esc to return.");
    printf("\n\n\t\t\tEnter the major (short form): ");
    scanf("%s",major_choice_mgmt);
    toLowerCase(major_choice_mgmt);
    if ((strcmp(major_choice_mgmt, "bca")) == 0) {
        disp_student_bca();
    }
    else if((strcmp(major_choice_mgmt, "bba")) == 0){
        disp_student_bba();
    }
    else if((strcmp(major_choice_mgmt, "bbm")) == 0){
        disp_student_bbm();
    }
    else if ((strcmp(major_choice_mgmt, "esc")) == 0) {
        main_body();
    }
    else{
        printf("\n\t\t\tEnter valid major from list");
        getch(); 
    }
    printf("\n\n\t\t\tPress esc to return to main menu");
    printf("\n\t\t\telse press any key to proceed");

    escape=getch();    //takes in the key to proceed
    if(escape==27)    //The ascii value of esc is 27 
    main_body();
    else
    disp_student_mgmt();
}
void disp_student_bca(){
    if((f=fopen("recordsbca.txt","r"))==NULL){   //a+ is append + read mode
        //file doesn't exist scenario
        printf("Sorry, cannot open the file.");
        exit(1);  
    }
    printf("\n\n\t\t\t BCA STUDENT DATA\n");
    printf("\t\t\t**************************");
    int flag=0;
    while((fread(&data,sizeof(data),1,f))==1){
        flag=1;
		printf("\n\n\n\t\t\tName:%s\n\t\t\tID:%s\n\t\t\tEmail:%s\n\t\t\tAddress:%s\n\t\t\tPhone Number:%s\n\t\t\tMajor:%s\n"
        ,data.student_name,data.student_id,data.email ,data.address,data.phone_number,data.major);
    }
    if(!flag){
    printf("\n\n\t\t\tBCA STUDENT DATA\n");
	printf("\t\t\t**************************");
	printf("\n\n\n\n\n\n\t\t\t::No Records Available::");
    printf("\n\n\n\t\t\tpress any key to continue");
    }
    fclose(f);
}
void disp_student_bba(){
    if((f=fopen("recordsbba.txt","r"))==NULL){   // read mode
        //file doesn't exist scenario
        printf("Sorry, cannot open the file.");
        exit(1);  
    }
    int flag=0;
    printf("\n\n\t\t\t BBA STUDENT DATA\n");
    printf("\t\t\t**************************");
    while((fread(&data,sizeof(data),1,f))==1){
        flag=1;
 		printf("\n\n\n\t\t\tName:%s\n\t\t\tID:%s\n\t\t\tEmail:%s\n\t\t\tAddress:%s\n\t\t\tPhone Number:%s\n\t\t\tMajor:%s\n"
        ,data.student_name,data.student_id,data.email ,data.address,data.phone_number,data.major);
    }
    if(!flag){
        printf("\n\n\t\t\tBBA STUDENT DATA\n");
	    printf("\t\t\t**************************");
	    printf("\n\n\n\n\n\n\t\t\t::No Records Available::");
        printf("\n\n\n\t\t\tpress any key to continue");
    }
    fclose(f);

}
void disp_student_bbm(){
    if((f=fopen("recordsbbm.txt","r"))==NULL){   //a+ is append + read mode
        //file doesn't exist scenario
        printf("Sorry, cannot open the file.");
        exit(1);  
    }
    printf("\n\n\t\t\t BCT STUDENT DATA\n");
    printf("\t\t\t**************************");
    int flag=0;
    while((fread(&data,sizeof(data),1,f))==1){
        flag=1;
		printf("\n\n\n\t\t\tName:%s\n\t\t\tID:%s\n\t\t\tEmail:%s\n\t\t\tAddress:%s\n\t\t\tPhone Number:%s\n\t\t\tMajor:%s\n"
        ,data.student_name,data.student_id,data.email ,data.address,data.phone_number,data.major);
    }
    if(!flag){
    printf("\n\n\t\t\t\tBBM STUDENT DATA\n");
	printf("\t\t\t**************************");
	printf("\n\n\n\n\n\n\t\t\t::No Records Available::");
    printf("\n\n\n\t\t\tpress any key to continue");
    }
    fclose(f);
}



//search section
void search(){
    char id_check[20], name_check[100];     //to store info
    printf("\n\t\t\t======SEARCH=====\n\n");
    printf("\n\t\t\t\tEnter student id:");
    scanf("%s",id_check);
    toLowerCase(id_check);
    // Check for invalid characters in the student ID
    for (int i = 0; id_check[i] != '\0'; i++) {    //every string ends with /0
        if (!isalnum(id_check[i])) { // isalnum() checks if the character is alphanumeric
            printf("\n\n\n\t\t\t::Invalid character in student ID::");
            printf("\n\n\n\t\t\tPress any key to continue");
            getch();
            main_body();
            return; // Return from the function if an invalid character is found
        }
    }
    int flag=0;
    //search in recordsbct.txt
    //the iteration will stop if the file is found
    if((f=fopen("recordsbct.txt","r"))){     //the file exist the following code will be executed
        while(fread(&data,sizeof(data),1,f)==1){
            if((strcmp(data.student_id,id_check))==0){
                flag=1;
                break;
            }
        }
        fclose(f);
    }
    //search in recordsbce.txt
    if (!flag && (f = fopen("recordsbce.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }
    //search in recordsbee
    if (!flag && (f = fopen("recordsbee.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }

    if (!flag && (f = fopen("recordsbca.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }
    if (!flag && (f = fopen("recordsbba.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }
        if (!flag && (f = fopen("recordsbbm.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }
        if (flag){
 		printf("\n\n\n\t\t\tName:%s\n\t\t\tID:%s\n\t\t\tEmail:%s\n\t\t\tAddress:%s\n\t\t\tPhone Number:%s\n\t\t\tMajor:%s\n"
        ,data.student_name,data.student_id,data.email ,data.address,data.phone_number,data.major);
        printf("\n\t\t\tPress escape key to return to main menu or");
        printf("\n\n\t\t\tPress any key to continue searching.");
        escape=getch();
        if(escape==27)
        main_body();
        else 
        search();
        }
    else{
        
        printf("\n\n\n\t\t\t::No such Record::");
        printf("\n\n\n\t\t\tPress escape key to return to main menu or");
        printf("\n\t\t\tPress any key to continue searching.");
        escape=getch();
        if(escape==27)
        main_body();
        else 
        search();
    }
}

void modify(){
    FILE *tempf;      //to store data temp
    char id_check[20],mod_choice[20];
    int found=0;
    printf("\n\n\t\t\t=====MODIFY STUDENT DATA=====");
    printf("\n\t\t\t\tEnter student id");
    printf("\n\t\t\t\tor type esc to return to main menu:");

    scanf("%s",id_check);
    toLowerCase(id_check);
    // Check for invalid characters in the student ID
    for (int i = 0; id_check[i] != '\0'; i++) {    //every string ends with /0
        if (!isalnum(id_check[i])) { // isalnum() checks if the character is alphanumeric
            printf("\n\n\n\t\t\t::Invalid character in student ID::");
            printf("\n\n\n\t\t\tPress any key to continue");
            getch();
            main_body();
            return; // Return from the function if an invalid character is found
        }
    }

    //search in recordsbct.txt
    //the iteration will stop if the file is found
    if((f=fopen("recordsbct.txt","r"))){     //the file exist the following code will be executed
        while(fread(&data,sizeof(data),1,f)==1){
            if((strcmp(data.student_id,id_check))==0){
                flag=1;
                break;
            }
        }
        fclose(f);
    }

    //search in recordsbce.txt
    if (!flag && (f = fopen("recordsbce.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }

    //search in recordsbee
    if (!flag && (f = fopen("recordsbee.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }

    if (!flag && (f = fopen("recordsbca.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }

    if (!flag && (f = fopen("recordsbba.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }

    if (!flag && (f = fopen("recordsbbm.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    } //these for checking and reading file

    tempf=fopen("tempf.txt","w");
    if(tempf==NULL){   //incase the disk is full or file permission error
		printf("Cannot open the file");
		exit(1);
	}
        if (flag){
            
		printf("\n\n\n\t\t\tName:%s\n\t\t\tID:%s\n\t\t\tEmail:%s\n\t\t\tAddress:%s\n\t\t\tPhone Number:%s\n\t\t\tMajor:%s\n"
        ,data.student_name,data.student_id,data.email ,data.address,data.phone_number,data.major);
            printf("\n\n\t\t\tWhat do you want to modify? ");
            printf("\n\t\t\ttype 'all' to modify everything: ");
            printf("\n\t\t\ttype esc to return to main menu: ");

            scanf("%s",mod_choice);
            toLowerCase(mod_choice);

            if((strcmp(mod_choice,"esc")==0)){
                main_body();
            }

            //bct portion
            if((strcmp(data.major,"BCT")==0)){
                f=fopen("recordsbct.txt","a+");
                if((strcmp(mod_choice,"name"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name field (student_name)
                            printf("\n\t\t\tEnter new name: ");
                            scanf(" %[^\n]", data.student_name); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"id"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the id field (student_id)
                            printf("\n\t\t\tEnter new id: ");
                            scanf(" %[^\n]", data.student_id); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"email"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the email field (student_email)
                            printf("\n\t\t\tEnter new email: ");
                            scanf(" %[^\n]", data.email); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"address"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name address (student_address)
                            printf("\n\t\t\tEnter new Address: ");
                            scanf(" %[^\n]", data.address); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }    
                }
                if((strcmp(mod_choice,"phone number"))==0||(strcmp(mod_choice,"number"))==0||(strcmp(mod_choice,"phone"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name number (student_number)
                            printf("\n\t\t\tEnter new Phone Number: ");
                            scanf("  %[^\n]", data.phone_number); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"all"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){

                            printf("\n\t\t\t Enter the name:");
                            scanf(" %[^\n]",data.student_name);
                            printf("\n\t\t\t Enter ID:");
                            scanf(" %[^\n]",data.student_id);
                            toLowerCase(data.student_id);
                            printf("\n\t\t\t Enter Email:");
                            scanf(" %[^\n]",data.email);
                            printf("\n\t\t\t Enter Address:");
                            scanf(" %[^\n]",data.address);
                            printf("\n\t\t\t Enter Phone Number:");  //numbers above 10 digit will be stored in buffer
                            scanf(" %[^\n]",data.phone_number);       //to avoid overflow
                            fflush(stdin); // Clear the input buffer   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }

                }   
                fclose(f);    // Close the original file
                fclose(tempf); // Close the temporary file

                // Remove the original file and rename "tempf" to the original filename
                remove("recordsbct.txt"); // Remove the original file
                rename("tempf.txt", "recordsbct.txt"); // Rename "tempf" to the original filename
            
            }


            //bce portion
            if((strcmp(data.major,"BCE")==0)){
                f=fopen("recordsbce.txt","a+");
                if((strcmp(mod_choice,"name"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name field (student_name)
                            printf("\n\t\t\tEnter new name: ");
                            scanf(" %[^\n]", data.student_name); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"id"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the id field (student_id)
                            printf("\n\t\t\tEnter new id: ");
                            scanf(" %[^\n]", data.student_id); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"email"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the email field (student_email)
                            printf("\n\t\t\tEnter new email: ");
                            scanf(" %[^\n]", data.email); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"address"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name address (student_address)
                            printf("\n\t\t\tEnter new Address: ");
                            scanf(" %[^\n]", data.address); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }    
                }
                if((strcmp(mod_choice,"phone number"))==0||(strcmp(mod_choice,"number"))==0||(strcmp(mod_choice,"phone"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name number (student_number)
                            printf("\n\t\t\tEnter new Phone Number: ");
                            scanf(" %[^\n]", data.phone_number); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"all"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){

                            printf("\n\t\t\t Enter the name:");
                            scanf(" %[^\n]",data.student_name);
                            printf("\n\t\t\t Enter ID:");
                            scanf(" %[^\n]",data.student_id);
                            toLowerCase(data.student_id);
                            printf("\n\t\t\t Enter Email:");
                            scanf(" %[^\n]",data.email);
                            printf("\n\t\t\t Enter Address:");
                            scanf(" %[^\n]",data.address);
                            printf("\n\t\t\t Enter Phone Number:");  //numbers above 10 digit will be stored in buffer
                            scanf(" %[^\n]",data.phone_number);       //to avoid overflow
                            fflush(stdin); // Clear the input buffer   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }

                }   
            fclose(f);    // Close the original file
            fclose(tempf); // Close the temporary file

            // Remove the original file and rename "tempf" to the original filename
            remove("recordsbce.txt"); // Remove the original file
            rename("tempf.txt", "recordsbce.txt"); // Rename "tempf" to the original filename
            
            }


            //bee portion
            if((strcmp(data.major,"BEE")==0)){
                f=fopen("recordsbee.txt","a+");
                if((strcmp(mod_choice,"name"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name field (student_name)
                            printf("\n\t\t\tEnter new name: ");
                            scanf(" %[^\n]", data.student_name); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"id"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the id field (student_id)
                            printf("\n\t\t\tEnter new id: ");
                            scanf(" %[^\n]", data.student_id); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"email"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the email field (student_email)
                            printf("\n\t\t\tEnter new email: ");
                            scanf(" %[^\n]", data.email); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"address"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name address (student_address)
                            printf("\n\t\t\tEnter new Address: ");
                            scanf(" %[^\n]", data.address); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }    
                }
                if((strcmp(mod_choice,"phone number"))==0||(strcmp(mod_choice,"number"))==0||(strcmp(mod_choice,"phone"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name number (student_number)
                            printf("\n\t\t\tEnter new Phone Number: ");
                            scanf("  %[^\n]", data.phone_number); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"all"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){

                            printf("\n\t\t\t Enter the name:");
                            scanf(" %[^\n]",data.student_name);
                            printf("\n\t\t\t Enter ID:");
                            scanf(" %[^\n]",data.student_id);
                            toLowerCase(data.student_id);
                            printf("\n\t\t\t Enter Email:");
                            scanf(" %[^\n]",data.email);
                            printf("\n\t\t\t Enter Address:");
                            scanf(" %[^\n]",data.address);
                            printf("\n\t\t\t Enter Phone Number:");  //numbers above 10 digit will be stored in buffer
                            scanf(" %[^\n]",data.phone_number);       //to avoid overflow
                            fflush(stdin); // Clear the input buffer   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }

                }   
            fclose(f);    // Close the original file
            fclose(tempf); // Close the temporary file

            // Remove the original file and rename "tempf" to the original filename
            remove("recordsbee.txt"); // Remove the original file
            rename("tempf.txt", "recordsbee.txt"); // Rename "tempf" to the original filename
            
            }



            //bca portion
            if((strcmp(data.major,"BCA")==0)){
                f=fopen("recordsbca.txt","a+");
                if((strcmp(mod_choice,"name"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name field (student_name)
                            printf("\n\t\t\tEnter new name: ");
                            scanf(" %[^\n]", data.student_name); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"id"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the id field (student_id)
                            printf("\n\t\t\tEnter new id: ");
                            scanf(" %[^\n]", data.student_id); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"email"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the email field (student_email)
                            printf("\n\t\t\tEnter new email: ");
                            scanf(" %[^\n]", data.email); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"address"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name address (student_address)
                            printf("\n\t\t\tEnter new Address: ");
                            scanf(" %[^\n]", data.address); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }    
                }
                if((strcmp(mod_choice,"phone number"))==0||(strcmp(mod_choice,"number"))==0||(strcmp(mod_choice,"phone"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name number (student_number)
                            printf("\n\t\t\tEnter new Phone Number: ");
                            scanf("  %[^\n]", data.phone_number); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"all"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){

                            printf("\n\t\t\t Enter the name:");
                            scanf(" %[^\n]",data.student_name);
                            printf("\n\t\t\t Enter ID:");
                            scanf(" %[^\n]",data.student_id);
                            toLowerCase(data.student_id);
                            printf("\n\t\t\t Enter Email:");
                            scanf(" %[^\n]",data.email);
                            printf("\n\t\t\t Enter Address:");
                            scanf(" %[^\n]",data.address);
                            printf("\n\t\t\t Enter Phone Number:");  //numbers above 10 digit will be stored in buffer
                            scanf(" %[^\n]",data.phone_number);       //to avoid overflow
                            fflush(stdin); // Clear the input buffer   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }

                }   
            fclose(f);    // Close the original file
            fclose(tempf); // Close the temporary file

            // Remove the original file and rename "tempf" to the original filename
            remove("recordsbca.txt"); // Remove the original file
            rename("tempf.txt", "recordsbca.txt"); // Rename "tempf" to the original filename
            
            }


            //bba portion
            if((strcmp(data.major,"BBA")==0)){
                f=fopen("recordsbba.txt","a+");
                if((strcmp(mod_choice,"name"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name field (student_name)
                            printf("\n\t\t\tEnter new name: ");
                            scanf(" %[^\n]", data.student_name); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"id"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the id field (student_id)
                            printf("\n\t\t\tEnter new id: ");
                            scanf(" %[^\n]", data.student_id); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"email"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the email field (student_email)
                            printf("\n\t\t\tEnter new email: ");
                            scanf(" %[^\n]", data.email); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"address"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name address (student_address)
                            printf("\n\t\t\tEnter new Address: ");
                            scanf(" %[^\n]", data.address); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }    
                }
                if((strcmp(mod_choice,"phone number"))==0||(strcmp(mod_choice,"number"))==0||(strcmp(mod_choice,"phone"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name number (student_number)
                            printf("\n\t\t\tEnter new Phone Number: ");
                            scanf("  %[^\n]", data.phone_number); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"all"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){

                            printf("\n\t\t\t Enter the name:");
                            scanf(" %[^\n]",data.student_name);
                            printf("\n\t\t\t Enter ID:");
                            scanf(" %[^\n]",data.student_id);
                            toLowerCase(data.student_id);
                            printf("\n\t\t\t Enter Email:");
                            scanf(" %[^\n]",data.email);
                            printf("\n\t\t\t Enter Address:");
                            scanf(" %[^\n]",data.address);
                            printf("\n\t\t\t Enter Phone Number:");  //numbers above 10 digit will be stored in buffer
                            scanf(" %[^\n]",data.phone_number);       //to avoid overflow
                            fflush(stdin); // Clear the input buffer   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }

                }   
            fclose(f);    // Close the original file
            fclose(tempf); // Close the temporary file

            // Remove the original file and rename "tempf" to the original filename
            remove("recordsbba.txt"); // Remove the original file
            rename("tempf.txt", "recordsbba.txt"); // Rename "tempf" to the original filename
            
            }




            //bbmt portion
            if((strcmp(data.major,"BBM")==0)){
                f=fopen("recordsbbm.txt","a+");
                if((strcmp(mod_choice,"name"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name field (student_name)
                            printf("\n\t\t\tEnter new name: ");
                            scanf(" %[^\n]", data.student_name); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"id"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the id field (student_id)
                            printf("\n\t\t\tEnter new id: ");
                            scanf(" %[^\n]", data.student_id); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"email"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the email field (student_email)
                            printf("\n\t\t\tEnter new email: ");
                            scanf(" %[^\n]", data.email); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"address"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name address (student_address)
                            printf("\n\t\t\tEnter new Address: ");
                            scanf(" %[^\n]", data.address); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }    
                }
                if((strcmp(mod_choice,"phone number"))==0||(strcmp(mod_choice,"number"))==0||(strcmp(mod_choice,"phone"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){
                             // Modify only the name number (student_number)
                            printf("\n\t\t\tEnter new Phone Number: ");
                            scanf(" %[^\n]", data.phone_number); // Use space before % to consume leading whitespace   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }
                }
                if((strcmp(mod_choice,"all"))==0){
                    while(fread(&data,sizeof(data),1,f)==1){
                        if(strcmp(data.student_id,id_check)==0){

                            printf("\n\t\t\t Enter the name:");
                            scanf(" %[^\n]",data.student_name);
                            printf("\n\t\t\t Enter ID:");
                            scanf(" %[^\n]",data.student_id);
                            toLowerCase(data.student_id);
                            printf("\n\t\t\t Enter Email:");
                            scanf(" %[^\n]",data.email);
                            printf("\n\t\t\t Enter Address:");
                            scanf(" %[^\n]",data.address);
                            printf("\n\t\t\t Enter Phone Number:");  //numbers above 10 digit will be stored in buffer
                            scanf(" %[^\n]",data.phone_number);       //to avoid overflow
                            fflush(stdin); // Clear the input buffer   
                            found=1;
                        }
                        //fwrite is put here so that the data is entered after its changed
                        fwrite(&data, sizeof(data), 1, tempf); // Write data to the temporary file
                    }

                }  
                fclose(f);    // Close the original file
            fclose(tempf); // Close the temporary file

            // Remove the original file and rename "tempf" to the original filename
            remove("recordsbbm.txt"); // Remove the original file
            rename("tempf.txt", "recordsbbm.txt"); // Rename "tempf" to the original filename
            } 
            
            
            else if (!found){
                    printf("\n\t\t\t Enter Valid Respone");
                    printf("\n\t\t\t Press any key to continue");
                    getch();
                    modify();
                }
            
        
           
            fclose(f);    // Close the original file
            fclose(tempf); // Close the temporary file

            // Remove the original file and rename "tempf" to the original filename
            remove("recordsbbm.txt"); // Remove the original file
            rename("tempf.txt", "recordsbbm.txt"); // Rename "tempf" to the original filename
    }     
    if (found) {
        printf("\n\n\n\t\t\tRecord modified");
        printf("\n\t\t\tPress esc to return to main menu");
        printf("\n\t\t\telse press any key to proceed");

        escape=getch();    //takes in the key to proceed
        if(escape==27)    //The ascii value of esc is 27 
        main_body();
        else
        modify();

    } 
    else {
        printf("\n\n\n\t\t\t::No such Record::");

        printf("\n\t\t\tPress esc to return to main menu");
        printf("\n\t\t\telse press any key to proceed");

        escape=getch();    //takes in the key to proceed
        if(escape==27)    //The ascii value of esc is 27 
        main_body();
        else
        modify();
    }
    getch();  
}

void delete(){
    FILE *tempf;      //to store data temp
    char id_check[20],mod_choice[20];
    int found=0;
    printf("\n\n\t\t\t=====MODIFY STUDENT DATA=====");
    printf("\n\t\t\t\tEnter student id");
    printf("\n\t\t\t\tor type esc to return to main menu: ");

    scanf("%s",id_check);
    toLowerCase(id_check);

    //escaping
    if(strcmp("esc",id_check)==0){
        main_body();
        
    }
    // Check for invalid characters in the student ID
    for (int i = 0; id_check[i] != '\0'; i++) {    //every string ends with /0
        if (!isalnum(id_check[i])) { // isalnum() checks if the character is alphanumeric
            printf("\n\n\n\t\t\t::Invalid character in student ID::");
            printf("\n\n\n\t\t\tPress any key to continue");
            getch();
            main_body();
            return; // Return from the function if an invalid character is found
        }
    }

    //search in recordsbct.txt
    //the iteration will stop if the file is found
    if((f=fopen("recordsbct.txt","r"))){     //the file exist the following code will be executed
        while(fread(&data,sizeof(data),1,f)==1){
            if((strcmp(data.student_id,id_check))==0){
                flag=1;
                break;
            }
        }
        fclose(f);
    }

    //search in recordsbce.txt
    if (!flag && (f = fopen("recordsbce.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }

    //search in recordsbee
    if (!flag && (f = fopen("recordsbee.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }

    if (!flag && (f = fopen("recordsbca.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }

    if (!flag && (f = fopen("recordsbba.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    }

    if (!flag && (f = fopen("recordsbbm.txt", "r"))) {
        while (fread(&data, sizeof(data), 1, f) == 1) {
            if (strcmp(data.student_id, id_check) == 0) {
                flag = 1;
                break;
            }
        }
        fclose(f);
    } //these for checking and reading file

    tempf=fopen("tempf.txt","w");
    if(tempf==NULL){   //incase the disk is full or file permission error
		printf("Cannot open the file");
		exit(1);
	}
    if (flag){
        printf("\n\n\n\t\t\tName:%s\n\t\t\tID:%s\n\t\t\tEmail:%s\n\t\t\tAddress:%s\n\t\t\tPhone Number:%s\n\t\t\tMajor:%s\n"
        ,data.student_name,data.student_id,data.email ,data.address,data.phone_number,data.major);
        printf("\n\t\t\t\t\tAre you sure you want to delete this data?(Y/N) ");
        scanf("%s",mod_choice);
        toLowerCase(mod_choice);
        if(strcmp(mod_choice,"y")==0){

            //for bct
            if((strcmp(data.major,"BCT")==0)){
            f=fopen("recordsbct.txt","r");
                while(fread(&data,sizeof(data),1,f)==1){
                    if(strcmp(data.student_id,id_check)==0){
                        found=1;
                        continue; //skips the matched value
                    }
                    else
                    fwrite(&data, sizeof(data), 1, tempf);  
                }
                fclose(f);    // Close the original file
                fclose(tempf); // Close the temporary file

                // Remove the original file and rename "tempf" to the original filename
                remove("recordsbct.txt"); // Remove the original file
                rename("tempf.txt", "recordsbct.txt"); // Rename "tempf" to the original filename
                printf("\n\t\t\t\t\tSucessfully removed");
                printf("\n\t\t\t\t\tPress esc to return to main menu");
                printf("\n\t\t\t\t\telse press any key to proceed");
                escape=getch();    //takes in the key to proceed
                if(escape==27)    //The ascii value of esc is 27 
                main_body();
                else
                delete();
            }

            //for bce
            if((strcmp(data.major,"BCE")==0)){
            f=fopen("recordsbce.txt","r");
                while(fread(&data,sizeof(data),1,f)==1){
                    if(strcmp(data.student_id,id_check)==0){
                        found=1;
                        continue; //skips the matched value
                    }
                    else
                    fwrite(&data, sizeof(data), 1, tempf);  
                }
                fclose(f);    // Close the original file
                fclose(tempf); // Close the temporary file

                // Remove the original file and rename "tempf" to the original filename
                remove("recordsbce.txt"); // Remove the original file
                rename("tempf.txt", "recordsbce.txt"); // Rename "tempf" to the original filename
                printf("\n\t\t\t\t\tSucessfully removed");
                printf("\n\t\t\t\t\tPress esc to return to main menu");
                printf("\n\t\t\t\t\telse press any key to proceed");
                escape=getch();    //takes in the key to proceed
                if(escape==27)    //The ascii value of esc is 27 
                main_body();
                else
                delete();
            }

            //for bee
            if((strcmp(data.major,"BEE")==0)){
            f=fopen("recordsbee.txt","r");
                while(fread(&data,sizeof(data),1,f)==1){
                    if(strcmp(data.student_id,id_check)==0){
                        found=1;
                        continue; //skips the matched value
                    }
                    else
                    fwrite(&data, sizeof(data), 1, tempf);  
                }
                fclose(f);    // Close the original file
                fclose(tempf); // Close the temporary file

                // Remove the original file and rename "tempf" to the original filename
                remove("recordsbee.txt"); // Remove the original file
                rename("tempf.txt", "recordsbee.txt"); // Rename "tempf" to the original filename
                printf("\n\t\t\t\t\tSucessfully removed");
                printf("\n\t\t\t\t\tPress esc to return to main menu");
                printf("\n\t\t\t\t\telse press any key to proceed");
                escape=getch();    //takes in the key to proceed
                if(escape==27)    //The ascii value of esc is 27 
                main_body();
                else
                delete();
            }

            //for bca
            if((strcmp(data.major,"BCA")==0)){
            f=fopen("recordsbca.txt","r");
                while(fread(&data,sizeof(data),1,f)==1){
                    if(strcmp(data.student_id,id_check)==0){
                        found=1;
                        continue; //skips the matched value
                    }
                    else
                    fwrite(&data, sizeof(data), 1, tempf);  
                }
                fclose(f);    // Close the original file
                fclose(tempf); // Close the temporary file

                // Remove the original file and rename "tempf" to the original filename
                remove("recordsbca.txt"); // Remove the original file
                rename("tempf.txt", "recordsbca.txt"); // Rename "tempf" to the original filename
                printf("\n\t\t\t\t\tSucessfully removed");
                printf("\n\t\t\t\t\tPress esc to return to main menu");
                printf("\n\t\t\t\t\telse press any key to proceed");
                escape=getch();    //takes in the key to proceed
                if(escape==27)    //The ascii value of esc is 27 
                main_body();
                else
                delete();
            }


            //for bba
            if((strcmp(data.major,"BBA")==0)){
            f=fopen("recordsbca.txt","r");
                while(fread(&data,sizeof(data),1,f)==1){
                    if(strcmp(data.student_id,id_check)==0){
                        found=1;
                        continue; //skips the matched value
                    }
                    else
                    fwrite(&data, sizeof(data), 1, tempf);  
                }
                fclose(f);    // Close the original file
                fclose(tempf); // Close the temporary file

                // Remove the original file and rename "tempf" to the original filename
                remove("recordsbba.txt"); // Remove the original file
                rename("tempf.txt", "recordsbba.txt"); // Rename "tempf" to the original filename
                printf("\n\t\t\t\t\tSucessfully removed");
                printf("\n\t\t\t\t\tPress esc to return to main menu");
                printf("\n\t\t\t\t\telse press any key to proceed");
                escape=getch();    //takes in the key to proceed
                if(escape==27)    //The ascii value of esc is 27 
                main_body();
                else
                delete();
            }


            //for bbm
            if((strcmp(data.major,"BBM")==0)){
            f=fopen("recordsbbm.txt","r");
                while(fread(&data,sizeof(data),1,f)==1){
                    if(strcmp(data.student_id,id_check)==0){
                        found=1;
                        continue; //skips the matched value
                    }
                    else
                    fwrite(&data, sizeof(data), 1, tempf);  
                }
                fclose(f);    // Close the original file
                fclose(tempf); // Close the temporary file

                // Remove the original file and rename "tempf" to the original filename
                remove("recordsbbm.txt"); // Remove the original file
                rename("tempf.txt", "recordsbbm.txt"); // Rename "tempf" to the original filename
                printf("\n\t\t\t\t\tSucessfully removed");
                printf("\n\t\t\t\t\tPress esc to return to main menu");
                printf("\n\t\t\t\t\telse press any key to proceed");
                escape=getch();    //takes in the key to proceed
                if(escape==27)    //The ascii value of esc is 27 
                main_body();
                else
                delete();
            }
            




        }
        if(strcmp(mod_choice,"n")==0){
            printf("\n\t\t\t\t\tPress esc to return to main menu");
            printf("\n\t\t\t\t\telse press any key to proceed");
            escape=getch();    //takes in the key to proceed
            if(escape==27)    //The ascii value of esc is 27 
            main_body();
            else
            delete();
        }
        else{
            printf("\n\t\t\t\t\tenter either y or n");
            delete();

        }
    }
    else{
                printf("\n\n\n\t\t\t::No such Record::");
                printf("\n\t\t\t\t\tPress esc to return to main menu");
                printf("\n\t\t\t\t\telse press any key to continue");
                escape=getch();    //takes in the key to proceed
                if(escape==27)    //The ascii value of esc is 27 
                main_body();
                else
                delete();

            }
    

}

void login_update(){
    lp=fopen("login.txt","w");
    if(!lp){
        printf("cannot open the file");
        exit(1);
    }
    else{
    printf("\n\n\n\t\t\t\t\t\t\t\t\tUPDATE CREDENTIAL");
    printf("\n\t\t\t\t\t\t\tEnter new username: \t");
	scanf(" %[^\n]",lgn.username);
	printf("\n\t\t\t\t\t\t\tEnter new password: \t");
	scanf(" %[^\n]",lgn.password);
	fwrite(&lgn,sizeof(lgn),1,lp);
	fclose(lp);
    fflush(stdin);
    printf("\n\t\t\t\t\t\tUsername and Password has been changed successfully");
    printf("\n\n\t\t\t\t\t\tLogin Again\n\n\n");
    getch();
    login();
    }

}









