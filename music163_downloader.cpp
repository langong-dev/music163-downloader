#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
	int tmp_i = 0;
	char URL[200];
	for (int i = 0; i < 200; i++)
		URL[i] = 0; //对URL进行清零
	char tmp[20];
	for (int i = 0; i < 20; i++)
		tmp[i] = 0; //对tmp进行清零
	cout<<"This program is for linux and build by Arch-Jason(on github). It's use to download music from music163!\npleas input the URL of your favourit music(the URL mast has \"/\"in the end):";
	cin>>URL;
	/*for (int i = 0; i < 200; i++)
		cout<<URL[i];*/
	for (int i = 0; i < 200; i++) //寻找歌曲id并保存进tmp数组
	{
		if (URL[i] == 'i' && URL[i+1] == 'd' && URL[i+2] == '=')
		{
			while(tmp_i < 20)
			{
				tmp[tmp_i] = URL[i+3];
				tmp_i++;
				i++;
			}
			break;
		}
		if (i == 197)
		{
			cout<<"Error!";
			return 0;
		}
	}
	/*for (int i = 0; i < 20; i++)
		cout<<tmp[i];*/
	char download_URL[100] = "http://music.163.com/song/media/outer/url?id=";
	/*for (int i = 0; i < 100; i++)
		cout<<download_URL[i];*/
	strcat(download_URL,tmp);
	char x[10] = ".mp3";
	strcat(download_URL,x);
	/*for (int i = 0; i < 100; i++)
		cout<<download_URL[i];*/
	char command[10] = "wget ";
	strcat(command,download_URL);
	system(command);
	return 0;
}
