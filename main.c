#include <stdio.h>
#include "libft.h"

int main(void)
{
    char *test_str = "hello 'world test' \"this \\\"is\\\" a test\" simple";
/**     0: [hello], 
	1: [world test], 
	2: [this \"is\" a test], 
	3: [simple]
 **/
    char *sep = " ";  // space as separator

    char **result = ft_split_str(test_str, sep);

    if (!result)
    {
        printf("Split failed\n");
        return 1;
    }

    for (int i = 0; result[i] != NULL; i++)
        printf("Token %d: [%s]\n", i, result[i]);

    // Free memory
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);

    return 0;
}

