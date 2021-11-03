#include <iostream>
#include <cstring>
#include "cleaning_robot.h"
using namespace std;

/*
   *    COMP 2011 2021 Fall Programming Assignment 2
   *    Student Name        : Kwong Ka Lok 
   *    Student ID          : 20772439
   *    Student ITSC email  : klkwongab@connect.ust.hk
   * 
   * You are not allowed to use extra library
*/

// Please do all your work in this file. You just need to submit this file.

int findMaximumPlace(int robot_x, int robot_y, int robot_energy, int robot_full_energy, char result_map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH])
{
   int count;
   if (robot_energy < 0 || robot_y > MAP_HEIGHT || robot_x > MAP_WIDTH || result_map[robot_y][robot_x] == 'B')
   {
      return count;
   }
   else
   {
      if (result_map[robot_y][robot_x] == 'C')
      {
         robot_energy = robot_full_energy;
      }

      result_map[robot_y][robot_x] = 'V';
      
      findMaximumPlace(robot_x, robot_y - 1, robot_energy - 1, robot_full_energy, result_map, temp_map);
      findMaximumPlace(robot_x + 1, robot_y, robot_energy - 1, robot_full_energy, result_map, temp_map);
      findMaximumPlace(robot_x, robot_y + 1, robot_energy - 1, robot_full_energy, result_map, temp_map);
      findMaximumPlace(robot_x - 1, robot_y, robot_energy - 1, robot_full_energy, result_map, temp_map);
   }
   return count;
}

int findShortestDistance(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH])
{
   return 0;
}

int findPathSequence(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, char result_sequence[], const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH])
{
   return 0;
}
int findFarthestPossibleCharger(int robot_x, int robot_y, int robot_original_x, int robot_original_y, int &target_x, int &target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH])
{
   return 0;
}