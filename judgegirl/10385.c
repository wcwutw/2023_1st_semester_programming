#include<stdio.h>
#include<string.h>

int main() {
	int n;
	scanf("%d", &n);
	char plate[n+2][n+2];
	for(int i=0;i<n*(n+1);i++) {
		//for(int j=0;j<n+1;j++) {
			char c;
			scanf("%c", &c);
			plate[i/(n+1)][i%(n+1)]=c;
		//}
	}
	int deg[n+2][n+2];
	memset(deg, 0, sizeof(deg));
	int fx[2], fy[2], fid=0;
	int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
	for(int zz=0;zz<n*n;zz++) {
		//for(int j=1;j<n+1;j++) {
		int i=zz/(n), j=zz%(n)+1;
		//if(plate[i][j]=='0') continue;
			for(int k=0;k<4;k++) {
				int nx=i+dx[k], ny=j+dy[k];
				//if(nx<0 || nx>=n || ny<1 || ny>n || plate[nx][ny]=='0') continue;
				deg[i][j]+=(!(nx<0 || nx>=n || ny<1 || ny>n || plate[nx][ny]=='0'));
			}
			((deg[i][j]==1 && plate[i][j]!='0')&&(fx[fid]=i));
			((deg[i][j]==1 && plate[i][j]!='0')&&(fy[fid]=j));
			((deg[i][j]==1 && plate[i][j]!='0')&&(fid++));
		//}
	}
	/*for(int i=0;i<n;i++) {
		for(int j=1;j<n+1;j++) {
			printf("%d ", deg[i][j]);
		}
		printf("\n");
	}
	printf("%d %d %d %d\n", fx[0], fy[0], fx[1], fy[1]);
	*/
	char str[n*n];
	int id=0, nx=fx[0], ny=fy[0];
	while(!(nx==fx[1] && ny==fy[1])) {
		str[id++]=plate[nx][ny];
		plate[nx][ny]='0';
		for(int k=0;k<4;k++) {
			int nnx=nx+dx[k], nny=ny+dy[k];
			!(nnx<0 || nnx>=n || nny<1 || nny>n || plate[nnx][nny]=='0')&&(nx=nnx);
			!(nnx<0 || nnx>=n || nny<1 || nny>n || plate[nnx][nny]=='0')&&(ny=nny);
			((!(nnx<0 || nnx>=n || nny<1 || nny>n || plate[nnx][nny]=='0'))&&(k=10));
		}
	}
	str[id++]=plate[fx[1]][fy[1]];
	char ans[id+1], str1[id+1], str2[id+1];
	/*for(int i=0;i<id;i++) {
		str1[i]=str[i];
		str2[i]=str[id-1-i];
	}*/
	for(int i=0;i<id;i++) {
        str1[i]=str[i];
        str2[i]=str[id-1-i];
    }
	str1[id]='\0';
	str2[id]='\0';
	//printf("\n%s\n%s\n", str1, str2);
	((str1[0]>str2[0] || (str1[0]==str2[0] && (fx[0]>fx[1] || (fx[0]==fx[1] && fy[0]>fy[1]))))&&(strcpy(ans, str2)));
	((!(str1[0]>str2[0] || (str1[0]==str2[0] && (fx[0]>fx[1] || (fx[0]==fx[1] && fy[0]>fy[1])))))&&(strcpy(ans, str1)));

	/*else {
		strcpy(ans, str1);
	}-*/
	printf("%s", ans);
}
