#include <iostream>
#include <cstring>
#include "cleaning_robot.h"
using namespace std;

/*
 *    COMP 2011 2021 Fall Programming Assignment 2
 *    Student Name        : LAU Ming Kit
 *    Student ID          : 20772685
 *    Student ITSC email  : mklauag@connnect.ust.hk
 *
 * You are not allowed to use extra library
 */

// Please do all your work in this file. You just need to submit this file.

int findMaximumPlace(int robot_x, int robot_y, int robot_energy, int robot_full_energy,
                     char result_map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH])
{
   int v_score = 0;
   int score_up = 0;
   int score_down = 0;
   int score_left = 0;
   int score_right = 0;
   char thing = result_map[robot_y][robot_x];
   if (robot_energy != 0 && robot_y >= 0 && robot_y < MAP_HEIGHT && robot_x >= 0 && robot_x < MAP_WIDTH)
   {

      switch (thing)
      {
      case 'C':
      case 'R':
         robot_energy = robot_full_energy + 1;
      case ' ':
         v_score++;
      case 'V':
         result_map[robot_y][robot_x] = 'V';
         score_left = findMaximumPlace(robot_x - 1, robot_y, robot_energy - 1, robot_full_energy, result_map, temp_map);
         score_right = findMaximumPlace(robot_x + 1, robot_y, robot_energy - 1, robot_full_energy, result_map, temp_map);
         score_down = findMaximumPlace(robot_x, robot_y - 1, robot_energy - 1, robot_full_energy, result_map, temp_map);
         score_up = findMaximumPlace(robot_x, robot_y + 1, robot_energy - 1, robot_full_energy, result_map, temp_map);
         break;
      default:
         break;
      }
   }
   v_score += score_up + score_down + score_left + score_right;
   return v_score;
}

int findShortestDistance(int robot_x, int robot_y, int target_x, int target_y, int robot_energy,
                         int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH])
{
   int score1 = PA2_MAX_PATH;
   int score2 = PA2_MAX_PATH;
   int score3 = PA2_MAX_PATH;
   int score4 = PA2_MAX_PATH;
   int min = PA2_MAX_PATH;
   copyMap(temp_map, map);

   if (temp_map[target_y][target_x] == 'B' || target_y < 0 || target_y >= MAP_HEIGHT || target_x >= MAP_WIDTH || target_x < 0)
      return PA2_MAX_PATH;
   else
   {

      char thing = temp_map[robot_y][robot_x];
      if (robot_energy >= 0 && robot_y >= 0 && robot_y < MAP_HEIGHT && robot_x >= 0 && robot_x < MAP_WIDTH && temp_map[robot_y][robot_x] != 'B')
      {
         if (robot_x == target_x && robot_y == target_y)
            return 1;
         else
         {
            if (thing == ' ')
            {
               score1 = findShortestDistance(robot_x - 1, robot_y, target_x, target_y, robot_energy - 1, robot_full_energy, temp_map, temp_map) + 1;
               score2 = findShortestDistance(robot_x + 1, robot_y, target_x, target_y, robot_energy - 1, robot_full_energy, temp_map, temp_map) + 1;
               score3 = findShortestDistance(robot_x, robot_y - 1, target_x, target_y, robot_energy - 1, robot_full_energy, temp_map, temp_map) + 1;
               score4 = findShortestDistance(robot_x, robot_y + 1, target_x, target_y, robot_energy - 1, robot_full_energy, temp_map, temp_map) + 1;
            }
            else if (thing == 'C' || thing == 'R')
            {
               temp_map[robot_y][robot_x] = ' ';
               score1 = findShortestDistance(robot_x - 1, robot_y, target_x, target_y, robot_full_energy, robot_full_energy, temp_map, temp_map) + 1;
               score2 = findShortestDistance(robot_x + 1, robot_y, target_x, target_y, robot_full_energy, robot_full_energy, temp_map, temp_map) + 1;
               score3 = findShortestDistance(robot_x, robot_y - 1, target_x, target_y, robot_full_energy, robot_full_energy, temp_map, temp_map) + 1;
               score4 = findShortestDistance(robot_x, robot_y + 1, target_x, target_y, robot_full_energy, robot_full_energy, temp_map, temp_map) + 1;
            }
           
            if (score1 < min)
               min = score1;
            if (score2 < min)
               min = score2;
            if (score3 < min)
               min = score3;
            if (score4 < min)
               min = score4;
            return min;
         }
      }
      else
         return PA2_MAX_PATH;
   }
}
// This recursive function finds the shortest distance from the current robot position (robot_x, robot_y) to the target position (target_x, target_y),
//          based on the constraints of energy, chargers and blocked areas.
//      If the robot cannot go there within the robot_energy,
//          it returns the constant PA2_MAX_PATH and that indicates that the specified position is unreachable.
// Parameters:
// 	robot_x: the x coordinate of the robot
// 	robot_y: the y coordinate of the robot
// 	target_x: the x coordinate of the target
// 	target_y: the y coordinate of the target
// 	robot_energy: the current energy of the robot
// 	robot_full_energy: the full capacity of robot energy
// 	result_map: the 2d array with the map information
// 	temp_map: extra temperary 2D char array, optional for you to use
// Return Value:
// 	the distance of the shortest path between the robot and the target
// 	if the target cannot be reached, the constant PA2_MAX_PATH is returned

int findPathSequence(int robot_x, int robot_y, int target_x, int target_y, int robot_energy,
                     int robot_full_energy, char result_sequence[], const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]) { return 0; }
// This recursive function finds the sequence of moves which gives the shortest distance from the current robot position (robot_x, robot_y) to the target position (target_x, target_y),
//          based on the constraints of energy, chargers and blocked areas. target_y), based on the constraints of energy, chargers and blocked areas.
//      If the robot cannot go there within the robot_energy,
//          it returns the constant PA2_MAX_PATH and that indicates that that position is unreachable.
// Parameters:
// 	robot_x: the x coordinate of the robot
// 	robot_y: the y coordinate of the robot
// 	target_x: the x coordinate of the target
// 	target_y: the y coordinate of the target
// 	robot_energy: the current energy of the robot
// 	robot_full_energy: the full capacity of robot energy
// 	result_sequence: the sequence of moves that gives the shortest path (Note: it has to be a C-String)
// 	map: the 2d array with the map information
// 	temp_map: extra temperary 2D char array, optional for you to use
// Return Value:
// 	the distance of the shortest path between the robot and the target
// 	if the target cannot be reached, the constant PA2_MAX_PATH is returned

int findFarthestPossibleCharger(int robot_x, int robot_y, int robot_original_x, int robot_original_y,
                                int &target_x, int &target_y, int robot_energy, int robot_full_energy,
                                const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]) { return 0; }
//  The function will scan through the walkable area and then determine whether there is any position that matches with a charger.
//      If there is at least one charger, then the farthest position will be returned by the reference variables target_x and target_y,
//          together with returning the shortest distance between the robot's original position to that position.
//      When a charger is not found or none of the chargers can be reached by the robot under the energy constraint,
//          the function returns -1 and we do not care about the value of target_x and target_y.
// Parameters:
// 	robot_x: the current x coordinate of the robot
// 	robot_y: the current y coordinate of the robot
// 	robot_original_x: the initial x coordinate of the robot
// 	robot_original_y: the initial y coordinate of the robot
// 	target_x: to store the x coordinate of the farthest charger if found
// 	target_y: to store the y coordinate of the farthest charger if found
// 	robot_energy: the current energy of the robot
// 	robot_full_energy: the full capacity of robot energy
// 	map: the 2d array with the map information
// 	temp_map: extra temperary 2D char array, optional for you to use
// Return Value:
// 	the distance of the shortest path between the robot and the farthest charger
// 	if no charger is reachable, -1 is returned
