#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main() {
    char* mat[12]={
        "if", "else", "while", "for", "switch", "case", "break", "return", "void", "int", "float", "char"   };
    char c;
    char tmp[500005];
    char *tok;
    int id=0;
    while(scanf("%c", &c)!=EOF && c!='\0') {
       // if(c=='9' || c=='\0') break;
        ((isdigit(c) || c=='_' || isalpha(c))&&(tmp[id++]=c));
        ((!(isdigit(c) || c=='_' || isalpha(c)))&&(tmp[id++]='/'));
    }
    tmp[id]='\0';
    //for(int i=0;i<id;i++) printf("%c", tmp[i]);
    tok=strtok(tmp, "/");
    char now[39][27];
	int nid=0;
    for(int i=0;tok!=NULL;i++) {
		//printf("%s\n", tok);
        int flag=1;
		for(int j=0;j<12;j++) {
			char* tar=mat[j];
			((strcmp(tar, tok)==0 || isdigit(tok[0]))&&(flag=0));
			((strcmp(tar, tok)==0 || isdigit(tok[0]))&&(j=13));
			((strcmp(tar, tok)==0 || isdigit(tok[0]))&&(tok=strtok(NULL, "/")));

		}
		if(!flag || isdigit(tok[0])) continue;
        int j;
		for(j=0;j<24 && j<strlen(tok);j++) {
			now[nid][j]=tok[j];
		}
		now[nid][j]='\0';
		nid++;
		tok=strtok(NULL, "/");
	}
	int ava[nid];
	memset(ava, 1, sizeof(ava));
    for(int i=0;i<nid;i++) {
		char* str=now[i];
		int cnt=1;
        for(int j=i+1;j<nid;j++) {
			((ava[i] && ava[j] && strcmp(str, now[j])==0)&&(cnt++));
			((ava[i] && ava[j] && strcmp(str, now[j])==0)&&(ava[j]=0));

			//	cnt++;
			//	ava[j]=0;
			
		}
		//printf("%d\n", count[i]);
        ((ava[i])&&(printf("%s %d\n", str, cnt)));
    }
}
