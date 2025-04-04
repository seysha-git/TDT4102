#include <exercises.h>
#include <random>
#include <cctype>
#include <iostream>
void task2(){
    std::string name;
    std::cout << "Write your name: ";
    std::cin >> name;

    for(int i = 0; i < name.size(); i++){
        std::cout << (i+1) << ": " << name.at(i) << "\n";
    }
}

void task3(){
    vector<double> temps;
    for(double temp; cin >> temp;){
        temps.push_back(temp);
    }
    ranges::sort(temps);
    if(temps.size() % 2 == 0){//Partall
        std::cout << (temps[temps.size()/2] + temps[temps.size()/2-1])/2;
    }else{
        std::cout << temps[(temps.size())/2];
    }
}

void task4(){
    std::vector<double>city_dist;
    for(double dist; std::cin >> dist;){
        city_dist.push_back(dist);
    }
    //Sum of all distances
    double sum = 0;
    double min_dist, largest_dist = city_dist.at(0);
    for(int i = 0; i < city_dist.size(); i++){
        sum += city_dist.at(i);
        if(city_dist.at(i) < min_dist){
            min_dist = city_dist.at(i);
        }
        else if(city_dist.at(i) > largest_dist){
            largest_dist = city_dist.at(i);
        }
    }

    std::cout << "Sum of all distances: " << sum << '\n';
    std::cout << "Smallest distance: " << min_dist << '\n'
    << "Largest distance: " << largest_dist << '\n' <<
    "Mean distance: " << sum/city_dist.size(); 
}

void task5(){
    int guessing_number = 20;
    int upper = 100;
    int lower = 0;
    char g, won;
    int attempts = 0;
    int guess_number;
    while(attempts < 7){
        guess_number = (upper+lower)/2;
        std::cout << '\n' << "Is " << guess_number << " the correct number(Y or N): ";
        cin >> won;
        if(won == 'Y'){
            std::cout << "Yay." << guess_number << " was correct"; 
            break;
        }
        std::cout << '\n' << "Question: " << (attempts+1) << ". Is the number you are thinking of less than " << guess_number << "(Y or N)?: ";
        cin >> g;
        if(g == 'Y'){
            upper = guess_number;
        }
        else if(g == 'N'){
            lower = guess_number;
        }
        attempts += 1;
    }
}
  
void task6(){
    std::vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string input;
    std::cout << "Enter a digit (0-9) or its spelled out form: " << '\n';
    while(std::cin >> input){
        if(isdigit(input[0]) && input.size() == 1){
            int index = input[0] - '0';
            std::cout << numbers.at(index) << '\n';
        }
        else{
            for(int i = 0; i < numbers.size(); i++){
                if(numbers.at(i) == input){
                    std::cout << i << '\n';
                }
            }
        }
    }
}

void check_rps_winner(int player1, int machine, std::vector<string> choices){
    std::cout << "Machine: " << choices.at(machine) << '\n';
    std::cout << "Player1: " << choices.at(player1) << '\n';
    if(player1 == machine){
        std::cout << "Tie" << '\n';
    }
    else if( (player1 == 0 && machine == 1) ||
            (player1 == 1 && machine == 0) ||
            (player1 == 2 && machine == 1)
        ){
        std::cout << "Your won";
    }
    else if( (machine == 0 && player1 == 1) ||
            (machine == 1 && player1 == 0) ||
            (machine == 2 && player1 == 1)
        ){
        std::cout << "Machine won";
    }
    else{
        std::cout << "Nothing happened";
    }

}

void rock_paper_scissors(){
    //Game settings
    std::vector<string> choices = {"rock", "paper", "sciccors"};
    //Player settings
    int player_index;
    std::string player_choice;
    //Machine settings
    int machine_index;
    random_device rd;
    default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0, choices.size() - 1);
    //Game loop



    std::cout << "Rock, paper, sciccors?: ";
    cin >> player_choice;
    for(int i = 0; i < choices.size(); i++){
        if(player_choice == choices.at(i)){
            player_index = i;
        }
    }
    for(int i = 0; i < player_choice.size(); i++){
        player_choice.at(i) = tolower(player_choice.at(i));
    }
    machine_index = distribution(generator);
    std::cout << "Machine choice: " << choices.at(machine_index) << "\n" <<
    "Winner is ....";
    switch (player_index)
    {
    case 0:
        switch (machine_index)
        {
        case 0:
            std::cout << "Tie";
            break;
        case 1:
            std::cout << "Machine won";
            break;
        case 2:
            std::cout << "Player won";
            break;
        
        default:
            break;
        }
        break;
    case 1:
        switch (machine_index)
        {
        case 0:
            std::cout << "Player won";
            break;
        case 1:
            std::cout << "Tie";
            break;
        case 2:
            std::cout << "Machine won";
            break;
        
        default:
            break;
        }
        break;
    case 2:
        switch (machine_index)
        {
        case 0:
            std::cout << "Machine won";
            break;
        case 1:
            std::cout << "Player won";
            break;
        case 2:
            std::cout << "Tie";
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }

    

}


void find_prime(int lower, int upper){
    int n = lower + upper;
    std::vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false; //0 and 1 are not primes
    for(int i = 2; i <= n; i++){
        if(is_prime[i] && (long long)i*i <= n){ //(long long) to prevent overflow errors
            for(int j = i*i; j < n; j+=i){
                is_prime[j] = false;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(is_prime[i]){
            std::cout << "Prime number: " << i << '\n';
        }
    }
}


void name_value_pair(){
    std::vector<string> names;
    std::vector<int> ages;
    std::string name;
    std::string search_name;
    int age;
    bool valid = true;
    bool not_found = false;
    int n = 0;
    while(true){
        std::cout << '\n' << "Enter name and age: ";
        std::cin >> name >> age;
        if(name == "NoName" && age==0){
            break;
        }
        for(std::string nn: names){
            if(name == nn){
                std::cout << "Same name entered twice" << '\n';
                valid = false;
            }
        }
        if(valid){
            names.push_back(name);
            ages.push_back(age);
            n += 1;
        }
                
    }
    while(true){
        std::cout << '\n' << "Enter a name in the list: ";
        std::cin >> search_name;
        for(int i = 0; i < n; i++){
            if(names.at(i) == search_name){
                std::cout << '\n' << "Found name: " << search_name << " at index " << (i+1);
                not_found = false;
            }
        }
        if(not_found){
            std::cout << '\n' << "Name not found";
        }
    }
    
    

}
