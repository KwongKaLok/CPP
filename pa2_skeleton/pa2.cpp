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
   int count_up = 0;
   int count_right = 0;
   int count_left = 0;
   int count_down = 0;
   int count = 0;
   // if (robot_energy != 0 && robot_x >= 0 && robot_x < MAP_WIDTH && robot_y >= 0 && robot_y < MAP_HEIGHT)
   // {
   //    switch (result_map[robot_y][robot_x])
   //    {
   //    case 'R':
   //    case 'C':
   //       robot_energy = robot_full_energy + 1;
   //    case ' ':
   //       count++;
   //    case 'V':
   //       result_map[robot_y][robot_x] = 'V';
   //       count_up = findMaximumPlace(robot_x, robot_y - 1, robot_energy - 1, robot_full_energy, result_map, temp_map);
   //       count_right = findMaximumPlace(robot_x + 1, robot_y, robot_energy - 1, robot_full_energy, result_map, temp_map);
   //       count_down = findMaximumPlace(robot_x, robot_y + 1, robot_energy - 1, robot_full_energy, result_map, temp_map);
   //       count_left = findMaximumPlace(robot_x - 1, robot_y, robot_energy - 1, robot_full_energy, result_map, temp_map);
   //       break;
   //    default:
   //       break;
   //    }
   // }
   // count += count_down + count_right + count_up + count_left;
   // return count;
   if (robot_energy >= 0 && (robot_y < MAP_HEIGHT) && (robot_x < MAP_WIDTH) && (result_map[robot_y][robot_x] != 'B') && robot_y >= 0 && robot_x >= 0)
   {

      if (result_map[robot_y][robot_x] == 'C')
      {
         robot_energy = robot_full_energy;
      }

      if (result_map[robot_y][robot_x] == 'C' || result_map[robot_y][robot_x] == 'R' || result_map[robot_y][robot_x] == ' ')
      {
         count++;
         result_map[robot_y][robot_x] = 'V';
      }

      count += findMaximumPlace(robot_x, robot_y - 1, robot_energy - 1, robot_full_energy, result_map, temp_map);
      count += findMaximumPlace(robot_x + 1, robot_y, robot_energy - 1, robot_full_energy, result_map, temp_map);
      count += findMaximumPlace(robot_x, robot_y + 1, robot_energy - 1, robot_full_energy, result_map, temp_map);
      count += findMaximumPlace(robot_x - 1, robot_y, robot_energy - 1, robot_full_energy, result_map, temp_map);
      return count;
   }
   else
   {
      return 0;
   }
}

int findShortestDistance(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH])
{
   struct pa2
   {
      int total;
      int up_OR_dwon;
      int right;
      int left;
   };
   pa2 path;
   copyMap(temp_map, map);
   if (map[target_y][target_x] == 'B' || map[robot_y][robot_x] == 'B' || target_y < 0 || target_x < 0 || robot_x < 0 ||
       robot_y < 0 || target_y >= MAP_HEIGHT || target_x >= MAP_WIDTH || robot_y >= MAP_HEIGHT || robot_x >= MAP_WIDTH || robot_energy < 0)

   {
      return PA2_MAX_PATH;
   }
   else
   {
      path.total = PA2_MAX_PATH;
      path.up_OR_dwon = PA2_MAX_PATH;
      path.right = PA2_MAX_PATH;
      path.left = PA2_MAX_PATH;

      if (robot_x == target_x && robot_y == target_y)
      {
         return 1;
      }
      else
      {
         if (map[robot_y][robot_x] == 'C'|| map[robot_y][robot_x] == 'R'&& temp_map[robot_y][robot_x] != 'X')
         {
            temp_map[robot_y][robot_x] = 'X'; //the machine have eaten the charger C, and not come back
            robot_energy = robot_full_energy;
         }

         if (target_y>robot_y) //the target is above the machine, it goes up first
         {
            path.up_OR_dwon=findShortestDistance(robot_x, robot_y + 1, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
         }
         else  //the target is below the machine, it goes down first
         {
            path.left = findShortestDistance(robot_x - 1, robot_y, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
            path.right = findShortestDistance(robot_x + 1, robot_y, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
            path.up_OR_dwon = findShortestDistance(robot_x, robot_y - 1, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
         }        
         if (path.up_OR_dwon < path.total)
         {
            path.total = path.up_OR_dwon;
         }
         if (path.right < path.total)
         {
            path.total = path.right;
         }
         if (path.left < path.total)
         {
            path.total = path.left;
         }

         return path.total;
      }
   }
}

int findPathSequence(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, char result_sequence[], const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH])
{
   return 0;
}
int findFarthestPossibleCharger(int robot_x, int robot_y, int robot_original_x, int robot_original_y, int &target_x, int &target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH])
{
   return 0;
}