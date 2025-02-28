#include <iostream>
#include <string>
using namespace std;

class player_Node {
public:
    string name , team, position;
    int player_Id ,age;
    float salary;
    player_Node *next;
    player_Node(string n, string t , string pos , int id , int playerage , int sal) {
        name = n;
        team = t;
        position = pos;
        player_Id = id;
        age = playerage;
        salary = sal;
        next = NULL;
    }
};

class playerList {
public:
   player_Node *head;
    playerList() {
        head = NULL;
    }

    void add_Player(string n, string t , string pos , int id , int age , int sal) {
        player_Node *newPlayer = new player_Node(n, t, pos, id, age, sal);
        if (head == NULL) {
            head = newPlayer;
            newPlayer->next = NULL;
        }
        else {
          player_Node *temp = head;
          while (temp->next != NULL) {
              temp = temp->next;
          }
            temp->next = newPlayer;
            newPlayer->next = NULL;

        }
    }                      // End Of Adding

    void Remove_Player_byName(string name){
        player_Node *current,*previous;
        current=head;
        previous=head;

        if(head == NULL){cout<<"THE PLAYER IS NOT EXIST"<<endl;} //first::case
        else{
            if(current->name == name){      //second::case
                head=current->next;
                delete(current);
                return ;   }
            while(current->name !=name){    //third::case
                previous=current;
                current=current->next;
            }
            previous->next=current->next;
            delete(current);
        }
        cout<<"THE PLAYER IS REMOVED SUCCSESFULLY"<<endl;
    }

    void Display_Player_Data(string name){
        player_Node *temp = head;
        if(head == NULL){cout<<"THE PLAYER IS NOT EXIST"<<endl;}
        else{
            while( temp != NULL && temp->name != name){
                temp=temp->next;
            }
            if (temp == NULL) {
                cout << "THe player Not FouND\n";
            }else {
                cout<<"player NAME IS :"<<temp->name<<endl;
                cout<<"player ID IS :"<<temp->player_Id<<endl;
                cout<<"player SALARY IS :"<<temp->salary<<endl;
                cout<<"player TEAM IS :"<<temp->team<<endl;
                cout<<"player POSITION IS :"<<temp->position<<endl;
            }
        }
    }

    void Search_For_Player_Name(string name){
        player_Node *temp = head;
        if(head == NULL){cout<<"THE PLAYER IS NOT EXIST"<<endl;}
        else{
            while(temp->name != name){
                temp=temp->next;
            }
            cout<<"YES THE PLAYER : \""<<temp->name<<"\" IS IN THIS TEAM :: "<<temp->team<<endl;
        }
    }

    void update_team_info(string playername,string newteam) {
        if (head == NULL) {
            cout << "the list is empty ! \n";
        }

        player_Node *temp = head;
        while (temp != NULL && temp->name != playername) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Player Not found "<< endl;
        }else {
            cout << " Team updated succesfuly from " << temp->team << " to ("<< newteam <<")" << endl;
            temp->team = newteam;
        }
    }


};

//=================================
class teamNode {
public:
    string team_Name;
    string team_Presedent;
    int team_Id;
    teamNode* next;
    teamNode(string tname ,string tpres, int tid ){
        team_Name = tname;
        team_Presedent = tpres;
        team_Id = tid;

    }
};
    //team list and Functions
class teamList {
public:
    teamNode* head;
    teamList() {
        head = NULL;
    }

    //Add new team.
    void add(string tname, string tPres , int teamId) {
        if (head == NULL) {
            teamNode *newteam = new teamNode(tname, tPres, teamId);
            head = newteam;
            newteam->next = NULL;
        }else {
            teamNode *newteam = new teamNode(tname, tPres, teamId);
            teamNode *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newteam;
            newteam->next = NULL;
        }
    }

    // Display team
    void displayTeam(int teamid) {

        teamNode *temp = head;
        while (temp != NULL && temp->team_Id != teamid) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Team not found !!\n";
        }else {
            cout << "Team Id : " << temp->team_Id <<"\n";
            cout << "Team Name : " << temp->team_Name <<"\n";
            cout << "Team presedent : " << temp->team_Presedent <<"\n";
        }
    }

    // Search for team by ID
    void search_Team(int teamId) {
        teamNode* temp = head;
        while (temp != NULL) {
            if(temp->team_Id == teamId) {
                cout << "Team is Found :" << endl;
                cout << "Team Id : " << temp->team_Id <<"\n";
                cout << "Team Name : " << temp->team_Name <<"\n";
                cout << "Team presedent : " << temp->team_Presedent <<"\n";
                return;
            }
            temp = temp->next;
        }
        cout << "TEAM not found !" << endl;
    }

    //End of team list
};


int main() {

    playerList players;
    teamList teams;

    int choice;

    cout << "\n\t\t\t\t == Egyptian League Management System == \n" << endl;

    do {

        cout << "1.Add New Team" << endl;
        cout << "2.Display Team" << endl;
        cout << "3.Search for Team by ID" << endl;
        cout << "4.Add new player" << endl;
        cout << "5.Delete a Player" << endl;
        cout << "6.Display Player info" << endl;
        cout << "7.Search for Player by Name" << endl;
        cout << "8.Update Player Team " << endl;
        cout << "9.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string teamName, president;
            int teamId;
            cout << "Enter Team Name: ";
            cin.ignore();
            getline(cin, teamName);
            cout << "Enter Team President: ";
            getline(cin, president);
            cout << "Enter Team ID: ";
            cin >> teamId;
            teams.add(teamName, president, teamId); //Add team
            cout << "Team added successfully!" << endl;
            break;
        }
        case 2: {
            int teamId;
            cout << "Enter Team ID to Display: ";
            cin >> teamId;
            teams.displayTeam(teamId); // Display team
            break;
        }
        case 3: {
            int teamId;
            cout << "Enter Team ID to Search: ";
            cin >> teamId;
            teams.search_Team(teamId); // Search team by ID
            break;
        }
        case 4: {
            string playerName, team, position;
            int playerId, age;
            float salary;
            cout << "Enter Player Name: ";
            cin.ignore();
            getline(cin, playerName);
            cout << "Enter Player Team: ";
            getline(cin, team);
            cout << "Enter Player Position: ";
            getline(cin, position);
            cout << "Enter Player ID: ";
            cin >> playerId;
            cout << "Enter Player Age: ";
            cin >> age;
            cout << "Enter Player Salary: ";
            cin >> salary;
            players.add_Player(playerName, team, position, playerId, age, salary); // Add player function
            cout << "Player added successfully!" << endl;
            break;
        }
        case 5: {
            string playerName;
            cout << "Enter Player Name to Remove: ";
            cin.ignore();
            getline(cin, playerName);
            players.Remove_Player_byName(playerName); // Remove player function
            break;
        }
        case 6: {
            string playerName;
            cout << "Enter Player Name to Display: ";
            cin.ignore();
            getline(cin, playerName);
            players.Display_Player_Data(playerName); // Display player data function
            break;
        }
        case 7: {
            string playerName;
            cout << "Enter Player Name to Search: ";
            cin.ignore();
            getline(cin, playerName);
            players.Search_For_Player_Name(playerName); // Search player by name function
            break;
        }
        case 8: {
            string playerName, newTeam;
            cout << "Enter Player Name to Update Team: ";
            cin.ignore();
            getline(cin, playerName);
            cout << "Enter New Team Name: ";
            getline(cin, newTeam);
            players.update_team_info(playerName, newTeam); // Update player team function
            break;
        }
        case 9:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}


