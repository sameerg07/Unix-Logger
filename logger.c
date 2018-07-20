#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include <unistd.h>
#define MAX 52

void copy_process(long tgid) {
	char path[40],*temp,*p,*out,c[1000],*arr[1000];
	int i,len;
	FILE* statusf;
	for(i=0;i<1000;i++){
		arr[i] = (char*) malloc(sizeof(char)*20);
	out= (char*) malloc(sizeof(char)*100);
}	
	snprintf(path, 40, "/proc/%ld/stat", tgid);

	statusf = fopen(path, "r");
	if(!statusf)
		return;
	fscanf(statusf,"%[^\n]", c);
	p = strtok(c, " ");
	i=0;
	while(p!=NULL) {
		printf("%s",p);
		len = strlen(p);
		//printf("%d\n",i);
		strcpy(arr[i],p);
		printf("%s------------------------------------%s\n",p, arr[i]);
		i++;
		p = strtok(NULL, " ");	
	
				
}
	strcpy(out,arr[0]);
	strcat(out,"\t\t");
	strcat(out,arr[1]);
	strcat(out,"\t\t");
	strcat(out,arr[2]);
	strcat(out,"\t\t");
	strcat(out,arr[21]);
	strcat(out,"\t\t");
	strcat(out,arr[3]);
	strcat(out,"\t\t");
	strcat(out,arr[23]);
	strcat(out,"KB");
	strcat(out,"\t\t");
	strcat(out,arr[25]);
	strcat(out,"\n");
	FILE *final = fopen("log1.txt", "a");  
	  fprintf(final, "%s", out);  
	  fclose(final);


printf("%s\n\n\n\n\n\n\n",out);


for(i=0;i<MAX;i++)
{
	free(arr[i]);
}
free(out);

	
	fclose(statusf);
	
}
int main()
{
	FILE *final = fopen("log1.txt", "a");  
  	fprintf(final, "%s", "Pid\t\tP-Name\t\tStatus\t\tStarttime\t\tOwner\t\tMem-Usage\t\tstart\n");  
  	fclose(final);
	
	struct dirent* ent;
	long tgid;
	while(1){
		DIR* proc = opendir("/proc");
		if(proc == NULL) {
			perror("opendir(/proc)");
			return 1;
		}

		while(ent = readdir(proc)) {
		    if(!isdigit(*ent->d_name))
			continue;

		    tgid = strtol(ent->d_name, NULL, 10);

		    copy_process(tgid);
		}
	sleep(10);

}
	return(0);	
}
