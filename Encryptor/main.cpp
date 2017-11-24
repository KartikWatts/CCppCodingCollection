#include <stdio.h>
#include <stdlib.h>

int main()
{
    int status;
   char ch, file_name[25];
   FILE *fp,*fp2;

   printf("Enter the name of file to Encrypt and delete\n");

   gets(file_name);

   fp = fopen(file_name,"r"); // read mode

   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   fp2 = fopen("Encrypted file","w");
    if(fp2 == NULL)
    {
        printf("Target File Could Not Be Found\n");
    }
    while(1)
    {
        ch = fgetc(fp);
        if(ch == EOF)
        {
            printf("\nFile has been Encrypted\n");
            break;
        }
        else
        {
            ch = ch - 5;
            fputc(ch, fp2);
        }
    }

     status = remove(file_name);

   if( status == 0 )
      printf("%s file deleted successfully.\n",file_name);
   else
   {
      printf("Unable to delete the file\n");
      perror("Error:");
   }

   fclose(fp);
    fclose(fp2);
   return 0;
}
