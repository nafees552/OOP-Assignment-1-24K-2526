#include<iostream>
using namespace std;

class Mentor;
class Sport;
class Skill;

class Student
{
	private:
		string studentID;
		string name;
		int age;
		string sportsInterests[5];
		string mentorAssigned;
	public:
		Student(string s, string n, int a, string i[], int size, string m)
		{
			studentID = s;
			name = n;
			age = a;
			for (int j = 0; j < size; j++)
			{
				sportsInterests[j] = i[j];
			}
			mentorAssigned = m;
		}
		void registerForMentorship(Mentor &m);
		void viewMentorDetails()
		{
			cout << "\nThe name of the mentor who is assigned to you is: " << mentorAssigned << endl;
		}
		void updateSportsInterest()
		{
			cout << "\nEnter the number of sports in which you are interested: ";
			int n;
			cin >> n;
			cout << endl << "Enter the sports interests: " << endl;
			for (int j = 0; j < n; j++)
			{
				cin >> sportsInterests[j];
				cout << endl;
			}
		}
};

class Mentor
{
	private:
		int mentorID;
		string name;
		string sportsExpertise[5];
		int maxLearners;
		string assignedLearners[3];
	public:
		Mentor(int m, string n, string s[], int size)
		{
			mentorID = m;
			name = n;
			for (int j = 0; j < size; j++)
			{
				sportsExpertise[j] = s[j];
			}
			maxLearners = 3;
		}
		void assignLearner(Student &s);
		void removeLearner(string learner)
		{
			for (int j = 0; j < maxLearners; j++)
			{
				if (assignedLearners[j] == learner)
				{
					assignedLearners[j] = "";
					cout << "\nLearner successfully removed" << endl;
					return;
				}
			}
		}
		void viewLearners()
		{
			cout << "\nThe assigned learners are: " << endl;
			for (int j = 0; j < maxLearners; j++)
			{
				cout << assignedLearners[j] << endl;
			}
		}
		void provideGuidance()
		{
			cout << "\nA journey of a thousand steps begins with a single step" << endl;
		}
};

class Sport
{
	private:
		int sportID;
		string name;
		string description;
		string requiredSkills[5];
		int max;
	public:
		Sport(int s, string n, string d, string r[], int size)
		{
			sportID = s;
			name = n;
			description = d;
			for (int j = 0; j < size; j++)
			{
				requiredSkills[j] = r[j];
			}
			max = size;
		}
		void addSkill()
		{
			cout << "\nEnter the maximum number of skills: ";
			cin >> max;
			cout << "\nEnter the names of the skills required: " << endl;
			for (int j = 0; j < max; j++)
			{
				cin >> requiredSkills[j];
			}
		}
		void removeSkill(string skill)
		{
			for (int j = 0; j < max; j++)
			{
				if (requiredSkills[j] == skill)
				{
					requiredSkills[j] = "";
					cout << "\nSkill successfully removed" << endl;
					return;
				}
			}
		}
};

class Skill
{
	private:
		int skillID;
		string skillName;
		string description;
	public:
		Skill(int i, string n, string d)
		{
			skillID = i;
			skillName = n;
			description = d;
		}
		void showSkillDetails()
		{
			cout << "\nThe ID of the skill is: " << skillID;
			cout << "\nThe name of the skill is: " << skillName;
			cout << "\nThe description of the skill is: " << description << endl;
		}
		void updateSkillDescription(string newDescription)
		{
			description = newDescription;
			cout << "Description successfully updated";
		}
};

int main()
{
	cout<<"Nafees Uddin 24K-2526"<<endl;
	string sports[] = {"Tennis", "Football"};
	string skills[] = {"Agility", "Speed"};
	
	Student student1("S123", "Saad", 20, sports, 2, "Ali");
	Mentor mentor1(1, "Ali", sports, 2);
	Sport sport1(101, "Tennis", "A game of skill and agility", skills, 2);
	Skill skill1(201, "Agility", "Improves movement speed and reaction time");

	student1.viewMentorDetails();
	mentor1.provideGuidance();
	sport1.addSkill();
	skill1.showSkillDetails();

	return 0;
}
