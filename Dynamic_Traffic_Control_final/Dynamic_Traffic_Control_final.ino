const int echoPin1=12;
const int echoPin2=11;
const int echoPin3;
const int echoPin4;

const int triggerPin1=2;
const int triggerPin2=10;
const int triggerPin3;
const int triggerPin4;

double distance;
double pingtime;

int car1=0;
int car2=0;
int car3=0;
int car4=0;

int ontime1=6000;
int ontime2=-1;
int ontime3=-1;
int ontime4=-1;
unsigned long t_passed=0;
void setup()
{
  // put your setup code here, to run once:
  pinMode(triggerPin1, OUTPUT);
  pinMode(triggerPin2, OUTPUT);
  pinMode(triggerPin3, OUTPUT);
  pinMode(triggerPin4, OUTPUT);
  
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
  Serial.begin(9600);
}

int sensor(int trigPin,int echoPin)
{
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  pingtime=pulseIn(echoPin,HIGH);
  distance=pingtime*0.034/2;
  if(distance>20)
  {
    return 0;
  }
  else
  {
    return 1;
  } 
}

void car_counter()
{
  car1=car1+sensor(triggerPin1,echoPin1);
  car2=car2+sensor(triggerPin2,echoPin2);
  car3=car3+sensor(triggerPin3,echoPin3);
  car4=car4+sensor(triggerPin4,echoPin4);
  t_passed+=2;
  //will need to assume all cars will take same time to pass because it 
  //is so fast it will count one car many times
  //If it is too high we can divide 100.. and take GIF so it will come as 1.
  //check new ping library 
}



void loop()
{
  
  car_counter();
  /*
  Serial.print("car in dir 1=");
  Serial.println(car1);
  Serial.print("car in dir 2=");
  Serial.println(car2);
  delay(1000);
  
  Serial.print("car in dir 3");
  Serial.println(car3);
  Serial.print("car in dir 4");
  Serial.println(car4);
  */
  
   if(ontime2==-1 && ontime3==-1 && ontime4==-1 && ontime1!=-1)
   {
      if(ontime1<tpassed)
      {
       tpassed=0;
       ontime1=-1;
       ontime=car1;//Multiply by constant
      } 
      else
      {
        ontime1+=2;
       //lane 1 green light all other red 
      }
    }
    if(ontime1==-1 && ontime3==-1 && ontime4==-1 && ontime2!=-1)
   {
      if(ontime1<tpassed)
      {
       tpassed=0;
       ontime2=-1;
       ontime=car2;
      } 
      else
      {
        ontime2+=2;
       //lane 2 green light all other red 
      }
    }
    if(ontime1==-1 && ontime2==-1 && ontime4==-1 && ontime3!=-1)
   {
      if(ontime1<tpassed)
      {
       tpassed=0;
       ontime2=-1;
       ontime=car3;
      } 
      else
      {
        ontime3+=3;
       //lane 2 green light all other red 
      }
 
   
}
