#include "headers.cpp"
#include "structures.cpp"
#include "file_handler.cpp"

using namespace std;

// Data Structures for Logging & Computing physical activities
enum Physical_Activities
{
    LIGHT_WALKING = 1,
    MODERATE_WALKING,
    JOGGING,
    LIGHT_CYCLING,
    NORMAL_CYCLING,
    MODERATE_CYCLING,
    ROPE_JUMPING,
    WEIGHT_TRAINING,
    LIGHT_CALISTHENICS,
    MODERATE_CALISTHENICS,
    VIGOROUS_CALISTHENICS
};

enum Physical_Fitness_Level
{
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED
};

enum Physical_Fitness_Goal
{
    CARDIO = 1,
    STRENGTH,
    ENDURANCE
};

const map<Physical_Activities, float> MET_value = 
{
    {LIGHT_WALKING, 2.60},
    {MODERATE_WALKING, 3.30},
    {JOGGING, 7.00},
    {LIGHT_CYCLING, 5.30},
    {NORMAL_CYCLING, 4.00},
    {MODERATE_CYCLING, 5.50},
    {ROPE_JUMPING, 10.00},
    {WEIGHT_TRAINING, 3.50},
    {LIGHT_CALISTHENICS, 3.50},
    {MODERATE_CALISTHENICS, 3.80},
    {VIGOROUS_CALISTHENICS, 8.00}
};

const map<Physical_Fitness_Level, vector<Exercise>> Cardio_Exercises = 
{
  {
    BEGINNER,
    {
        //Exercise Name, Description, Sets / Repetitions
        {"Walking", "10 - 35 minutes"},
        {"Jogging in Place", "10 - 35 minutes"},
        {"Jumping Jacks", "10 - 35 minutes"},
        {"Jump Rope", "10 - 35 minutes"}
    }
  },
  {
    INTERMEDIATE,
    {
        {"Jogging", "15 - 30 minutes"},
        {"Jump Rope", "15 - 30 minutes"},
        {"Lunge Jumps", "15 - 30 minutes"}
    }
  },
  {
    ADVANCED,
    {
        {"Jogging", "30 - 45 - minutes"},
        {"Battle Ropes", "1 minute, 3 sets"},
        {"Sprints", "30 seconds, 2 sets, 1 minute rest after each set"}
    }
  }
};

const map<Physical_Fitness_Level, vector<Exercise>> Endurance_Exercises = 
{
  {
    BEGINNER,
    {
        //Exercise Name, Description, Sets / Repetitions
        {"Squats", "2 sets of 25, 1 minute rest after each set"},
        {"Calf/Heel Raise", "2 sets of 25, 1 minute rest after each set"},
        {"Planks", "3 sets of 15 - 30 second holds, 1 minute rest after each set"}
    }
  },
  {
    INTERMEDIATE,
    {
        {"Squats", "2 sets of 30, 1 minute rest after each set"},
        {"Calf/Heel Raise", "2 sets of 50, 1 minute rest after each set"},
        {"Planks", "3 sets of 30 secons - 1 minute holds, 1 minute rest after each set"}
    }
  },
  {
    ADVANCED,
    {
        {"Squats", "2 sets of 50, 1 minute rest after each set"},
        {"Calf/Heel Raise", "2 sets of 100, 1 minute rest after each set"},
        {"Planks", "3 sets of 1 - 1.5 minute holds, 1 minute rest after each set"}
    }
  }
};

const map<Physical_Fitness_Level, vector<Exercise>> Strength_Exercises = 
{
  {
    BEGINNER,
    {
        //Exercise Name, Description, Sets / Repetitions
        {"Knee Push Ups", "2 sets of 10, 1 minute rest after each set"},
        {"Bodyweight Squats", "2 sets of 25, 1 minute rest after each set"},
        {"Negative Pullups", "3 sets of 5, 1 minute rest after each set"}
    }
  },
  {
    INTERMEDIATE,
    {
        {"Standard Push Ups", "3 sets of 10, 1 minute rest after each set"},
        {"Squats with Resistance Bands", "3 sets of 30, 1 minute rest after each set"},
        {"Resistance Bands Assisted Pullups", "3 sets of 10, 1 minute rest after each set"}
    }
  },
  {
    ADVANCED,
    {
        {"Decline Push Ups", "3 sets of 12, 1 minute rest after each set"},
        {"Weighted Squats", "2 sets of 35, 1 minute rest after each set"},
        {"Pullups", "2 sets of 10, 1 minute rest after each set"}
    }
  }
};




// Declare Global Variable:
User user;


// Prototypes
void display_main_menu();
void update_user_info_process();
void display_user_status(const User &user);
void display_activity(const Physical_Activity &physical_activity);
void suggest_exercise(Physical_Fitness_Level physical_level, Physical_Fitness_Goal physical_goal);

bool log_physical_activity(Physical_Activity *container);
float calculate_BMI_score(float height, float weight);
string classify_BMI(float BMI_score);

int main()
{
    int choice;

    while (true)
    {   
        display_main_menu();

        cout << "\nSelection: ";
        cin >> choice;

        if (choice == 5)
        {   
            cout << "\n-------------------Thank you for using FitNest-------------------\n";
            break;
        }else if (choice == 4) // Suggest Excersise
        {
            int level, goal;
            Physical_Fitness_Goal enum_goal;
            Physical_Fitness_Level enum_level;
            cout << "Let's find an exercise just for you...\n";

            // Get physical activity goal
            cout << "What is your physical activity goal?\n";
            cout << "[1] - Cardiovascual Health\n";
            cout << "[2] - Strength\n";
            cout << "[3] - Endurance\n";

            cout << "Selection: ";
            cin >> goal;

            while(goal < 1 || goal > 3)
            {
                cout << "Enter from the give choices...\nSelection: ";
                cin >> goal;
            }

            if (goal == 1) enum_goal = CARDIO;
            else if (goal == 2) enum_goal = STRENGTH;
            else enum_goal = ENDURANCE;

            // Get Physical Fitness Level
            cout << "What is your physical fitness level?\n";
            cout << "[1] - Beginner\n";
            cout << "[2] - Intermediate\n";
            cout << "[3] - Advanced\n";

            cout << "Selection: ";
            cin >> level;

            while(level < 1 || level > 3)
            {
                cout << "Enter from the give choices...\nSelection: ";
                cin >> level;
            }

            if (level == 1) enum_level = BEGINNER;
            else if (level== 2) enum_level = INTERMEDIATE;
            else enum_level = ADVANCED;

            suggest_exercise(enum_level, enum_goal);

        }else if (choice == 3) // Generate Status Report
        {
            int report_choice;

            cout << "What report do you want?\n";
            cout << "[1] - User Status.\n";
            cout << "[2] - Physical Activity Log\n";
            cout << "Selection: ";

            cin >> report_choice;

            while(report_choice <= 0 || report_choice > 2)
            {
                cout << "Please select from the options... Selection: ";
                cin >> report_choice;
            }

            if (report_choice == 1) // Display User data
            {
                display_user_status(user);
            }else
            {
                vector<Physical_Activity> *temp_container = new vector<Physical_Activity>;

                extract_activities(ACTIVITY_PATH, temp_container);

                for (Physical_Activity activity : *temp_container)
                {
                    display_activity( activity );
                }

                delete temp_container;
            }

            char return_choice;

            do
            {
                cout << "Return to Menu [Y]? ";
                cin  >> return_choice;
            } while (return_choice != 'Y' && return_choice != 'y');

        }else if (choice == 2)
        {
            Physical_Activity *temp_activity = new Physical_Activity;

            if (log_physical_activity ( temp_activity ) )
            {
                update_activities(ACTIVITY_PATH, *temp_activity);
            }

            delete temp_activity;
        }else if (choice == 1)
        {
            update_user_info_process();
        }else
        {
            cout << "Pleases select a valid option from the menu.";
        }

        Sleep(2000); // Wait for 2 seconds

        system("cls"); // Clear screen
    }
    return 0;
}

void display_main_menu()
{
    // Display Title
    cout << "\n----------FitNest: A Health & Fitness Tracking Software----------\n\n";

    // Show available options
    cout << "What would you like to do?\n";
    cout << "[1] - Update User Information.\n";
    cout << "[2] - Log Physical Activity.\n";
    cout << "[3] - Generate Status Report.\n";
    cout << "[4] - Suggest Exercise.\n";
    cout << "[5] - Quit.\n";
}

void update_user_info_process()
{
    // Ask for the user's infromation
    cout << "Update your user information...\n\n";

    User temp_user;
    char choice;

    cout << "Enter new username: ";
    cin.ignore();
    getline(cin, temp_user.name);

    cout << "Enter updated age: ";
    cin >> temp_user.age;

    cout << "Enter updated height: ";
    cin >> temp_user.height;

    cout << "Enter updated weight: ";
    cin >> temp_user.weight;


    cout << "\n---Updated User Information---\n";
    cout << "Updated Name: " << temp_user.name << "\n";
    cout << "Updated Age: "<< temp_user.age << "\n";
    cout << "Updated Height: "<< temp_user.height << "\n";
    cout << "Updated Weight: "<< temp_user.weight << "\n";

    cout << "Confirm update [Y/N]? ";
    cin >> choice;

    while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
    {
        cout << "Invalid choice...\nConfirm update [Y/N]? ";
        cin >> choice;
    }

    if (choice == 'y' || choice == 'Y')
    {
        user = temp_user;
        cout << "User information has been updated.\n";
        return;
    }else return;

}

bool log_physical_activity(Physical_Activity *container)
{   
    cout << "\nLog new physical activity...\n";
    
    // Display Log Menu
    cout << "\nWhat activity did you do?...\n";

    cout << "----Cardio Exercises----\n";
    cout << "[1]  - Light Walking\n";
    cout << "[2]  - Moderate Walking\n";
    cout << "[3]  - Jogging\n";
    cout << "[4]  - Light Cycling\n";
    cout << "[5]  - Normal Cycling\n";
    cout << "[6]  - Moderate Cycling\n";
    cout << "[7]  - Rope Jumping\n";

    cout << "\n----Muscle Training----\n";
    cout << "[8]  - Weight Training\n";
    cout << "[9]  - Light Calisthenics\n";
    cout << "[10] - Moderate Calisthenics\n";
    cout << "[11] - Vigorous Calisthenics\n\n";

    int selection;
    string activity_name = "";
    float time, calories_burned, MET = -1;

    do{
        cout << "Selection: ";
        cin >> selection;
    } while(0 >= selection && selection > 11);


    cout << "How long did you do it (minutes)? ";
    cin >> time;

    switch ( selection )
    {
        case LIGHT_WALKING:
            MET = MET_value.at(LIGHT_WALKING);
            activity_name = "Light Walking";
            break;
        case MODERATE_WALKING:
            cout << "Moderate Walking\n";
            MET = MET_value.at(MODERATE_WALKING);
            activity_name = "Moderate Walking";
            break;
        case JOGGING:
            cout << "Jogging\n";
            MET = MET_value.at(JOGGING);
            activity_name = "Jogging";
            break;
        case LIGHT_CYCLING:
            cout << "Light Cycling\n";
            MET = MET_value.at(LIGHT_CYCLING);
            activity_name = "Light Cycling";
            break;
        case NORMAL_CYCLING:
            cout << "Normal Cycling\n";
            MET = MET_value.at(NORMAL_CYCLING);
            activity_name = "Normal Cycling";
            break;
        case MODERATE_CYCLING:
            cout << "Moderate Cycling\n";
            MET = MET_value.at(MODERATE_CYCLING);
            activity_name = "Moderate Cycling";
            break;
        case ROPE_JUMPING:
            cout << "Rope Jumping\n";
            MET = MET_value.at(ROPE_JUMPING);
            activity_name = "Rope Jumping";
            break;
        case WEIGHT_TRAINING:
            cout << "Weight Training\n";
            MET = MET_value.at(WEIGHT_TRAINING);
            activity_name = "Weight Training";
            break;
        case LIGHT_CALISTHENICS:
            cout << "Light Calisthenics\n";
            MET = MET_value.at(LIGHT_CALISTHENICS);
            activity_name = "Light Calisthenics";
            break;
        case MODERATE_CALISTHENICS:
            cout << "Moderate Calisthenics\n";
            MET = MET_value.at(MODERATE_CALISTHENICS);
            activity_name = "Moderate Calisthenics";
            break;
        case VIGOROUS_CALISTHENICS:
            cout << "Vigorous Calisthenics\n";
            MET = MET_value.at(VIGOROUS_CALISTHENICS);
            activity_name = "Vigorous Calisthnics";
            break;
        default:
            cout << "Invalid Option";
            MET = -1;
            break;
    }

    if (MET < 0)
    { 
        cout << "Could not get MET Value\n";
        return false;
    }

    // Calculate Calories Burned
    if (user.weight < 0)
    {
        cout << "Cannot compute calories burned...\nPlease update user information.\n";
        return false;
    }
    
    calories_burned = MET * user.weight * 0.0175 * time;

    cout << "\n-----------------------------------------\n";
    cout << "Physical Activity Log:\n";
    cout << "Activity: " << activity_name << '\n';
    cout << "Time Elapsed (minutes): " << time << '\n';
    cout << "Calories Burned: " << setprecision(2) << fixed << calories_burned << '\n'; 
    cout << "-----------------------------------------\n";

    char update_choice;

    cout << "Confirm Log? [Y/N]? ";
    cin >> update_choice;

    while (  update_choice != 'Y' && update_choice != 'y' &&  update_choice != 'N' && update_choice == 'n')
    {
       cout << "Invalid choice... Confirm Log? [Y/N]? ";
       cin >> update_choice; 
    }

    if (update_choice == 'N' || update_choice == 'n')
    {
        cout << "Log Cancelled...\n";
        return false;
    }

    cout << "Physical Activity Logged!\n";
    container->activity = activity_name;
    container->minutes_conducted = time;
    container->calories_burned = calories_burned;

    return true;
}

float calculate_BMI_score(float height_cm, float weight_kg)
{
    float height_m = height_cm / 100;

    float BMI_score = weight_kg / ( height_m* height_m );

    return  BMI_score;
}

string classify_BMI(float BMI_score)
{
    if      (BMI_score < 18.50) return "Underweight"; // Underweight
    else if (BMI_score < 25.00) return "Normal Weight"; // Normal
    else if (BMI_score < 30.00) return "Overweight"; // Overweight
    else if (BMI_score < 35.00) return "Class 1 Obesity"; // Class 1 Obesity
    else if (BMI_score < 40.00) return "Class 2 Obesity"; // Class 2 Obesity
    else                        return "Class 3 Obesity"; // Class 3 Obesity
}

void display_user_status(const User &user)
{   
    float BMI_score = calculate_BMI_score(user.height, user.weight);
    string BMI_class = classify_BMI(BMI_score);

    cout << "\n------------------------------\n";
    cout << "Name: " << user.name << "\n";
    cout << "Age: " << user.age << "\n";
    cout << "Height: " << user.height << "\n";
    cout << "Weight: " << user.weight << "\n\n";

    cout << "BMI Score: " << setprecision(2) << fixed << BMI_score << "\n";
    cout << "BMI_Class: " << BMI_class << "\n";
    cout << "------------------------------\n\n";

    return;
}

void display_activity(const Physical_Activity &physical_activity)
{
    cout << "\n------------------------------\n";
    cout << "Activity: " << physical_activity.activity << "\n";
    cout << "Minutes Elapsed: " << physical_activity.minutes_conducted << "\n";
    cout << "Calories Burned: " << physical_activity.calories_burned << "\n";
    cout << "------------------------------\n";
}

void suggest_exercise(Physical_Fitness_Level physical_level, Physical_Fitness_Goal physical_goal)
{   
    Exercise suggested_exercise;
    
    int vector_size = -1;

    switch (physical_goal) // Get the number of available exercises in each category in _Exercises maps.
    {
    case CARDIO:
        vector_size = Cardio_Exercises.at(physical_level).size();
        break;
    case ENDURANCE:
        vector_size = Endurance_Exercises.at(physical_level).size();
        break;
    case STRENGTH:
        vector_size = Strength_Exercises.at(physical_level).size();
        break;
    default:
        cout << "Error -1\n";
        break;
    }
    
    // Give a random exercise based on the selected fields
    srand(time(0));
    int random_index = rand() % vector_size;

    switch (physical_goal) 
    {
    case CARDIO:
        suggested_exercise = Cardio_Exercises.at(physical_level).at(random_index);
        break;
    case ENDURANCE:
        suggested_exercise = Endurance_Exercises.at(physical_level).at(random_index);
        break;
    case STRENGTH:
        suggested_exercise = Strength_Exercises.at(physical_level).at(random_index);
        break;
    default:
        cout << "Error -1\n";
        break;
    }

    cout << "\n-------------------------------\n";
    cout << "Exercise Suggestion: " << suggested_exercise.name << '\n';
    cout << "Instruction/s:\n" << suggested_exercise.instruction << '\n';
    cout << "-------------------------------\n";
}