int red_light_pin_1 = 12;
int red_light_pin_2 = 11;

int green_light_pin_1 = 6;
int green_light_pin_2 = 5;

int blue_light_pin_1 = 3;
int blue_light_pin_2 = 2;

long colors [8][3] = {
  {255, 0, 0},  // Red
  {0, 255, 0},  // Green
  {0, 0, 255},  // Blue
  {255, 255, 125},  // Raspberry
  {0, 255, 255},  // Cyan
  {255, 0, 255},  // Magenta
  {255, 255, 0},  // Yellow
  {255, 255, 255} // White
  }; 

long randNumber;

const int buzzer = 9;

void setup() {
  pinMode(red_light_pin_1, OUTPUT);
  pinMode(red_light_pin_2, OUTPUT);
  
  pinMode(green_light_pin_1, OUTPUT);
  pinMode(green_light_pin_2, OUTPUT);
  
  pinMode(blue_light_pin_1, OUTPUT);
  pinMode(blue_light_pin_2, OUTPUT);

  Serial.begin(9600);
  randomSeed(analogRead(0));

  pinMode(buzzer, OUTPUT);
}

void loop() {
  RGB_color();
  buzz();
  delay(10000);
}

void RGB_color(){

  //random number from 0 to 7
  randNumber = random(0, 8);

  long rgb_red_value = colors[randNumber][0];
  long rgb_green_value = colors[randNumber][1];
  long rgb_blue_value = colors[randNumber][2];

  analogWrite(red_light_pin_1, rgb_red_value);
  analogWrite(red_light_pin_2, rgb_red_value);
  
  analogWrite(green_light_pin_1, rgb_green_value);
  analogWrite(green_light_pin_2, rgb_green_value);
  
  analogWrite(blue_light_pin_1, rgb_blue_value);
  analogWrite(blue_light_pin_2, rgb_blue_value); 
}

buzz(){
  tone(buzzer, 100); // Send 1KHz sound signal...
  delay(2000);
  noTone(buzzer);
}
