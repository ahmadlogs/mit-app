String serial_data = "";

#define relay1 8
#define relay2 9

boolean relay1status = false;
boolean relay2status = false;

void setup() {
  //start serial communication with Android
  //baudrate = 9600, it must be same in
  //MIT App and here
  Serial.begin(9600);
  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
}

void loop() {

  while(Serial.available() > 0)
  {
    serial_data = Serial.readString();
    
    //use either 0x0A or '\n' for new line
    //if (data == '\n')
      //{Serial.println("All Data Received");}

    serial_data.toLowerCase();
    //MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
    if(serial_data == "relay1 on"){
      digitalWrite(relay1, HIGH);
      Serial.println("Relay1 is ON");
    }
    else if(serial_data == "relay1 off"){
      digitalWrite(relay1, LOW);
      Serial.println("Relay1 is OFF");
    }
    //MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM

    //MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
    else if(serial_data.indexOf("dark") > -1){
      if(relay2status == false){
        digitalWrite(relay2, HIGH);
        relay2status = true;
        Serial.println("It is dark. Light is ON");
      }
    }
    else if(serial_data.indexOf("bright") > -1){
      if(relay2status == true){
        digitalWrite(relay2, LOW);
        relay2status = false;
        Serial.println("It is Bright. Light is OFF");
      }
    }
    //MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
    
    //while(Serial.available() > 0) Serial.read();
  }
}
