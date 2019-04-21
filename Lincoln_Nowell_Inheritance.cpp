#include <string>
#include <iostream>
#include <iomanip>


class SportsTeam{

    public:

    std::string Team_Name;
    int total, win, lose, ties;

    std::string str_win, str_total, str_lose, str_ties;

    SportsTeam(){

    }
    
    SportsTeam(std::string name){
        Team_Name = name;
        total = 0;
        win = 0;
        lose = 0;
        ties = 0;
    }

    SportsTeam(std::string name, int total, int wins, int lose, int ties) :
    Team_Name(name), total(total), win(wins), lose(lose), ties(ties){

    }   

    int Games_Won(){
        return (win / total) * 100;
    } 

    std::string get_name(){return Team_Name;}
    int get_total_games_played(){return total;}
    int get_num_wins(){return win;}
    int get_loses(){return lose;}
    int get_ties(){return ties;}

    void playGame(const std::string& Game_Outcome ){
        if(Game_Outcome == "W"){
            win++;
        }
        else if(Game_Outcome == "L"){
            lose++;
        }
        else{
            ties++;
        }

    }

    std::string toString(){

        str_win = std::to_string(win), str_total = std::to_string(total), str_lose = std::to_string(lose)
        , str_ties = std::to_string(ties);

        return Team_Name + " Total games: " + str_total + " Games Won: " + str_win + " Games lost: " 
        + str_lose + " Games tied: " + str_ties; 
    }
};

class Football : public SportsTeam
{
    public:
    
    Football(std::string name){
    Team_Name = name;
    total = 0;
    win = 0;
    lose = 0;
    ties = 0;
    touchdowns = 0;
    interceptions = 0;
    }

    Football(std::string name, int total_games, int wins, int loses, int tie, int TDs, int INTs){
        Team_Name = name; 
        total = total_games; 
        win = wins; 
        lose = loses; 
        ties = tie;
        touchdowns = TDs;
        interceptions = INTs; 
    }

    int touchdowns, interceptions;


    int get_touchdowns(){return touchdowns;}
    int get_interceptions(){return interceptions;}


    std::string toString(){

        std::string str_TDs = std::to_string(touchdowns), str_Ints = std::to_string(interceptions);

        str_win = std::to_string(win), str_total = std::to_string(total), str_lose = std::to_string(lose)
        ,str_ties = std::to_string(ties);

        return Team_Name + " Total games: " + str_total + ", Games Won: " 
        + str_win + ", Games lost: " + str_lose + ", Games tied: " + str_ties + ", " + str_TDs + " Touchdowns, "
        + str_Ints + " Interceptions";
    }
    
};

class BaseBall : public SportsTeam
{
    public:

    double home_runs, RBIs, errors;

    std::string str_home_runs, str_RBIs, str_errors;

    BaseBall(std::string name){
        Team_Name = name;
        total = 0;
        win = 0;
        lose = 0;
        ties = 0;
        home_runs = 0;
        RBIs = 0;
        errors = 0;
    }

    BaseBall(std::string name,int total_games, int wins, int loses, int tie, double home_run, double RBI, double error){
        Team_Name = name; 
        total = total_games; 
        win = wins; 
        lose = loses; 
        ties = ties; 
        home_runs = home_run;
        RBIs = RBI; 
        errors = error;
    }

    double homeRunsPerGame(){return home_runs;}
    double rbisPerGame(){return RBIs;}
    double errorsPerGame(){return errors;}


    std::string toString(){


        str_win = std::to_string(win), str_total = std::to_string(total), str_lose = std::to_string(lose)
        ,str_ties = std::to_string(ties);

        str_home_runs = std::to_string(static_cast<int>(home_runs)), str_RBIs = std::to_string(static_cast<int>(RBIs)), str_errors = std::to_string(static_cast<int>(errors));

        return Team_Name + " Total games: " + str_total + " Games Won: " 
        + str_win + " Games lost: " + str_lose + " Games tied: " + str_ties + ", " + str_home_runs + " Home Runs, " + str_RBIs + " RBI's, " + str_errors + " Errors"; 
    }
    
};

int main()
{
    Football obj1("Lions", 16, 6, 10, 0, 35, 12);
    BaseBall obj2("Tigers", 162, 59,103,0,200,690,126);

    std::cout << obj1.toString() << "\n";
    std::cout << obj2.toString() << "\n";
    
}