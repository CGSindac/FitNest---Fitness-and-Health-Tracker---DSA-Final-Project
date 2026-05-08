#include "headers.cpp"
#pragma once
using namespace std;

struct Physical_Activity
{
   string activity= "";
   float minutes_conducted = -1;
   float calories_burned = -1;
};

struct User
{
   string name = "";
   int age = -1;
   float height = -1;
   float weight = -1;
};

struct Exercise
{
   string name = "NULL";
   string instruction = "NULL";
};
