#include<unistd.h>
#include<string.h>
void wr(char*s)
{
	write(1,s,strlen(s));
}
int main(int d, char**a){
	if (d !=3) return -1;wr(a[1]);wr(a[2]);wr("\n");return 2;
}