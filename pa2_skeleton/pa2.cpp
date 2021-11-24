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
         if ((map[robot_y][robot_x] == 'C' || map[robot_y][robot_x] == 'R') && temp_map[robot_y][robot_x] != 'X')
         {
            temp_map[robot_y][robot_x] = 'X'; //the machine have eaten the charger C, and not come back
            robot_energy = robot_full_energy;
         }

         if (robot_y == target_y)
         {
            int temp1 = findShortestDistance(robot_x, robot_y + 1, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
            int temp2 = findShortestDistance(robot_x, robot_y - 1, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
            if (temp2 > temp1)
            {
               path.up_OR_dwon = temp1;
            }
            else
            {
               path.up_OR_dwon = temp2;
            }
         }
         else
         {
            if (robot_y > target_y && map[robot_y - 1][robot_x] != 'B')
            {
               if (!((robot_x - 1 < 0 && map[robot_y - 1][robot_x + 1] == 'B' || robot_x + 1 >= MAP_WIDTH && map[robot_y - 1][robot_x - 1] == 'B' || map[robot_y - 1][robot_x + 1] == 'B' && map[robot_y - 1][robot_x - 1] == 'B') && robot_y - 1 == target_y) || (robot_y - 1 == target_y && robot_x == target_x))
                  path.up_OR_dwon = findShortestDistance(robot_x, robot_y - 1, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
               else
                  path.up_OR_dwon = PA2_MAX_PATH;
            }
            else
            {
               if (!(map[robot_y + 1][robot_x ] == 'B' && map[robot_y ][robot_x + 1] == 'B' && map[robot_y ][robot_x - 1] == 'B'))
                  if (!((robot_x - 1 < 0 && map[robot_y + 1][robot_x + 1] == 'B' || robot_x + 1 >= MAP_WIDTH && map[robot_y + 1][robot_x - 1] == 'B' || map[robot_y + 1][robot_x + 1] == 'B' && map[robot_y + 1][robot_x - 1] == 'B') && robot_y + 1 == target_y) || (robot_y + 1 == target_y && robot_x == target_x))
                     path.up_OR_dwon = findShortestDistance(robot_x, robot_y + 1, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
                  else
                     path.up_OR_dwon = PA2_MAX_PATH;
               else
                  path.up_OR_dwon = findShortestDistance(robot_x, robot_y - 1, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
            }
         }

         path.left = findShortestDistance(robot_x - 1, robot_y, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
         path.right = findShortestDistance(robot_x + 1, robot_y, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
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
   struct pa2
   {
      int total;
      int up;
      int down;
      int right;
      int left;
   };
   pa2 path;
   char clean_map[MAP_HEIGHT][MAP_WIDTH] = {};
   int min_dis = findShortestDistance(robot_x, robot_y, target_x, target_y, robot_energy, robot_full_energy, map, temp_map);
   copyMap(temp_map, clean_map);
   if (min_dis == PA2_MAX_PATH) //check reachable
   {
      return PA2_MAX_PATH;
   }
   else
   {
      char sequence;
      if (map[target_y][target_x] == 'B' || map[robot_y][robot_x] == 'B' || target_y < 0 || target_x < 0 || robot_x < 0 ||
          robot_y < 0 || target_y >= MAP_HEIGHT || target_x >= MAP_WIDTH || robot_y >= MAP_HEIGHT || robot_x >= MAP_WIDTH || robot_energy < 0)
      {
         return PA2_MAX_PATH;
      }
      if (strchr(result_sequence, 'T') != NULL)
      {
         memset(result_sequence, '\0', MAX_STRING_SIZE);
      }
      if ((map[robot_y][robot_x] == 'C' || map[robot_y][robot_x] == 'R') && temp_map[robot_y][robot_x] != 'X')
      {
         temp_map[robot_y][robot_x] = 'X'; //the machine have eaten the charger C, and not come back
         robot_energy = robot_full_energy;
      }

      if (min_dis == 1)
      {
         result_sequence[strlen(result_sequence)] = 'T';
         result_sequence[strlen(result_sequence) + 1] = '\0';
         return 1;
      }
      else
      {
         int target_step = min_dis;
         path.up = PA2_MAX_PATH;
         path.down = PA2_MAX_PATH;
         path.left = PA2_MAX_PATH;
         path.right = PA2_MAX_PATH;

         path.up = findShortestDistance(robot_x, robot_y - 1, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map);
         copyMap(temp_map, clean_map);
         path.right = findShortestDistance(robot_x + 1, robot_y, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map);
         copyMap(temp_map, clean_map);
         path.down = findShortestDistance(robot_x, robot_y + 1, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map);
         copyMap(temp_map, clean_map);
         path.left = findShortestDistance(robot_x - 1, robot_y, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map);
         copyMap(temp_map, clean_map);

         if (target_step > path.up)
         {
            target_step = path.up;
            sequence = 'U';
         }
         if (target_step > path.right)
         {
            target_step = path.right;
            sequence = 'R';
         }
         if (target_step > path.down)
         {
            target_step = path.down;
            sequence = 'D';
         }
         if (target_step > path.left)
         {
            target_step = path.left;
            sequence = 'L';
         }
         result_sequence[strlen(result_sequence)] = sequence;
      }
      if (sequence == 'U')
      {
         findPathSequence(robot_x, robot_y - 1, target_x, target_y, robot_energy - 1,
                          robot_full_energy, result_sequence, map, temp_map);
         copyMap(temp_map, clean_map);
      }
      else if (sequence == 'R')
      {
         findPathSequence(robot_x + 1, robot_y, target_x, target_y, robot_energy - 1,
                          robot_full_energy, result_sequence, map, temp_map);
         copyMap(temp_map, clean_map);
      }
      else if (sequence == 'D')
      {
         findPathSequence(robot_x, robot_y + 1, target_x, target_y, robot_energy - 1,
                          robot_full_energy, result_sequence, map, temp_map);
         copyMap(temp_map, clean_map);
      }

      else if (sequence == 'L')
      {
         findPathSequence(robot_x - 1, robot_y, target_x, target_y, robot_energy - 1,
                          robot_full_energy, result_sequence, map, temp_map);
         copyMap(temp_map, clean_map);
      }

      else
      {
         return PA2_MAX_PATH;
      }

      return min_dis;
   }
}

int findFarthestPossibleCharger(int robot_x, int robot_y, int robot_original_x, int robot_original_y, int &target_x, int &target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH])
{
   if (map[robot_y][robot_x] == 'B' || map[robot_original_y][robot_original_x] == 'B' || robot_x < 0 || robot_y < 0 || robot_original_x < 0 || robot_original_y < 0 || robot_x >= MAP_WIDTH || robot_y >= MAP_HEIGHT || robot_original_x >= MAP_WIDTH || robot_original_y >= MAP_HEIGHT || robot_energy < 0)
   {
      return -1;
   }
   else
   {
      int charger1_dis = 0;
      int charger2_dis = 0;
      char clean_map[MAP_HEIGHT][MAP_WIDTH] = {};

      if (map[robot_y][robot_x] == 'C')
      {
         if (target_x != -1)
         {
            charger1_dis = findShortestDistance(robot_original_x, robot_original_y, robot_x, robot_y, robot_energy, robot_full_energy, map, temp_map);
            copyMap(temp_map, clean_map);
            charger2_dis = findShortestDistance(robot_original_x, robot_original_y, target_x, target_y, robot_energy, robot_full_energy, map, temp_map);
            copyMap(temp_map, clean_map);
            if (charger1_dis > charger2_dis)
            {
               target_x = robot_x;
               target_y = robot_y;
            }
         }
         else
         {
            target_x = robot_x;
            target_y = robot_y;
         }
      }
      findFarthestPossibleCharger(robot_x, robot_y - 1, robot_original_x, robot_original_y,
                                  target_x, target_y, robot_energy - 1, robot_full_energy,
                                  map, temp_map);
      copyMap(temp_map, clean_map);
      findFarthestPossibleCharger(robot_x + 1, robot_y, robot_original_x, robot_original_y,
                                  target_x, target_y, robot_energy - 1, robot_full_energy,
                                  map, temp_map);
      copyMap(temp_map, clean_map);
      findFarthestPossibleCharger(robot_x, robot_y + 1, robot_original_x, robot_original_y,
                                  target_x, target_y, robot_energy - 1, robot_full_energy,
                                  map, temp_map);
      copyMap(temp_map, clean_map);
      findFarthestPossibleCharger(robot_x - 1, robot_y, robot_original_x, robot_original_y,
                                  target_x, target_y, robot_energy - 1, robot_full_energy,
                                  map, temp_map);
      copyMap(temp_map, clean_map);
      if (findShortestDistance(robot_original_x, robot_original_y, target_x, target_y, robot_full_energy, robot_full_energy, map, temp_map) < PA2_MAX_PATH)
         return findShortestDistance(robot_original_x, robot_original_y, target_x, target_y, robot_full_energy, robot_full_energy, map, temp_map);
      else
         return -1;
   }
}