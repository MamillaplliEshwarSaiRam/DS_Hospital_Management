//Hospital managmenet, diagnosis , health tips suggestor and medication
#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#define SIZE 100
int top=-1,front=-1,rear=-1;
char s[100][100],q[100][100];
class patient
{
	char name[30],gender[5],blood[10],phone[20];
	int age,weight,bmi,tiredness,chest_pain,freq_thirst;
	float height;
	int freq_hunger,freq_urine,weight_loss,blur_vision,sweatness;
	int alchohol,exercise,junk,smoking;
	int severity_obesity,severity_type1,severity_type2,severity_heart;
	public:
		patient()
		{
			int ct=0;
			cout<<"Enter name\n";
			cin>>name;
			strcpy(s[++top],name);
			if(front==-1&&rear==-1)
			{
				front=0;
				rear=0;
				strcpy(q[rear],name);
			}
			else
				strcpy(q[++rear],name);
			cout<<"Enter gender(M/F)\n";
			cin>>gender;
			cout<<"Enter blood group\n";
			cin>>blood;
			cout<<"Enter age\n";
			cin>>age;
			cout<<"Enter weight(in kgs)\n";
			cin>>weight;
			cout<<"Enter height(in metres)\n";
			cin>>height;
			bmi=(weight)/(height*height);
			cout<<"Enter phone number\n";
			cin>>phone;
			while(strlen(phone)!=10)
			{
				if(ct!=0)
					cout<<"Invalid phone no.\nEnter again\n";
				cin>>phone;
				ct++;
			}
			store();
		}
		patient(char t)
		{
		}
		void store()
		{
			ofstream fout;
			fout.open("storage.dat",ios::app|ios::binary);
			fout.write((char*)this,sizeof(*this));
			fout.close();
		}
		void sdisplay()
		{
			int i;
			if(top==-1)
				cout<<"Stack is empty\n";
			else
			{
				cout<<"Patients names in stack order are\n";
				for(i=top;i>=0;i--)
					cout<<s[i]<<endl;
			}
		}
		void qdisplay()
		{
			int i;
			if(front==-1)
				cout<<"Queue is mepty\n";
			else
			{
				cout<<"Patients in queue order\n";
				for(i=front;i<=rear;i++)
					cout<<q[i]<<endl;
			}
		}
		void showall()
		{
			sdisplay();
			qdisplay();
		}
		void symptom()
		{
			cout<<"For the below symptos give range from 0 to 5\n";
			cout<<"Frequency of hunger\n";
			cin>>freq_hunger;
			cout<<"Frequency of thirst\n";
			cin>>freq_thirst;
			cout<<"Frequncy of urination\n";
			cin>>freq_urine;
			cout<<"Blurred vison\n";
			cin>>blur_vision;
			cout<<"Rapid weight loss without workout or dieting\n";
			cin>>weight_loss;
			cout<<"Tiredness\n";
			cin>>tiredness;
			cout<<"Chest pain\n";
			cin>>chest_pain;
			cout<<"Sweatness\n";
			cin>>sweatness;
			cout<<"Lack of proper exercise\n";
			cin>>exercise;
			cout<<"Junk food\n";
			cin>>junk;
			cout<<"Freqeuncy of smoking\n";
			cin>>smoking;
			cout<"Last required detail\n";
			cout<<"Alochol intake\n";
			cin>>alchohol;
		}
		void act()
		{
			predictor();
			getch();
			tips();
			getch();
			medication();
			getch();
		}
		void predictor()
		{
			severity_obesity=obesity();
			severity_type1=type1_diabetes();
			severity_type2=type2_diabetes();
			severity_heart=heart_disease();
			cout<<"Obesity severity: "<<severity_obesity<<endl;
			cout<<"Type1 diabetes severity: "<<severity_type1<<endl;
			cout<<"Type2 diabetes severity: "<<severity_type2<<endl;
			cout<<"Heart disease severity: "<<severity_heart<<endl;
		}
		int type1_diabetes()
		{
			int sev=0;
			if(tiredness>3)
				sev+=16;
			if(freq_urine>3)
				sev+=16;
			if(freq_thirst>3)
				sev+=16;
			if(freq_hunger>3)
				sev+=16;
			if(blur_vision>3)
				sev+=16;
			if(weight_loss>3)
				sev+=16;
			return sev;
		}
		int type2_diabetes()
		{
			int sev=0;
			if(bmi<30)
				return 0;
			else
			{
				if(bmi>=30)
					sev+=14;
				if(tiredness>3)
					sev+=14;
				if(freq_urine>3)
					sev+=14;
				if(freq_thirst>3)
					sev+=14;
				if(freq_hunger>3)
					sev+=14;
				if(blur_vision>3)
					sev+=14;
				if(weight_loss>3)
					sev+=14;
				return sev;
			}
		}
		int heart_disease()
		{
			int sev=0;
			if(chest_pain>3)
				sev+=33;
			if(sweatness>3)
				sev+=33;
			if(tiredness>3)
				sev+=33;

			return sev;
		}
		int obesity()
		{
			 if(bmi<18)
			 {
				cout<<"Under weight\n";
				return 100;
			 }
			 else if(bmi<25)
			 {
				cout<<"Normal weight\n";
				return 0;
			 }
			 else if(bmi<30)
			 {
				cout<<"Overweight\n";
				return  (50+(((bmi-25)/5)*10));
			 }
			 else
			 {
				cout<<"Obese\n";
				return 100;
			 }
		}
		void tips()
		{
			cout<<"Health tips\n";
			if(exercise>0)
				cout<<"Exercise for atleast 1.5 hrs daily\n";
			if(junk>0)
				cout<<"Avoid eating junk foods at all costs\n";
			if(smoking>0)
				cout<<"Avoid smoking at all costs\n";
			if(severity_heart>0||severity_type1>0||severity_type2>0)
			{
				cout<<"Meditate for .5 hr daily\n";
				cout<<"Focus on the following food groups\n";
				cout<<"1.Vegetables\n2.Whoel grains\n3.Fruits\n";
				cout<<"4.Fat_free dairy products\n";
				cout<<"5.Lean protein sources such as chicken, fish and lean beef\n";
			}
			if(alchohol>0)
				cout<<"Don't drink alchohol\n";
		}
		void medication()
		{
			if(severity_type1>0)
			{
				cout<<"Type 1 diabetes basic medication\n";
				cout<<"Metformin\nPramlintide\n";
			}
			if(severity_type2>0)
			{
				cout<<"Type 2 diabetes basic medication\n";
				cout<<"Metformin\nSulfonylureas\n";
			}
			if(severity_heart>0)
			{
				cout<<"Heart disease basic medication\n";
				cout<<"Anti-clotting: Asprin\n";
				cout<<"Antiplatent: Clopidogrel\n";
				cout<<"Anticoagulant: Warfarin\n";
				cout<<"Blood pressure: ACE inhibitors\n";
				cout<<"Cholestrol: Statin\n";
				cout<<"Anti anginal: Nitrate\n";
			}
			if(severity_obesity>0)
			{
				cout<<"Obesity basic medicayion\n";
				cout<<"Avoid junk food\n";
				cout<<"Cut back on calories\n";
				cout<<"Belviq\nContrave\n";
			}
		}
		void show()
		{
			cout<<"Name:"<<name<<endl;
			cout<<"Gender:"<<gender<<endl;
			cout<<"Age:"<<age<<endl;
			cout<<"Blood group:"<<blood<<endl;
			cout<<"Previous diesease severities\n";
			cout<<"Obesity: "<<severity_obesity<<endl;
			cout<<"Type 1 diabetes: "<<severity_type1<<endl;
			cout<<"Type 2 diabetes: "<<severity_type2<<endl;
			cout<<"Heart disease: "<<severity_heart<<endl;
		}
		void search(char *n,char *p)
		{
			int ct=0;
			ifstream fin;
			fin.open("storage.dat",ios::in|ios::binary);
			if(!fin)
				cout<<"File not found\n";
			else
			{
				fin.read((char*)this,sizeof(*this));
				while(!fin.eof())
				{
					if(strcmp(name,n)==0&&strcmp(phone,p)==0)
					{
						show();
						symptom();
						act();
						ct++;
						break;
					}
					fin.read((char*)this,sizeof(*this));
				}
				fin.close();
				if(ct==0)
					cout<<"Not found\n";
			}
		}
		void delete_record(char *n,char *p)
		{
			int ct=0;
			ifstream fin;
			ofstream fout;
			fin.open("storage.dat",ios::in|ios::binary);
			if(!fin)
				cout<<"File not found\n";
			else
			{
				fout.open("tempfile.dat",ios::out|ios::binary);
				fin.read((char*)this,sizeof(*this));
				while(!fin.eof())
				{
					if(strcmp(name,n)==0&&strcmp(phone,p)==0)
					{
						cout<<"Found and deleted\n";
						ct++;
					}
					else
						fout.write((char*)this,sizeof(*this));
					fin.read((char*)this,sizeof(*this));
				}
				fin.close();
				fout.close();
				remove("storage.dat");
				rename("tempfile.dat","storage.dat");
				if(ct==0)
					cout<<"Not found\n";
			}
		}
};
int main()
{
	int ch=0;
	char name[30],phone[20];
	clrscr();
	patient test('t');
	while(ch!=4)
	{
		cout<<"1.New patient\n2.Old patient\n3.Delete patient info\n";
		cout<<"4.Exit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				patient obj;
				obj.symptom();
				obj.act();
				break;
			case 2:
				cout<<"Enter name and phone no.\n";
				cin>>name>>phone;
				test.search(name,phone);
				break;
			case 3:
				cout<<"Enter name and phone no. for deletion\n";
				cin>>name>>phone;
				test.delete_record(name,phone);
				break;
			case 4:
				cout<<"Exiting\n";
				break;
			default:
				cout<<"Invalid choice\n";

		}
	}
	test.showall();
	getch();
	return 0;
}