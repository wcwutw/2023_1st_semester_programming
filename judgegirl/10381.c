#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main() {
    char c;
    char tmp[105];
    char tablea[1005][105], tableb[1005][105];
    int tabaid=0, tabbid=0;
	int zid=0;
	while(scanf("%c", &c)!=EOF && c!='\n') {
           	((isupper(c)||islower(c))&&(tablea[tabaid][zid++]=c));
			((isupper(c)||islower(c))&&(tablea[tabaid][zid]=0));
           	((!isupper(c)&&!islower(c))&&(tabaid+=(zid!=0)));
           	((!isupper(c)&&!islower(c))&&(zid=0));

	}
	zid=0;
	while(scanf("%c", &c)!=EOF && c!='\n') {
		//if(isupper(c) || islower(c)) {
           	((isupper(c)||islower(c))&&(tableb[tabbid][zid++]=c));
			((isupper(c)||islower(c))&&(tableb[tabbid][zid]=0));
        //}
       	//else {
           	((!isupper(c)&&!islower(c))&&(tabbid+=(zid!=0)));
           	((!isupper(c)&&!islower(c))&&(zid=0));
		//	tabbid+=(zid!=0);
		//	zid=0;
		//}
	}
    int l=0, r=0;
    while(l<tabaid || r<tabbid) {
        //if(l==tabaid) {
            ((l==tabaid)&&(printf("%s", tableb[r])));
            ((l==tabaid)&&(r++));
        //}
        //else if(r==tabbid) {
            ((l!=tabaid && r==tabbid)&&(printf("%s", tablea[l])));
            ((l!=tabaid && r==tabbid)&&(l++));
        //}
        //else {
            ((l!=tabaid&&r!=tabbid&&strcmp(tablea[l], tableb[r])<0)&&(printf("%s", tablea[l])));
            ((l!=tabaid&&r!=tabbid&&strcmp(tablea[l], tableb[r])<0)&&(l++));
            ((l!=tabaid&&r!=tabbid&&strcmp(tablea[l], tableb[r])>=0)&&(printf("%s", tableb[r])));
            ((l!=tabaid&&r!=tabbid&&strcmp(tablea[l], tableb[r])>=0)&&(r++));
            /*if(strcmp(tablea[l], tableb[r])<0) {
                printf("%s", tablea[l]);
                l++;
            }
            else {
                printf("%s", tableb[r]);
                r++;
            }*/
        //}
    }
}
