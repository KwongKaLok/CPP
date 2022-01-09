int findShortestDistance(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH])
{
    if (robot_x >= MAP_WIDTH || robot_y >= MAP_HEIGHT || robot_x < 0 || robot_y < 0 || target_x >= MAP_WIDTH ||
        target_y >= MAP_HEIGHT || target_x < 0 || target_y < 0 ||
        robot_energy < 0 || map[robot_y][robot_x] == 'B' || map[target_y][target_x] == 'B')
    {
        return PA2_MAX_PATH;
    }
    //how to charge when it meets 'C'
    else
    {
        int left = PA2_MAX_PATH;
        int right = PA2_MAX_PATH;
        int upordown = PA2_MAX_PATH;
        int total = PA2_MAX_PATH;

        if (robot_x == target_x && robot_y == target_y)
        {
            return 1;
        }
        else
        {
            if (map[robot_y][robot_x] == 'C' || map[robot_y][robot_x] == 'R' && temp_map[robot_y][robot_x] != 'X')
            {
                robot_energy = robot_full_energy;
                temp_map[robot_y][robot_x] = 'X';
            }

            if (target_y > robot_y)
            {
                int upordown = findShortestDistance(robot_x, robot_y + 1, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
            }
            else
            {
                int upordown = findShortestDistance(robot_x, robot_y - 1, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
                int left = findShortestDistance(robot_x - 1, robot_y, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
                int right = findShortestDistance(robot_x + 1, robot_y, target_x, target_y, robot_energy - 1, robot_full_energy, map, temp_map) + 1;
            }
            
            if (left < total)
            {
                total = left;
            }
            if (right < total)
            {
                total = right;
            }
            if (upordown < total)
            {
                total = upordown;
            }
            return total;
        }
    }
}