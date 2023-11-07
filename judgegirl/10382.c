#include<stdio.h>
#include<string.h>
 
int main() {
    int count[20];
    memset(count, 0, sizeof(count));
    char bad[9];
    bad[0]=' ';
    bad[1]='.';
    bad[2]=',';
    bad[3]='!';
    bad[4]='?';
    bad[5]=';';
    bad[6]=':';
    bad[7]='\n';
    char* mat[20]={
        "able", "ary", "ed", "ence", "ful", "hood", "ical", "ing", "ish", "ism", "ist", "ive", "ize", "less", "ly", "ment", "ness", "ous", "ship", "tion"
    };
    char c;
    char tmp[300005];
    char *tok;
    int id=0;
    while(scanf("%c", &c)!=EOF && c!='\0') {
        //if(c=='9' || c=='\0') break;
        ((bad[0]==c || bad[1]==c || bad[2]==c || bad[3]==c || bad[4]==c || bad[5]==c || bad[6]==c || bad[7]==c)&&(tmp[id++]='/'));
        ((!(bad[0]==c || bad[1]==c || bad[2]==c || bad[3]==c || bad[4]==c || bad[5]==c || bad[6]==c || bad[7]==c))&&(tmp[id++]=c));
        //else if(c=='-') tmp[id++]='x';
        //else tmp[id++]=c;
    }
    tmp[id++]='/';
    tmp[id]='\0';
    //for(int i=0;i<id;i++) printf("%c", tmp[i]);
    tok=strtok(tmp, "/");
    //printf("\n");
    char prefix[]="zzz";
    char now[100005];
    for(int i=0;tok!=NULL;i++) {
        strcpy(now, prefix);
        //printf("%s\n", tok);
        strcat(now, tok);
        //printf("%s\n", now);
        for(int j=0;j<20;j++) {
            char* tar=mat[j];
            int len=strlen(tar);
            char dest[len];
            int nowlen=strlen(now);
printf("\n");           
            //#ifdef LOCAL
            //printf("nowlen: %d\nlen: %d\n", nowlen, len);
            //#endif
            int flag=1;
            for(int k=0;k<len;k++) {
                dest[nowlen-len+k]=now[nowlen-len+k];
                ((dest[nowlen-len+k]!=tar[k])&&(flag=0));
                //printf("%c ", dest[nowlen-len+k]);
                //printf("%c", tar[k]);
                //printf("\n");
            }
            //printf("\n");
            //if(strcmp(dest, tar)==0) count[j]++;
            count[j]+=flag;
        }
        tok=strtok(NULL, "/");
        //printf("%s\n", tok);
    }
    for(int i=0;i<20;i++) {
        //printf("%d\n", count[i]);
        //if(count[i]==0) continue;
        count[i]!=0&&(printf("%s:\nFrequency: %d\n", mat[i], count[i]));
    }
}
