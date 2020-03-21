#include<stdio.h>
#include<string.h>
#include<conio.h>

int main( int argc, const char *argv[] )
{

	FILE *fp1, *fp2,*fp3 ,*rm_fp1,*rm_fp2;
	char ch;
	
	int i = 0, count=0;
  	char ch1[100];
	
if(argc<3)
{
 printf("maximum 2 file name you have to pass");
}
else if(argc>3)
{
	printf("2 arguments expected");             
}

else
{
	fp1 = fopen(argv[1],"r");  //to take the input file
	fp2 = fopen("temp.c","w");// to take the output file
	
	
//*************************************************************************************************

	
	 
	while((ch=fgetc(fp1))!=EOF)
	{
        //memset(ch1,0,100);
		if(ch=='#')
		{
			
			ch=fgetc(fp1);
			if(ch=='i')
			{
				
				while((ch=fgetc(fp1))!='"');
			
			}
		
			if(ch=='"')
			{
				while((ch=fgetc(fp1))!='"')
				{
					ch1[i]=ch;
					i++;
					
				}
                            ch1[i]='\0';

				for(i=0;i<count;i++);
				
			}
			
                	fp3=fopen(ch1,"r");
			
                	ch = fgetc(fp3);
			ch= fputc(ch,fp2);
			while((ch=fgetc(fp3))!=EOF)
			{
				ch= fputc(ch,fp2);
				
			}
			ch=fputc(' ',fp2);

                     
				
			
		}



	ch=fputc(ch,fp2);
	
		
	}
fclose(fp2);
fclose(fp1);

//**********************************************************************************************************
char rm_ch, rm_ch2;
int flag = 0;
rm_fp1=fopen("temp.c","r");
rm_fp2=fopen(argv[2],"w");

	while((rm_ch=fgetc(rm_fp1))!=EOF) // read the whole file
	{
		
		if(rm_ch=='/')         // check the first slash
		{
			flag = 0;     
			rm_ch = fgetc(rm_fp1);     // flag will be 0 and continously read until it get 2nd slash
			if(rm_ch=='/')           //checking for 2nd slash
			{
				flag = 1;
				while((rm_ch=fgetc(rm_fp1))!='\n');       // condition true flag will be 1 now and it read until new line 
		
				
			}
			if(rm_ch == '*')                         //check for * after /
			{
				flag = 1;
				while((rm_ch=fgetc(rm_fp1))!=EOF)     // read upto end of file
				{
			
					if((rm_ch=fgetc(rm_fp1))=='*'  && (rm_ch= fgetc(rm_fp1))=='/')   //while reading it will check for  anotehr * and /
					{
						
						rm_ch='\n';    //if condition true it will insert next line instead of multi line
						break;    

					}
				}
			}
			
		
		if(flag==0)       //while the flag is 0
		rm_ch2 = fputc('/',rm_fp2);      // it will put same slash there
		
		}                    // main if condition over
		
//******************************************************************************************************

		rm_ch=fputc(rm_ch,rm_fp2);         // it will continuosly read file and copy to output file


//***********************************************************************************************************

		if(rm_ch=='"')              // it will check if double slash is in printf
		{
			while((rm_ch=fgetc(rm_fp1))!='"')     // if condition true it will read upto next inverted comma
			{
				rm_ch = fputc(rm_ch,rm_fp2);      // it will put all the character in output file
			}
			
			rm_ch = fputc('"',rm_fp2);		 //it will put last inverted comma also in output file
					
		}
		
	}
fclose(rm_fp2);
fclose(rm_fp1);
remove("temp.c");	
}

	


getch();
}







	
	
	

	
