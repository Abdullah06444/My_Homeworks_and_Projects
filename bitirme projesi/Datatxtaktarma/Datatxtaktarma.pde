//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial mySerial;

void setup() {
  mySerial = new Serial(this, Serial.list()[0], 115200);
  output = createWriter ("data.txt");
}

void draw() {
  if (mySerial.available() > 0) {
    String SenVal = mySerial.readString();
    if (SenVal != null) {
      output.println(SenVal);
    }
  }
}

void keyPressed(){
  output.flush();
  output.close();
  exit();
}
