#include "headers.cpp"
#include "structures.cpp"
#include "functions.cpp"
#include "file_handler.cpp"

// Declare Global Variable:
User user;

int main()
{
    int choice;
    extract_user_info(USER_INFO, user);

    while (true)
    {   
        display_main_menu();

        get_value(choice, "\nSelection: ");

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

            get_value(goal, "Selection: ");

            while(goal < 1 || goal > 3)
            {
                cout << "Enter from the give choices...\nSelection: ";
                get_value(goal, "Selection: ");
            }

            if (goal == 1)      enum_goal = CARDIO;
            else if (goal == 2) enum_goal = STRENGTH;
            else                enum_goal = ENDURANCE;

            // Get Physical Fitness Level
            cout << "What is your physical fitness level?\n";
            cout << "[1] - Beginner\n";
            cout << "[2] - Intermediate\n";
            cout << "[3] - Advanced\n";

            get_value(level, "Selection: ");

            while(level < 1 || level > 3)
            {
                cout << "Enter from the give choices...\n";
                get_value(level, "Selection: ");
            }

            if (level == 1)     enum_level = BEGINNER;
            else if (level== 2) enum_level = INTERMEDIATE;
            else                enum_level = ADVANCED;

            suggest_exercise(enum_level, enum_goal);

            char return_choice;

            do
            {
                cout << "Return to Menu [Y]? ";
                cin  >> return_choice;
            } while (return_choice != 'Y' && return_choice != 'y');

        }else if (choice == 3) // Generate Status Report
        {
            int report_choice;

            cout << "What report do you want?\n";
            cout << "[1] - User Status.\n";
            cout << "[2] - Physical Activity Log\n";

            get_value(report_choice, "Selection: ");

            while(report_choice <= 0 || report_choice > 2)
            {
                cout << "Please select from the options...\n";
                get_value(report_choice, "Selection: ");
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

            if ( log_physical_activity ( temp_activity , user ) )
            {
                update_activities(ACTIVITY_PATH, *temp_activity); // Updates the database when activity is successfully logged 
            }

            delete temp_activity;

            Sleep(2000); // Wait for 2 seconds
        }else if (choice == 1)
        {
            update_user_info_process( user );
            update_user_info(USER_INFO, user);
            extract_user_info(USER_INFO, user);

            Sleep(2000); // Wait for 2 seconds
        }else
        {
            cout << "Pleases select a valid option from the menu.";
        }

        // Uncomment the code below if you will be running it outside of vsCode terminal.
        //system("cls");
    }
    return 0;
}



