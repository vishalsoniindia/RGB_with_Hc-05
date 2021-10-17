/*
Written by = Vishal Soni
Date of Update :- 10 oct 2021
youtube :- http://youtube.com/vishalsoniindia
*/

#include <SoftwareSerial.h>

SoftwareSerial bt(10, 11); // RX, TX

#define red_pin 3
#define green_pin 5
#define blue_pin 6

char input = ' ';
char Command = '3';

int red_value = 0;
int green_value = 0;
int blue_value = 0;
int led_value = 0;
int led_fade = 5;
int change_color = 1;
int count = 0;
int zero_all_flag = 0;

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  bt.setTimeout(10);

}

void loop() {
  while (bt.available()) {
    input = bt.read();
    Command = input;
    Serial.print(Command);
    zero_all_flag = 1;
    delay(10);
  }


  switch (Command) {
    case 'r':
      rgb_fade();
      break;
    case '1':
      flash_all_color_slow();
      break;
    case '2':
      flash_all_color();
      break;
    case '3':
      all_color_fade();
      break;
    case 'R':
      red();
      break;
    case 'G':
      green();
      break;
    case 'B':
      blue();
      break;
    case 'S':
      light_blue();
      break;
    case 'Y':
      yellow();
      break;
    case 'O':
      orange();
      break;
    case 'D':
      purple();
      break;
    case 'P':
      pink();
      break;

  }

  //red();
  //blue();
  //green();
  //light_blue();
  //yellow();
  //orange();
  //pink();
  //purple();
  //flash_all_color();
  //flash_all_color_slow();
  //rgb_fade();
  //all_color_fade();
  //analogWrite(blue_pin, 255);

}

void feed_RGB(int red, int green, int blue) {

  analogWrite(red_pin, red);
  analogWrite(green_pin, green);
  analogWrite(blue_pin, blue);

}

void all_color_fade() {

  if (zero_all_flag == 1) {
    change_color = 1;
    led_value = 0;
    red_value = 0;
    green_value = 0;
    blue_value = 0;
    zero_all_flag = 0;
  }

  switch (change_color) {
    case 1:
      red_value = led_value;
      green_value = 0;
      blue_value = 0;
      break;
    case 2:
      red_value = 255;
      green_value = led_value;
      blue_value = 0;
      break;
    case 3:

      red_value = led_value ;
      green_value = 255;
      blue_value = 0;
      break;
    case 4:

      red_value = 0 ;
      green_value = 255;
      blue_value = led_value;
      break;
    case 5:

      red_value = 0 ;
      green_value = led_value;
      blue_value = 255;
      break;
    case 6:

      red_value = led_value;
      green_value = 0;
      blue_value = 255;
      break;
    case 7:

      red_value = 255;
      green_value = 0;
      blue_value = led_value;
      break;
  }

  feed_RGB(red_value , green_value , blue_value);

  led_value = led_value + led_fade;
  
  if (led_value > 255 || led_value < 0 ) {

    change_color ++;
    if (change_color == 8) {
      change_color = 2;
      led_fade = -led_fade;
    }
    if (change_color == 3 || change_color == 5 || change_color == 7 ) {
      led_value = 255;
      led_fade = -led_fade;

    }
    if ( change_color == 4 || change_color == 6 ) {
      led_value = 0;
      led_fade = -led_fade;
    }
    if ( change_color == 1 || change_color == 2 ) {
      if(led_fade < 0){
        led_fade = -led_fade;
      }
      led_value = 0;
    }
  }


  delay(30);

}

void red() {
  int red_fix = 255;
  int green_fix = 0;
  int blue_fix = 0;
  feed_RGB(red_fix, green_fix , blue_fix );
}

void green() {
  int red_fix = 0;
  int green_fix = 255;
  int blue_fix = 0;
  feed_RGB(red_fix, green_fix , blue_fix );
}

void blue() {
  int red_fix = 0;
  int green_fix = 0;
  int blue_fix = 255;
  feed_RGB(red_fix, green_fix , blue_fix );
}

void light_blue() {
  int red_fix = 0;
  int green_fix = 255;
  int blue_fix = 255;
  feed_RGB(red_fix, green_fix , blue_fix );
}

void yellow() {
  int red_fix = 255;
  int green_fix = 50;
  int blue_fix = 0;
  feed_RGB(red_fix, green_fix , blue_fix );
}

void orange() {
  int red_fix = 255;
  int green_fix = 10;
  int blue_fix = 0;
  feed_RGB(red_fix, green_fix , blue_fix );
}

void pink() {
  int red_fix = 255;
  int green_fix = 0;
  int blue_fix = 30;
  feed_RGB(red_fix, green_fix , blue_fix );
}

void purple() {
  int red_fix = 255;
  int green_fix = 0;
  int blue_fix = 3;
  feed_RGB(red_fix, green_fix , blue_fix );
}

void flash_all_color() {
  if (zero_all_flag == 1) {
    change_color = 1;
    count = 0;
    zero_all_flag = 0;
  }
  switch (change_color) {
    case 1:
      red();
      break;
    case 2:
      blue();
      break;
    case 3:
      orange();
      break;
    case 4:
      green();
      break;
    case 5:
      pink();
      break;
    case 6:
      light_blue();
      break;
    case 7:
      purple();
      break;
    case 8:
      yellow();
      break;
  }

  count ++;

  if (count >= 5000) {
    change_color ++;
    if (change_color >= 9) {
      change_color = 1;
    }
    count = 0;
  }
}

void flash_all_color_slow() {
  if (zero_all_flag == 1) {
    change_color = 1;
    count = 0;
    zero_all_flag = 0;
  }
  switch (change_color) {
    case 1:
      red();
      break;
    case 2:
      blue();
      break;
    case 3:
      orange();
      break;
    case 4:
      green();
      break;
    case 5:
      pink();
      break;
    case 6:
      light_blue();
      break;
    case 7:
      purple();
      break;
    case 8:
      yellow();
      break;
  }

  count ++;

  if (count >= 20000) {
    change_color ++;
    
    if (change_color >= 9) {
      change_color = 1;
    }
    count = 0;
  }
}

void rgb_fade() {
  if (zero_all_flag == 1) {
    change_color = 1;
    led_value = 0;
    red_value = 0;
    green_value = 0;
    blue_value = 0;
    zero_all_flag = 0;
  }

  switch (change_color) {
    case 1:
     
      red_value = led_value;
      green_value = 0;
      blue_value = 0;
      break;
    case 2:
     
      red_value = 0;
      green_value = led_value;
      blue_value = 0;
      break;
    case 3:
     
      red_value = 0;
      green_value = 0;
      blue_value = led_value ;
      break;
    case 4:
     
      red_value = 0 ;
      green_value = 255;
      blue_value = led_value;
      break;

  }

  feed_RGB(red_value , green_value , blue_value);

  led_value = led_value + led_fade;
  if (led_value > 255 ) {
    led_value = 255;
    led_fade = -led_fade;
  }
  if (led_value < 0 ) {
    change_color ++;
    if (change_color == 4) {
      change_color = 1;
    }
    led_fade = -led_fade;
    led_value = 0;
  }

  delay(30);

}
