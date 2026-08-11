#include<stdio.h>
#include<unistd.h>
int main(){
pid_t pid;
pid = fork();
if(pid == 0) {
printf("Father\n");
}
else{
printf("Mother\n");
}
return 0;
}
