#include<stdio.h>
#include<string.h>
int main() {
	long long n;
	scanf("%lld", &n);
	char* ans[105];
	char* mp[105];
	mp[1]="one";
	mp[2]="two";
	mp[3]="three";
	mp[4]="four";
	mp[5]="five";
	mp[6]="six";
	mp[7]="seven";
	mp[8]="eight";
	mp[9]="nine";
	mp[11]="eleven";
	mp[12]="twelve";
	mp[13]="thirteen";
	mp[14]="fourteen";
	mp[15]="fifteen";
	mp[16]="sixteen";
	mp[17]="seventeen";
	mp[18]="eighteen";
	mp[19]="nineteen";
	mp[21]="twenty-one";
mp[22]="twenty-two";
mp[23]="twenty-three";
mp[24]="twenty-four";
mp[25]="twenty-five";
mp[26]="twenty-six";
mp[27]="twenty-seven";
mp[28]="twenty-eight";
mp[29]="twenty-nine";
mp[31]="thirty-one";
mp[32]="thirty-two";
mp[33]="thirty-three";
mp[34]="thirty-four";
mp[35]="thirty-five";
mp[36]="thirty-six";
mp[37]="thirty-seven";
mp[38]="thirty-eight";
mp[39]="thirty-nine";
mp[41]="forty-one";
mp[42]="forty-two";
mp[43]="forty-three";
mp[44]="forty-four";
mp[45]="forty-five";
mp[46]="forty-six";
mp[47]="forty-seven";
mp[48]="forty-eight";
mp[49]="forty-nine";
mp[51]="fifty-one";
mp[52]="fifty-two";
mp[53]="fifty-three";
mp[54]="fifty-four";
mp[55]="fifty-five";
mp[56]="fifty-six";
mp[57]="fifty-seven";
mp[58]="fifty-eight";
mp[59]="fifty-nine";
mp[61]="sixty-one";
mp[62]="sixty-two";
mp[63]="sixty-three";
mp[64]="sixty-four";
mp[65]="sixty-five";
mp[66]="sixty-six";
mp[67]="sixty-seven";
mp[68]="sixty-eight";
mp[69]="sixty-nine";
mp[71]="seventy-one";
mp[72]="seventy-two";
mp[73]="seventy-three";
mp[74]="seventy-four";
mp[75]="seventy-five";
mp[76]="seventy-six";
mp[77]="seventy-seven";
mp[78]="seventy-eight";
mp[79]="seventy-nine";
mp[81]="eighty-one";
mp[82]="eighty-two";
mp[83]="eighty-three";
mp[84]="eighty-four";
mp[85]="eighty-five";
mp[86]="eighty-six";
mp[87]="eighty-seven";
mp[88]="eighty-eight";
mp[89]="eighty-nine";
mp[91]="ninety-one";
mp[92]="ninety-two";
mp[93]="ninety-three";
mp[94]="ninety-four";
mp[95]="ninety-five";
mp[96]="ninety-six";
mp[97]="ninety-seven";
mp[98]="ninety-eight";
mp[99]="ninety-nine";
	char* fast[7];
	fast[0]="\n";
	fast[1]="thousand";
	fast[2]="million";
	fast[3]="billion";
	fast[4]="trillion";
	fast[5]="quadrillion";
	fast[6]="quintillion";
	int nowid=0, cnt=0;
	while(n>0) {
		ans[nowid++]=fast[cnt];
		long long now=n%1000;
		long long hun=now/100;
		long long mud=now%100;
		ans[nowid++]=mp[mud];
		
		hun!=0&&(ans[nowid++]="hundred");
		hun!=0&&(ans[nowid++]=mp[hun]);
		cnt++;
		//ans[nowid++]=fast[cnt];
		n/=1000;
	}
	
	for(int i=nowid-1;i>=0;i--) {
		printf("%s ", ans[i]);
	}


}
