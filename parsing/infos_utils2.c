#include"../includes/parsing.h"

int return_type(char *tokens)
{
    int type;
    // int i;

    // i = 0;
    type = NO_TYPE;
    if(!ft_strncmp(tokens, "F", 1) && ft_strlen(tokens)== 1)
        type = FLOOR;
    else    if(!ft_strncmp(tokens, "C",1) && ft_strlen(tokens)== 1)
        type = CEILEING;
    else    if(!ft_strncmp(tokens, "SO",2) && ft_strlen(tokens)== 2)
        type = IMG_SO;
    else    if(!ft_strncmp(tokens, "NO",2) && ft_strlen(tokens)== 2)
        type = IMG_NO;
    else    if(!ft_strncmp(tokens, "EA",2) && ft_strlen(tokens)== 2)
        type = IMG_EA;
    else    if(!ft_strncmp(tokens, "WE",2) && ft_strlen(tokens)== 2)
        type = IMG_WE;
    else
        type = NO_TYPE;
    return type;
}

int count_occ(char *set, char c)
{
    int i ;

    i = 0;
    while(set && *set )
    {
        if(*set == c)
            i++;
        set++;    
    }
    return i;
}

int chcek_set_len(char **sets)
{
    int i;
    int j;
    
    i = 0;
    while(sets[i])
    {
        j = 0;
        while(sets[i][j]){
            if(sets[i][j] && sets[i][j] != '0'){
                if(ft_strlen(&sets[i][j]) > 3)
                    return (1);
            }
            j++;
        }    
        i++;
    }
    return 0;
}



