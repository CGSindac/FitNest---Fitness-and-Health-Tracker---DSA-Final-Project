#include "headers.cpp"
#include "structures.cpp"

using namespace std;

bool file_exists(const string &file_path);
bool extract_activities(const string &file_path, vector<Physical_Activity> &container);

int main()
{
    vector<Physical_Activity> temp;
    string s = "myfile.txt";

    if (file_exists(s))
    {
        extract_activities("myfile.txt", temp);
    }

    for (Physical_Activity act : temp)
    {
        cout << "\n------------------------------------\n";
        cout << "Name: " << act.activity << "\n";
        cout << "Time Elapsed: " << act.minutes_conducted << "\n";
        cout << "Calories Burned: " << act.calories_burned << "\n"; 
    }
    

    return 0;
}

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

bool extract_activities(const string &file_path, vector<Physical_Activity> &container)
{
    ifstream file(file_path);

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
            container.push_back(temp);
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