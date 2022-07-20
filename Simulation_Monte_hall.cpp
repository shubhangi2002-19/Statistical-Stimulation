#include <bits/stdc++.h>
using namespace std;

string sp=" ";
#define all(x) x.begin(),x.end()
#define Time cout <<"\nTime : "<<1000*clock()/CLOCKS_PER_SEC<<"ms\n";

int Random(int a, int b) {
    return a + rand() % (b - a + 1);
}

int Rounds = 50; 

vector<int> Wins_with_no_switch(Rounds+1, 0);
vector<int> Wins_with_switching(Rounds+1, 0);

int Wins_no_switch = 0;
int Wins_by_switch = 0;

void Simulate(){
    for(int Process = 1; Process<=Rounds; Process += 1){

        // Basically the gameshow has 3 doors
        set<int> Doors = {1,2,3};

        // Door with the prize will be chosen randomly
        int Door_with_Prize = Random(1,3);

        // Door, which the user Chooses will also be chosen randomly
        int Door_chosen = Random(1,3);

        // Now, we have to choose a door which is closed
        // Host will not open a door which has Prize in it
        int Door_Chosen_by_Host = Random(1,3);

        // choosing the door with no prize and different from the user.
        while(Door_Chosen_by_Host==Door_chosen || Door_Chosen_by_Host==Door_with_Prize){
            Door_Chosen_by_Host = Random(1,3);
        }

        // Now we will check if the user wins or not
        if( Door_chosen == Door_with_Prize ){
            Wins_with_no_switch[Process] += 1;
            Wins_no_switch += 1;
        }

        // If the user chooses to switch then 
        Door_chosen = 6 - (Door_chosen + Door_Chosen_by_Host);

        if( Door_chosen == Door_with_Prize ){
            Wins_by_switch += 1;
            Wins_with_switching[Process] += 1;
        }
    }

    //  Statistics

    long double Prob_with_no_switching = (Wins_no_switch*1.0)/Rounds;
    long double Prob_with____switching = (Wins_by_switch*1.0)/Rounds;

    cout << "Prob_with____switching = " << Prob_with____switching << endl;
    cout << "Prob_with_no_switching = " << Prob_with_no_switching << endl;
}

int32_t main(){
    srand(01);
    cout<<fixed<<setprecision(25);
    Simulate();
    Time;
    return 0;
}
