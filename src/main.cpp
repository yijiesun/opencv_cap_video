#include <stdio.h>
#include <termio.h>
#include <stdio.h>
#include <stdlib.h>
#include "include.h"
#include "functions.h"
#include "config.h"
#include <iostream> 
#include <pthread.h>


#define   NR(x)   (sizeof(x)/sizeof(x[0]+0))
//定义枚举Keyboard的键值数据 

enum
{
	UP = 87,
	UP_ = 119,
	DOWN = 83,
	DOWN_ = 115,
	LEFT = 65,
	LEFT_ = 97,
	RIGHT = 68,
	RIGHT_ = 100,
	ENTER = 13,
	ESC = 27,
	K_= 75,
	K__=107,
	T_=84,
	T__=116,
};

char *capMenu[200] =
{
	"＊ 采集中...                      ＊",
	"＊ 返回                           ＊",
};
char *mainMenu[200] =
{
	"＊ 1  启动采集              ＊",
	"＊ 2  参数配置              ＊",
	"＊ 3  退出                  ＊",
};
char *paramMenu[200] =
{
	"＊ 1  frame_downsampling_percent            ＊",
	"＊ 2  continues_frame_goal_cnt              ＊",
	"＊ 3  返回                                  ＊",
};

#define DEVNAME "/dev/input/event4"

int fd_kbd;
bool isStart;
bool quit;
string videoFileName;

void *cap_process(void *threadarg)
{
	isStart=false;
	VideoCapture cap;
	VideoWriter outputVideo;
	Mat frame;
	Config cfg("..//config.txt");
	int video_width=static_cast<int>(cfg.get_param("video_width"));
	int video_height=static_cast<int>(cfg.get_param("video_height"));
	int fps=static_cast<int>(cfg.get_param("fps"));
	int cap_num=static_cast<int>(cfg.get_param("cap_num"));
	string show_log_fps,show_log_w,show_log_h,externShowLog;
	show_log_fps="fps:";
	show_log_fps+=int2string(fps);
	show_log_w="video_width: ";
	show_log_w+=int2string(video_width);
	show_log_h="video_height:";
	show_log_h+=int2string(video_height);
	externShowLog="";

	bool isOpen = cap.open(cap_num);
	if(!isOpen)
	{
		cout<<"\n\nopen camera fail"<<endl;
		pthread_exit(NULL);
	}
	bool caping=false;
	string videoFileName="../data/";
	videoFileName+=getCurrentDate();
	videoFileName+=".avi";
	while (!quit)
	{

		if(!caping&&isStart)
		{
			outputVideo.open(videoFileName, VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, Size(video_width, video_height));// 配置输出视频文件
			externShowLog=videoFileName;
			caping=true;

		}
		cap >> frame;
		if(!isStart&&caping)
		{
			caping=false;
			outputVideo.release();
		}

		if(caping)
		{
			outputVideo.write(frame);// 将该帧写入视频文件
			circle(frame,Point(20,20),4,Scalar(0,0,255),20);
		}
		putText(frame,show_log_fps.c_str(),Point(50,20),FONT_HERSHEY_COMPLEX,0.5,Scalar(0, 255, 0),1);
		putText(frame,show_log_w.c_str(),Point(50,40),FONT_HERSHEY_COMPLEX,0.5,Scalar(0, 255, 0),1);
		putText(frame,show_log_h.c_str(),Point(50,60),FONT_HERSHEY_COMPLEX,0.5,Scalar(0, 255, 0),1);
		putText(frame,externShowLog.c_str(),Point(50,80),FONT_HERSHEY_COMPLEX,0.5,Scalar(0, 255, 0),1);

		imshow("Recording...", frame);// 展示图片
		int k=waitKey(100);
		if(k==K_||k==K__)
		{
			isStart=true;
		}
		else if(k==T_||k==T__)
		{
			isStart=false;
		}
		else if(k==LEFT||k==LEFT_)
		{
			quit=true;
		}
		//printf("key:%d\n",k);

		 if (quit)
		{
			outputVideo.release();
			cap.release();
			destroyWindow("Recording...");
		}
		
		

    }
}

class Menu {
private:

	int paramLength;
	float paramValueList[10];
	int menuStatus;//0-out;1-main;2-启动采集;3-采集中；4-param
	int ret;
	int mainIndex;
	int capIndex;
	int paramIndex;
	bool isOut;
public:
	Menu() {
		menuStatus = 1;
		mainIndex = 0;
		capIndex=0;
		paramIndex = 0;
		isOut = false;
	};
	~Menu() {
		cout<<endl;
	};
	//获取用户输入的接口 
	int  get_userinput(int *index, int size)
	{
		int ch;
	    ch =scanKeyboard();
		switch (ch)
		{
			//上 
			//如果选择上，那么光标向上移动 
		case UP_:
		case UP: if (*index > 0)  *index -= 1;  break;
			//下 
			//如果选择下，那么光标向下移动 
		case DOWN_:
		case DOWN:if (*index < size - 1)  *index += 1;  break;
			//左 
		case LEFT_: return LEFT;
		case LEFT: return LEFT;
			//右 
		case RIGHT_:return ENTER;
		case RIGHT:return ENTER;
			//回车 
		case ENTER: return ENTER;
			//ESC
		case ESC: return ESC;
		case K_:
		case K__:return K_;
		case T_:
		case T__:return T_;
		}
		return 0;
	}

	void run()
	{
		
		const char * split = " ";
		char **paramList;
		paramList = (char **)malloc(sizeof(char *) * 10);
		for (int i = 0; i < 10; i++)
			paramList[i] = (char *)malloc(sizeof(char) * 200);

		Config cfg("..//config.txt");
		cfg.readConfig(paramLength, paramList, paramValueList);
		paramList[paramLength++] = "返回";

		float frame_downsampling_percent;
		int cnt;
		int menu_size = 0;
		char **menu = mainMenu;
		int *index = &mainIndex;
		char *capingMenu;
		capingMenu = (char *)malloc(sizeof(char ) * 200);
		while (!isOut)
		{
			string fileName="..//data//";
			string menuName="";
			//状态显示
			//0-out;1-main;2-sub;3-param
			switch (menuStatus)
			{
			case 0:
				isOut = true;
				break; //退出
			case 1:
				menu_size = 3;
				menu = mainMenu;
				index = &mainIndex;
				break;  	//主界面
			case 3://采集中
				menu_size = 2;
				menu = capMenu;
				index = &capIndex;
				break;
			case 4:
				menu_size = paramLength;
				menu = paramList;
				index = &paramIndex;
				break;  	//参数配置界面
			}
			if(menuStatus==2)
			{
				menuStatus=3;
				menu_size = 2;
				fileName+=getCurrentDate();
				fileName+=".avi";
				menuName="采集预览启动，按K键开始，T键结束";
				memcpy(capingMenu,menuName.c_str(),200*sizeof(char));
				capMenu[0]=capingMenu;

				menu = capMenu;
				index = &capIndex;
				pthread_t threads_cap;
				pthread_create(&threads_cap, NULL, cap_process, NULL);
			}
			show(menu, menu_size, *index);
			ret = get_userinput(index, menu_size);

			//按键处理
			if (ret == ESC)
				break;
			else if (ret == ENTER)
			{
				switch (menuStatus)
				{
				case 1://主界面
					switch (mainIndex)
					{
					case 0: menuStatus = 2; quit=false;     break;  	//启动项目
					case 1:	menuStatus = 4;	     break;  	//参数配置
					case 2: isOut = true;        break;    //返回
					}
					break; 
				case 3://采集中
					switch (capIndex)
					{
					case 0:                                         break; 
					case 1: 
						menuStatus = 1;   
						quit=true;
						break;    //返回
					}
					break; 
				case 4://参数配置界面
					if (paramIndex == paramLength - 1)
					{
						menuStatus = 1;
						break;
					}
					char paramTmp[200];
					memcpy(paramTmp, paramList[paramIndex],200);
					strtok(paramTmp, split);
					float paramValue= cfg.get_param(paramTmp);

					float new_value=0;
					cout << "\n\n\n请输入新的参数:  ";
					scanf("%f", &new_value);
					cfg.set_param(paramTmp, new_value);
					cfg.openFile("r");
					cfg.readConfig(paramLength, paramList, paramValueList);
					paramList[paramLength++] = "返回";
					break;
				}

			}
			else if (ret == LEFT)
			{
				switch (menuStatus)
				{
				case 1://主界面
					isOut = true;
					break;
				case 3://采集中
						quit=true;
						menuStatus = 1;
						break;
				case 4://参数配置界面
					menuStatus = 1;
					break;
				}
			}
			else if(ret==K_)
				isStart=true;
			else if(ret==T_)
				isStart=false;
		}
		if(paramList)
		{
			free(paramList);
			paramList=NULL;
		}
		free(capingMenu);
		capingMenu=NULL;
		cfg.clearBlank();
		cfg.closeFile();
		menu=NULL;
		index=NULL;
	};

	int scanKeyboard()
	{
		int in;
		struct termios new_settings;
		struct termios stored_settings;
		tcgetattr(0,&stored_settings);
		new_settings = stored_settings;
		new_settings.c_lflag &= (~ICANON);
		new_settings.c_cc[VTIME] = 0;
		tcgetattr(0,&stored_settings);
		new_settings.c_cc[VMIN] = 1;
		tcsetattr(0,TCSANOW,&new_settings);
		
		in = getchar();
		
		tcsetattr(0,TCSANOW,&stored_settings);
		return in;
	}

	void show(char **menu, int size, int index)
	{
	int i;
		system("clear");

		for (i = 0; i < size; i++)
		{
			//如果i==index表示在当前选项的位置，默认初始化显示是第一项，显示为红色，
			//当按下上下按键选择的时候，光标会移动，也就看到了列表选择的现象 
			if (i == index)
			{
				//红色 
				string tmp="\033[";
				tmp+=int2string(i+5);
				tmp+=";10H";
				tmp+=RED;
				tmp+="%s";
				printf(tmp.c_str(), menu[i]);
			}
			//否则显示为白色 
			else
			{
				//白色 
				string tmp="\033[";
				tmp+=int2string(i+5);
				tmp+=";10H";
				tmp+=WHITE;
				tmp+="%s";
				printf(tmp.c_str(), menu[i]);
			}
		}
	}


};


int main(int argc,char** argv)
{
	isStart=false;
	quit=false;
	Menu menu;
	menu.run();
	return 0;
}