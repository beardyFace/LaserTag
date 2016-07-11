char GetData[] = {
  'B', 'A','B','A', 'D'};

volatile boolean fires = false;

void fire()
{
  for(int i = 0; i < sizeof(GetData); i++)
    Serial.print(GetData[i]);
}

void fireSet(){
  fires = true;
//  delay(1000);
}

void setup()
{
  Serial.begin(4800);
  tone(4, 38000);
  attachInterrupt(0, fireSet, RISING);//Pin 2
//  pinMode(2, INPUT);
}

void loop()
{
  if(fires){
    fire();
    fires = false;
  }
  delay(100);
//  while(!Serial.available()){
//    int val = digitalRead(2); 
//    Serial.print(val);
//  }
//  char value = Serial.read();
//  Serial.print(value);
//  if(value == 'F')
//    fire();
  //fire();
  //  for(int i = 0; i < sizeof(GetData); i++)
  //      Serial.print(GetData[i]);
  //  delay(1000);
}

