#include <iostream>
#include <queue>
#include <string>
using namespace std;

class HospitalP_queue{
	private:
		struct patient{
			string name;
			int priority;
			
			patient(string n,int p): name(n),priority(p){}
			
			bool operator<(const patient& other)const{
				return priority>other.priority;	
			}
		};
		priority_queue<patient> patients;
		
		public:
			void addpatient(const string& name, int priority){
				patients.push(patient(name,priority));
			}
			
			string serveNextPatient(){
				if(!patients.empty()){
					string nextPatient=patients.top().name;
					patients.pop();
					return nextPatient;
				}
				else{
					return "No patients in the queue";
				}
			}
};

int main(){
	HospitalP_queue hosp_q;
	char ch;
	do{
		string name;
		int priority;
		cout<<"enter patient's name:";
		cin>>name;
		cout<<"enter patient's health condition(1:serious , 2:non-serious , 3.general cheackup):";
		cin>>priority;
		hosp_q.addpatient(name,priority);
		cout<<"do you want to add another patient?(y/n):";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	
	cout<<"Patient served in order :";
	string nextPatient=hosp_q.serveNextPatient();
	while(nextPatient!="No patients in the queue"){
		cout<<nextPatient<<endl;
		nextPatient=hosp_q.serveNextPatient();
	}
	return 0;
}
