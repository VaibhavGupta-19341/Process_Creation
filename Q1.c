#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define BUFFSIZE 1024

int main()
{
	

	pid_t pid = fork();
	char buff[BUFFSIZE];


	if(pid == 0)
	{
		FILE *fp = fopen("marks.csv","r");
	if(!fp)
	{
		printf("file does not exist");
		return 0;
	}
		printf("\nChild Process\n");
		int row_count = 0, field_count = 0;

		int stu_id;
		char sec[2];
		float ass_1;
		float ass_2;
		float ass_3;
		float ass_4;
		float avg;

		int i=0;
		while(fgets(buff,BUFFSIZE,fp))
		{
			//printf("%s\n", buff);
			field_count =0;
			row_count++;
			if(row_count == 1)
				continue;

			char *field = strtok(buff," ");
			while(field)
			{
				if(field_count == 0)
					stu_id = atoi(field);

				if(field_count == 1)
					strcpy(sec,field);

				if(field_count == 2)
					ass_1 = atoi(field);

				if(field_count == 3)
					ass_2 = atoi(field);

				if(field_count == 4)
					ass_3 = atoi(field);

				if(field_count == 5)
					ass_4 = atoi(field);

				field = strtok(NULL," ");
				field_count++;
			}

			if(sec[0] == 'A')
			{
				avg = (float) ((ass_1 + ass_2 + ass_3 + ass_4)/4.0);
				printf("%d\t%s\t%f\n",stu_id,sec,avg);
			}

			i++;
		}
		fclose(fp);
		printf("\nChild process complete\n");
		exit(3);
	}

	
	
		int status;
		pid_t cp = waitpid(pid,&status,0);


		if(WIFEXITED(status))
		{
			FILE *fp = fopen("marks.csv","r");
	if(!fp)
	{
		printf("file does not exist");
		return 0;
	}
			printf("\nParent process\n");
			int row_count = 0, field_count = 0;

			int stu_id;
			char sec[2];
			float ass_1;
			float ass_2;
			float ass_3;
			float ass_4;
			float avg;

			int i=0;
			while(fgets(buff,BUFFSIZE,fp))
			{
				//printf("%s\n", buff);
				field_count =0;
				row_count++;
				if(row_count == 1)
					continue;

				char *field = strtok(buff," ");
				while(field)
				{
					if(field_count == 0)
						stu_id = atoi(field);

					if(field_count == 1)
						strcpy(sec,field);

					if(field_count == 2)
						ass_1 = atoi(field);

					if(field_count == 3)
						ass_2 = atoi(field);

					if(field_count == 4)
						ass_3 = atoi(field);

					if(field_count == 5)
						ass_4 = atoi(field);

					field = strtok(NULL," ");
					field_count++;
				}

				if(sec[0] == 'B')
				{
					avg = (float) ((ass_1 + ass_2 + ass_3 + ass_4)/4.0);
					printf("%d\t%s\t%f\n",stu_id,sec,avg);
				}

				i++;
			}
			fclose(fp);
			printf("\nParent process complete\n");
		}
	

	

	return 0;
}