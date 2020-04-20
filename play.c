#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <song.h>




struct name {

	char text[200];		// testo della canzone

	char input[80];		// nome del file con il link

	char link[150];		// link alla canzone

} name;

int exists(const char *fname) 
{

	FILE *file;

	if ((file = fopen(name.input, "r"))) {

		fclose(file);

		return 1;

	}

	return 0;

}
void browseSong(char *link) 
{
		
        FILE *fd = fopen(link, "r");

		if (fd != NULL) 
        {

			do {

				fgets(name.link, 150, fd);

			} while (!feof(fd));

			system(name.link);

		} else

			perror("errore in apertura");

		fclose (fd);

}

void createlink(char *link) 
{

	system ("nano link");

}


void createLyric(char *link)
{
	

    system ("nano testo");


}

void readLyrics(char *nome) 
{

	FILE *fd = fopen(nome, "r");

	if (fd != NULL) {

		system("clear");

		do {

			if (feof(fd))

				break;

			fgets(name.text, 80, fd);

			printf("%s", name.text);

		} while (!feof(fd));

	} else

		perror("errore in apertura");

	fclose (fd);

}

int main(int argc, char ** argv) 

{
	char *link = " link";

    char *path = "/home/luigi/Documents/musica/";

    int i = 2, input;


    strcpy(name.input,path);

    
    if (argc == 1)
    {


        	printf("inserire il nome della canzone\n");
        
        	scanf("%[^\n]s ", name.input);
        
    }    


    if (argc > 1)

    {

        if (argc == 2)

        {

            strcat(name.input,argv[1]);

            goto start;

        }

        strcat(name.input,argv[1]);

        strcat (name.input, " ");            

        while (i <= argc - 1)

        {

            strcat (name.input,argv[i]);

            if (i != argc - 1)  

                strcat (name.input, " ");

            i++;      

        }
        
        printf ("%s\n\n",name.input);
    


    }    

start:
	if (exists (name.input) == 0)
    
    {

        printf ("la canzone non è presente, vuoi inserirla?  (Sì : 1 , No : 0)\n> ");

        scanf ("%d", &input);
    
        if (input == 1)

        {

            printf("è una canzone con testo? (Sì : 1 , No : 0)\n>");

            scanf("%d", &input);

            if (input == 1)        

            {            
        
       		    createLyric(name.input);

                 createlink(name.input);

                 readLyrics(name.input);
        
                	strcat(name.input, link);
            
                	browseSong(name.input);

            }

            else

            {

                createlink(name.input);

                strcat(name.input, link);
            
                	browseSong(name.input);

            }

        }

        else return 1;

    }

    else

    {

        if (exists (name.input) == 0)        
       
        {        
 
            	readLyrics(name.input);
        
            	strcat(name.input, link);
        
         	browseSong(name.input);
        
        }

        else

        {

            strcat(name.input, link);
        
         	browseSong(name.input);

        }

    }

}
