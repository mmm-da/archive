#include <stdio.h>
#include <io.h>

int main()
{
    FILE *f, *tmp;
    char name[255];
    char tmpname[255];
    int t;
    long max_pos;
    int max;
    printf("Enter file name: ");
    scanf("%s", name);
    printf("Enter temp file name: ");
    scanf("%s", tmpname);
    int state,i;
    if ((f = fopen(name, "r+b"))!=NULL && (tmp = fopen(tmpname, "w+b"))!=NULL)
	{
        state=1;
        while (state)
		{
            max = 0;
            i=0;
            while ((state = fread(&t, sizeof(int), 1, f)) != 0 && t!=0)
			{
                if (t>max) {
                    max = t;
                    max_pos = ftell(f);
                }
                i++;
                printf(" %d ",t);
            }
            if (i!=0)
            {
            fseek(f, max_pos, SEEK_SET);
            printf("\nfseek ");
            while ((state = fread(&t, sizeof(int), 1, f)) != 0 && t!=0)
			{
                fwrite(&t, sizeof(int), 1, tmp);
                
            }
	    fseek(tmp,1*sizeof(int),SEEK_CUR);
            }
        }
        fseek(tmp,1*sizeof(int),SEEK_CUR);
        fclose(f);
        fclose(tmp);
        remove(name);
        rename(tmpname,name);
	printf("\ndone!");
    }
	else printf("\nerr!");
    }

