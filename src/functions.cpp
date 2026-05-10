#include "headers.cpp"
#include "structures.cpp"
#pragma once
// 
// Prototypes
void display_main_menu();
void update_user_info_process(User &user);
void display_user_status(const User &user);
void display_activity(const Physical_Activity &physical_activity);
void suggest_exercise(Physical_Fitness_Level physical_level, Physical_Fitness_Goal physical_goal);

bool log_physical_activity(Physical_Activity *container, const User &user);
float calculate_BMI_score(float height, float weight);
string classify_BMI(float BMI_score);


void get_value(int &container, string prompt = "") 
{
    cout << prompt;

    while(!(cin >> container))
    {
        cout << "Enter a valid number...\n";
        cout << prompt;
        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This ignores any previous everything behind a newline character
    }
}

void get_value(float &container, string prompt = "") 
{
    cout << prompt;

    while(!(cin >> container))
    {
        cout << "Enter a valid number...\n";
        cout << prompt;

        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This ignores any previous everything behind a newline character
    }
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

void update_user_info_process(User &user)
{
    // Ask for the user's infromation
    cout << "Update your user information...\n\n";

    User temp_user;
    char choice;

    cout << "Enter new username: ";
    cin.ignore();
    getline(cin, temp_user.name);

    get_value(temp_user.age, "Enter updated age: ");
    get_value(temp_user.height, "Enter updated height (in centimeters): ");
    get_value(temp_user.weight, "Enter updated weight (in kilograms): ");


    cout << "\n---Updated User Information---\n";
    cout << "Updated Name: " << temp_user.name << "\n";
    cout << "Updated Age: "<< temp_user.age << "\n";
    cout << "Updated Height: "<< temp_user.height << "cm\n";
    cout << "Updated Weight: "<< temp_user.weight << "kg\n";

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

bool log_physical_activity(Physical_Activity *container, const User &user)
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

    // Calculate Calories Burned
    string activity_name = "";
    float m_time, calories_burned, MET = -1;

    do{
        get_value(selection, "Selection: ");
    } while(0 >= selection && selection > 11);

    get_value(m_time, "How long did you do it (minutes)? ");

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
    
    calories_burned = MET * user.weight * 0.0175 * m_time;

    time_t timestamp;
    time(&timestamp);

    string date = ctime(&timestamp);
    date[24] = '\0';

    // Finalize Update
    cout << "\n-----------------------------------------\n";
    cout << "Physical Activity Log:\n";
    cout << "Date Logged: " << date << "\n";
    cout << "Activity: " << activity_name << '\n';
    cout << "Time Elapsed (minutes): " << m_time << '\n';
    cout << "Calories Burned: " << setprecision(2) << fixed << calories_burned << '\n'; 
    cout << "-----------------------------------------\n";

    char update_choice;

    cout << "Confirm Log? [Y/N]? ";
    cin >> update_choice;

    while (update_choice != 'Y' && update_choice != 'y' &&  update_choice != 'N' && update_choice == 'n')
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
    container->date = date;
    container->activity = activity_name;
    container->minutes_conducted = m_time;
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
    cout << "Height: " << user.height << " cm\n";
    cout << "Weight: " << user.weight << " kg\n\n";

    cout << "BMI Score: " << setprecision(2) << fixed << BMI_score << "\n";
    cout << "BMI_Class: " << BMI_class << "\n";
    cout << "------------------------------\n\n";

    return;
}

void display_activity(const Physical_Activity &physical_activity)
{
    cout << "\n------------------------------\n";
    cout << "Date Logged: " << physical_activity.date << '\n';
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

    cout << "\n------------------------------------------------------------------\n";
    cout << "Exercise Suggestion: " << suggested_exercise.name << '\n';
    cout << "Instruction/s:\n" << suggested_exercise.instruction << '\n';
    cout << "--------------------------------------------------------------------\n";
}