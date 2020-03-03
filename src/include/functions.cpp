#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<stdio.h>
#include <iostream>
#include <string>
#include<sstream>
#ifdef win32
#include <windows.h>
#else
#include <sys/time.h>
#include <sys/timeb.h>
#include <sys/stat.h>
#endif
#include<time.h>
#include "functions.h"

using namespace cv;
using namespace std;

string fp2string(float Num)
{
	ostringstream oss;
	oss << Num;
	string str(oss.str());
	return str;
}

string int2string(int Num)
{
	ostringstream oss;
	oss << Num;
	string str(oss.str());
	return str;
}

//h.m.s.ms
string getCurrentDate()
{
	string date;
	char date_char[7][100];
#ifdef win32
	SYSTEMTIME tm;
	GetLocalTime(&tm);

	sprintf(date_char[0],"%d", tm.wHour);
	sprintf(date_char[1], "%d", tm.wMinute);
	sprintf(date_char[2], "%d", tm.wSecond);
	sprintf(date_char[3], "%d", tm.wMilliseconds);

#else

	struct  tm      *ptm;
    struct  timeb   stTimeb;
    ftime(&stTimeb);
    ptm = localtime(&stTimeb.time);
	sprintf(date_char[0],"%d", ptm->tm_year+1900);
	sprintf(date_char[1], "%d", ptm->tm_mon+1);
	sprintf(date_char[2],"%d", ptm->tm_mday);
	sprintf(date_char[3],"%d", ptm->tm_hour);
	sprintf(date_char[4], "%d", ptm->tm_min);
	sprintf(date_char[5], "%d",  static_cast<int>(ptm->tm_sec));
	sprintf(date_char[6], "%d", static_cast<int>(stTimeb.millitm));

#endif
	date = date_char[0];
	date += "_";
	date += date_char[1];
	date += "_";
	date += date_char[2];
	date += "_";
	date += date_char[3];
	date += "_";
	date += date_char[4];
	date += "_";
	date += date_char[5];
	date += "_";
	date += date_char[6];
	return date;
}

double what_time_is_it_now_s()
{
#ifdef win32
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	return (double)tm.wSecond + (double)tm.wMilliseconds * 0.001;
#else
	 struct timeval time;
    if (gettimeofday(&time,NULL)){
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
#endif
return 0;
}