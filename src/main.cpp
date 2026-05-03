#include "headers.cpp"
#include "structures.cpp"

using namespace std;

// Enums for phgysical activities

// Declare Global Variable:
User user;

// Prototypes
void display_main_menu();
void update_user_info_process();
void log_physical_activity(Physical_Activity *container);

float calculate_BMI_score(float height, float weight);
int classify_BMI(float BMI_score);

int main()
{
    int choice;

    while (true)
    {   
        display_main_menu();

        cout << "\nAction: ";
        cin >> choice;

        if (choice == 5)
        {   
            cout << "\n-------------------Thank you for using FitNest-------------------\n";
            break;
        }else if (choice == 4)
        {
            // Suggest Excersise
        }else if (choice == 3)
        {
            // Generate Report
        }else if (choice == 2)
        {
            Physical_Activity *temp_activity = new Physical_Activity;

            log_physical_activity ( temp_activity );

            delete temp_activity;
        }else if (choice == 1)
        {
            // Update User information
            update_user_info_process();
        }else
        {
            cout << "Pleases select a valid option from the menu.";
        }
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
    cout << temp_user.name << "\n";
    cout << temp_user.age << "\n";
    cout << temp_user.height << "\n";
    cout << temp_user.weight << "\n";

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

void log_physical_activity(Physical_Activity *container)
{   
    cout << "Log new physical activity...\n";
    
    cout << "Activity done: ";
    cin >> container->activity;

    cout << "Minutes elapsed: ";
    cin >> container->minutes_conducted;

}

float calculate_BMI_score(float height_cm, float weight_kg)
{
    float height_m = height_cm / 100;

    float BMI_score = weight_kg / ( height_m* height_m );

    return  BMI_score;
}

int classify_BMI(float BMI_score)
{
    if      (BMI_score < 18.50) return 1; // Underweight
    else if (BMI_score < 25.00) return 2; // Normal
    else if (BMI_score < 30.00) return 3; // Overweight
    else if (BMI_score < 35.00) return 4; // Class 1 Obesity
    else if (BMI_score < 40.00) return 5; // Class 2 Obesity
    else                        return 6; // Class 3 Obesity
}