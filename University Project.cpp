#include<iostream>
#include<string.h>
using namespace std;
struct Students{
	char name[30],fname[30],address[40],dob[15],RegNumber[15];
};
struct Result{
	float gpa[5],GPA,CGPA;
};
float gpaCalculator(Result * ptr,int i){
	float ratio = (ptr[i].gpa[0]+ptr[i].gpa[1]+ptr[i].gpa[2]+ptr[i].gpa[3]+ptr[i].gpa[4])/5; 
	return ratio;
}
void subjects(int a){
	if(a==0)
	cout<<"GPA OF COMPUTER PROGRAMMING: ";
	else if(a==1)
	cout<<"GPA OF CIRCUIT ANALYSIS: ";
	else if(a==2)
	cout<<"GPA OF CALCULUS AND ANALYTICAL GEOMETRY: ";
	else if(a==3)
	cout<<"GPA OF ELECTRONIC DEVICES: ";
	else if(a==4)
	cout<<"GPA OF COMMUNICATION SKILLS: ";
}
void menu(){
	cout<<"Press \"1\" to Enter Record for students: "<<endl;
	cout<<"Press \"2\" to Modifying/Deleting for students: "<<endl;
	cout<<"Press \"3\" to View Records  for students: "<<endl;
	cout<<"Press \"4\" to exit: "<<endl;
}
void insertData(Students *ptr,int i){
	cout<<"\n====>INSERT PERSONAL DETAIL OF STUDENTS: \n\n";
		cin.ignore();
		cout<<"Data of Student No "<<i+1<<endl;
		cout<<"Enter Name of Student: ";
		cin.getline(ptr[i].name,30);
		cout<<"Enter Father Name of Student: ";
		cin.getline(ptr[i].fname,30);
		cout<<"Enter Address of Student: ";
		cin.getline(ptr[i].address,40);
		cout<<"Enter D.O.B of Student: ";
		cin.getline(ptr[i].dob,15);
		cout<<"Enter Registration Number of Student: ";
		cin.getline(ptr[i].RegNumber,15);
}
int  search(Students *ptr,int noOfStudents){
	cin.ignore();
	char RollNo[15];
	cout<<"Enter Roll No: ";
	cin.getline(RollNo,15);
	for(int i=0;i<noOfStudents;i++){
		if(strcmp(RollNo,ptr[i].RegNumber)==0){
			return i;
		}
	}
	return -1;
}
void viewData(Students *ptr,Result *ptr1,int noOfStudents=3){
	int i = search(ptr,noOfStudents);
	if(i!=-1){
		cout<<"====>PERSONAL INFORMATION: \n";
	cout<<"Name: \t\t"<<ptr[i].name<<"\nFather Name: \t"<<ptr[i].fname<<"\nAddress: \t"<<ptr[i].address;
	cout<<"\nD.O.B: \t\t"<<ptr[i].dob<<endl;
	cout<<"\n====>RESULT INFORMATION\n";
		int a=0;
		for(int j=0;j<5;j++){
			subjects(a++);
			cout<<ptr1[i].gpa[j]<<endl;
		}
		cout<<"GPA: "<<ptr1[i].GPA<<"\t\t"<<"CGPA: "<<ptr1[i].CGPA<<endl;
		
	}
	else{
		cout<<"\nNo such record is found\n";
	}
	cout<<endl;
}
void deleteData(Students *ptr,Result *ptr1,int &noOfStudents){
	int index = search(ptr , noOfStudents);
	if(index!=-1){
		for(int i=index;i<noOfStudents;i++){
		strcpy(ptr[i].name,ptr[i+1].name);
		strcpy(ptr[i].fname,ptr[i+1].fname);
		strcpy(ptr[i].address,ptr[i+1].address);
		strcpy(ptr[i].dob,ptr[i+1].dob);
		strcpy(ptr[i].RegNumber,ptr[i+1].RegNumber);
		for(int j=0;j<5;j++){
			ptr1[i].gpa[j]=ptr1[i+1].gpa[j];
		}
	}
	noOfStudents-=1;
	}
	else{
		cout<<"\nNo record of such student is found\n";
	}
	cout<<"\nStudent data deleted sucessfully\n";
}
void insertResult(Result *ptr1,int i){
	cout<<"\n=====>INSERT ACADEMIC DETAIL OF STUDENTS: \n\n";
		int a=0;
		for(int j=0;j<5;j++){
			subjects(a++);
			cin>>ptr1[i].gpa[j];
		}
		float gpa = gpaCalculator(ptr1,i);
		 ptr1[i].GPA=gpa;
		 ptr1[i].CGPA=gpa;
}
void updateData(Students *ptr,Result *ptr1,int noOfStudents){
	int index = search(ptr , noOfStudents);
	int x;
	do{
		cout<<"Press 1 for changing Personal Details: ";
		cout<<"\nPress 2 for changing Academic Details: ";
		cout<<"\nPress 3 for save changes:\n";
		cin>>x;
		if(x==1){
			cout<<"\nPress 1 for changing Name\n";
			cout<<"Press 2 for changing Father Name\n";
			cout<<"Press 3 for changing Address\n";
			cout<<"Press 4 for changing D.O.B\n";
			cout<<"Press 5 for changing Registration No.\n";
			cout<<"Press 6 for saving updated info: \n";
			int choice;
			do{
				cout<<"\nUse above instructions carefully\n";
				cin>>choice;
				cin.ignore();
				if(choice==1){
					cout<<"Enter Student Name: ";
					cin.getline(ptr[index].name,30);
				}
				else if(choice==2){
					cout<<"Enter Student Father Name: ";
					cin.getline(ptr[index].fname,30);
				}
				else if(choice==3){
					cout<<"Enter Student Address: ";
					cin.getline(ptr[index].address,40);
				}
				else if(choice==4){
					cout<<"Enter Student D.O.B: ";
					cin.getline(ptr[index].dob,15);
				}
				else if(choice==5){
					cout<<"Enter Student Registration No.: ";
					cin.getline(ptr[index].RegNumber,15);
				}
			}while(choice!=6);
		}
		else if(x==2){
			int userChoice;
			cout<<"\nPress 1 for changing COMPUTER PROGRAMMING GPA\n";
			cout<<"Press 2 for changing CIRCUIT ANALYSIS GPA\n";
			cout<<"Press 3 for changing CALCULUS AND ANALYTICAL GEOMETRY GPA\n";
			cout<<"Press 4 for ELECTRONIC DEVICES GPA\n";
			cout<<"Press 5 for COMMUNICATION SKILLS GPA\n";
			cout<<"Press 6 for saving updated info: \n";
			do{
				cout<<"\nUse above instructions carefully\n";
				cin>>userChoice;
				subjects(userChoice-1);
				cin>>ptr1[index].gpa[userChoice-1];
			}while(userChoice!=6);
			float gpa = gpaCalculator(ptr1,index);
			 ptr1[index].GPA=gpa;
			 ptr1[index].CGPA=gpa;
		}
	}while(x!=3);
	cout<<"Student Record Updated Sucessfully\n\n";
}
int main(){
	cout<<"FA22-CSE-024\n\n";
	int choice,NoOfStudents;
	Students * ptr;
	Result *ptr1;
	do{
		menu();
	cin>>choice;
	if(choice==1){
		cout<<"Data of how many students do you want to enter? ";
		cin>>NoOfStudents;
		ptr = new Students[NoOfStudents];
		ptr1= new Result[NoOfStudents];
		for(int i=0;i<NoOfStudents;i++){
			insertData(ptr,i);
			insertResult(ptr1,i);
		}
		cout<<endl;
	}
	else if(choice==2){
		char ch;
		cout<<"Press \"M\" for modify or \"D\" for delete the record of student: ";
		cin>>ch;
		if(ch=='M')
		updateData(ptr,ptr1,NoOfStudents);
		else if(ch=='D')
		deleteData(ptr,ptr1,NoOfStudents);
		else 
		cout<<"invlaid entry";
	}
	else if(choice==3){
		viewData(ptr,ptr1,NoOfStudents);
	}
	}while(choice!=4);
	cout<<"Thank You for visiting";
}
