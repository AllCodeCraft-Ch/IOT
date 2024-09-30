void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop() {
  int t_time = 250;
  p_led(1,0,1,0);
  delay(t_time);
  p_led(0,1,0,1);
  delay(t_time);
  p_led(1,1,0,0);
  delay(t_time);
  p_led(0,0,1,1);
  delay(t_time);
  }

void p_led (int a,b,c,d){
  int t_time = 250;
  digitalWtite(2, a);
  digitalWtite(3, b);
  digitalWtite(4, c);
  digitalWtite(5, d);
  delay(t_time);
}