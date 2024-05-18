#include<iostream> 
using namespace std;
					/***********CONTACT CLASS***********/
class contact{
	public:
		int no;
		string name;
		string phone_no;
		string email;
		contact* next;
		contact(int ID_VALUE,string NAME,string MOBILE,string EMAIL){
			no = ID_VALUE;
			name = NAME;
			phone_no = MOBILE;
			email = EMAIL;
		}
};
 
					/***********INSERTION FUNCTION***********/

void traverse(contact* &head,int ID_VALUE,string NAME,string MOBILE,string EMAIL)
{
	contact* store = new contact(ID_VALUE,NAME,MOBILE,EMAIL);
	contact* temp = head;
	if(head == NULL){
		head=store;
		return;
	}
	while(temp->next!=NULL){
	    temp = temp->next;
	}
	temp->next = store;
}


					/***********DISPLAY FUNCTION***********/
void display(contact* head){
	if(head == NULL){
		return;
	}
	cout <<"ID.\t\t" <<"Name\t\t" <<"Phone no\t\t" <<"Email\n";
	contact* temp = head;
	while(temp!=NULL){
		cout <<temp->no <<"\t\t";
			cout <<temp->name <<"\t\t";
			cout <<temp->phone_no <<"\t\t";
			cout <<temp->email <<"\n";
			temp = temp->next;
	}
}

					/***********DELETION FUNCTION***********/

void deletion(contact* &head,int num){
	if(head == NULL){
		return;
	}
	if(head->no == num){                       // deleting head 
		contact* todelete = head;
		head = head->next;
		delete todelete;
	}
	else{                                   // deleting at middle + end
		contact* temp = head; 
		while(temp->next->no!=num){
			temp = temp->next;
		}
		contact* todelete = temp->next;
		temp->next = temp->next->next;
		delete todelete;
	}
}


                    /***********SEARCH FUNCTION***********/       

void search(contact* head){
	if(head == NULL){
		return;
	}
	contact* temp = head;
	int KEY_ID,select_search;
	string KEY_NAME;
	cout << "Select Search:\n\t1)By ID\n\t2)By NAME\n";
	cin >> select_search;
	if(select_search == 1){
		cout << "Enter the ID: ";
		cin >> KEY_ID;                                             
		while(temp!=NULL){
			if(temp->no == KEY_ID){
				cout << "Found\n";
				cout <<"ID" <<"\t\t:\t\t"<<temp->no<<endl;
				cout<<"Name"<<"\t\t:\t\t"<<temp->name<<endl;
				cout<<"Phone"<<"\t\t:\t\t"<<temp->phone_no<<endl;
				cout<<"Email"<<"\t\t:\t\t"<<temp->email<<endl;
			}
			else{
				cout << "Not Found"<<endl;
			}
			temp = temp->next;
		}
	}
	else if(select_search == 2){
		cout << "Enter the Name: ";
		cin >> KEY_NAME;                                            
		while(temp!=NULL){
			if(temp->name == KEY_NAME){
				cout << "Found\n";
				cout <<"ID" <<"\t\t:\t\t"<<temp->no<<endl;
				cout<<"Name"<<"\t\t:\t\t"<<temp->name<<endl;
				cout<<"Phone"<<"\t\t:\t\t"<<temp->phone_no<<endl;
				cout<<"Email"<<"\t\t:\t\t"<<temp->email<<endl;
			}
			else
			{
				cout << "Not Found "<<endl;
			}
			temp = temp->next;
		
	}
}
}

					/***********LENGTH FUNCTION***********/
					
void length(contact* head){
	if(head == NULL){
		return;
	}
	else
	{
		int count = 0;
		contact* temp = head;
		while(temp!=NULL){
			temp = temp->next;
			count++;
		}
		cout << count;
	}
}

					/***********UPDATE FUNCTION***********/

void update(contact* &head,int pos){
	
	contact* temp= head;
	while(temp!=NULL){
		if(temp->no == pos){
			break;
		}
		temp=temp->next;
	}
	
	int ID_Update;
	string NAME_Update,Mobile_Update,EMAIL_Update;
	cout << "Enter you want to update: ";
	int option;
	cin >> option;
	if(option == 1){		
		cout << "Enter the id: ";
		cin >> ID_Update;
		cout << "Enter the name: ";
		cin >> NAME_Update;
		cout << "Enter the phone: ";
		cin >> Mobile_Update;
		cout << "Enter the email: ";
		cin >> EMAIL_Update;
		temp->no = ID_Update;
		temp->name = NAME_Update;
		temp->phone_no = Mobile_Update;
		temp->email = EMAIL_Update;
	}
	else if(option == 2){
		cout << "Enter the id: ";
		cin >> ID_Update;
		temp->no = ID_Update;
	}
	else if(option == 3){
		cout << "Enter the name: ";
		cin >> NAME_Update;
		temp->name = NAME_Update;
	}
	else if(option == 4){
		cout << "Enter the phone: ";
		cin >> Mobile_Update;
		temp->phone_no = Mobile_Update;
	}
	else if(option == 5){
		cout << "Enter the email: ";
		cin >> EMAIL_Update;
		temp->email = EMAIL_Update;
	}
	else{
		cout << "\nError";
	}
}

					/***********SORT FUNCTION***********/

void sort(contact* head){
	contact* First_value = head;
	contact* Second_value;
	while(First_value!=NULL){
		Second_value = First_value->next;
		while(Second_value!=NULL){
			if(First_value->no > Second_value->no){
				//id
				int temp = First_value->no;
				First_value->no = Second_value->no;
				Second_value->no = temp;
				// name
				string temp_name = First_value->name;
				First_value->name = Second_value->name;
				Second_value->name = temp_name;
				//phone no
				string temp_mobile = First_value->phone_no;
				First_value->phone_no = Second_value->phone_no;
				Second_value->phone_no = temp_mobile;
				//email
				string temp_email = First_value->email;
				First_value->email = Second_value->email;
				Second_value->email = temp_email;
				
				
			}
			Second_value = Second_value->next;
		}
		First_value = First_value->next;
	}
}

					/***********INTERFACE FUNCTION***********/
void intro(){
	for(int i=1;i<=120;i++){
		cout << "*";
		if(i==60){
			cout <<endl;
		}
	}
	cout << endl;
	cout << "\t\t\tContact Management System\n";
	for(int i=1;i<=120;i++){
		cout << "*";
		if(i==60){
			cout <<endl;
		}
	}
	cout <<endl;
	cout << "\t\t\t1.Insert Phone No.\n";
	cout << "\t\t\t2.Display\n";
	cout << "\t\t\t3.Deletion\n";
	cout << "\t\t\t4.Seacrh\n";
	cout << "\t\t\t5.Number of Contact\n";
	cout << "\t\t\t6.Update\n";
	cout << "\t\t\t7.Sort the Data (.ID)\n";
	cout << "\t\t\t8.Exit\n";
}

/************************************************************************************
*************************************************************************************
							Main function Part
*************************************************************************************
*************************************************************************************/

int main(){
	// head instance of contact class and Login = 0 for sign in condition
	contact* head = NULL;
	int Login = 0;               
	
	/* This Loop part for design the sign page 
	and use condition for login in system if condition true 
	then login varible value wil increament*/
	
	while(true){
	for(int i=1;i<=120;i++){
		cout << "*";
		if(i==60){
			cout <<endl;
		}
	}
	cout << "\n\t\t\t\tSign in\n";
	for(int i=1;i<=120;i++){
		cout << "*";
		if(i==60){
			cout <<endl;
		}
	}
	cout <<endl;
	string Username;
	string Password;
	cout << "\n\t\tUsername: ";
	cin >> Username;
	cout << "\n\t\tPassword: ";
	cin >> Password;
	if(Username == "contact"){
		if(Password == "1234"){
			Login++;
			break;
		}
		else{
			cout << "Passowrd is wrong\n";
			system("pause");
			system("cls");
		}
	}
	else{
		cout << "Username is wrong\n";
		system("pause");
		system("cls");
	}
}

/*If login is 1 then we login in main part of the system.
this part use switch cases to choose option you want select.
some feature we provide in this project */

	if(Login == 1){
	system("cls");
	while(true){
	intro();                  // intro function
	cout << "Choose:";
	int choose;               // choose variable for selection
	cin >> choose;
	if(choose>=8){
		break;
	}
	// selection part is over here
	
	// Enter in switch statements adter selection
	switch(choose)
	{
		// case 1 is for "INSERTION" 
		case 1:{
			system("cls");
			int range;
			cout << "Enter the nummber of entries do you want: ";
			cin >> range;
			int ID;
			string NAME;
			string MOBILE;
			string EMAIL;
			for(int i=1;i<=range;i++)
			{
			cout << "Enter the ID: ";
			cin >> ID;
			cout << "Enter the Name: ";
			cin >> NAME;
			cout << "Enter the Phone: ";
			cin >> MOBILE;
			cout << "Enter the Email: ";
			cin >> EMAIL;
			traverse(head,ID,NAME,MOBILE,EMAIL);
			cout << endl;
			}
			system("pause");
			system("cls");
			// insertion
			break;
		}
		// Case 2 is for "DISPLAY" the data you insert
		case 2:{
			system("cls");
			display(head);
			system("pause");
			system("cls");
			break;
		}
		// case 3 is for "Deletion" to delete data from system
		case 3:
			{
				system("cls");
				display(head);
				cout <<endl;
				cout << "Enter the ID of contact you want to delete: ";
				int ID_DEL;
				cin >> ID_DEL;
				deletion(head,ID_DEL);
				system("cls");
				break;
			}
		// case 4 is for "SEARCHING" 
		case 4:
			{
				system("cls");
				search(head);
				system("pause");
				system("cls");
				break;
			}
		// CASE 5: is for "HOW MANY CONTACT IN PROGRAM"
		case 5:{
			system("cls");
			cout << "Number of contact in system: ";
			length(head);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		// Case 6 is for "UPDATING" the data
		case 6:{
			system("cls");
			display(head);
			cout << "\nEnter the id you want to update:";
			int Position;
			cin >> Position;
			cout << "\n\t\t1.All\n\t\t2.ID\n\t\t3.Name\n\t\t4.Mobile NO\n\t\t5.Email\n\n";
			update(head,Position);
			system("pause");
			system("cls");
			break;
	}
	// Case 7 is for "Sort" the data
		case 7:{
			sort(head);
			system("cls");
			cout << "Data is sorted.......\n";
			system("pause");
			system("cls");
			break;
		}
	}
}
}
}
	/****************************************************************************
	*****************************************************************************
    	                       END OF PROGRAM
	*****************************************************************************
	****************************************************************************/
