void filtering_by_occurrence(unsigned int number_to_process, unsigned int occurrence_threshold)
{
    int digit_array[10];
    int digit;
    int l = 0;
    for (int i = 0; i < 10; i++)
    {
        digit_array[i] = 10;
    }
    do
    {
        bool repeated = false;
        digit = number_to_process % 10;
        if (occurrence_counting(number_to_process, digit) > occurrence_threshold)
        {
            for (int j = 0; j < 10; j++)
            {
                if (digit == digit_array[j])
                {
                    repeated = true;
                }
            }
            if (!repeated)
            {
                digit_array[l] = digit;
                l++;
            };
        };
    } while (number_to_process /= 10);

    /* int temp;
    int k;
    for (int j = 0; j < 10; j++){
        for (int k = j + 1; k < 10; k++){
            if (digit_array[j] > digit_array[k]){
                temp = digit_array[j];
                digit_array[j] = digit_array[k];
                digit_array[k] = temp;            }
        }
    } */
    int i = 0;
    while (digit_array[i] != 10)
    {
        cout << digit_array[i] << " ";
        i++;
    }
}