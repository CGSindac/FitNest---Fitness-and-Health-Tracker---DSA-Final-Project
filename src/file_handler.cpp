#include "headers.cpp"
#include "structures.cpp"

using namespace std;

const char *ACTIVITY_PATH = "../data/physical_activities.txt";
const char *USER_INFO = "../data/user_info.txt";

bool file_exists(const string &file_path);
bool extract_activities(const char *file_path, vector<Physical_Activity> *container);
bool update_activities(const char *file_path, Physical_Activity activity);
bool extract_user_info(const char *path, User &user);
bool update_user_info(const char *file_path, const User &user);

bool file_exists(const string &file_path)
{
    const char *temp = file_path.c_str();

    FILE *test;
    test = fopen(temp, "r");

    // Try to open file
    if (test == NULL)
    {
        cout << "Could not open file.\n";

        fclose(test);

        return false;
    }
    cout << "File opened.\n";

    fclose(test);

    return true;
}

bool extract_activities(const char *file_path, vector<Physical_Activity> *container)
{
    ifstream file(file_path);

    if (!file) return false; // If we can't open the file

    Physical_Activity temp;

    string text;

    enum Read_State{
        NONE = -1,
        NAME = 0,
        TIME = 1,
        CAL_BURNED = 2
    };

    enum Read_State status = NONE;   
    
    // Parse text file
    while(getline(file, text))
    {
        if (text == "--ENTRY--")
        {
            status = NONE;
            container->push_back(temp);
            continue;
        }else if (text == "-N")
        {
            status = NAME;
            continue;
        }else if (text == "-T")
        {
            status = TIME;
            continue;
        }else if (text == "-C")
        {
            status = CAL_BURNED;
            continue;
        }

        // Create temporary physical activity variable
        if (status == NAME)
        {
            temp.activity = text;
        }else if (status == TIME)
        {
            temp.minutes_conducted = stof(text);
        }else if (status == CAL_BURNED)
        {
            temp.calories_burned = stof(text);
        }

        status = NONE;
    }

    file.close();
    return true;
}

bool update_activities(const char *file_path, Physical_Activity activity)
{
    ofstream file(file_path, ios::app);

    if (!file) return false;
    
    stringstream format_activity;   // format to Calix' File Notation
    string activity_container;      // Final string variable

    format_activity <<  "-N\n" << activity.activity << "\n" 
                    << "-T\n" << activity.minutes_conducted << "\n"
                    << "-C\n" << activity.calories_burned << "\n"
                    << "--ENTRY--\n\n";

    activity_container = format_activity.str(); // Combine multiple strings 

    file << activity_container; // Append to text file

    file.close();

    return true;
}

bool extract_user_info(const char *file_path, User &user)
{
    ifstream file(file_path);

    if (!file) return false; // If we can't open the file

    string text;

    enum Read_State{
        NONE = -1,
        NAME = 0,
        AGE = 1,
        HEIGHT= 2,
        WEIGHT = 3,
    };

    enum Read_State status = NONE;   
    
    // Parse text file
    while(getline(file, text))
    {
        if (text == "--ENTRY--")
        {
            status = NONE;
            break;
        }else if (text == "-N")
        {
            status = NAME;
            continue;
        }else if (text == "-A")
        {
            status = AGE;
            continue;
        }else if (text == "-H")
        {
            status = HEIGHT;
            continue;
        }else if (text == "-W")
        {
            status = WEIGHT;
            continue;
        }

        // Create temporary physical activity variable
        if (status == NAME)
        {
            user.name = text;
        }else if (status == AGE)
        {
            user.age = stoi(text);
        }else if (status == HEIGHT)
        {
            user.height = stof(text);
        }else if (status == WEIGHT)
        {
            user.weight = stof(text);
        }

        status = NONE;
    }

    file.close();
    return true;
}

bool update_user_info(const char *file_path, const User &user)
{
    ofstream file(file_path);

    if (!file) return false;
    
    stringstream format_string;   // format to Calix' File Notation
    string info_container;      // Final string variable

    format_string   <<  "-N\n" << user.name << "\n" 
                    << "-A\n" << user.age << "\n"
                    << "-H\n" << user.height << "\n"
                    << "-W\n" << user.weight << "\n"
                    << "--END--\n\n";

    info_container = format_string.str(); // Combine multiple strings 

    file << info_container; // Overwrite to text file

    file.close();

    return true;
}