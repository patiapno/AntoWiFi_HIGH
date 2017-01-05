#include <Arduino.h>
#include <Wire.h>
#include <Ciao.h>

class AntoWiFi{
	public: 
	   AntoWiFi(const char* key);
	   
	   void AntodigitalGet(int pin,const char* anto_thing,const char* anto_ch);
	   
	   void AntosetString(const char* anto_thing,const char* anto_ch
	   ,String myString);
	   
	   void AntogetString(const char* anto_thing,const char* anto_ch);
	   
	   void AntodataService(const char* anto_service);
   	
    private:
   		String CutData(int count,char cdms[]);
   		String rawString; //rawData
   		String CutString; //CutString
    public:
    	String readString;
    	String status;
};