#include "headers.cpp"
#pragma once


struct Physical_Activity
{
   string date = "";
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