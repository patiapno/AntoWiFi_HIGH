#include <Wire.h>
#include <Ciao.h>
#include "AntoWiFi.h"

#define driver "rest"
#define host "api.anto.io"

#define WIFI_GET "/channel/get/"
#define WIFI_SET "/channel/set/"

#define WIFI_BAD "BadReauest"
#define WIFI_ERROR "Error"

const char* anto_key;

AntoWiFi::AntoWiFi(const char* key)
{
	anto_key=key;
}
String AntoWiFi::CutData(int count,char cdms[])
{
	String Cut1,Cut2[4];
	int i,y;
	for(y=0;y<count;y++)
	{
		if(cdms[y]=='{'||cdms[y]=='"')
		{
			continue;
		}
		else
		{
			Cut1+=cdms[y];
		}
	}
	int j=Cut1.length();
	char cdms2[j];
	Cut1.toCharArray(cdms2,j);
	
	for(i=0;i<4;i++)
	{
		for(y=0;y<j;y++)
		{
			if(cdms2[y]==':'||cdms2[y]==',')
			{
				i+=1;
			}
			else if(cdms2[y]==' ')
			{
				i=5;
				y=j+1;
			}
			else
			{
				Cut2[i]+=cdms2[y];
			}
		}
	}
	return Cut2[3];
}
void AntoWiFi::AntodigitalGet(int pin,const char* anto_thing
,const char* anto_ch)
{
	String request=WIFI_GET;
	request+=anto_key;
	request+="/";
	request+=anto_thing;
	request+="/";
	request+=anto_ch;
	
	CiaoData data=Ciao.read(driver,host,request,"GET");
	if(!data.isEmpty())
	{
		String a=data.get(1);
		if(a=="400"||a=="404")
		{
			readString=WIFI_BAD;
		}
		else
		{
			CutString=data.get(2);
			int count=CutString.length();
			char cdms[count];
			CutString.toCharArray(cdms,count);
			readString=CutData(count,cdms);
		}
	}
	else
	{
		readString=WIFI_ERROR;
	}
	
	if(readString=="0")
	{
		digitalWrite(pin,LOW);
		status="DeviceOff";
		Ciao.println(status);
	}
	else if(readString=="1")
	{
		digitalWrite(pin,HIGH);
		status="DeviceOn";
		Ciao.println(status);
	}
	else
	{
		status="DeviceExcption";
		Ciao.println(status);
	}
}

void AntoWiFi::AntogetString(const char* anto_thing,const char* anto_ch)
{
	String request=WIFI_GET;
	request+=anto_key;
	request+="/";
	request+=anto_thing;
	request+="/";
	request+=anto_ch;
	
	CiaoData data=Ciao.read(driver,host,request,"GET");
	if(!data.isEmpty())
	{
		String a=data.get(1);
		if(a=="400"||a=="404")
		{
			readString=WIFI_BAD;
		}
		else
		{
			CutString=data.get(2);
			int count=CutString.length();
			char cdms[count];
			CutString.toCharArray(cdms,count);
			readString=CutData(count,cdms);
		}
	}
	else
	{
		readString=WIFI_ERROR;
	}
}

void AntoWiFi::AntosetString(const char* anto_thing,const char* anto_ch,
String myString)
{
	String url=WIFI_SET;
	url+=anto_key;
	url+="/";
	url+=anto_thing;
	url+="/";
	url+=anto_ch;
	url+="/";
	url+=myString;
	
	CiaoData data=Ciao.write(driver,host,url,"GET");
	if(!data.isEmpty())
	{
		String a=data.get(1);
		if(a=="400"||a=="404")
		{
			status=WIFI_BAD;
		}
		else
		{
			status="WriteOk";
		}
	}
	else
	{
		status=WIFI_ERROR;
	}
}

void AntoWiFi::AntodataService(const char* anto_service)
{
	String request="/request/";
	request+=anto_key;
	request+="/";
	request+=anto_service;
	
	CiaoData data=Ciao.read(driver,host,request,"GET");
	if(!data.isEmpty())
	{
		String a=data.get(1);
		if(a=="400"||a=="404")
		{
			status=WIFI_BAD;	
		}
		else
		{
			CutString=data.get(2);
			int count=CutString.length();
			char cdms[count];
			CutString.toCharArray(cdms,count);
			status=CutData(count,cdms);
		}
	}
	else
	{
		status=WIFI_ERROR;
	}
}
