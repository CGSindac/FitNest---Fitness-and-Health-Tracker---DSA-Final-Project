#include "headers.cpp"

using namespace std;

bool file_exists(const string &file_path);

int main()
{
    string s = "myfile.txt";

    file_exists(s);

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

bool extract_content(const string &file_path)
{
    return true;
}