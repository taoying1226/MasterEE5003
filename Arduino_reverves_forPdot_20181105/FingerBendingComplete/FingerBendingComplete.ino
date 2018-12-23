/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/


//-------------------------------------------  variables for signal 1------------------------------------------------
float voltage1 = 0;
float maxpulse1=0;
float maxpulse1print1=0;
int continouspulse1=0;
int innercount1=0;
// Threshold for signal 1 ---- needs to be changed depending on the person
float threshold11=1.9;   //low
float threshold21=1.6;   // medium
float threshold31=1.4;  // high
float thresholdabove1=2.0;   // release th

//-------------------------------------------  variables for signal 2------------------------------------------------
float voltage2 = 0;
float maxpulse2=0;
float maxpulse1print2=0;
int continouspulse2=0;
int innercount2=0;
// Threshold for signal 1 ---- needs to be changed depending on the person
float threshold12=1.6;
float threshold22=1.5;
float threshold32=1.9;
float thresholdabove2=2.3;//release


//-------------------------------------------  variables for signal 3------------------------------------------------

float voltage3 =0;
float maxpulse3=0;
float maxpulse1print3=0; 
int continouspulse3=0;  
int innercount3=0;  
// Threshold for signal 3 ---- needs to be changed depending on the person
float threshold13=2;   //medium
float threshold23=1.3;   // highest
float threshold33=1.9;  // lowest
float thresholdabove3=2.0;   // release th

  
 //-------------------------------------------  variables for signal 4------------------------------------------------
float voltage4 = 0;
float maxpulse4=0;
float maxpulse1print4=0;
int continouspulse4=0;
int innercount4=0;
// Threshold for signal 4 ---- needs to be changed depending on the person
float threshold14=2;   //medium
float threshold24=1.1;   // highest
float threshold34=1.8;  // lowest
float thresholdabove4=2.1;   // release th



//-------------------------------------------  variables for signal 5------------------------------------------------
float voltage5 = 0;
float maxpulse5=0;
float maxpulse1print5=0;
int continouspulse5=0;
int innercount5=0;
// Threshold for signal 5 ---- needs to be changed depending on the person
float threshold15=2;   //medium
float threshold25=1.7;   // highest
float threshold35=2.05;  // lowest
float thresholdabove5=2.2;   // release th



//-------------------------------------------  variables for signal 6------------------------------------------------
float voltage6 = 0;
float maxpulse6=0;
float maxpulse1print6=0;
int continouspulse6=0;
int innercount6=0;
// Threshold for signal 4 ---- needs to be changed depending on the person
float threshold16=2;   //medium
float threshold26=1.8;   // highest
float threshold36=1.6;  // lowest
float thresholdabove6=2.4;   // release th



// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  

  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  int sensorValue4 = analogRead(A3);
  int sensorValue5 = analogRead(A4);
  int sensorValue6 = analogRead(A5);

  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
 voltage1 = sensorValue1 * (5.0 / 1023.0);
 voltage2 = sensorValue2 * (5.0 / 1023.0);
 voltage3 = sensorValue3 * (5.0 / 1023.0);
 voltage4 = sensorValue4 * (5.0 / 1023.0);
 voltage5 = sensorValue5 * (5.0 / 1023.0);
 voltage6 = sensorValue6 * (5.0 / 1023.0);

//-------------------------------------------------------- Detection and pre-processing of voltage 1---------------------------------------------------------
//continouspulse1=0;
if(innercount1 == 0){
  if(voltage1<threshold11){
    innercount1 = 1;
    maxpulse1=threshold11;
    continouspulse1=0;
  }
}

if(innercount1==1){
   if(voltage1 < maxpulse1)
   {
      maxpulse1=voltage1;
   }
   else
   {
      if(maxpulse1 < threshold11 && maxpulse1 >= threshold21)
      {//Use threshold1 if three bending degree needed.
          continouspulse1 = 1;//lower bending
      }
      else if(maxpulse1 < threshold21 && maxpulse1 >= threshold31)
      {
          continouspulse1 = 2;//medium bending
      }
      else if(maxpulse1 < threshold31)
      {
           continouspulse1 = 3;//higher bending
      }
    }


if(voltage1 > thresholdabove1){  
    innercount1 = 0;
    continouspulse1 = 0;
}
  
  }


//-------------------------------------------------------- Detection and pre-processing of voltage 2---------------------------------------------------------
if(innercount2 == 0){
  if(voltage2<threshold32){
    innercount2 = 1;
    maxpulse2=threshold32;
    continouspulse2=0;
  }
}

if(innercount2==1){
   if(voltage2 < maxpulse2)
   {
      maxpulse2=voltage2;
   }
   else
   {
      if(maxpulse2 < threshold32 && maxpulse2 > threshold12)
      {//Use threshold1 if three bending degree needed.
          continouspulse2 = 1;//lower bending
      }
      else if(maxpulse2 < threshold12 && maxpulse2 > threshold22)
      {
          continouspulse2 = 1;//medium bending
      }
      else if(maxpulse2 < threshold22)
      {
           continouspulse2 = 2;//higher bending
      }
    }


if(voltage2 > thresholdabove2){  
    innercount2 = 0;
    continouspulse2 = 0;
}
  
  }


//-------------------------------------------------------- Detection and pre-processing of voltage 3---------------------------------------------------------
if(innercount3 == 0){
  if(voltage3 < threshold33){
    innercount3 = 1;
    maxpulse3=threshold33;
    continouspulse3=0;
  }
}

if(innercount3==1){
   if(voltage3 < maxpulse3)
   {
      maxpulse3=voltage3;
   }
   else
   {
      if(maxpulse3 < threshold33 && maxpulse3 > threshold13)
      {//Use threshold1 if three bending degree needed.
          continouspulse3 = 1;//lower bending
      }
      else if(maxpulse3 < threshold13 && maxpulse3 > threshold23)
      {
          continouspulse3 = 1;//medium bending
      }
      else if(maxpulse3 < threshold23)
      {
           continouspulse3 = 2;//higher bending
      }
    }


if(voltage3 > thresholdabove3){  
    innercount3 = 0;
    continouspulse3 = 0;
}
  
  }


//-------------------------------------------------------- Detection and pre-processing of voltage 4---------------------------------------------------------
if(innercount4 == 0){
  if(voltage4<threshold34){
    innercount4 = 1;
    maxpulse4=threshold34;
    continouspulse4=0;
  }
}

if(innercount4==1){
   if(voltage4 < maxpulse4)
   {
      maxpulse4=voltage4;
   }
   else
   {
      if(maxpulse4 < threshold34 && maxpulse4 > threshold14)
      {//Use threshold1 if three bending degree needed.
          continouspulse4 = 1;//lower bending
      }
      else if(maxpulse4 < threshold14 && maxpulse4 > threshold24)
      {
          continouspulse4 = 1;//medium bending
      }
      else if(maxpulse4 < threshold24)
      {
           continouspulse4 = 2;//higher bending
      }
    }


if(voltage4 > thresholdabove4){  
    innercount4 = 0;
    continouspulse4 = 0;
}
  
  }

//-------------------------------------------------------- Detection and pre-processing of voltage 5---------------------------------------------------------
if(innercount5 == 0){
  if(voltage5<threshold35){
    innercount5 = 1;
    maxpulse5=threshold35;
    continouspulse5=0;
  }
}

if(innercount5==1){
   if(voltage5 < maxpulse5)
   {
      maxpulse5=voltage5;
   }
   else
   {
      if(maxpulse5 < threshold35 && maxpulse5 > threshold15)
      {//Use threshold1 if three bending degree needed.
          continouspulse5 = 1;//lower bending
      }
      else if(maxpulse5 < threshold15 && maxpulse5 > threshold25)
      {
          continouspulse5 = 1;//medium bending
      }
      else if(maxpulse5 < threshold25)
      {
           continouspulse5 = 2;//higher bending
      }
    }


if(voltage5 > thresholdabove5){  
    innercount5 = 0;
    continouspulse5 = 0;
}
  
  }

//-------------------------------------------------------- Detection and pre-processing of voltage 6---------------------------------------------------------

if(innercount6 == 0){
  if(voltage6<threshold36){
    innercount6 = 1;
    maxpulse6=threshold36;
    continouspulse6=0;
  }
}

if(innercount6==1){
   if(voltage6 < maxpulse6)
   {
      maxpulse6=voltage6;
   }
   else
   {
      if(maxpulse6 < threshold36 && maxpulse6 > threshold16)
      {//Use threshold1 if three bending degree needed.
          continouspulse6 = 1;//lower bending
      }
      else if(maxpulse6 < threshold16 && maxpulse6 > threshold26)
      {
          continouspulse6 = 1;//medium bending
      }
      else if(maxpulse6 < threshold26)
      {
           continouspulse6 = 2;//higher bending
      }
    }


if(voltage6 > thresholdabove6){  
    innercount6 = 0;
    continouspulse6 = 0;
}
  
  }


 //--------------------------------------------------------Debug Prints---------------------------------





//-------------------------------------------------PRINT Thresholds for Finger 1----------------------------------------
//Serial.print(threshold11);
//Serial.print(",");
//Serial.print(threshold21);
//Serial.print(",");
//Serial.print(threshold31);
//Serial.print(",");
//Serial.print(thresholdabove1);
//Serial.print(",");
////---------------------------------------------------Print Result for Finger 1 -----------------------------------------
//Serial.print(continouspulse1);
//Serial.print(",");  
//Serial.println(voltage1);


////
//-------------------------------------------------PRINT Thresholds for Finger 2----------------------------------------
//Serial.print(threshold21);
//Serial.print(",");
//Serial.print(threshold22);
//Serial.print(",");
//Serial.print(threshold32);
//Serial.print(",");
//Serial.print(thresholdabove2);
//Serial.print(",");
////---------------------------------------------------Print Result for Finger 2 -----------------------------------------
//Serial.print(continouspulse2);
//Serial.print(",");
//Serial.println(voltage2);
//——————————————————————————————————————————————————————————————————
//

////-------------------------------------------------PRINT Thresholds for Finger 3----------------------------------------
////Serial.print(threshold13);
////Serial.print(",");
//Serial.print(threshold23);
//Serial.print(",");
//Serial.print(threshold33);
//Serial.print(",");
//Serial.print(thresholdabove4);
//Serial.print(",");
////---------------------------------------------------Print Result for Finger 3 -----------------------------------------
//Serial.print(continouspulse3);
//Serial.print(","); 
//Serial.println(voltage3); 

// //-------------------------------------------------PRINT Thresholds for Finger 4----------------------------------------
//Serial.print(threshold1);
//Serial.print(",");
//Serial.print(threshold24);
//Serial.print(",");
//Serial.print(threshold34);
//Serial.print(",");
//Serial.print(thresholdabove4);
//Serial.print(",");
////---------------------------------------------------Print Result for Finger 4 -----------------------------------------
//Serial.print(continouspulse4);
//Serial.print(",");  
//Serial.println(voltage4);
//

//// //-------------------------------------------------PRINT Thresholds for Finger 5----------------------------------------
////Serial.print(threshold15);
////Serial.print(",");
//Serial.print(threshold25);
//Serial.print(",");
//Serial.print(threshold35);
//Serial.print(",");
//Serial.print(thresholdabove5);
//Serial.print(",");
////---------------------------------------------------Print Result for Finger 5-----------------------------------------
//Serial.print(continouspulse5);
//Serial.print(",");  
//Serial.println(voltage5);



// -------------------------------------------------PRINT Thresholds for Finger 6----------------------------------------
//Serial.print(threshold16);
//Serial.print(",");
//Serial.print(threshold26);
//Serial.print(",");
//Serial.print(threshold36);
//Serial.print(",");
//Serial.print(thresholdabove6);
//Serial.print(",");
//////---------------------------------------------------Print Result for Finger 6 -----------------------------------------
//Serial.print(continouspulse6);
//Serial.print(",");  
//Serial.println(voltage6);


//Serial.println(String(continouspulse1)+String(continouspulse2)+String(continouspulse3)+String(continouspulse4)+String(continouspulse5));
Serial.println(String(voltage1));
}




//float detectionfunction(float voltage,float threshold1,float threshold2,float threshold3,float thresholdbelow){
//
//
//  
//if(innercount == 0){
//  if(voltage>threshold3){
//    innercount++;
//    maxpulse=threshold3;
//    maxpulse1print=0;
//    continouspulse=0;
//  }
//}
//
//
//if(innercount==1){
//   if(voltage>maxpulse){
//      maxpulse=voltage;
//      maxpulse1print=maxpulse;
//   }else{
//
//      if(maxpulse>threshold3 && maxpulse<threshold1){
//          maxpulse1print=maxpulse1print;
//          continouspulse=1;
//         
//        }else if(maxpulse>threshold1 && maxpulse<threshold2){
//          
//           maxpulse1print=maxpulse1print;
//           continouspulse=1;
//        }else if(maxpulse>threshold2 ){
//        
//           maxpulse1print=maxpulse1print;
//           continouspulse=2;
//        }else{
//           maxpulse=0;
//           maxpulse1print=0;  
//        }
//    }
//
//if(voltage<threshold3){
//    maxpulse=threshold3;
//    maxpulse1print=0;
//    }
//
//if(voltage<thresholdbelow){
//   innercount--;
//    maxpulse=threshold3;
//    maxpulse1print=0;
//    continouspulse=0;
//}
//  
//  }
//
//return continouspulse;
//
//  
//  }
