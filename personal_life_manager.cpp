#include<iostream>
#include<vector>
using namespace std;
class task{
	private:
	string title;
	bool completed;
	public:
		task(string t){
			title=t;
			completed=false;
		}
		void updatetask(){
			cout<<"Enter the new title:";
			getline(cin>>ws,title);
			cout<<"The updated title is:"<<title<<endl;
		}
		void markcom(){
			completed=true;
			cout<<"The task "<<title<<" is completed"<<endl;
		}
		void showtask(){
			cout<<title<<"-"<<(completed?"done":"pending")<<endl;
		}
};
class goal{
	private:
	string title;
	string deadline;
	bool done;
	public:
		goal(string t,string d){
			title=t;
			deadline=d;
			done=false;
		}
		void upgoaltitle(){
			cout<<"Enter the new title of goal";
			getline(cin>>ws,title);
			cout<<"Updated title is:"<<title<<endl;
		}
		void upgoaldeadline(){
			cout<<"Enter the new deadline of goal:";
			getline(cin>>ws,deadline);
			cout<<"The updated deadline is:"<<deadline<<endl;
		}
		void markdone(){
			string date;
			cout<<"Enter the date:"; cin>>date;
			char ans;
			cout<<"Have you completed the goal?(Y/N):";
			cin>>ans;
			if(date==deadline&&ans=='Y'){
				done=true;
				cout<<"Goal:"<<title<<" marked done"<<endl;
			}
			else{
				done=false;
			}
		}
		void display(){
			cout<<title<<"_"<<deadline<<"_"<<(done?"done":"Pending")<<endl;
		}
};
class user{
	private:
	string name;
	int age;
	vector<task>tasks;
	vector<goal>goals;
	public:
		
	user(string n,int a){
			name=n;
			age=a;
		}
		int count;
	void menu(){
			int choice;
			int menuchoice;
				int index;
	do{
			cout<<"\n***DETAILS***"<<endl;
			cout<<"1.Add tasks"<<endl;
			cout<<"2.Add goals"<<endl;
			cout<<"3.Exit"<<endl;
			cout<<"Which one do you want to perform? Enter number.";
			cin>>menuchoice;
		if(menuchoice==1){
			cout<<"How many tasks do you want to add?";
			cin>>count;
			cin.ignore();
			cout<<"Enter tasks:"<<endl;
			for(int i=0;i<count;i++){
				string title;
				cout<<i+1<<".";
				getline(cin,title);
				tasks.push_back(task(title));
			}
	do{
		cout<<"\n***TASK MENU***"<<endl;
			cout<<"1.List of tasks"<<endl;
			cout<<"2.Marking a task complete"<<endl;
			cout<<"3.Updating a task"<<endl;
			cout<<"4.Exit"<<endl;
			cout<<"\nChoose a number:";
			cin>>choice;
		if(choice==1){
			cout<<"\n***List of tasks:"<<endl;
			for(int i=0;i<tasks.size();i++){
				cout<<i+1<<".";
				tasks[i].showtask();
		}
}
		else if(choice==2){
			
			cout<<"\nWhich one? Enter the number.:";
			cin>>index;
			if(index>=1&&index<=tasks.size()){
				tasks[index-1].markcom();
			}
			else{
				cout<<"Incorrect number"<<endl;
		 }
	}
		else if(choice==3){	
			cout<<"\nWhich one? Enter number of that task:"; 
					cin>>index;
         	if(index>=1&&index<=tasks.size()){
         		tasks[index-1].updatetask();
			 }
			 else{
			 	cout<<"Incorrrect number."<<endl;
			 }
			 }
			 else if(choice==4){
				cout<<"\nExited task menu"<<endl;
		}
		}while(choice!=4);
	}
	else if(menuchoice==2){
	  	int gchoose;
	  	cout<<"\nHow many goals do you want to add?";
	  	cin>>count;
	  	cin.ignore();
	  	cout<<"Enter goals:"<<endl;
	  	for(int i=0;i<count;i++){
	  		string title,deadline;
	  		cout<<i+1<<":";
	  		cout<<"Title:";
	  		getline(cin,title);
	  		cout<<"Deadline:";
	  		getline(cin,deadline);
	  		goals.push_back(goal(title,deadline));
		  }
		  do{
		  
		  cout<<"\n***Goals Menu***"<<endl;
		  cout<<"1.Display list"<<endl;
		  cout<<"2.Mark a goal done"<<endl;
		  cout<<"3.Update goals"<<endl;
		  cout<<"4.Exit"<<endl;
		  cout<<"\nWhat do you want to do? Choose a number:";
		  cin>>gchoose;
		  if(gchoose==1){
		  	cout<<"\nList of goals:"<<endl;
		  	for(int i=0;i<goals.size();i++){
		  		goals[i].display();
			  }
		  }
		  else if(gchoose==2){
		  	cout<<"\nWhich one? Enter the number:";
		  	cin>>index;
		  	if(index>=1&&index<=goals.size()){
		  		goals[index-1].markdone();
			  }
		  	
		  }
		  else if(gchoose==3){
		  
		  	cout<<"\nWhich one? Enter number:";
		  	cin>>index;
		  	if(index>=1&&index<=goals.size()){ 
		  	
		  	cout<<"1.Update title or any goal."<<endl;
		  	cout<<"2.Update deadline of any goal."<<endl;
		  	cout<<"3.Update both."<<endl;
		  	cout<<"\nNow choose:";
		  	cin>>count;
		  	if(count==1){
		  		goals[index-1].upgoaltitle();
			  }
			  else  if(count==2){
			  	goals[index-1].upgoaldeadline();
			  }
			  else if(count==3){
			  	goals[index-1].upgoaltitle();
			  	goals[index-1].upgoaldeadline();
			  }
			  else{
			  	cout<<"Invalid choice"<<endl;
			  }
		  }
		  else{
		  	cout<<"Invalid choice"<<endl;
		  }
	}
	else if(gchoose==4){
		cout<<"\nExited"<<endl;
	}
}while(gchoose!=4);
}
		else if(menuchoice==3){
		cout<<"\nExited"<<endl;
	}
	}while(menuchoice!=3);
}
};
int main(){
	user u("Ali",23);
	u.menu();
	return 0;
}

